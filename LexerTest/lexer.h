#ifndef LEXER_H
#define LEXER_H
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <deque>
#define EndLine "\r\n"
using namespace std;

class Token;
class Lexer
{
public:
    Lexer();
    Lexer(string inputFile);
    Token *read();
    Token *peek(int i);

private:
    int readLine();
    void addToken(int lineNumber,smatch sm);
    fstream _inputFile;
    int _lineNumber;
    regex _reg;
    bool _hasMore;
    deque<Token*> _tokenQueue;
    Token *token;

};
//const string Token::endLine = "\r\n";

class Token
{
public:
    Token();
    static const string endLine;
    virtual bool isNumber() = 0;
    virtual string getText() = 0;
    virtual bool isIdentifier() = 0;
    virtual int getLineNumber() = 0;

private:    

};

class NumToken:public Token
{
public:
    NumToken(int lineNumber,string value);
    virtual bool isNumber();
    virtual string getText();
    virtual bool isIdentifier();
     virtual int getLineNumber();


private:
    int _lineNumber;
    string _value;

};

class IdToken:public Token
{
public:
    IdToken(int lineNumber,string id);
    virtual bool isNumber();
    virtual bool isIdentifier();
    virtual string getText();
     virtual int getLineNumber();
private:
    int _lineNumber;
    string _id;
};

#endif // LEXER_H
