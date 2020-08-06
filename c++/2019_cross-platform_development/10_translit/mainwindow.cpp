#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Translit");
    initTranslitTable();
    connect(ui->russianTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::updateTranslation);
    auto helpMenu = new QMenu("Help", this);
    auto showInfo = [=]() {
        QMessageBox::about(this,
                           "About Program",
                           "Transliteration system: Приказ МИД N 4271.");
    };
    helpMenu->addAction("About...", this, showInfo);
    ui->menuBar->addMenu(helpMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTranslation()
{
    QString translit;
    for (auto ch: ui->russianTextEdit->toPlainText()) {
        auto lowerChar = ch.toLower();
        QString charTranslation = ch;
        if (translitTable.contains(lowerChar)) {
            charTranslation = translitTable[lowerChar];
            if (ch.isUpper() && charTranslation != "") {
                charTranslation[0] = charTranslation[0].toUpper();
            }
        }
        translit += charTranslation;
    }
    ui->translitTextEdit->setPlainText(translit);
}

void MainWindow::initTranslitTable()
{
    translitTable[L'а'] = "a";
    translitTable[L'б'] = "b";
    translitTable[L'в'] = "v";
    translitTable[L'г'] = "g";
    translitTable[L'д'] = "d";
    translitTable[L'е'] = "e";
    translitTable[L'ё'] = "e";
    translitTable[L'ж'] = "zh";
    translitTable[L'з'] = "z";
    translitTable[L'и'] = "i";
    translitTable[L'й'] = "i";
    translitTable[L'к'] = "k";
    translitTable[L'л'] = "l";
    translitTable[L'м'] = "m";
    translitTable[L'н'] = "n";
    translitTable[L'о'] = "o";
    translitTable[L'п'] = "p";
    translitTable[L'р'] = "r";
    translitTable[L'с'] = "s";
    translitTable[L'т'] = "t";
    translitTable[L'у'] = "u";
    translitTable[L'ф'] = "f";
    translitTable[L'х'] = "kh";
    translitTable[L'ц'] = "ts";
    translitTable[L'ч'] = "ch";
    translitTable[L'ш'] = "sh";
    translitTable[L'щ'] = "shch";
    translitTable[L'ъ'] = "ie";
    translitTable[L'ы'] = "y";
    translitTable[L'ь'] = "";
    translitTable[L'э'] = "e";
    translitTable[L'ю'] = "iu";
    translitTable[L'я'] = "ia";
}
