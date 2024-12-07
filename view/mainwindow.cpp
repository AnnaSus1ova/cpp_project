#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include "errors.h"
#include <QFileDialog>
#include <QString>
#include <vector>
#include <string>
#include <algorithm>
#include "Data.h"
#include <iostream>
#include "secdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/img/my-background.png");

    ui->picture->setPixmap(pix);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Error_clicked()
{
    //ui->ShowError_1->clear();
    //ui->ShowError_2->clear();

    //MeasurementError AV{std::vector<double> (5)};
    //MeasurementError AME{std::vector<double> (5)};

    //QString AMEString = QString::number(AME.average_measurement_error());
    //ui->ShowError_1->insertPlainText(QString(AMEString));

    //QString AVString = QString::number(AV.average_value());
    //ui->ShowError_2->insertPlainText(QString(AVString));
}


std::vector<std::string> strings;

std::vector<std::string> customSplit(const std::string& str, const char* separator) {
    int startIndex = 0;
    std::vector<std::string> result;

    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == separator[0] || i == str.size()) {
            std::string temp = str.substr(startIndex, i - startIndex);
            if (!temp.empty())
                result.push_back(temp);
            startIndex = i + 1;
        }
    }
    return result;
}


void MainWindow::on_AddFile1_clicked()
{
    QString text1 = ui->Abscissa->toPlainText();
    if (text1.isEmpty()){
        text1 = QFileDialog::getOpenFileName(this, tr("Выберите файл с измерениями абсцисс"), QString(), tr("Text files (*.txt)"));
        if (text1.isEmpty()) return;
    }
    std::vector<std::string> absci_str = customSplit(text1.toUtf8().constData(), " ");
    std::vector<double> absci_d;
    std::transform(absci_str.begin(), absci_str.end(), std::back_inserter(absci_d),
                   [](const std::string& str) { return std::stod(str); });
    for (std::vector<double>::iterator i = absci_d.begin(); i != absci_d.end(); ++i)
        std::cout << *i;
    Data.set_abscissa(absci_d);
}

void MainWindow::on_AddFile2_clicked()
{
    QString text2 = ui->Ordinate->toPlainText();
    if (text2.isEmpty()){
        text2 = QFileDialog::getOpenFileName(this, tr("Выберите файл с измерениями ординат"),
                                             QString(),
                                             tr("Text files (*.txt)"));
        if (text2.isEmpty()) return;
    }
    std::vector<std::string> ordin_str = customSplit(text2.toUtf8().constData(), " ");
    std::vector<double> ordin_d;
    std::transform(ordin_str.begin(), ordin_str.end(), std::back_inserter(ordin_d),
                   [](const std::string& str) { return std::stod(str); });
    for (std::vector<double>::iterator i = ordin_d.begin(); i != ordin_d.end(); ++i)
        std::cout << *i;
    Data.set_ordinate(ordin_d);
}

void MainWindow::on_question_clicked()
{
    SecDialog secdialog;
    secdialog.setModal(true);
    secdialog.exec();

}

