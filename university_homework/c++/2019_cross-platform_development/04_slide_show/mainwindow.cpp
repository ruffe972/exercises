#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QDebug>

int const DELAY = 2000;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Init menu
    auto fileMenu = new QMenu("File", this);
    fileMenu->addAction("Open image...", this, &MainWindow::openImage, QKeySequence::Open);
    ui->menuBar->addMenu(fileMenu);

    ui->graphicsView->setScene(&scene);
    connect(ui->buttonPrevious, &QAbstractButton::clicked, [=]()
    {
        updateImage(imagePosInList - 1);
        killTimer(timerId);
        timerId = startTimer(DELAY);
    });
    connect(ui->buttonNext, &QAbstractButton::clicked, [=]()
    {
        updateImage(imagePosInList + 1);
        killTimer(timerId);
        timerId = startTimer(DELAY);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    updateImage(imagePosInList + 1);
}

void MainWindow::openImage()
{
    auto imageName = QFileDialog::getOpenFileName(
                this,
                "Open Image",
                "",
                "Image Files (*.png *.jpg *.bmp *.jpeg *.gif *.PNG *.JPG *.BMP *.JPEG *.GIF)");
    if (imageName != "")
    {
        updateImage(imageName);
        auto imageInfoList = QFileInfo(imageName).dir().entryInfoList({"*.png",
                                                                       "*.jpg",
                                                                       "*.bmp",
                                                                       "*.jpeg",
                                                                       "*.gif",
                                                                       "*.PNG",
                                                                       "*.JPG",
                                                                       "*.BMP",
                                                                       "*.JPEG",
                                                                       "*.GIF"});
        imageFileNameList = QStringList();
        for (const QFileInfo &info: imageInfoList)
        {
            imageFileNameList << info.absoluteFilePath();
        }
        imagePosInList = imageFileNameList.indexOf(imageName);

        killTimer(timerId);
        timerId = startTimer(DELAY);
    }
}

void MainWindow::updateImage(const QString &imageName)
{
    QPixmap pixmap(imageName);
    auto view = ui->graphicsView;
    if (pixmap.width() > view->width() || pixmap.height() > view->height())
    {
        pixmap = pixmap.scaled(view->size(), Qt::KeepAspectRatio);
    }
    for (auto item: scene.items())
    {
        scene.removeItem(item);
    }
    scene.addPixmap(pixmap);
}

void MainWindow::updateImage(int posInList)
{
    if (posInList >= 0 && posInList < imageFileNameList.size())
    {
        imagePosInList = posInList;
        updateImage(imageFileNameList.at(posInList));
    }
}
