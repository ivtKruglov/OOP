#include "database.h"
#include "ui_database.h"

DataBase::DataBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DataBase)
{
    ui->setupUi(this);
    addRowWindow = new AddRowClass;
    createWindow = new NewDBClass;
    msgWindow = new WarningClass;
    isCreated = false;
    connect(createWindow, SIGNAL(created()), this, SLOT(created()));
    connect(addRowWindow, SIGNAL(checkData()), this, SLOT(checkData()));
    connect(this, SIGNAL(OK()), addRowWindow, SLOT(close()));
    connect(this, SIGNAL(error()), addRowWindow, SLOT(incorrectData()));
}

DataBase::~DataBase()
{
    delete ui;
    delete addRowWindow;
    delete createWindow;
    delete msgWindow;
}

void DataBase::closeEvent(QCloseEvent *event)
{
    msgWindow->setText("Вы уверены, что хотите выйти? Все несохраненные данные будут утеряны.");
    msgWindow->run();
    if (msgWindow->getClickedButton() == msgWindow->getButtons()[0])
        event->accept();
    else
        event->ignore();
}

void DataBase::created()
{
    if (isCreated)
    {
        msgWindow->setText("Вы уверены, что хотите создать новую базу данных? Все несохраненные данные будут утеряны.");
        msgWindow->run();
        if (msgWindow->getClickedButton() == msgWindow->getButtons()[0])
        {
            ui->tableWidget->setRowCount(0);
            database.clear();
        }
    }
    else
    {
        ui->tableWidget->setEnabled(true);
        ui->addrow->setEnabled(true);
        ui->tableWidget->setColumnCount(database.getColumnSize());
        ui->tableWidget->setHorizontalHeaderLabels(database.getHeaders());
        isCreated = true;
    }
}

void DataBase::updateTable()
{
    ui->tableWidget->setRowCount(database.getRows().size());
    for (int rowIndex = 0; rowIndex < database.getRows().size(); ++rowIndex)
    {
        for (int columnIndex = 0; columnIndex < database.getColumnSize(); ++columnIndex)
            ui->tableWidget->setItem(rowIndex, columnIndex, new QTableWidgetItem(database.getRows()[rowIndex][columnIndex]));
    }
}

void DataBase::checkData()
{
    if (database.checkRow(addRowWindow->getNewRow()))
    {
        emit OK();
        database.addRow(addRowWindow->getNewRow());
        if (!ui->addrow->isEnabled())
            ui->addrow->setEnabled(true);
        if (!ui->removerow->isEnabled())
            ui->removerow->setEnabled(true);
        if (!ui->clear->isEnabled())
            ui->clear->setEnabled(true);
        if (!ui->search->isEnabled())
        {
            ui->search->setEnabled(true);
            ui->lineEdit->setEnabled(true);
        }
        if (database.getRows().size() >= 2)
            if (!ui->sort->isEnabled())
                ui->sort->setEnabled(true);
        updateTable();
    }
    else
        emit error();
}

void DataBase::on_addrow_clicked()
{
    addRowWindow->exec();
}

void DataBase::on_removerow_clicked()
{
    for (int indexRow = 0; indexRow < database.getRows().size(); ++indexRow)
    {
        if (ui->tableWidget->item(indexRow, 0)->isSelected())
        {
            database.removeRow(ui->tableWidget->item(indexRow, 0)->text().toInt());
            ui->tableWidget->removeRow(indexRow);
        }
    }
    if (database.getRows().size() < 2)
    {
        ui->sort->setEnabled(false);
        if (database.getRows().size() < 1)
        {
            ui->removerow->setEnabled(false);
            ui->clear->setEnabled(false);
            ui->search->setEnabled(false);
            ui->lineEdit->setEnabled(false);
        }
    }
}

void DataBase::on_sort_clicked()
{
    database.sort();
    updateTable();
}

void DataBase::on_clear_clicked()
{
    msgWindow->setText("Вы уверены, что хотите очистить базу данных?");
    msgWindow->run();
    if (msgWindow->getClickedButton() == msgWindow->getButtons()[0])
    {
        ui->tableWidget->setRowCount(0);
        database.clear();
        ui->search->setEnabled(false);
        ui->lineEdit->setEnabled(false);
        ui->removerow->setEnabled(false);
        ui->clear->setEnabled(false);
        if (ui->sort->isEnabled())
            ui->sort->setEnabled(false);
    }
}

void DataBase::on_search_clicked()
{
    for (int rowIndex = 0; rowIndex < database.getRows().size(); ++rowIndex)
    {
        if (ui->tableWidget->item(rowIndex, 1)->text() == ui->lineEdit->text())
            ui->tableWidget->item(rowIndex, 1)->setSelected(true);
    }
}

void DataBase::on_newbd_triggered()
{
    createWindow->exec();
    database.newName(createWindow->bdName());
}

