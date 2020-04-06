#ifndef GRIDCELLLABEL_H
#define GRIDCELLLABEL_H

#include <QWidget>

class GridCellLabel : public QWidget
{
    Q_OBJECT
public:
    explicit GridCellLabel(bool black, QWidget *parent = nullptr);
    void setCount(int count);

protected:
    void paintEvent(QPaintEvent * e);

private:
    bool _black;
    int _count = 0;

signals:

};

#endif // GRIDCELLLABEL_H
