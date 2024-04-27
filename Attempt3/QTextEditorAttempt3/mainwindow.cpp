#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDialog>
#include "analyze2.h"

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QMap>
#include <QRegularExpression>

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
    this->fileName = QFileDialog::getOpenFileName(this, "Open the file", "", "HTML (*.html);; Markdown (*.md);; Text Files (*.txt *.rtf);; All Files (*)");
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
    this->fileName = QFileDialog::getSaveFileName(this, "Save the file", "", "HTML (*.html);; Markdown (*.md);; Text Files (*.txt *.rtf);; All Files (*)");
    QFile file(this->fileName);
    QTextStream out(&file);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    out << ui->textEdit->toHtml();
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    if(this->fileName == ""){
        this->fileName = QFileDialog::getSaveFileName(this, "Save the file", "", "HTML (*.html);; Markdown (*.md);; Text Files (*.txt *.rtf);; All Files (*)");

    }
    QFile file(this->fileName);
    QTextStream out(&file);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    out << ui->textEdit->toHtml();
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


void MainWindow::on_actionUnderline_triggered()
{
    QTextCharFormat format;
    format.setFontUnderline(!ui->textEdit->fontUnderline());
    ui->textEdit->mergeCurrentCharFormat(format);
}



void MainWindow::on_actionItallic_triggered()
{
    QTextCharFormat format;
    format.setFontItalic(!ui->textEdit->fontItalic());
    ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionStrike_triggered()
{
    QTextCharFormat format;
    format.setFontStrikeOut(!ui->textEdit->currentCharFormat().fontStrikeOut());
    ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionAnalysis_triggered()
{
    QString text = ui->textEdit->toPlainText();
    Analyize *analysis = new Analyize(text, this);
    analysis->displayChart();
    analysis->exec();

}



void MainWindow::on_actionAnalysis_2_triggered()
{
    QString text = ui->textEdit->toPlainText();
    analyze2 *analysis = new analyze2(text, this);
    analysis->displayChart();
    analysis->exec();
    delete analysis;
}

