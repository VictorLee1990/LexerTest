#ifndef ABSTRACTSYNTAXTREE_H
#define ABSTRACTSYNTAXTREE_H
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <list>
#include "lexer.h"

using namespace std;

class AbstractSyntaxTree
{
public:
    AbstractSyntaxTree();
    virtual AbstractSyntaxTree* child(int i)=0;
    virtual int numChildren()=0;
    virtual vector<AbstractSyntaxTree*> children()=0;
    virtual string location()=0;
    virtual string toString()=0;
    vector<AbstractSyntaxTree*> Iterator(){return children();}

private:

};


class ASTLeaf:public AbstractSyntaxTree
{
public:
    ASTLeaf();
    ASTLeaf(Token* t);
    AbstractSyntaxTree* child(int i);
    virtual int numChildren();
    vector<AbstractSyntaxTree*> children();
    string toString();
    string location();
    Token* token();
protected:
    Token* _token;
private:


};

class ASTList:public AbstractSyntaxTree
{
public:
    ASTList();
    ASTList(vector<AbstractSyntaxTree*> ABSTree);
    AbstractSyntaxTree* child(int i);
    virtual int numChildren();
    vector<AbstractSyntaxTree*> children();
    string toString();
    string location();
protected:
    vector<AbstractSyntaxTree*> _children;
private:
};

///-----------------------------------------------------------------///

class NumberLiteral:public ASTLeaf
{
public:
    NumberLiteral(Token* t);
    int value();
private:
    ASTLeaf* _astLeaf;

};

class Name:public ASTLeaf
{
public:
    Name(Token* t);
    string name();
private:
    ASTLeaf* _astLeaf;
};

class BinaryExpr:public ASTList
{
public:
    BinaryExpr(vector<AbstractSyntaxTree*> c);
    AbstractSyntaxTree* left();
    string operatorSymbols();
    AbstractSyntaxTree* right();
    ASTList* _astList;
private:

};

#endif // ABSTRACTSYNTAXTREE_H
