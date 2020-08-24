#pragma once
#include <QtWidgets>
#include <QtNetwork>
#include <QTcpSocket>

/// Local chat server
class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);

private slots:
    void sessionOpened();
    void sendMessage();
    void connectClient();
    void processIncomingData();
    void maybeEnableSendButton();
    void disconnected();

private:
    void installWidgets();
    const QString windowTitle = "Local Chat Server";

    QLabel *portLabel;
    QTextEdit *chatTextEdit;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;

    QTcpServer *tcpServer;
    QNetworkSession *networkSession;
    QTcpSocket *tcpSocket;
    quint16 blockSize;
};
