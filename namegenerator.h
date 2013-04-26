#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <QMainWindow>
#include <QVector>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>

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
    //void generateStuff();
private slots:
    void generateStuff();
    void on_pb_AddPattern_clicked();
    void on_le_PatternString_textChanged(const QString &arg1);

    void on_pb_Refresh_clicked();

private:
    Ui::NameGenerator *ui;
    QVector<QTextEdit*> m_Patterns;
    int m_Char;
    QRegExp rx;

};

#endif // NAMEGENERATOR_H
