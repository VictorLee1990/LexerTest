#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{  
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_openFile_triggered()
{
    QString InputImgFile = QFileDialog::getOpenFileName(this,
                                                        "Select one files to open",
                                                        "/",
                                                        "txt (*.txt)");

    ui->srcText_listWidget->clear();
    ui->LexingText_listWidget->clear();
    _line.clear();
    _file = InputImgFile.toStdString();
    _inputFile.open(_file);
    _lexer = new Lexer(_file);
    _fsmLexer = new FSM_Lexer(_file);
//    _exprParser = new ExprParser(_lexer);
    _exprParser = new ExprParser(_file);
    string line;
    while(getline(_inputFile,line))
    {
        _line.push_back(line);
        qDebug() << QString::fromStdString(line);
        ui->srcText_listWidget->addItem(QString::fromStdString(line));
    }

    _inputFile.close();

}

void MainWindow::on_Reg_Btn_clicked()
{
    Token* token;
    QString lexingText;
    QString NumberLexing;
    QString IdentifierLexing;
    NumberLexing = "Number:";
    IdentifierLexing = "Identifier:";
    int lineNumber = 0;
    while((token = _lexer->read()) != nullptr)
    {

        if( token->isNumber())
        {
            lexingText += lexingText.fromStdString(token->getText());
            NumberLexing += "\r\n" + NumberLexing.fromStdString(token->getText());
        }
        else if(token->isIdentifier())
        {
            if(token->getText() == "\r\n")
            {
                ui->LexingText_listWidget->addItem("\r\n" + QString::fromStdString(_line[lineNumber]));
                qDebug() << "\r\n" + QString::fromStdString(_line[lineNumber]);
                ui->LexingText_listWidget->addItem(NumberLexing);
                ui->LexingText_listWidget->addItem(IdentifierLexing);
                NumberLexing = "Number:";
                IdentifierLexing = "Identifier:";
                if(lineNumber < _line.size()-1)
                    lineNumber++;
            }
            else
            {
//                qDebug() << "IdentifierLexing1:" << IdentifierLexing;
                lexingText += lexingText.fromStdString(token->getText());
                IdentifierLexing += "\r\n" + IdentifierLexing.fromStdString(token->getText());
//                qDebug() << "IdentifierLexing:" << IdentifierLexing;
                //            ui->LexingText_listWidget->addItem(lexingText);
            }
        }


    }
    //    ui->LexingText_listWidget->addItem(lexingText);
}

void MainWindow::on_FSM_Btn_clicked()
{
//    for(string s;!(s = _fsmLexer->read2()).empty();)
//    {
//        qDebug() << QString::fromStdString(s);
//        ui->LexingText_listWidget->addItem(QString::fromStdString(s));
//    }

    Token* token;
    QString lexingText;
    QString NumberLexing;
    QString IdentifierLexing;
    NumberLexing = "Number:";
    IdentifierLexing = "Identifier:";
    int lineNumber = 0;
    while((token = _fsmLexer->readToken()) != nullptr)
    {

        if( token->isNumber())
        {
            lexingText += lexingText.fromStdString(token->getText());
            NumberLexing += "\r\n" + NumberLexing.fromStdString(token->getText());
        }
        else if(token->isIdentifier())
        {
            if(token->getText() == "\r\n")
            {
                ui->LexingText_listWidget->addItem("\r\n" + QString::fromStdString(_line[lineNumber]));
                qDebug() << "\r\n" + QString::fromStdString(_line[lineNumber]);
                ui->LexingText_listWidget->addItem(NumberLexing);
                ui->LexingText_listWidget->addItem(IdentifierLexing);
                NumberLexing = "Number:";
                IdentifierLexing = "Identifier:";
                if(lineNumber < _line.size()-1)
                    lineNumber++;
            }
            else
            {
//                qDebug() << "IdentifierLexing1:" << IdentifierLexing;
                lexingText += lexingText.fromStdString(token->getText());
                IdentifierLexing += "\r\n" + IdentifierLexing.fromStdString(token->getText());
//                qDebug() << "IdentifierLexing:" << IdentifierLexing;
                //            ui->LexingText_listWidget->addItem(lexingText);
            }
        }


    }
    //    ui->LexingText_listWidget->addItem(lexingText);
}

void MainWindow::on_pushButton_clicked()
{
//   Token* aaa = _lexer->read();
    AbstractSyntaxTree* t = _exprParser->expression();
    qDebug() << QString::fromStdString(t->toString());
}
