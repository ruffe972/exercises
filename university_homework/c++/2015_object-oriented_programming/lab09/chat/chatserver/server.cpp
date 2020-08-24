#include <QDebug>
#include "server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    // Have ownership
    portLabel(new QLabel),
    chatTextEdit(new QTextEdit),
    messageLineEdit(new QLineEdit),
    sendButton(new QPushButton("Send")),

    tcpServer(nullptr),
    networkSession(nullptr),
    tcpSocket(nullptr),
    blockSize(0)
{
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));
        networkSession->open();
    }
    else
        sessionOpened();
    installWidgets();
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(connectClient()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(messageLineEdit, SIGNAL(textChanged(QString)), this, SLOT(maybeEnableSendButton()));
}

void Server::installWidgets()
{
    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(portLabel, 0, 0);
    mainLayout->addWidget(chatTextEdit, 1, 0, 1, 2);
    mainLayout->addWidget(messageLineEdit, 2, 0);
    mainLayout->addWidget(sendButton, 2, 1);
    setLayout(mainLayout);

    setWindowTitle(windowTitle);
    resize(400, 300);
    chatTextEdit->setReadOnly(true);
    connect(messageLineEdit, SIGNAL(returnPressed()), sendButton, SLOT(click()));
    sendButton->setEnabled(false);
}

void Server::sessionOpened()
{
    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen())
    {
        QMessageBox::critical(this, windowTitle, tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
    }
    else
    {
        tcpServer->setMaxPendingConnections(1);
        portLabel->setText(tr("Port: %1").arg(tcpServer->serverPort()));
    }
}

void Server::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << messageLineEdit->text();

    chatTextEdit->append("me: " + messageLineEdit->text());
    messageLineEdit->clear();

    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);
}

void Server::processIncomingData()
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
        chatTextEdit->append("client: " + message);
        blockSize = 0;
    }
}

void Server::connectClient()
{
    if (tcpSocket && tcpSocket->state() != QAbstractSocket::UnconnectedState)
        QMessageBox::information(this, windowTitle, "More than one client is not allowed. "
                                                    "The connected client will not work correctly.");
    else
    {
        // Becomes a child of the server
        tcpSocket = tcpServer->nextPendingConnection();
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(processIncomingData()));
        connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
        chatTextEdit->append("Connected.");
        maybeEnableSendButton();
    }
}

void Server::disconnected()
{
    chatTextEdit->append("Disconnected.");
    sendButton->setEnabled(false);
}

void Server::maybeEnableSendButton()
{
    sendButton->setEnabled(tcpSocket && tcpSocket->state() == QAbstractSocket::ConnectedState &&
                           !messageLineEdit->text().isEmpty());
}
