#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include<QDialog>
#include<QLabel>

class QLineEdit;
class QPushButton;


class findDialog : public QDialog
{
    Q_OBJECT
public:
    findDialog(QWidget *parent = nullptr);
    QString getFindText();
    //~findDialog();
public slots:
   // void findClicked();
private:
    QPushButton *findButton;
    QLineEdit *lineEdit;
    QString findText;
};

#endif // FINDDIALOG_H
