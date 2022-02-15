
#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include "scope.h"
#include "Node.h"
#include <iostream>
#include <vector>

struct duplicate 
{
    record *duplicateScope;
    record *duplicateRecord;
    duplicate() { duplicateScope = nullptr; duplicateRecord = nullptr; }
};

class symbolTable
{
private:
    Node *nodeRoot;
    scope *root;
    scope *current;
    std::vector<std::string> expressionElements;
    void stBuilderRec(Node *walker, Node *parent);
    void stBuilder();
    void declared(std::string key);
    bool expressionCheck();
    bool expressionCheckRec(Node *nodePtr);
    void expressionCheckRecNode(Node *nodePtr);

public:
    symbolTable();
    void enterScope();
    bool typeCheck();
    void exitScope();
    void init(Node *root);
    void printSTtree();
    void resetScopes();
    scope *operator[](int index);
    scope *getCurrent();
    int size();
    bool duplicatesFound();
    bool duplicatesFoundRec(scope *ptr);

    void put(std::string key, record *item);
    record *lookup(std::string key);
};

#endif