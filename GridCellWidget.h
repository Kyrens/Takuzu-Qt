#ifndef GRIDCELLWIDGET_H
#define GRIDCELLWIDGET_H

#include <QWidget>
#include <QFrame>

class GridCellWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GridCellWidget(QWidget* cellWidget, QWidget *parent = nullptr);
    ~GridCellWidget();
    QFrame * backGround;
    QWidget * cellWidget;

signals:

};

#endif // GRIDCELLWIDGET_H
