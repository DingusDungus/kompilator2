#include "scope.h"
#include "Node.h"
#include <iostream>
#include <vector>

class symbolTable
{
private:
    Node *nodeRoot;
    scope *root;
    scope *current;
    void stBuilderRec(Node *walker, Node *parent);
    void stBuilder();

public:
    symbolTable();
    void enterScope();
    void exitScope();
    void init(Node *root);

    void put(std::string key, record *item);
    record *lookup(std::string key);
};