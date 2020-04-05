#include "GridCellWidget.h"
#include <iostream>
#include <QPainter>
#include <QStackedLayout>
#include <QRect>
#include <QLabel>

GridCellWidget::GridCellWidget(QWidget* cellWidget, QWidget *parent) : QWidget(parent)
{
    this->cellWidget = cellWidget;
    this->setFixedWidth(cellWidget->geometry().width());
    this->setFixedHeight(cellWidget->geometry().height());
    if (!dynamic_cast<QLabel*>(cellWidget)) {
        QStackedLayout* layout = new QStackedLayout(this);
        layout->addWidget(cellWidget);
    }
}

GridCellWidget::~GridCellWidget() {
    delete cellWidget;
}

void GridCellWidget::paintEvent(QPaintEvent * e) {
    QPainter painter(this);
    if (QLabel * label = dynamic_cast<QLabel*>(cellWidget)) {
        painter.fillRect(QRect(0, 2, 50, 50), QBrush(QColor(255, 0, 0)));
        painter.drawText(0, 2, 50, 50, Qt::AlignHCenter | Qt::AlignVCenter, label->text());
    }
    else {
        painter.fillRect(QRect(0, 0, 50, 50), QBrush(QColor(255, 0, 0)));
    }
}
