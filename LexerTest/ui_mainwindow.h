/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_openFile;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Reg_Btn;
    QListWidget *srcText_listWidget;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *FSM_Btn;
    QLabel *label;
    QLabel *label_2;
    QListWidget *LexingText_listWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(611, 533);
        action_openFile = new QAction(MainWindow);
        action_openFile->setObjectName(QStringLiteral("action_openFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 591, 461));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Reg_Btn = new QPushButton(layoutWidget);
        Reg_Btn->setObjectName(QStringLiteral("Reg_Btn"));
        Reg_Btn->setEnabled(true);

        gridLayout->addWidget(Reg_Btn, 2, 2, 1, 1);

        srcText_listWidget = new QListWidget(layoutWidget);
        srcText_listWidget->setObjectName(QStringLiteral("srcText_listWidget"));

        gridLayout->addWidget(srcText_listWidget, 0, 0, 10, 1);

        verticalSpacer_2 = new QSpacerItem(72, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 9, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(68, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(72, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 8, 2, 1, 1);

        FSM_Btn = new QPushButton(layoutWidget);
        FSM_Btn->setObjectName(QStringLiteral("FSM_Btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FSM_Btn->sizePolicy().hasHeightForWidth());
        FSM_Btn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(FSM_Btn, 4, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 7, 2, 1, 1);

        LexingText_listWidget = new QListWidget(layoutWidget);
        LexingText_listWidget->setObjectName(QStringLiteral("LexingText_listWidget"));
        LexingText_listWidget->setAutoScrollMargin(40);

        gridLayout->addWidget(LexingText_listWidget, 0, 3, 10, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 611, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_openFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_openFile->setText(QApplication::translate("MainWindow", "\351\226\213\345\225\237\346\252\224\346\241\210", nullptr));
        Reg_Btn->setText(QApplication::translate("MainWindow", "Regular Expression", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "ExprParser", nullptr));
        FSM_Btn->setText(QApplication::translate("MainWindow", "FSM", nullptr));
        label->setText(QApplication::translate("MainWindow", "Lexing", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "syntax tree", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\252\224\346\241\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
