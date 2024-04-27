// Analyize.h
#ifndef ANALYIZE_H
#define ANALYIZE_H

#include <QDialog>
#include <QtCharts>

class Analyize : public QDialog
{
    Q_OBJECT

public:
    Analyize(const QString &text, QWidget *parent = nullptr);
    QMap<QChar, int> getMap();
    void displayChart();
    QString getText();

private:
    QChart *chart;
    QChartView *chartView;
    QMap<QChar, int> freqMap;
    void createChart(const QString &text);

};

#endif // ANALYIZE_H
