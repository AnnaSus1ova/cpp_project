#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Error_clicked();

    void on_question_clicked();

    void on_AddFile1_clicked();

    void on_AddFile2_clicked();

    void on_Graph1_clicked();

    void on_Graph2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
