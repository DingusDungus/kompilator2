
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
    void stBuilderRec(Node *walker, Node *parent);
    void stBuilder();
    void declared(std::string key);

public:
    symbolTable();
    void enterScope();
    void exitScope();
    void init(Node *root);
    void printSTtree();
    void resetScopes();
    scope *operator[](int index);
    scope *getCurrent();
    int size();
    bool duplicatesFound();
    bool duplicatesFoundRec(scope *ptr);
    void listDuplicates();
    void listDuplicatesRec(scope *ptr);

    void put(std::string key, record *item);
    record *lookup(std::string key);
};

#endif