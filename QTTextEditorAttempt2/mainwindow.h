#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void openFile();
    void saveFile();
    void boldText();
    void itallicsText();
    void underlineText();

private:
    Ui::MainWindow *ui;
    QPushButton *openButton;
    QPushButton *saveButton;
    QPushButton *boldButton;
    QPushButton *italicButton;
    QPushButton *underlineButton;
    QTextEdit *textEdit;

};
#endif // MAINWINDOW_H
