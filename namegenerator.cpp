#include "namegenerator.h"
#include "ui_namegenerator.h"
#include <QDebug>

const unsigned short CAPITAL_ALPHA_OFFSET = 65;
const unsigned short SMALL_ALPHA_OFFSET = 97;

NameGenerator::NameGenerator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NameGenerator),
    m_Char(CAPITAL_ALPHA_OFFSET)
{
    ui->setupUi(this);

    this->setWindowFlags( Qt::MSWindowsFixedSizeDialogHint);

    for(int i = 0; i < 3; ++i) {
       m_Patterns << addPattern(); // Adding 3 initial pattern inputs
    }

    rx.setPattern("[A-Ca-c]{0,26}");
    QRegExpValidator *validator = new QRegExpValidator(rx, this);
    ui->le_PatternString->setValidator(validator);
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

    te->setFont(QFont("Verdana",9));

    lt->addWidget(lb);
    lt->addWidget(te);

    ui->Patterns->addLayout(lt);
    return te;
}

QList<int> *NameGenerator::patternsIndexes()
{
    QString str = ui->le_PatternString->text();
    QList<int> *t = new QList<int>();

    foreach (char ch, str.toUpper().toStdString()) {
        *t << (static_cast<int>(ch)-CAPITAL_ALPHA_OFFSET);
    }

    return t;
}

QString NameGenerator::generatePatternCheck()
{
    int size = m_Patterns.size() - 1;
    QString str = QString("[A-%1a-%2]{0,26}").arg(static_cast<QString>(size+CAPITAL_ALPHA_OFFSET))
                                                                                            .arg(static_cast<QString>(size+SMALL_ALPHA_OFFSET));
    return str;
}

bool NameGenerator::save()
{
}

void NameGenerator::keyPressEvent(QKeyEvent *e)
{
    if(e->matches(QKeySequence::Refresh)) {
        generateStuff();
    }
}

void NameGenerator::generateStuff()
{
    if(ui->checkBox->isChecked()) {
        m_StrList.clear();
        foreach(int i, *(patternsIndexes())) {
            m_StrList.append(QString(m_Patterns.at(i)->toPlainText()).split(","));
        }
        ui->te_NamesList->clear();
        qsrand(time(0));
        QString str;
        for (int i = 0; i < 15; ++i) {
            str.clear();
            foreach (QStringList strl, m_StrList) {
                if(!strl.isEmpty()) {
                    str.append(strl.at(qrand()%(strl.size())));
                }
            }
            ui->te_NamesList->append(str);
        }

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
    for (int i = 0; i < m_Patterns.size(); ++i) {
        disconnect(m_Patterns.at(i),0,0,0);
    }
    foreach (int i, *(patternsIndexes())) {
        connect(m_Patterns[i], SIGNAL(textChanged()),this,SLOT(generateStuff()));
    }
}

void NameGenerator::on_pb_Refresh_clicked()
{
    generateStuff();
}

void NameGenerator::on_actionQuit_triggered()
{
    QMessageBox::StandardButton b;
    b = QMessageBox::question(this,
                              "Name generator",
                              "You've got some unsaved changes.\nWould you like to save?",
                              QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if( b  == QMessageBox::Yes ) {
        save();
        this->close();
    } else if( b == QMessageBox::No ) {
        this->close();
    } else {
        return;
    }
}

void NameGenerator::on_actionAbout_programm_triggered()
{
    QMessageBox::about(this,"About Name generator",
                       "This is program that gives you support in creating different names by its parts.\n"
                       "You can create names by any pattern you want.\n"
                       "Program uses some rules from regular grammars to produce random generated names.\n"
                       "Program is free to use.\n"
                       "Distributed under GNU\\GPL license.\n\nSintell - 2013");
}

void NameGenerator::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "About Qt");
}
