#include "Interpreter.h"


void Interpreter::schemesToDatabase(std::vector<Predicate *> Schemes) {
    for(unsigned int i = 0; i < Schemes.size(); ++i){
        std::string name = Schemes.at(i)->getPredicateId();
        Header myHeader;
        for (unsigned int j = 0; j < Schemes.at(i)->getParameters().size(); ++j){
            myHeader.addAttribute(Schemes.at(i)->getParameters().at(j)->toString());
        }
        Relation newRelation;
        newRelation.setName(name);
        newRelation.setHeader(myHeader);
        database.addRelation(name, newRelation);
    }
}
void Interpreter::factsToDatabase(std::vector<Predicate *> Facts) {
    for(unsigned int i = 0; i < Facts.size(); ++i){
        std::string name;
        name = Facts.at(i)->getPredicateId();
        Tuple myTuple;
        for (unsigned int j = 0; j < Facts.at(i)->getParameters().size(); ++j){
            myTuple.addValue(Facts.at(i)->getParameters().at(j)->toString());
        }
        database.addTupleToRelation(name, myTuple);
    }
}
void Interpreter::evaluateQueries(std::vector<Predicate *> Queries) {

    // withing for loop, print out predicate, ?, yes or no, then evalpred.toString();
    //for loop through queries, and then call eval pred on each query
    for(unsigned int i = 0; i < Queries.size(); ++i){
        std::cout << Queries.at(i)->toString() << "?";
        if (evaluatePredicate(Queries.at(i)).tuples.size() != 0){
            std::cout << " Yes(" << std::to_string(evaluatePredicate(Queries.at(i)).tuples.size()) << ')' << std::endl;
        }
        else{
            std::cout << " No\n";
        }
        std::cout << (evaluatePredicate(Queries.at(i))).tupleToString();
    }


}

void Interpreter::evaluateRules() {
    for(std::set<unsigned int> curSCC : datalogProgram.getVecScc()){
        std::vector<Rule*> myRules;

        std::cout << "SCC: ";
        std::string sep = "";
        for(unsigned int curNode : curSCC){
            std::cout << sep << "R" << curNode;
            myRules.push_back(datalogProgram.getRules().at(curNode));
            sep = ",";
        }
        std::cout << std::endl;

        if(myRules.size() > 1){
            evaluateRuleVec(myRules);
        }
        else{
            bool isDependent = false;
            //if(//check to see if the rule is dependent one itself, if it ia evaluate single rule and pass in the rule and
            // increment shcme counter to 1 )
            for (unsigned int i = 0; i < myRules.at(0)->getPredSize(); ++i){
                if (myRules.at(0)->getPred()->getPredicateId() == myRules.at(0)->getBodyPred(i)->getPredicateId()){
                    isDependent = true;
                }
            }

            if (!isDependent){
                evaluateRule(*myRules.at(0));
                schemeCounter = 1;

            }
            else{
                evaluateRuleVec(myRules);
            }

            //else (call eval rule vec
        }
        std::cout << schemeCounter << " passes: ";
        schemeCounter = 0;
        sep = "";
        for(unsigned int curNode : curSCC){
            std::cout << sep << "R" << curNode;
            sep = ",";
        }
        std::cout << std::endl;
    }

}
void Interpreter::evaluateRule(Rule curRule) {
    Relation tempRel;
    std::vector<Relation> vecRel;
    // ADDS ALL RELATIONS BASED ON THE CUR RULES BODY PREDICATES
    for (unsigned int i = 0; i < curRule.getPredSize(); ++i){
        vecRel.push_back(evaluatePredicate(curRule.getBodyPred(i)));
    }
    tempRel = vecRel.at(0);
    //JOINS EACH RELATION WITH THE JOINED RELATIONS BEFORE IT
    for (unsigned int i = 1; i < vecRel.size(); ++i){
        tempRel = tempRel.joinRelation(vecRel.at(i));
    }
    std::vector<unsigned int> indexes;
    // GETS THE INDEXES WITHIN THE BODY PREDICATE OF THE PARAMETERS IN THE HEAD PREDICATE
    // FINDS INDEXES OF c (4) AND n(1) IN -> cn(c,n) :- snap(S,n,A,P),csg(c,S,G).
    for(unsigned int i = 0; i < curRule.getPred()->getParameters().size(); ++i){
        for(unsigned int j = 0; j < tempRel.getHeader().getSize(); ++j){
            if(tempRel.getHeader().find(j) == curRule.getPred()->getParameters().at(i)->toString()){
                indexes.push_back(j);
            }
        }
    }
    tempRel = tempRel.project(indexes);
    std::cout << curRule.toString() << std::endl;
    database.getRelationByRef(curRule.getPred()->getPredicateId()).unionRelation(tempRel);

}

Relation Interpreter::evaluatePredicate(Predicate* p) {
    Relation r = database.getRelation(p->getPredicateId());
    std::map<std::string, unsigned int> valuePairs;
    std::vector<unsigned int> projectInts;
    std::vector<std::string> renameStrings;
    for(unsigned int i = 0; i < p->getParameters().size(); ++i){
        std::string parameter = p->getParameters().at(i)->toString();
        if(parameter.at(0) == '\''){
            r = r.select1(i, parameter);
        }
        else{
            if(valuePairs.find(parameter) != valuePairs.end()){
                r = r.select2(i, valuePairs.at(parameter));
            }
            else{
                valuePairs.insert({parameter, i});
                projectInts.push_back(i);
                renameStrings.push_back(parameter);
            }
        }
    }
    r = r.project(projectInts);
    r = r.rename(renameStrings);
    return r;
}

void Interpreter::evaluateRuleVec(std::vector<Rule *> myRules) {
    unsigned int before;
    unsigned int after;
    do {
        before = database.getNumTuples(); // CHECKS THE NUM OF TUPLES BEFORE EVALUATING
        for (Rule *x: myRules) {
            evaluateRule(*x); // CALLS EVAL RULE ON EACH RULE
        }
        after = database.getNumTuples(); // CHECKS THE NUM OF TUPLES AFTER EVALUATING
        schemeCounter++;
    } while(before != after);
}


