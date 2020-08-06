#pragma once
#include <QMainWindow>
#include <QWebElement>
#include <QWebFrame>
#include <QWebView>

namespace Ui {
class QuotesWindow;
}

/// bash.im quotes browser
/** Crashes (throws a built-in qt exception)
 * if there is no internet connection,
 * when the site is down, etc. */
class QuotesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuotesWindow(QWidget *parent = 0);
    ~QuotesWindow();

private slots:
    void showNextQuote();
    void loadQuotes();

private:
    Ui::QuotesWindow *ui;
    QWebView webView;
    QList<QWebElement> quotesBlocks;
    QList<QWebElement>::iterator quoteIterator;
};
