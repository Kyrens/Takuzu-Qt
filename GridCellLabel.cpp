#include "GridCellLabel.h"
#include <QPainter>
#include <QStackedLayout>
#include <QRect>

GridCellLabel::GridCellLabel(QLabel * label, bool black, QWidget *parent) : QWidget(parent) {
    this->label = label;
    this->setFixedWidth(50);
    this->setFixedHeight(50);
    _black = black;
}

void GridCellLabel::paintEvent(QPaintEvent * e) {
    QPainter painter(this);
    if (_black) {
        painter.fillRect(QRect(0, 0, 50, 50), QBrush(QColor(0, 0, 0)));
        painter.setPen(Qt::white);
    }
    else {
        painter.fillRect(QRect(0, 0, 50, 50), QBrush(QColor(255, 255, 255)));
        painter.setPen(Qt::black);
    }
    painter.drawText(0, 2, 50, 50, Qt::AlignHCenter | Qt::AlignVCenter, label->text());
}
