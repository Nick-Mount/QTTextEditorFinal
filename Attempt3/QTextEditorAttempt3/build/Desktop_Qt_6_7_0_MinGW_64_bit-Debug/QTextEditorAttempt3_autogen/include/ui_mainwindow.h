/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionBold;
    QAction *actionUnderline;
    QAction *actionItallic;
    QAction *actionStrike;
    QAction *actionColor;
    QAction *actionFont;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFIle;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuText;
    QStatusBar *statusbar;
    QToolBar *itemBar;
    QToolBar *editBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName("actionSave_As");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName("actionReplace");
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName("actionZoom_In");
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName("actionZoom_Out");
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName("actionBold");
        actionUnderline = new QAction(MainWindow);
        actionUnderline->setObjectName("actionUnderline");
        actionItallic = new QAction(MainWindow);
        actionItallic->setObjectName("actionItallic");
        actionStrike = new QAction(MainWindow);
        actionStrike->setObjectName("actionStrike");
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName("actionColor");
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName("actionFont");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(13, 9, 771, 531));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFIle = new QMenu(menubar);
        menuFIle->setObjectName("menuFIle");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuText = new QMenu(menubar);
        menuText->setObjectName("menuText");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        itemBar = new QToolBar(MainWindow);
        itemBar->setObjectName("itemBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, itemBar);
        editBar = new QToolBar(MainWindow);
        editBar->setObjectName("editBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, editBar);

        menubar->addAction(menuFIle->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuText->menuAction());
        menuFIle->addAction(actionNew);
        menuFIle->addAction(actionOpen);
        menuFIle->addSeparator();
        menuFIle->addAction(actionSave);
        menuFIle->addAction(actionSave_As);
        menuFIle->addSeparator();
        menuFIle->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionReplace);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);
        menuText->addAction(actionBold);
        menuText->addAction(actionUnderline);
        menuText->addAction(actionItallic);
        menuText->addAction(actionStrike);
        menuText->addSeparator();
        menuText->addAction(actionColor);
        menuText->addAction(actionFont);
        itemBar->addAction(actionNew);
        itemBar->addAction(actionOpen);
        itemBar->addAction(actionSave);
        itemBar->addAction(actionSave_As);
        itemBar->addSeparator();
        itemBar->addAction(actionCopy);
        itemBar->addAction(actionCut);
        itemBar->addAction(actionPaste);
        itemBar->addSeparator();
        itemBar->addAction(actionFind);
        itemBar->addAction(actionReplace);
        itemBar->addSeparator();
        itemBar->addAction(actionZoom_In);
        itemBar->addAction(actionZoom_Out);
        editBar->addAction(actionBold);
        editBar->addAction(actionUnderline);
        editBar->addAction(actionItallic);
        editBar->addAction(actionStrike);
        editBar->addSeparator();
        editBar->addAction(actionColor);
        editBar->addAction(actionFont);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        actionReplace->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
        actionZoom_In->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
        actionZoom_Out->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
        actionBold->setText(QCoreApplication::translate("MainWindow", "Bold", nullptr));
        actionUnderline->setText(QCoreApplication::translate("MainWindow", "Underline", nullptr));
        actionItallic->setText(QCoreApplication::translate("MainWindow", "Itallic", nullptr));
        actionStrike->setText(QCoreApplication::translate("MainWindow", "Strike", nullptr));
        actionColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        actionFont->setText(QCoreApplication::translate("MainWindow", "Font", nullptr));
        menuFIle->setTitle(QCoreApplication::translate("MainWindow", "FIle", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuText->setTitle(QCoreApplication::translate("MainWindow", "Text", nullptr));
        itemBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        editBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
