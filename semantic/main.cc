#include <iostream>
#include "parser.tab.hh"
#include "symbolTable.h"

extern Node *root;
extern FILE *yyin;

void yy::parser::error(std::string const &err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}

void stBuilderRec(symbolTable &ST, Node *walker, Node *parent)
{
  while (walker->children.size() > 0)
  {
    if (walker->type == "VarDeclaration")
    {
      record *newRecord = new variable();
      Node *typeNode = walker->children.front();
      newRecord->type = typeNode->children.front()->value;
      walker->children.pop_front();
      Node* idNode = walker->children.front();
      newRecord->id = idNode->children.front()->value;
      walker->children.pop_front();
      ST.put(newRecord->id, newRecord);
    }
    Node *next = walker->children.front();
    walker->children.pop_front();
    stBuilderRec(ST, next, walker);
  }
}

void stBuilder(symbolTable &ST)
{
  Node *walker = root;
  Node *next = walker->children.front();
  walker->children.pop_front();
  stBuilderRec(ST, next, walker);
}

int main(int argc, char **argv)
{
  //Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
  symbolTable ST;
  if (argc > 1)
  {
    if (!(yyin = fopen(argv[1], "r")))
    {
      perror(argv[1]);
      return 1;
    }
  }

  yy::parser parser;

  if (!parser.parse())
  {
    root->print_tree();
    root->generate_tree();
  }

  return 0;
}