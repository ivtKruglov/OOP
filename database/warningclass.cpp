#include "warningclass.h"

WarningClass::WarningClass()
{
    msgWindow = new QMessageBox();
    buttons.append(msgWindow->addButton("Да", QMessageBox::ActionRole));
    buttons.append(msgWindow->addButton("Нет", QMessageBox::ActionRole));
}

void WarningClass::run()
{
    msgWindow->exec();
}

void WarningClass::setText(const QString &text)
{
    msgWindow->setInformativeText(text);
}

QVector<QPushButton *> WarningClass::getButtons()
{
    return buttons;
}

QAbstractButton* WarningClass::getClickedButton()
{
    return msgWindow->clickedButton();
}

void WarningClass::removeButton(QAbstractButton *button)
{
    msgWindow->removeButton(button);
}

void WarningClass::addButton(QAbstractButton *button)
{
     msgWindow->addButton(button, QMessageBox::ActionRole);
}
