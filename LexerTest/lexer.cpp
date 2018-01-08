#include "lexer.h"
#include <qdebug.h>

Lexer::Lexer()
{


}

Lexer::Lexer(string inputFile)
{

    _lineNumber = 0;
    _reg = ("([A-Za-z]+)|([0-9]+)|([+|\\-|=|*|<|>|!|\"|\\\\\|%|&|(|)|;])");
    //    _reg = ("\\[[:punct:]]");
    _inputFile.open(inputFile);


}

int Lexer::readLine()
{
    string line;
    int pos = 0;
    smatch sm;
    int endpos = line.length();
    getline(_inputFile,line);

    _hasMore = true;

    if(line.empty())
    {
        _hasMore = false;
        return 0;
    }
    _lineNumber++;
    if(regex_search(line,sm,_reg)){


        cout << "Match!" << endl;
        while(regex_search(line,sm,_reg))
        {

            cout << " 0: " << sm[0] << " 1: " << sm[1]
                 << " 2: " << sm[2] << " 3: " << sm[3] << endl;
            addToken(_lineNumber,sm);
            line = sm.suffix().str();
            cout << line << endl;

        }
        token = new IdToken(_lineNumber,EndLine);
        _tokenQueue.push_back(token);
    }
    else{
        cout << "Not Match!" << endl;
    }
}

void Lexer::addToken(int lineNumber, smatch sm)
{
    string m = sm[0];

    if(sm[0] != "")
    {

        if(sm[1] != "")
        {
            token = new IdToken(lineNumber,sm[1].str());
        }
        else if(sm[2] != "")
        {
            token = new NumToken(lineNumber,sm[2].str());

        }
        else if(sm[3] != "")
        {
            token = new IdToken(lineNumber,sm[3].str());
        }

        _tokenQueue.push_back(token);
        string text = _tokenQueue.back()->getText();

        token->getText();

    }

}

Token* Lexer::read()
{
    while(0 >= _tokenQueue.size())
    {
        if(readLine() == 0)
        {
            break;
        }

    }
    Token* token = nullptr;

    if(_tokenQueue.size() >0)
    {

        token = _tokenQueue.front();

        _tokenQueue.pop_front();
    }

    return token;
}

Token* Lexer::peek(int i)
{
    while(0 >= _tokenQueue.size())
    {
        if(readLine() == 0)
        {
            break;
        }

    }

    Token *token;
    token = _tokenQueue[i];
    return token;
}

Token::Token()
{

}

bool Token::isNumber()
{
    return true;
}

string Token::getText()
{
    return "aaaaaaaaaa";
}

bool Token::isIdentifier()
{
    return true;
}

NumToken::NumToken(int lineNumber, string value)
{
    _lineNumber = lineNumber;
    _value = value;
}

bool NumToken::isNumber()
{
    return true;
}

string NumToken::getText()
{
    string value;
    value = _value;
    return value;
}

bool NumToken::isIdentifier()
{
    return false;
}

int NumToken::getLineNumber()
{
    return _lineNumber;
}

IdToken::IdToken(int lineNumber, string id)
{
    _lineNumber = lineNumber;
    _id = id;
}

bool IdToken::isNumber()
{
    return false;
}

bool IdToken::isIdentifier()
{
    return true;
}

string IdToken::getText()
{
    string id;
    id = _id;
    return id;
}

int IdToken::getLineNumber()
{
    return _lineNumber;
}
