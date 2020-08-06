#include <QtNetwork>
#include "quoteswindow.h"
#include "ui_quoteswindow.h"

QuotesWindow::QuotesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuotesWindow)
{
    ui->setupUi(this);
    setFixedSize(size());
    const QString url = "http://bash.im/bestyear/2004";
    setWindowTitle(url);
    webView.load(QUrl(url));
    connect(&webView, SIGNAL(loadFinished(bool)), this, SLOT(loadQuotes()));
    connect(ui->buttonNext, &QPushButton::clicked, this, &showNextQuote);
}

void QuotesWindow::loadQuotes()
{
    // webView "loadFinished" signal can be emitted several times
    if (!ui->buttonNext->isEnabled())
    {
        quotesBlocks = webView.page()->mainFrame()->findAllElements("div[class=quote]").toList();
        quoteIterator = --quotesBlocks.end();
        showNextQuote();
        ui->buttonNext->setEnabled(true);
    }
}

void QuotesWindow::showNextQuote()
{
    QString text;
    do
    {
        quoteIterator++;
        if (quoteIterator == quotesBlocks.end())
            quoteIterator = quotesBlocks.begin();
        text = quoteIterator->findFirst("div[class=text]").toPlainText();
    }
    while (text.isEmpty());
    ui->textWidget->clear();
    ui->textWidget->insertPlainText(text);
    ui->ratingLine->setText(quoteIterator->findFirst("span[class=rating-o]").toPlainText());
}

QuotesWindow::~QuotesWindow()
{
    delete ui;
}
