#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H

#include "Rule.h"
#include <set>
#include <sstream>
#include "Graph.h"
#include <iostream>

class DatalogProgram {

private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Rule*> rules;
    std::vector<Predicate*> queries;

    std::set<std::string> domain;
    std::vector<std::set<unsigned int>> vecSCC;

public:
    const std::vector<Predicate *> &getSchemes() const {
        return schemes;
    }
    void setSchemes(const std::vector<Predicate *> &schemes) {
        DatalogProgram::schemes = schemes;
    }
    const std::vector<Predicate *> &getFacts() const {
        return facts;
    }
    void setFacts(const std::vector<Predicate *> &facts) {
        DatalogProgram::facts = facts;
    }
    const std::vector<Rule *> &getRules() const {
        return rules;
    }
    void setRules(const std::vector<Rule *> &rules) {
        DatalogProgram::rules = rules;
    }
    const std::vector<Predicate *> &getQueries() const {
        return queries;
    }
    void setQueries(const std::vector<Predicate *> &queries) {
        DatalogProgram::queries = queries;
    }


    void addScheme(Predicate* p){schemes.push_back(p);}
    void addFact(Predicate* p){facts.push_back(p);}
    void addRule(Rule* p){rules.push_back(p);}
    void addQuery(Predicate* p){queries.push_back(p);}

    void makeDomain(){
        for(Predicate* pred : facts){
            for(Parameter* param: pred->getParameters()){
                domain.insert(param->toString());
            }
        }
    }

    std::string toString(){
        std::string finalString;
        std::ostringstream string;

        string << "Success!\n";
        string << "Schemes(" << std::to_string(schemes.size()) << "):\n";
        for (size_t i = 0; i < schemes.size(); i++){
            string << "  " << schemes.at(i)->toString() << std::endl;
        }
        string << "Facts(" << std::to_string(facts.size()) << "):\n";
        for (size_t i = 0; i < facts.size(); i++){
            string << "  " << facts.at(i)->toString() << "." << std::endl;
        }
        string << "Rules(" << std::to_string(rules.size()) << "):\n";
        for (size_t i = 0; i < rules.size(); i++){
            string << "  " << rules.at(i)->toString() << std::endl;
        }
        string << "Queries(" << std::to_string(queries.size()) << "):\n";
        for (size_t i = 0; i < queries.size(); i++){
            string << "  " << queries.at(i)->toString() << "?" << std::endl;
        }
        makeDomain();
        string << "Domain(" << std::to_string(domain.size()) << "):\n";
        for (std::string s : domain){
            string << "  " << s << std::endl;
        }


        finalString = string.str();

        return finalString;

    }

    void createDG() {
        Graph forwardGraph(rules.size());
        Graph reverseGraph(rules.size());
        for (unsigned int i = 0; i < rules.size(); ++i) {
            for (unsigned int j = 0; j < rules.size(); ++j) {
                for (unsigned int k = 0; k < rules.at(i)->getPredSize(); ++k) {
                    if (rules.at(j)->getPred()->getPredicateId() == rules.at(i)->getBodyPred(k)->getPredicateId()) {
                        forwardGraph.addEdges(i,j);
                        reverseGraph.addEdges(j,i);
                    }
                }
            }


        }
        std::cout << forwardGraph.toString();


        //DFS reverse graph
        std::vector<unsigned int> postOrder = reverseGraph.postOrder();

        // dfs forward graph
        std::vector<std::set<unsigned int>> SCC = forwardGraph.calculateSCC(postOrder);
        vecSCC = SCC;
    }

    const std::vector<std::set<unsigned int>> &getVecScc() const {
        return vecSCC;
    }


};


#endif //DATALOGPROGRAM_H
