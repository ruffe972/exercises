#include "syntaxhighlighter.h"

#include <QRegularExpression>

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent) :
        QSyntaxHighlighter(parent) {
}

void SyntaxHighlighter::highlightBlock(const QString &text) {
    auto keywords = {
        "char",
        "double",
        "float",
        "int",
        "void",
        "const",
        "enum",
        "static",
        "struct",
        "typedef",
        "if",
        "else",
        "switch",
        "case",
        "return"
    };

    QTextCharFormat format;
    format.setForeground(Qt::darkRed);

    for (auto keyword: keywords) {
        QRegularExpression pattern(QString("\\b%0\\b").arg(keyword));
        auto matchIterator = pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            auto match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), format);
        }
    }
}
