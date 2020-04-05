#ifndef GRIDCELLLABEL_H
#define GRIDCELLLABEL_H

#include <QWidget>
#include <QLabel>

class GridCellLabel : public QWidget
{
    Q_OBJECT
public:
    explicit GridCellLabel(QLabel * label, bool black, QWidget *parent = nullptr);
    QLabel * label;

protected:
    void paintEvent(QPaintEvent * e);

private:
    bool _black;

signals:

};

#endif // GRIDCELLLABEL_H
