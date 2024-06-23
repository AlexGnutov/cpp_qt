#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    c_dialog = new ConnectionDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_c_btn_clicked()
{
    c_dialog->show();
}

