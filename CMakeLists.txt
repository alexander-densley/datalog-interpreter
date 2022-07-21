cmake_minimum_required(VERSION 3.16)

project(C_S_236___Project_1)


set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

include_directories(.)

add_executable(C_S_236___Project_1
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h
        CommaAutomaton.h
        CommaAutomaton.cpp
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        Q_MarkAutomaton.cpp
        Q_MarkAutomaton.h
        Left_ParenAutomaton.cpp
        Left_ParenAutomaton.h
        Right_ParenAutomaton.cpp
        Right_ParenAutomaton.h
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        AddAutomaton.cpp
        AddAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        IdAutomaton.cpp
        IdAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        CommentAutomaton.cpp
        CommentAutomaton.h
        DatalogProgram.cpp
        DatalogProgram.h
        Parser.cpp
        Parser.h
        Parameter.h Predicate.h Rule.h Interpreter.cpp Interpreter.h Tuple.h Relation.h Header.h Database.h Relation.cpp Graph.cpp Graph.h)
