#ifndef RASBERRYPI_H
#define RASBERRYPI_H

#include <QObject>
#include <QDBusConnection>
#include <string.h>


class RasberryPI : public QObject
{
    Q_OBJECT
public:
    QString getSerialNumber();

};

#endif // RASBERRYPI_H
