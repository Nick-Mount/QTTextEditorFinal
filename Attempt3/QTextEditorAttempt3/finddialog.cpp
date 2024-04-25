#include "finddialog.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMessageBox>


findDialog::findDialog(QWidget *parent, QTextEdit *text) :QDialog(parent){
    QLabel *findLabel = new QLabel("What do you want to find");
    lineEdit = new QLineEdit;

    findButton = new QPushButton("&Find");
    findText = "";

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(findLabel);
    layout->addWidget(lineEdit);
    layout->addWidget(findButton);
    textEdit = text;

    setLayout(layout);
    setWindowTitle("Find a Word");
    connect(findButton, &QPushButton::clicked, this, &findDialog::findClicked);
    //connect(findButton, &QPushButton::clicked, this, &findDialog::accept);

    delete findLabel;
}

void findDialog::findClicked(){
    QString text = lineEdit->text();
    findText = text;
    if(!textEdit->find(this->getFindText())){
        QMessageBox::information(nullptr, "Error", "This string does not appear in this document any more times");
    }
    textEdit->repaint();
    textEdit->setFocus();

    //lineEdit->clear();
    //hide();
}
QString findDialog::getFindText(){

    return findText;
}
