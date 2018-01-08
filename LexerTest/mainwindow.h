#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "fsm_lexer.h"
#include <string>
#include <iostream>
#include <QFileDialog>
#include <sstream>
#include "exprparser.h"
#include "abstractsyntaxtree.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_openFile_triggered();

    void on_Reg_Btn_clicked();

    void on_FSM_Btn_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Lexer *_lexer;
    FSM_Lexer *_fsmLexer;
    string _file;
    fstream _inputFile;

    vector<string> _line;

    ExprParser* _exprParser;
};

#endif // MAINWINDOW_H
