#include "client.h"
#include <QDebug>

Client::Client(QWidget *parent) :
    QWidget(parent),
    // Have ownership
    portLabel(new QLabel("Server port:")),
    portLineEdit(new QLineEdit),
    connectButton(new QPushButton("Connect")),
    chatTextEdit(new QTextEdit),
    messageLineEdit(new QLineEdit),
    sendButton(new QPushButton("Send")),

    tcpSocket(new QTcpSocket(this)),
    networkSession(nullptr),
    blockSize(0)
{
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(maybeEnableConnectButton()));
        connectButton->setEnabled(false);
        networkSession->open();
    }

    installWidgets();
    connect(portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(maybeEnableConnectButton()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(processIncomingData()));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(messageLineEdit, SIGNAL(textChanged(QString)), this, SLOT(maybeEnableSendButton()));
}

void Client::connected()
{
    chatTextEdit->append("Connected.");
    maybeEnableSendButton();
    messageLineEdit->setFocus();
}

void Client::disconnected()
{
    chatTextEdit->append("Disconnected.");
    sendButton->setEnabled(false);
}

void Client::installWidgets()
{
    setWindowTitle(windowTitle);
    resize(400, 300);
    chatTextEdit->setReadOnly(true);
    connect(messageLineEdit, SIGNAL(returnPressed()), sendButton, SLOT(click()));

    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(portLabel, 0, 0);
    mainLayout->addWidget(portLineEdit, 0, 1);
    mainLayout->addWidget(connectButton, 0, 2);
    mainLayout->addWidget(chatTextEdit, 1, 0, 1, 3);
    mainLayout->addWidget(messageLineEdit, 2, 0, 1, 2);
    mainLayout->addWidget(sendButton, 2, 2);
    setLayout(mainLayout);

    portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    portLineEdit->setFocus();
    connectButton->setEnabled(false);
    sendButton->setEnabled(false);
    connect(portLineEdit, SIGNAL(returnPressed()), connectButton, SLOT(click()));
}

void Client::maybeEnableConnectButton()
{
    connectButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                              (tcpSocket->state() == QAbstractSocket::ConnectedState ||
                               tcpSocket->state() == QAbstractSocket::UnconnectedState) &&
                              !portLineEdit->text().isEmpty());
}

void Client::maybeEnableSendButton()
{
    sendButton->setEnabled(tcpSocket && tcpSocket->state() == QAbstractSocket::ConnectedState &&
                           !messageLineEdit->text().isEmpty());
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, windowTitle, "The connection was refused by the peer. "
                                                    "Make sure the chat server is running, "
                                                    "and check that the port is correct.");
        break;
    default:
        QMessageBox::information(this, windowTitle, tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }
    connectButton->setEnabled(true);
}

void Client::connectToServer()
{
    connectButton->setEnabled(false);
    tcpSocket->abort();
    tcpSocket->connectToHost("localhost", portLineEdit->text().toInt());
}

void Client::processIncomingData()
{
    QDataStream in(tcpSocket);
    if (blockSize == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }
    if (tcpSocket->bytesAvailable() >= blockSize)
    {
        QString message;
        in >> message;
        chatTextEdit->append("server: " + message);
        blockSize = 0;
    }
}

void Client::sendMessage()
{

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << messageLineEdit->text();

    chatTextEdit->append("me: " + messageLineEdit->text());
    messageLineEdit->clear();
    messageLineEdit->setFocus();

    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);
}
