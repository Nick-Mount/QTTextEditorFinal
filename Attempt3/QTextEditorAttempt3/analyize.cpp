#include "analyize.h"
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

Analyize::Analyize(const QString &text, QWidget *parent) : QDialog(parent) {
    setWindowTitle("Letter Frequency Analysis");
    createChart(text);
    QChartView *chartView = new QChartView(chart, this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);
    resize(720, 720);
}

void Analyize::createChart(const QString &text) {
    QMap<QChar, int> freqMap;
    for (QChar ch : text.toLower()) {
        if (ch.isLetter()) {
            freqMap[ch]++;
        }
    }

    QBarSet *set = new QBarSet("Letters");
    QStringList categories;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        categories << QString(ch);
        *set << freqMap[ch];
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Letter Frequency");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, *std::max_element(freqMap.begin(), freqMap.end()));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}
