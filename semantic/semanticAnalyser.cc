#include "semanticAnalyser.h"

semanticAnalyser::semanticAnalyser(symbolTable &ST, Node *root)
{
    this->ST = ST;
    this->root = root;
}

bool semanticAnalyser::analyse()
{
   if (ST.duplicatesFound())
   {
       ST.listDuplicates();
       return false;
   }
   return true;
}