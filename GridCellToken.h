#ifndef GRIDCELLTOKEN_H
#define GRIDCELLTOKEN_H

#include <QWidget>
#include <QPushButton>

class GridCellToken : public QWidget
{
    Q_OBJECT
public:
    explicit GridCellToken(QPushButton * button, QWidget *parent = nullptr);
    QPushButton * button;
    void setError(bool error);

protected:
    void paintEvent(QPaintEvent * e);

private:
    bool _error = false;

signals:

};

#endif // GRIDCELLTOKEN_H
