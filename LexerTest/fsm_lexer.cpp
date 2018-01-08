#include "fsm_lexer.h"
#include <qdebug.h>
FSM_Lexer::FSM_Lexer()
{


}

FSM_Lexer::FSM_Lexer(string inputFile)
{
    _lineNumber = 0;
    _lastChar = _EMPTY;
    _inputFile.open(inputFile);
}

int FSM_Lexer::getline2char()
{
    int gettingChar;


    if(_itChar != _itCharEnd)
    {
        gettingChar = *_itChar;
        _itChar++;
    }
    else
    {
        gettingChar = _EMPTY;
    }
    return gettingChar;


}

int FSM_Lexer::getChar()
{


    if(_lastChar == _EMPTY)
    {
        //        return _inputFile.get();
        return getline2char();
    }
    else
    {
        int c = _lastChar;
        _lastChar = _EMPTY;
        return c;
    }
}

void FSM_Lexer::ungetChar(int c)
{
    _lastChar = c;
}

string FSM_Lexer::read()
{
    string sb;
    int c;
    do
    {

        c = getChar();
    }
    while(isSpace(c));

    if(c<0)
    {
        qDebug() << c;
        sb.clear();
        return sb;
    }
    else if(isNumber(c))
    {
        do
        {
            sb.append(1,(char)c);
            c = getChar();
        }
        while(isNumber(c));
    }
    else if(isIdtentifier(c))
    {
        do
        {
            sb.append(1,(char)c);
            c = getChar();
        }
        while(isIdtentifier(c)||isNumber(c));
    }
    else if(c == '=')
    {
        c = getChar();
        if(c == '=')
            return "==";
        else
        {
            ungetChar(c);
            return "=";
        }
    }

    if(c>0)
        ungetChar(c);

    qDebug() << QString::fromStdString(sb);
    return  sb;

}

string FSM_Lexer::read2()
{
    string sb;
    while(1){
        sb ="";
        int c;
        do
        {
            c = getChar();
        }

        while(isSpace(c));

        if(c<0)
        {
            qDebug() << c;
            sb.clear();
            _token = new IdToken(_lineNumber,EndLine);
            _tokenQueue.push_back(_token);
            //            return sb;
            break;
        }

        if(isNumber(c))
        {
            while(isNumber(c))
            {
                sb.append(1,(char)c);
                c = getChar();
            }

            _token = new NumToken(_lineNumber,sb);
            _tokenQueue.push_back(_token);
        }

        else if(isIdtentifier(c))
        {
            while(isIdtentifier(c))
            {
                sb.append(1,(char)c);
                c = getChar();
            }
            _token = new IdToken(_lineNumber,sb);
            _tokenQueue.push_back(_token);
        }

        else if(isOperator(c))
        {
            while(isOperator(c))
            {
                switch (c)
                {
                case '=':
                    c = getChar();
                    if(c == '=')
                    {
                        _token = new IdToken(_lineNumber,"==");
                        _tokenQueue.push_back(_token);
                        //                    return "==";
                    }
                    else
                    {
                        ungetChar(c);
                        _token = new IdToken(_lineNumber,"=");
                        _tokenQueue.push_back(_token);
                        //                    return "=";
                    }
                    break;
                case '+':
                    _token = new IdToken(_lineNumber,"+");
                    _tokenQueue.push_back(_token);
                    c = getChar();

                    break;
                case '-':
                    _token = new IdToken(_lineNumber,"-");
                    _tokenQueue.push_back(_token);
                    c = getChar();
                    break;
                case '*':
                    _token = new IdToken(_lineNumber,"*");
                    _tokenQueue.push_back(_token);
                    c = getChar();
                    break;
                case '/':
                    _token = new IdToken(_lineNumber,"/");
                    _tokenQueue.push_back(_token);
                    c = getChar();
                    break;
                default:
                    break;
                }


            }
        }

        if(c>0)
            ungetChar(c);


        qDebug() << QString::fromStdString(sb);
        //        return  sb;
    }
    return sb;

}

Token *FSM_Lexer::readToken()
{

    while(0 >= _tokenQueue.size())
    {
        string str;
        getline(_inputFile,str);
        if(str.empty())
        {
            break;
        }
        _itChar = str.begin();
        _itCharEnd = str.end();
        read2();
    }

    Token* token = nullptr;
    _token = nullptr;

    if(_tokenQueue.size() >0)
    {

        token = _tokenQueue.front();

        _tokenQueue.pop_front();
    }

    return token;
}
