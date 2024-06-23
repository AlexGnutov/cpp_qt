#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{

    timer = new QTimer(this);
    timer->setInterval(100);

    QObject::connect(timer, &QTimer::timeout, this, [&]() {

        auto current = std::chrono::steady_clock::now();

        std::chrono::steady_clock::duration d = current - start_tp;

        auto sec = std::chrono::duration_cast<std::chrono::seconds>(d).count();
        auto msec = (std::chrono::duration_cast<std::chrono::milliseconds>(d).count() % 1000) / 100;

        emit time_update(QString::number(sec) + "." + QString::number(msec));
    });

}

void Stopwatch::start() {
    if (!in_loop) {
        start_tp = std::chrono::steady_clock::now();
        in_loop = true;
    }
    prev_lap_tp = std::chrono::steady_clock::now();
    timer->start();
}

void Stopwatch::stop() {
    timer->stop();
}

void Stopwatch::reset() {
    timer->stop();
    lap = 0;
    in_loop = false;
}

void Stopwatch::end_lap() {
    if (!in_loop || !timer->isActive()) return;

    auto cur = std::chrono::steady_clock::now();
    std::chrono::steady_clock::duration d = cur - prev_lap_tp;
    prev_lap_tp = cur;

    auto sec = std::chrono::duration_cast<std::chrono::seconds>(d).count();
    auto msec = (std::chrono::duration_cast<std::chrono::milliseconds>(d).count() % 1000) / 100;
    emit lap_update("Круг " + QString::number(lap) + ", время : " + QString::number(sec) + "." + QString::number(msec) + " сек");

    lap++;
}
