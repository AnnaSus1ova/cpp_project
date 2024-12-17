#ifndef DIFFERENT_QUANTITY_H
#define DIFFERENT_QUANTITY_H

#include <QDialog>

namespace Ui {
class DifferentQuantity;
}

class DifferentQuantity : public QDialog
{
    Q_OBJECT

public:
    explicit DifferentQuantity(QWidget *parent = nullptr);
    ~DifferentQuantity();

private:
    Ui::DifferentQuantity *ui;
};

#endif // DIFFERENT_QUANTITY_H
