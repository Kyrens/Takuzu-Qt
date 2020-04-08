#ifndef GRIDCELLTOKEN_H
#define GRIDCELLTOKEN_H

#include <QWidget>
#include <QPushButton>

enum TokenStyle { CIRCLE, SQUARE };

class GridCellToken : public QWidget
{
    Q_OBJECT
public:
    explicit GridCellToken(QWidget *parent = nullptr);
    QPushButton * button;
    void setError(bool error);
    bool hasError();
    void initToken();
    void setStyle(TokenStyle style);
    void refreshToken(char c);

protected:
    void paintEvent(QPaintEvent * e);

private:
    bool _error = false;
    TokenStyle _style = CIRCLE;

signals:

};

#endif // GRIDCELLTOKEN_H
