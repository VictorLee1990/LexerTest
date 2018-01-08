#ifndef FSM_LEXER_H
#define FSM_LEXER_H
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <deque>
#include "lexer.h"

using namespace std;


class FSM_Lexer
{
public:
    enum tokenType{Idtentifier=0,Number=1,Space=2};
    FSM_Lexer();
    FSM_Lexer(string inputFile);
    int getline2char();
    int getChar();
    void ungetChar(int c);
    string read();
    string read2();
    Token *readToken();

    inline static bool isIdtentifier(int c){return 'A' <= c && c <= 'Z' ||
                'a' <= c && c <= 'z';}

    inline static bool isNumber(int c){return '0' <= c && c <= '9';}

    inline static bool isOperator(int c){return  c == '=' || c == '+' || c == '-'
                || c == '*' || c == '/';}

    inline static bool isSpace(int c){return 0 <= c && c <= ' ';}

private:
    fstream _inputFile;
    int _lineNumber;
    deque<Token*> _tokenQueue;
    Token *_token;
    static const int _EMPTY = -1;
    int _lastChar;
    std::string::iterator _itChar;
    std::string::iterator _itCharEnd;

};

//class Token
//{
//public:
//    Token();
//    static const string endLine;
//    virtual bool isNumber() = 0;
//    virtual string getText() = 0;
//    virtual bool isIdentifier() = 0;

//private:

//};

//class NumToken:public Token
//{
//public:
//    NumToken(int lineNumber,string value);
//    virtual bool isNumber();
//    virtual string getText();
//    virtual bool isIdentifier();


//private:
//    string _lineNumber;
//    string _value;

//};

//class IdToken:public Token
//{
//public:
//    IdToken(int lineNumber,string id);
//    virtual bool isNumber();
//    virtual bool isIdentifier();
//    virtual string getText();
//private:
//    string _lineNumber;
//    string _id;
//};
#endif // FSM_LEXER_H
