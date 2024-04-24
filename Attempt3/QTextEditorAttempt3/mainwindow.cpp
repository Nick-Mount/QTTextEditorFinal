#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionNew_triggered()
{

}


void MainWindow::on_actionOpen_triggered()
{
    this->fileName = QFileDialog::getOpenFileName(this, "Open the file", "", "Text Files (*.txt *.rtf);; All Files (*)");
    QFile file(this->fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setPlainText(text);
    file.close();
}


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save the file", "", "Text Files (*.txt *.rtf);; All Files (*)");
    QFile file(fileName);
    QTextStream out(&file);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    out << ui->textEdit->toPlainText();
    file.close();
}

