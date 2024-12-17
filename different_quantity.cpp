#include "different_quantity.h"
#include "ui_different_quantity.h"

DifferentQuantity::DifferentQuantity(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DifferentQuantity)
{
    ui->setupUi(this);
}

DifferentQuantity::~DifferentQuantity()
{
    delete ui;
}
