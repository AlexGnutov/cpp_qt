#ifndef STOPHATCH_H
#define STOPHATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

    bool is_running() {
        return timer->isActive();
    }

private:
    QTimer *timer = nullptr;

    bool in_loop = false;
    int lap = 0;

    std::chrono::time_point<std::chrono::steady_clock> start_tp;
    std::chrono::time_point<std::chrono::steady_clock> prev_lap_tp;

public slots:

    void start();

    void stop();

    void reset();

    void end_lap();

signals:
    void time_update(const QString& time);

    void lap_update(const QString& value);

};

#endif // STOPWATCH_H
