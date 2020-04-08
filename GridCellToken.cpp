#include "GridCellToken.h"
#include <QPainter>
#include <QStackedLayout>
#include <QPoint>
#include <QPen>

GridCellToken::GridCellToken(QWidget *parent) : QWidget(parent) {
    button = new QPushButton;
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

void GridCellToken::initToken() {
    button->setFixedHeight(50);
    button->setFixedWidth(50);
    QRect rect(5,5,40,40);
    QRegion region(rect, QRegion::Ellipse);
    button->setMask(region);

    QPalette pal = button->palette();
    pal.setColor(QPalette::Button, QColor(Qt::gray));
    button->setAutoFillBackground(true);
    button->setPalette(pal);
}

void GridCellToken::refreshToken(char c) {

    QPalette pal = button->palette();

    switch (c) {
    case '.':
        pal.setColor(QPalette::Button, QColor(Qt::gray));
        break;
    case 'W':
        pal.setColor(QPalette::Button, QColor(Qt::white));
        break;
    case 'B':
        pal.setColor(QPalette::Button, QColor(Qt::black));
        break;
    default:
        break;
    }

    button->setAutoFillBackground(true);
    button->setPalette(pal);
    update();
}

void GridCellToken::setError(bool error) {
    _error = error;
}

bool GridCellToken::hasError() {
    return _error;
}
