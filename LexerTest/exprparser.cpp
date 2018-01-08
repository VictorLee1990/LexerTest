#include "exprparser.h"
#include <qdebug.h>
ExprParser::ExprParser()
{

}

ExprParser::ExprParser(Lexer* lexer)
{
    _lexer = lexer;
}

ExprParser::ExprParser(string inputFile)
{
    _lexer = new Lexer(inputFile);
}

AbstractSyntaxTree *ExprParser::expression()
{
    //    _lexer = new Lexer(inputFile);


    AbstractSyntaxTree* left = term();
    AbstractSyntaxTree* lefttttt;
    while(isToken("+") || isToken("-"))
    {
        vector<AbstractSyntaxTree*> abstTree;
        ASTLeaf* op = new ASTLeaf(_lexer->read());
        AbstractSyntaxTree* right = term();
        abstTree.push_back(right);
        abstTree.push_back(op);
        abstTree.push_back(left);
        lefttttt = new BinaryExpr(abstTree);
        //        lefttttt->children();
//        qDebug()<< QString::fromStdString(lefttttt->toString());

    }

    return lefttttt;
}

AbstractSyntaxTree* ExprParser::term()
{

    AbstractSyntaxTree* left = factor();
    while(isToken("*")||isToken("/"))
    {
        vector<AbstractSyntaxTree*> abstTree;
        ASTLeaf* op = new ASTLeaf(_lexer->read());
        AbstractSyntaxTree* right =factor();
        abstTree.push_back(right);
        abstTree.push_back(op);
        abstTree.push_back(left);
        left = new BinaryExpr(abstTree);
//        qDebug()<< QString::fromStdString(left->toString());
    }

    return left;


}

AbstractSyntaxTree *ExprParser::factor()
{

    if(isToken("("))
    {
        token("(");
        AbstractSyntaxTree* e = expression();
        token(")");
        return e;
    }
    else
    {
        Token* t = _lexer->read();
        if(t->isNumber())
        {
            NumberLiteral* n = new NumberLiteral(t);
            return n;
        }
    }

}

void ExprParser::token(string name)
{
    Token* t = _lexer->read();
    if(!(t->isIdentifier() && (name.compare(t->getText()))))
    {
        cout << "have problem" << endl;
    }

}

bool ExprParser::isToken(string name)
{

    //    Token* ttt = _lexer->peek(1);
    Token* t = _lexer->peek(0);
    return (t->isIdentifier() && ((name.compare(t->getText()))== 0));

}
