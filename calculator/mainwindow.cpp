#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    action = "";
    temp = "";
    flag_double = true;
    flag_action = false;
    flag_result = false;
    first_num = true;
    num.SetValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"1");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"2");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"3");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"4");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"5");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"6");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"7");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"8");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"9");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+"0");
    flag_action = true;
    flag_result = false;
}

void MainWindow::on_pushButton_22_clicked() // del
{
    ui->textEdit->setText(ui->textEdit->toPlainText().remove(ui->textEdit->toPlainText().length()-1, 1));
}

void MainWindow::on_pushButton_23_clicked() // C
{
    ui->textEdit->setText("");
    ui->label->setText("");
    flag_double = true;
    flag_action = false;
    first_num = true;
    action = "";
    num.SetValue(0);

}

void MainWindow::on_pushButton_11_clicked() // .
{
    if (flag_double && ui->textEdit->toPlainText().length() > 0)
    {
        ui->textEdit->setText(ui->textEdit->toPlainText()+".");
        flag_double = false;
    }
}

void MainWindow::on_pushButton_20_clicked() // +
{
    if (flag_action)
    {
        if (first_num)
        {
            num.SetValue(ui->textEdit->toPlainText().toDouble());
            first_num = false;
        }
        else
        {
            if (action == "+")
            {
                num += ui->textEdit->toPlainText().toDouble();
            }
            if (action == "-")
            {
                num -= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "*")
            {
                num *= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "/")
            {
                num /= ui->textEdit->toPlainText().toDouble();
            }
        }
        if (!flag_result)
        {
            if (ui->textEdit->toPlainText().mid(0, 1) == "-")
                temp = "("+ui->textEdit->toPlainText()+")";
            else
                temp = ui->textEdit->toPlainText();
            ui->label->setText(ui->label->text()+temp+"+");
        }
        else
            ui->label->setText(ui->textEdit->toPlainText()+"+");
        ui->textEdit->setText("");
        flag_action = false;
        action = "+";
        flag_double = true;
        flag_result = true;
    }
    else
    {
        if (ui->label->text().length() > 0)
        {
            ui->label->setText(ui->label->text().remove(ui->label->text().length()-1, 1));
            ui->label->setText(ui->label->text()+ui->textEdit->toPlainText()+"+");
            action = "+";
        }
    }
}

void MainWindow::on_pushButton_21_clicked() // -
{
    if (flag_action)
    {
        if (first_num)
        {
            num.SetValue(ui->textEdit->toPlainText().toDouble());
            first_num = false;
        }
        else
        {
            if (action == "+")
            {
                num += ui->textEdit->toPlainText().toDouble();
            }
            if (action == "-")
            {
                num -= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "*")
            {
                num *= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "/")
            {
                num /= ui->textEdit->toPlainText().toDouble();
            }
        }
        if (!flag_result)
        {
            if (ui->textEdit->toPlainText().mid(0, 1) == "-")
                temp = "("+ui->textEdit->toPlainText()+")";
            else
                temp = ui->textEdit->toPlainText();
            ui->label->setText(ui->label->text()+temp+"-");
        }
        else
            ui->label->setText(ui->textEdit->toPlainText()+"-");
        ui->textEdit->setText("");
        flag_action = false;
        action = "-";
        flag_double = true;
        flag_result = true;
    }
    else
    {
        if (ui->label->text().length() > 0)
        {
            ui->label->setText(ui->label->text().remove(ui->label->text().length()-1, 1));
            ui->label->setText(ui->label->text()+ui->textEdit->toPlainText()+"-");
            action = "-";
        }
    }
}

void MainWindow::on_pushButton_14_clicked() // *
{
    if (flag_action)
    {
        if (first_num)
        {
            num.SetValue(ui->textEdit->toPlainText().toDouble());
            first_num = false;
        }
        else
        {
            if (action == "+")
            {
                num += ui->textEdit->toPlainText().toDouble();
            }
            if (action == "-")
            {
                num -= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "*")
            {
                num *= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "/")
            {
                num /= ui->textEdit->toPlainText().toDouble();
            }
        }
        if (!flag_result)
        {
            if (ui->textEdit->toPlainText().mid(0, 1) == "-")
                temp = "("+ui->textEdit->toPlainText()+")";
            else
                temp = ui->textEdit->toPlainText();
            ui->label->setText(ui->label->text()+temp+"*");
        }
        else
            ui->label->setText(ui->textEdit->toPlainText()+"*");
        ui->textEdit->setText("");
        flag_action = false;
        action = "*";
        flag_double = true;
        flag_result = true;
    }
    else
    {
        if (ui->label->text().length() > 0)
        {
            ui->label->setText(ui->label->text().remove(ui->label->text().length()-1, 1));
            ui->label->setText(ui->label->text()+ui->textEdit->toPlainText()+"*");
            action = "*";
        }
    }
}

