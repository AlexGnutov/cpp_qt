#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mode_one_radio->setText("Mode One");
    ui->mode_two_radio->setText("Mode Two");

    ui->dpd_list->addItem("one", 1);
    ui->dpd_list->addItem("two", 2);
    ui->dpd_list->addItem("three", 3);

    ui->inc_button->setText("Increase");
    ui->inc_button->setCheckable(true);

    ui->progress_bar->setMinimum(0);
    ui->progress_bar->setMaximum(10);
    ui->progress_bar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_inc_button_clicked()
{
    auto current = ui->progress_bar->value();
    if (current < 10) {
        ui->progress_bar->setValue(current + 1);
    }
    else {
        ui->progress_bar->setValue(0);
    }
}

