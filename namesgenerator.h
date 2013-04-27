#ifndef NAMESGENERATOR_H
#define NAMESGENERATOR_H

#include <time.h>

#include <QObject>
#include <QString>
#include <QStringList>

enum CH_RACE {
    HUMAN = 0,
    ELF = 1,
    ORC = 2
};

enum CH_CLASS {
    WARRIOR = 0,
    ROGUE = 1,
    MAGE = 2
};

class NamesGenerator : public QObject
{

    public:
        explicit NamesGenerator(QObject *parent = 0);

        static QString run(CH_RACE chRace, CH_CLASS chClass);
        static QString generate(CH_RACE chRace, CH_CLASS chClass);
        static QString generateTitle(QString event, QString base = "");
        static QString generate();
    private:
        static QString generateName(bool withPrefix = false, bool withSuffix = false, bool withPostfix = false);
        static QString generateSurname(bool withPrefix = false, bool withSuffix = false, bool withPostfix = false);

};

#endif // NAMESGENERATOR_H
