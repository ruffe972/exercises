#pragma once
#include <QTcpSocket>
#include <QtWidgets>
#include <QtNetwork>

/// Local chat client
class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);

private slots:
    void connectToServer();
    void processIncomingData();
    void maybeEnableConnectButton();
    void maybeEnableSendButton();
    void displayError(QAbstractSocket::SocketError socketError);
    void sendMessage();
    void connected();
    void disconnected();

private:
    void installWidgets();
    const QString windowTitle = "Local Chat Client";

    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QPushButton *connectButton;
    QTextEdit *chatTextEdit;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;

    QTcpSocket *tcpSocket;
    QNetworkSession *networkSession;
    quint16 blockSize;
};
