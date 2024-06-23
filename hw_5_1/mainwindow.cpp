#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    watch = new Stopwatch();

    ui->lap_btn->setEnabled(false);

    QObject::connect(ui->start_btn, &QPushButton::clicked,
                     this, [&]() {
        if (watch->is_running()) {
            watch->stop();
            ui->start_btn->setText("Стaрт");
            ui->lap_btn->setEnabled(false);
        } else {
            watch->start();
            ui->start_btn->setText("Стоп");
            ui->lap_btn->setEnabled(true);
        }
    });

    QObject::connect(ui->lap_btn, &QPushButton::clicked,
                     this, [&](){
        watch->end_lap();
    });

    QObject::connect(ui->clear_btn, &QPushButton::clicked,
                     this, [&]() {
        ui->lap_btn->setEnabled(false);
        watch->reset();
        ui->start_btn->setText("Стaрт");

        ui->time_label->setText("0.0");
        ui->text_browser->clear();
    });

    QObject::connect(watch, &Stopwatch::time_update, this, [&](const QString& value){
        ui->time_label->setText(value);
    });

    QObject::connect(watch, &Stopwatch::lap_update, this, [&](const QString& value){
        ui->text_browser->append(value);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}



