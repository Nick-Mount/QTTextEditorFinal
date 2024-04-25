#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDialog>

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
    ui->textEdit->setText("");
    this->fileName = "";
}


void MainWindow::on_actionOpen_triggered()
{
    this->fileName = QFileDialog::getOpenFileName(this, "Open the file", "", "Text Files (*.txt *.rtf);; All Files (*)");
    QFile file(this->fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_As_triggered()
{
    this->fileName = QFileDialog::getSaveFileName(this, "Save the file", "", "Text Files (*.txt *.rtf);; All Files (*)");
    QFile file(this->fileName);
    QTextStream out(&file);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    out << ui->textEdit->toMarkdown();
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    if(this->fileName == ""){
        this->fileName = QFileDialog::getSaveFileName(this, "Save the file", "", "Text Files (*.txt *.rtf);; All Files (*)");

    }
    QFile file(this->fileName);
    QTextStream out(&file);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    out << ui->textEdit->toMarkdown();
    file.close();
}


void MainWindow::on_actionFind_triggered()
{
    ui->textEdit->moveCursor(QTextCursor::Start);
    findDialog *dialog = new findDialog(this, ui->textEdit);
    dialog->show();




}

void MainWindow::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn(1);
}


void MainWindow::on_actionZoom_Out_triggered()
{
    ui->textEdit->zoomOut(1);
}


void MainWindow::on_actionBold_triggered()
{
    QTextCharFormat format;
    format.setFontWeight(ui->textEdit->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    ui->textEdit->mergeCurrentCharFormat(format);
}

