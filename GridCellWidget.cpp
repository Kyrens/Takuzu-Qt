#include "GridCellWidget.h"

GridCellWidget::GridCellWidget(QWidget* cellWidget, QWidget *parent) : QWidget(parent)
{
    this->cellWidget = cellWidget;
    backGround = new QFrame();
}

GridCellWidget::~GridCellWidget() {
    delete backGround;
}