void MainWindow::on_pushButton_15_clicked() // /
{
    if (flag_action)
    {
        if (first_num)
        {
            num.SetValue(ui->textEdit->toPlainText().toDouble());
            first_num = false;
        }
        else
        {
            if (action == "+")
            {
                num += ui->textEdit->toPlainText().toDouble();
            }
            if (action == "-")
            {
                num -= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "*")
            {
                num *= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "/")
            {
                num /= ui->textEdit->toPlainText().toDouble();
            }
        }
        if (!flag_result)
        {
            if (ui->textEdit->toPlainText().mid(0, 1) == "-")
                temp = "("+ui->textEdit->toPlainText()+")";
            else
                temp = ui->textEdit->toPlainText();
            ui->label->setText(ui->label->text()+temp+"/");
        }
        else
            ui->label->setText(ui->textEdit->toPlainText()+"/");
        ui->textEdit->setText("");
        flag_action = false;
        action = "/";
        flag_double = true;
        flag_result = true;
    }
    else
    {
        if (ui->label->text().length() > 0)
        {
            ui->label->setText(ui->label->text().remove(ui->label->text().length()-1, 1));
            ui->label->setText(ui->label->text()+ui->textEdit->toPlainText()+"/");
            action = "/";
        }
    }
}

void MainWindow::on_pushButton_13_clicked() // =
{
    if (!flag_result)
    {
        if (action != "")
        {
            if (action == "+")
            {
                num += ui->textEdit->toPlainText().toDouble();
            }
            if (action == "-")
            {
                num -= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "*")
            {
                num *= ui->textEdit->toPlainText().toDouble();
            }
            if (action == "/")
            {
                num /= ui->textEdit->toPlainText().toDouble();
            }
        }
        if (ui->textEdit->toPlainText().mid(0, 1) == "-")
            temp = "("+ui->textEdit->toPlainText()+")";
        else
            temp = ui->textEdit->toPlainText();
        ui->label->setText(ui->label->text()+temp);
        ui->textEdit->setText(QString::number(num.GetValue()));
        action = "";
        flag_result = true;
        flag_double = true;
        first_num = true;
    }
}

void MainWindow::on_pushButton_26_clicked() // 1/x
{
    num.SetValue(ui->textEdit->toPlainText().toDouble());
    ui->textEdit->setText(QString::number(1/num.GetValue()));
}

void MainWindow::on_pushButton_28_clicked() // sin
{
    num.SetValue(ui->textEdit->toPlainText().toDouble());
    ui->textEdit->setText(QString::number(num.sinValue()));
}

void MainWindow::on_pushButton_16_clicked() // cos
{
    num.SetValue(ui->textEdit->toPlainText().toDouble());
    ui->textEdit->setText(QString::number(num.cosValue()));
}

void MainWindow::on_pushButton_18_clicked() // tg
{
    num.SetValue(ui->textEdit->toPlainText().toDouble());
    ui->textEdit->setText(QString::number(num.tgValue()));
}

void MainWindow::on_pushButton_19_clicked() // ctg
{
    num.SetValue(ui->textEdit->toPlainText().toDouble());
    ui->textEdit->setText(QString::number(num.ctgValue()));
}

void MainWindow::on_pushButton_25_clicked() // Exp
{
    num.SetValue(ui->textEdit->toPlainText().toDouble());
    ui->textEdit->setText(QString::number(num.expValue()));
}

void MainWindow::on_pushButton_29_clicked() // ln
{
    num.SetValue(ui->textEdit->toPlainText().toDouble());
    ui->textEdit->setText(QString::number(num.lnValue()));
}

void MainWindow::on_pushButton_27_clicked() // Sqr
{
    num.SetValue(ui->textEdit->toPlainText().toDouble());
    ui->textEdit->setText(QString::number(num.sqrValue()));
}

void MainWindow::on_pushButton_24_clicked() // Sqrt
{
    num.SetValue(ui->textEdit->toPlainText().toDouble());
    ui->textEdit->setText(QString::number(num.sqrtValue()));
}

void MainWindow::on_pushButton_12_clicked() // +/-
{
    if (ui->textEdit->toPlainText().mid(0, 1) == "-")
        ui->textEdit->setText(ui->textEdit->toPlainText().remove(0, 1));
    else
        ui->textEdit->setText("-"+ui->textEdit->toPlainText());
}
