#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle_button_clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString button_text = button->text();
    this->update_calculations(button_text.at(0));
}

void MainWindow::update_calculations(QChar c)
{
    QWidget *widget = this->findChild<QWidget *>("wMainWidget");
    QLineEdit *edt = widget->findChild<QLineEdit *>("edtResult");
    manager.calculate(c, edt);
}
