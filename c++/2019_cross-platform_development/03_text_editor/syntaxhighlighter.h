#pragma once

#include <QSyntaxHighlighter>

/// Highlighter for C language.
class SyntaxHighlighter : public QSyntaxHighlighter {
    Q_OBJECT

public:
    SyntaxHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) override;

};
