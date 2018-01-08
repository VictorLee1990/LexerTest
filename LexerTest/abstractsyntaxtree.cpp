#include "abstractsyntaxtree.h"
#include <qdebug.h>
AbstractSyntaxTree::AbstractSyntaxTree()
{

}

ASTLeaf::ASTLeaf()
{

}

ASTLeaf::ASTLeaf(Token* t)
{
    _token = t;
}

AbstractSyntaxTree *ASTLeaf::child(int i)
{
    return 0;
}

int ASTLeaf::numChildren()
{
    return 0;
}

vector<AbstractSyntaxTree *> ASTLeaf::children()
{
    vector<AbstractSyntaxTree *> abtree;
    return abtree;
}

string ASTLeaf::toString()
{
    return _token->getText();
}

string ASTLeaf::location()
{
    return "at line" + _token->getLineNumber();
}

Token *ASTLeaf::token()
{
    return _token;
}

ASTList::ASTList()
{

}

ASTList::ASTList(vector<AbstractSyntaxTree*> ABSTree)
{
    _children = ABSTree;
}

AbstractSyntaxTree* ASTList::child(int i)
{
    return _children.at(i);
}

int ASTList::numChildren()
{
    return 0;
}

vector<AbstractSyntaxTree *> ASTList::children()
{
    return _children[0]->Iterator();
}

string ASTList::toString()
{
    string buildString;
    buildString.append("(");
    string sep = "";
    AbstractSyntaxTree* ASTTree;
    qDebug() << _children.size()-1;
    for(int i=_children.size()-1;i>=0;i--)
    {
        ASTTree = _children[i];
        buildString.append(sep);
        sep = " ";
        qDebug() << QString::fromStdString(ASTTree->toString());
        buildString.append(ASTTree->toString());
    }
    buildString.append(")");
    return buildString;
}

string ASTList::location()
{
    AbstractSyntaxTree* ASTTree;

    for(int i=0;_children.size();i++)
    {
        ASTTree = _children[i];
        string s = ASTTree->location();
        if(s != "")
        {
            return s;
        }

    }
    return "";
}
///-----------------------------------------------------------------///

NumberLiteral::NumberLiteral(Token* t)
{
    _token = t;
}

int NumberLiteral::value()
{
    return _astLeaf->token()->getLineNumber();
}

Name::Name(Token *t)
{
    _token = t;
}

string Name::name()
{
    return _astLeaf->token()->getText();
}

BinaryExpr::BinaryExpr(vector<AbstractSyntaxTree *> c)
{
//    _astList = new ASTList(c);
//    _astList = _children;
    _children = c;
}

AbstractSyntaxTree *BinaryExpr::left()
{
    return child(0);
}

string BinaryExpr::operatorSymbols()
{
    return (((ASTLeaf*)child(1))->token()->getText());
}

AbstractSyntaxTree *BinaryExpr::right()
{
    return child(2);
}
