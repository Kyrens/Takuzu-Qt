#ifndef MAINMENUPRESENTER_H
#define MAINMENUPRESENTER_H

#include <QObject>

class MainMenuPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainMenuPresenter(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MAINMENUPRESENTER_H