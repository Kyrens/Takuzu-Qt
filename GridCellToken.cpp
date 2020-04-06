#include "GridCellToken.h"
#include <QPainter>
#include <QStackedLayout>
#include <QPoint>
#include <QPen>

GridCellToken::GridCellToken(QPushButton * button, QWidget *parent) : QWidget(parent) {
    this->button = button;
    button->setParent(this);
    this->setFixedWidth(50);
    this->setFixedHeight(50);
    QStackedLayout* layout = new QStackedLayout(this);
    layout->addWidget(button);
}

void GridCellToken::paintEvent(QPaintEvent * e) {
    if (_error) {
        QPainter painter(this);
        painter.setPen(QPen(Qt::red, 2));
        painter.drawEllipse(QPoint(25, 25), 22, 22);
    }
}

void GridCellToken::setError(bool error) {
    _error = error;
}

bool GridCellToken::hasError() {
    return _error;
}
