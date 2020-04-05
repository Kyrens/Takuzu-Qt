#ifndef GRIDCELLWIDGET_H
#define GRIDCELLWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPaintEvent>

class GridCellWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GridCellWidget(QWidget* cellWidget, QWidget *parent = nullptr);
    ~GridCellWidget();
    QFrame * backGround;
    QWidget * cellWidget;

protected:
    void paintEvent(QPaintEvent * e);

signals:

};

#endif // GRIDCELLWIDGET_H
