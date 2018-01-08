#ifndef EXPRPARSER_H
#define EXPRPARSER_H
#include "lexer.h"
#include "abstractsyntaxtree.h"
/*------------------------------------------------
factor: NUMBER | "(" expression ")"
term: factor { ("*" | "/") factor }
expression: term { ("+" | "-") term }
------------------------------------------------*/

class ExprParser
{
public:
    ExprParser();
    ExprParser(Lexer* lexer);
    ExprParser(string inputFile);
    AbstractSyntaxTree* expression();
    AbstractSyntaxTree* term();
    AbstractSyntaxTree* factor();
    void token(string name);
    bool isToken(string name);
private:
    Lexer* _lexer;
     fstream _inputFile;

};

#endif // EXPRPARSER_H
