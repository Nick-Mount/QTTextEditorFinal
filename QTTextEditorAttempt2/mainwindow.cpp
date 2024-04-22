#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    openButton = new QPushButton("Open", this);
    saveButton = new QPushButton("Save", this);
    boldButton = new QPushButton("Bold", this);
    italicButton = new QPushButton("Italic", this);
    underlineButton = new QPushButton("Underline", this);
    textEdit = new QTextEdit(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(openButton);
    layout->addWidget(saveButton);
    layout->addWidget(boldButton);
    layout->addWidget(italicButton);
    layout->addWidget(underlineButton);
    layout->addWidget(textEdit);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(openButton, &QPushButton::clicked, this, &MainWindow::openFile);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveFile);
    connect(boldButton, &QPushButton::clicked, this, &MainWindow::boldText);
    connect(italicButton, &QPushButton::clicked, this, &MainWindow::itallicsText);
    connect(underlineButton, &QPushButton::clicked, this, &MainWindow::underlineText);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    textEdit->setText(text);
    file.close();
}

void MainWindow::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    QTextStream out(&file);
    out << textEdit->toHtml();
    file.flush();
    file.close();
}

void MainWindow::boldText() {
    QTextCharFormat format;
    format.setFontWeight(textEdit->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::itallicsText() {
    QTextCharFormat format;
    format.setFontItalic(!textEdit->fontItalic());
    textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::underlineText() {
    QTextCharFormat format;
    format.setFontUnderline(!textEdit->fontUnderline());
    textEdit->mergeCurrentCharFormat(format);
}
