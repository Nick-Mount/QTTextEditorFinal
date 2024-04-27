#ifndef ANALYZE2_H
#define ANALYZE2_H

#include <QObject>
#include "analyize.h"

class analyze2 : public Analyize
{
    Q_OBJECT
public:
    analyze2(const QString &text, QWidget *parent = nullptr);
    void createChart(const QString &text = "");
    void displayChart();
private:
    QChart *chart2;

};

#endif // ANALYZE2_H
