#include "finddialog.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>


findDialog::findDialog(QWidget *parent) :QDialog(parent){
    QLabel *findLabel = new QLabel("What do you want to find");
    lineEdit = new QLineEdit;

    findButton = new QPushButton("&Find");
    findText = "";

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(findLabel);
    layout->addWidget(lineEdit);
    layout->addWidget(findButton);

    setLayout(layout);
    setWindowTitle("Find a Word");
   // connect(findButton, &QPushButton::clicked, this, &findDialog::findClicked);
    //connect(findButton, &QPushButton::clicked, this, &findDialog::accept);

    delete findLabel;
}

