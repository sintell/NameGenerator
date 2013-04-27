#include "namesgenerator.h"


NamesGenerator::NamesGenerator(QObject *parent) :
    QObject(parent)
{
}
QString NamesGenerator::run(CH_RACE chRace, CH_CLASS chClass) {

    QString name;

    switch(chRace) {
    case HUMAN: name = "Sample Human"; break;
    case ELF: name = "Sample Elf"; break;
    case ORC: name = "Sample Orc"; break;
    default: Q_ASSERT("Char race is undefined!");
    }

    switch (chClass) {
    case WARRIOR: name += " Warrior"; break;
    case ROGUE: name += " Rogue"; break;
    case MAGE: name += " Mage"; break;
    default: Q_ASSERT("Char class is undefined!");
    }



    return name;
}

QString NamesGenerator::generate()
{
    QString fullName;
    qsrand(time(0));
    for (int i = 0; i < 20; ++i) {
        fullName = generateName() + " " +
                generateSurname();

       // qDebug() << fullName;

    }
    return fullName;
}

QString NamesGenerator::generate(CH_RACE chRace, CH_CLASS chClass)
{
    QString fullName;
    qsrand(time(0));
    for (int i = 0; i < 20; ++i) {
        fullName = generateName() + " " +
                generateSurname();
      //  qDebug() << fullName;
    }
    return fullName;
}

QString NamesGenerator::generateName(bool withPrefix, bool withSuffix, bool withPostfix)
{
    QString begining = "z,d,k,x,g,j,y,a,o,e,l,b,c,f,r,h,m,n,p,r,s,t,v",
            main = "a,o,e,i,u",
            ending = "it,er,es,,s,t,or,n,b,ec";

    QStringList b = begining.split(',');
    QStringList m = main.split(',');
    QStringList e = ending.split(',');
    QString name = b.takeAt((qrand()%(b.size()/2))).toUpper() +
            m.takeAt(qrand()%m.size()) +
            b.takeAt(qrand()%(b.size())) +
            e.takeAt(qrand()%e.size());

    return name;
}


QString NamesGenerator::generateSurname(bool withPrefix, bool withSuffix, bool withPostfix)
{

    QString begining = "z,d,k,x,g,j,y,a,o,e,l,b,c,f,h,m,n,p,r,s,t,v",
            main = "a,o,e,i,u",
            ending = "ith,er,es,s,tis,rith";

    QStringList b = begining.split(',');
    QStringList m = main.split(',');
    QStringList e = ending.split(',');
    QString name;

    name = b.takeAt((qrand()%(b.size()/2))).toUpper() +
            m.takeAt(qrand()%m.size()) +
            b.takeAt(qrand()%(b.size())) +
            e.takeAt(qrand()%e.size());

    return name;
}

QString NamesGenerator::generateTitle(QString event, QString base)
{
    return QString("the " + (base.isEmpty()?" ":(" " + base + " ")) + event);
}
