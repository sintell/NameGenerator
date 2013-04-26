#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <QMainWindow>
#include <QVector>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QStringList>
#include <QMessageBox>
#include <QKeyEvent>
#include <time.h>

namespace Ui {
class NameGenerator;
}

class NameGenerator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit NameGenerator(QWidget *parent = 0);
    ~NameGenerator();
    
protected:
    void changeEvent(QEvent *e);
    QTextEdit *addPattern();
    QList<int> *patternsIndexes();
    QString generatePatternCheck();
    bool save();
    void keyPressEvent(QKeyEvent *e);
    //void generateStuff();
private slots:
    void generateStuff();
    void on_pb_AddPattern_clicked();
    void on_le_PatternString_textChanged(const QString &arg1);

    void on_pb_Refresh_clicked();

    void on_actionQuit_triggered();

    void on_actionAbout_programm_triggered();

    void on_actionAbout_Qt_triggered();

private:
    Ui::NameGenerator *ui;
    QVector<QTextEdit*> m_Patterns;
    int m_Char;
    QRegExp rx;
    QVector<QStringList> m_StrList;
};

#endif // NAMEGENERATOR_H