void DataBase::on_openbd_triggered()
{
    QFile file(QFileDialog::getOpenFileName(this, "Открыть файл", "", "*.csv"));
    if (isCreated)
    {
        msgWindow->setText("Вы уверены, что хотите открыть другую базу данных? Все несохраненные данные будут утеряны.");
        msgWindow->run();
        if (msgWindow->getClickedButton() == msgWindow->getButtons()[0])
        {
            QVector<QVector<QString>> fileData;
            fileData = readFile(file);
            if (fileData.size() != 0)
            {
                database.newData(fileData);
                updateTable();

                if (!ui->removerow->isEnabled())
                    ui->removerow->setEnabled(true);
                if (!ui->clear->isEnabled())
                    ui->clear->setEnabled(true);
                if (!ui->search->isEnabled())
                {
                    ui->search->setEnabled(true);
                    ui->lineEdit->setEnabled(true);
                }

                if (fileData.size() >= 2)
                {
                    if (!ui->sort->isEnabled())
                        ui->sort->setEnabled(true);
                }
                else
                {
                    if (ui->sort->isEnabled())
                        ui->sort->setEnabled(false);
                }
            }
            else
            {
                msgWindow->setText("Не удалось открыть файл");
                QPushButton * rButton;
                rButton = msgWindow->getButtons()[1];
                msgWindow->getButtons()[0]->setText("Ок");
                msgWindow->removeButton(msgWindow->getButtons()[1]);
                msgWindow->run();
                msgWindow->getButtons()[0]->setText("Да");
                msgWindow->addButton(rButton);
            }
        }
    }
    else
    {
        QVector<QVector<QString>> fileData;
        fileData = readFile(file);
        if (fileData.size() != 0)
        {
            ui->tableWidget->setEnabled(true);
            ui->tableWidget->setColumnCount(database.getColumnSize());
            ui->tableWidget->setHorizontalHeaderLabels(database.getHeaders());
            isCreated = true;

            database.newData(fileData);
            updateTable();

            ui->addrow->setEnabled(true);
            ui->removerow->setEnabled(true);
            ui->clear->setEnabled(true);
            ui->search->setEnabled(true);
            ui->lineEdit->setEnabled(true);

            if (fileData.size() >= 2)
                ui->sort->setEnabled(true);
            else
                ui->sort->setEnabled(false);
        }
        else
        {
            msgWindow->setText("Не удалось открыть файл");
            QPushButton * rButton;
            rButton = msgWindow->getButtons()[1];
            msgWindow->getButtons()[0]->setText("Ок");
            msgWindow->removeButton(msgWindow->getButtons()[1]);
            msgWindow->run();
            msgWindow->getButtons()[0]->setText("Да");
            msgWindow->addButton(rButton);
        }
    }
}

void DataBase::on_savebd_triggered()
{
    if (database.getRows().size() > 0)
    {
        QFile file(QFileDialog::getSaveFileName(this, "Сохранить файл", database.getName(), "*.csv"));
        writeFile(file, database.getRows());
    }
    else
    {
        msgWindow->setText("Вы не создали ни одной записи. Чтобы сохранить базу данных, она должна содержать как минимум 1 запись.");
        QPushButton * rButton;
        rButton = msgWindow->getButtons()[1];
        msgWindow->getButtons()[0]->setText("Ок");
        msgWindow->removeButton(msgWindow->getButtons()[1]);
        msgWindow->run();
        msgWindow->getButtons()[0]->setText("Да");
        msgWindow->addButton(rButton);
    }
}

void DataBase::on_exit_triggered()
{
    this->close();
}

QVector<QVector<QString>> DataBase::readFile(QFile &f)
{
    QVector<QVector<QString>> rows;
    if (f.open(QIODevice::ReadOnly))
    {
        QString rowfile;
        QString item;
        QVector<QString> row;
        while (!f.atEnd())
        {
            row.clear();
            item = "";
            rowfile = "";
            rowfile = f.readLine();
            for (int indexRow = 0; indexRow < rowfile.size()-1; ++indexRow)
            {
                if (rowfile[indexRow] != ";")
                    item.append(rowfile[indexRow]);
                else
                {
                    row.append(item);
                    item = "";
                }
            }
            rows.append(row);
        }
        f.close();
    }
    return rows;
}

void DataBase::writeFile(QFile &f, const QVector<QVector<QString>> &data)
{
    if (f.open(QIODevice::WriteOnly))
    {
        for (int rowIndex = 0; rowIndex < data.size(); ++rowIndex)
        {
            for (int columnIndex = 0; columnIndex < data[rowIndex].size(); ++columnIndex)
            {
                f.write(data[rowIndex][columnIndex].toStdString().c_str());
                f.write(";");
            }
            f.write("\n");
        }
        f.close();
    }
}
