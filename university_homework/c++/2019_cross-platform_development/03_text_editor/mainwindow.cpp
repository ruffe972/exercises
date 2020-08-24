#include "mainwindow.h"

#include "syntaxhighlighter.h"
#include "ui_mainwindow.h"
#include "unsavedchangesdialog.h"

#include <QDebug>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        _ui(new Ui::MainWindow) {

    _ui->setupUi(this);
    initMenu();
    resize(qApp->desktop()->screenGeometry().size() / 2);

    connect(_ui->plainTextEdit,
            &QPlainTextEdit::modificationChanged,
            this,
            &MainWindow::updateWindowTitle);

    updateWindowTitle();
}

MainWindow::~MainWindow() {
    delete _ui;
}

void MainWindow::initMenu() {
    auto fileMenu = new QMenu("File");
    fileMenu->addAction("New File...", this, &MainWindow::newFile, QKeySequence::New);
    fileMenu->addAction("Open File...", this, &MainWindow::openFile, QKeySequence::Open);
    fileMenu->addSeparator();
    fileMenu->addAction("Save File", this, &MainWindow::saveNewOrExistingFile, QKeySequence::Save);
    fileMenu->addAction("Save File As...", this, &MainWindow::saveFileAs, QKeySequence::SaveAs);
    _ui->menuBar->addMenu(fileMenu);

    auto helpMenu = new QMenu("Help");
    helpMenu->addAction("About...", this, [=]() {
        QMessageBox::about(this,
                           "About Program",
                           "Text editor written in Qt by students of MASU.");
    });
    _ui->menuBar->addMenu(helpMenu);
    auto fontMenu = new QMenu("Font Size");
    QList<int> fontSizes = {12, 14, 16, 18, 20, 22};
    for (int fontSize: fontSizes) {
        fontMenu->addAction(QString::number(fontSize), this, [=]() {
            changeFont(fontSize);
        });
    }
    _ui->menuBar->addMenu(fontMenu);
}

void MainWindow::newFile() {
    if (handleUnsavedChanges()) {
        setFileName("");
        _ui->plainTextEdit->clear();
        _ui->plainTextEdit->document()->setModified(false);
        updateWindowTitle();
    }
}

bool MainWindow::handleUnsavedChanges() {
    if (!_ui->plainTextEdit->document()->isModified()) {
        return true;
    }
    auto dialog = new UnsavedChangesDialog(this);
    auto code = dialog->customExec();
    return ((code == ChangesDialogCode::AcceptedWithSaving && saveNewOrExistingFile()) ||
            code == ChangesDialogCode::AcceptedWithoutSaving);
}

void MainWindow::updateWindowTitle() {
    auto shortName = (_fileName.isEmpty() ? "untitled.txt"
                                          : QFileInfo(_fileName).fileName());
    bool modified = _ui->plainTextEdit->document()->isModified();
    auto title = shortName + (modified ? "*" : "");
    setWindowTitle(title);
}

void MainWindow::setFileName(const QString &fileName) {
    _fileName = fileName;
    updateWindowTitle();

    if (fileName.endsWith(".c") || fileName.endsWith(".h")) {
        if (!_highlighter) {
            _highlighter = new SyntaxHighlighter(_ui->plainTextEdit->document());
        }
    } else if (_highlighter) {
        delete _highlighter;
        _highlighter = nullptr;
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (handleUnsavedChanges()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::openFile() {
    if (!handleUnsavedChanges()) {
        return;
    }
    auto name = QFileDialog::getOpenFileName(this);
    if (name != "") {
        QFile file(name);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            setFileName(name);
            QTextStream stream(&file);
            _ui->plainTextEdit->setPlainText(stream.readAll());
            _ui->plainTextEdit->document()->setModified(false);
        } else {
            QMessageBox::warning(this,
                                 "Error",
                                 "Error: can't read from file " + name);
        }
        file.close();
    }
}

bool MainWindow::saveNewOrExistingFile() {
    if (_fileName.isEmpty()) {
        return saveFileAs();
    } else {
        return saveFile(_fileName);
    }
}

bool MainWindow::saveFile(const QString &name) {
    QFile file(name);
    bool success = file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (success) {
        QTextStream out(&file);
        out << _ui->plainTextEdit->toPlainText();
        setFileName(name);
        _ui->plainTextEdit->document()->setModified(false);
    } else {
        QMessageBox::warning(this,
                             "Error",
                             "Error: can't write to file " + _fileName);
    }
    file.close();
    return success;
}

bool MainWindow::saveFileAs() {
    auto name = QFileDialog::getSaveFileName(this);
    return name != "" && saveFile(name);
}

void MainWindow::changeFont(int pixelSize)
{
    QFont font = _ui->plainTextEdit->font();
    font.setPixelSize(pixelSize);
    _ui->plainTextEdit->setFont(font);
}
