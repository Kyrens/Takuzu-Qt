#include "GridCellToken.h"
#include <QPainter>
#include <QStackedLayout>
#include <QRect>

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
        painter.fillRect(QRect(0, 0, 50, 50), QBrush(QColor(255, 0, 0)));
    }
}

void GridCellToken::setError(bool error) {
    _error = error;
}
