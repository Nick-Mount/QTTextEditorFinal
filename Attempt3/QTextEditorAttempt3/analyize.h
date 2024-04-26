// Analyize.h
#ifndef ANALYIZE_H
#define ANALYIZE_H

#include <QDialog>
#include <QtCharts>

class Analyize : public QDialog
{
    Q_OBJECT

public:
    explicit Analyize(const QString &text, QWidget *parent = nullptr);

private:
    QChart *chart;
    QChartView *chartView;
    void createChart(const QString &text);
};

#endif // ANALYIZE_H
