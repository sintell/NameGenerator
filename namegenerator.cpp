#include "namegenerator.h"
#include "ui_namegenerator.h"
#include <QDebug>

const unsigned short CAPITAL_ALPHA_OFFSET = 65;

NameGenerator::NameGenerator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NameGenerator),
    m_Char(CAPITAL_ALPHA_OFFSET)
{
    ui->setupUi(this);
    //<< ui->textEdit_2 << ui->textEdit_3 << ui->textEdit_4;

    rx.setPattern("[ABC]{0,26}");

    QRegExpValidator *validator = new QRegExpValidator(rx, this);

    ui->le_PatternString->setValidator(validator);

    for(int i = 0; i < 3; ++i) {
       m_Patterns << addPattern();
    }
}

NameGenerator::~NameGenerator()
{

    delete ui;
}

void NameGenerator::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QTextEdit *NameGenerator::addPattern()
{
    QHBoxLayout *lt = new QHBoxLayout(this);
    QLabel *lb = new QLabel(this);
    QTextEdit *te = new QTextEdit(this);

    lb->setText(static_cast<QString>(m_Char++));
    lb->setBuddy(te);
    lb->setMinimumSize(10,85);
    lb->setMaximumSize(10,85);
    lb->adjustSize();

    lt->addWidget(lb);
    lt->addWidget(te);

    connect(te, SIGNAL(textChanged()), this, SLOT(generateStuff()));
    ui->Patterns->addLayout(lt);
    return te;
}

QList<int> *NameGenerator::patternsIndexes()
{
    QString str = ui->le_PatternString->text();
    QList<int> *t = new QList<int>();

    foreach (char ch, str.toStdString()) {
        *t << (static_cast<int>(ch)-CAPITAL_ALPHA_OFFSET);
    }

    return t;
}

QString NameGenerator::generatePatternCheck()
{
    int size = m_Patterns.size();
    QString str = "[";
    for (int i = 0; i < size; ++i) {
        str.append(static_cast<char>(i+CAPITAL_ALPHA_OFFSET));
    }
    str.append("]{0,26}");

    return str;
}

void NameGenerator::generateStuff()
{
    if(ui->checkBox->isChecked()) {
        QStringList qsl;
        foreach(int i, *(patternsIndexes())) {
            qsl.append(QString(m_Patterns.at(i)->toPlainText()));
        }

        qDebug() << qsl.join("");
    }
}

void NameGenerator::on_pb_AddPattern_clicked()
{
    m_Patterns << addPattern();
    qDebug() << generatePatternCheck();
    rx.setPattern(generatePatternCheck());
    QRegExpValidator *validator = new QRegExpValidator(rx, this);
    ui->le_PatternString->setValidator(validator);
}

void NameGenerator::on_le_PatternString_textChanged(const QString &arg1)
{
    qDebug() << *(patternsIndexes());
    ui->le_PatternString->setText(arg1.toUpper());
}

void NameGenerator::on_pb_Refresh_clicked()
{
    generateStuff();
}
