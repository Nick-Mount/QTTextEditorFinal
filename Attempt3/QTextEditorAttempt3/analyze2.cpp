#include "analyze2.h"
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

analyze2::analyze2(const QString &text, QWidget *parent) :Analyize(text,parent) {
    createChart(text);

}
void analyze2::createChart(const QString &text){
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

    chart2 = new QChart();
    chart2->addSeries(series);
    chart2->setTitle("AsecondChart");
    chart2->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart2->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, *std::max_element(freqMap.begin(), freqMap.end()));
    chart2->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}
void analyze2::displayChart(){
    QChartView *chartView = new QChartView(chart2, this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);
    resize(720, 720);
}
