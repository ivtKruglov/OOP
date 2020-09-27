#ifndef WARNINGCLASS_H
#define WARNINGCLASS_H
#include <QMessageBox>

class WarningClass
{
private:
    QMessageBox *msgWindow;
    QVector<QPushButton *> buttons;

public:
    WarningClass();
    void run();
    void setText(const QString &text);
    QVector<QPushButton *> getButtons();
    QAbstractButton *getClickedButton();
    void removeButton(QAbstractButton *button);
    void addButton(QAbstractButton *button);
};

#endif // WARNINGCLASS_H
