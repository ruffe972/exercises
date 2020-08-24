# Инструкции для Windows
# 1) установить python3 https://www.python.org/downloads/
# 2) в консоли набрать python.exe -m pip install PyQt5 (регистр важен)

import sys
from math import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

PLOT_ZOOM = 30
BUTTON_FOCUS_COLOR = QColor(255, 105, 180)


class Button(QPushButton):
    def focusOutEvent(self, _):
        palette = QPalette()
        self.setPalette(palette)

    def focusInEvent(self, _):
        palette = QPalette()
        palette.setColor(QPalette.Button, BUTTON_FOCUS_COLOR)
        self.setPalette(palette)

    def keyPressEvent(self, event):
        if event.key() in (Qt.Key_Return, Qt.Key_Enter, Qt.Key_Space):
            self.animateClick()
        return super().keyPressEvent(event)


class PlotWidget(QWidget):
    def __init__(self):
        super().__init__()
        palette = QPalette()
        palette.setColor(QPalette.Background, Qt.white)
        self.setAutoFillBackground(True)
        self.setPalette(palette)
        # members
        self.f = None
        self.gridStep = 1
        self.plotColor = Qt.blue
        self.shouldDrawGrid = True

    def getRealX(self, screenX):
        return (screenX - self.width() // 2) / PLOT_ZOOM

    def getRealY(self, screenY):
        return (self.height() // 2 - screenY) / PLOT_ZOOM

    def getScreenX(self, x):
        return self.width() // 2 + round(x * PLOT_ZOOM)

    def getScreenY(self, y):
        return self.height() // 2 - round(y * PLOT_ZOOM)

    def drawGrid(self, painter):
        pen = QPen(Qt.darkGray, 1, Qt.DotLine)
        painter.setPen(pen)
        maxX = -floor(self.getRealX(0))
        for x in range(self.gridStep, maxX + 1, self.gridStep):
            painter.drawLine(self.getScreenX(x), 0, self.getScreenX(x), self.height())
            painter.drawLine(self.getScreenX(-x), 0, self.getScreenX(-x), self.height())
        maxY = ceil(self.getRealY(0))
        for y in range(self.gridStep, maxY + 1, self.gridStep):
            painter.drawLine(0, self.getScreenY(y), self.width(), self.getScreenY(y))
            painter.drawLine(0, self.getScreenY(-y), self.width(), self.getScreenY(-y))

    def drawAxes(self, painter):
        pen = QPen()
        painter.setPen(pen)
        screenX0, screenY0 = self.getScreenX(0), self.getScreenY(0)
        painter.drawLine(screenX0, 0, screenX0, self.height())
        painter.drawLine(0, screenY0, self.width(), screenY0)
        # arrows
        arrowSide = 6
        painter.drawLine(screenX0, 0, screenX0 - arrowSide, arrowSide * 2)
        painter.drawLine(screenX0, 0, screenX0 + arrowSide, arrowSide * 2)
        tempArgs = (self.width() - 1, screenY0, self.width() - arrowSide * 2 - 1)
        painter.drawLine(*tempArgs, screenY0 - arrowSide)
        painter.drawLine(*tempArgs, screenY0 + arrowSide)
        # labels
        offset = 3
        fm = QFontMetrics(QFont())
        painter.drawText(screenX0 + offset, screenY0 - offset, '0')
        painter.drawText(self.getScreenX(1) + offset, screenY0 - offset, '1')
        painter.drawText(screenX0 + offset, self.getScreenY(1) - offset, '1')
        painter.drawText(self.width() - fm.height() - offset, screenY0 - arrowSide - offset, 'x')
        painter.drawText(screenX0 + arrowSide + offset, fm.height() + offset, 'y')
        # marks
        pen = QPen(Qt.black, 3)
        painter.setPen(pen)
        painter.drawPoint(self.getScreenX(1), screenY0)
        painter.drawPoint(screenX0, self.getScreenY(1))

    def drawPlot(self, painter):
        if self.f is None:
            return
        pen = QPen(self.plotColor, 1)
        painter.setPen(pen)
        for screenX1 in range(self.width() - 1):
            x1 = self.getRealX(screenX1)
            x2 = self.getRealX(screenX1 + 1)
            screenY1 = self.getScreenY(self.f(x1))
            screenY2 = self.getScreenY(self.f(x2))
            painter.drawLine(screenX1, screenY1, screenX1 + 1, screenY2)

    def paintEvent(self, _):
        painter = QPainter(self)
        if self.shouldDrawGrid:
            self.drawGrid(painter)
        self.drawAxes(painter)
        self.drawPlot(painter)


def makeExpandable(widget: QWidget):
    widget.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)


class SettingsDialog(QDialog):
    def __init__(self, plotWidget):
        super().__init__()
        layout = QGridLayout()
        layout.setVerticalSpacing(15)
        self.setLayout(layout)

        sliderLayout = QVBoxLayout()
        sliderLabel = QLabel()
        self.updateSliderLabel(sliderLabel, plotWidget.gridStep)
        sliderLabel.setAlignment(Qt.AlignCenter)
        sliderLayout.addWidget(sliderLabel)

        slider = QSlider(Qt.Horizontal)
        slider.setRange(1, 5)
        slider.setSingleStep(1)
        slider.setValue(plotWidget.gridStep)
        slider.valueChanged.connect(lambda: self.updateSliderLabel(sliderLabel, slider.value()))
        sliderLayout.addWidget(slider)

        layout.addLayout(sliderLayout, 0, 0, 1, 2)
        self.initButtons(layout)
        # members
        self.plotWidget = plotWidget
        self.slider = slider
        self.plotColor = plotWidget.plotColor

    def initButtons(self, layout: QGridLayout):
        plotColorButton = Button('Выбор цвета графика')
        plotColorButton.clicked.connect(self.onPlotColorButton)
        makeExpandable(plotColorButton)
        layout.addWidget(plotColorButton, 2, 0, 1, layout.columnCount())

        okButton = Button('ОК')
        okButton.clicked.connect(self.onOkButon)
        layout.addWidget(okButton, 3, 0)

        cancelButton = Button('Отмена')
        cancelButton.clicked.connect(self.close)
        layout.addWidget(cancelButton, 3, 1)

    @staticmethod
    def updateSliderLabel(sliderLabel, value):
        sliderLabel.setText('Шаг сетки: ' + str(value))

    def onPlotColorButton(self):
        color = QColorDialog.getColor(self.plotColor)
        if color.isValid():
            self.plotColor = color

    def onOkButon(self):
        self.plotWidget.plotColor = self.plotColor
        self.plotWidget.gridStep = self.slider.value()
        self.plotWidget.update()
        self.close()

    def showEvent(self, _):
        self.setFixedSize(self.size())


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        centralWidget = QWidget()
        self.setCentralWidget(centralWidget)
        self.setFixedSize(800, 600)
        mainLayout = QVBoxLayout()
        mainLayout.setAlignment(Qt.AlignTop)
        centralWidget.setLayout(mainLayout)
        self.addNonFunctionButtons(mainLayout)
        self.addFunctionButtons(mainLayout)
        # init plotWidget
        plotWidget = PlotWidget()
        makeExpandable(plotWidget)
        mainLayout.addWidget(plotWidget)
        # members
        self.plotWidget = plotWidget

    def addNonFunctionButtons(self, mainLayout):
        subLayout = QHBoxLayout()
        mainLayout.addLayout(subLayout)

        infoButton = Button('Автор')
        infoButton.clicked.connect(self.onInfoButton)
        subLayout.addWidget(infoButton)

        gridButton = Button('Сетка')
        gridButton.clicked.connect(self.onGridButton)
        subLayout.addWidget(gridButton)

        settingsButton = Button('Настройки')
        settingsButton.clicked.connect(self.onSettingsButton)
        subLayout.addWidget(settingsButton)

        exitButton = Button('Выход')
        exitButton.clicked.connect(self.close)
        subLayout.addWidget(exitButton)

    def addFunctionButtons(self, mainLayout):
        subLayout = QHBoxLayout()
        mainLayout.addLayout(subLayout)
        functionTexts = ['x*sin(x)',
                         'abs(x)+cos(x*8)-2',
                         'e^(x/e)-e',
                         'sqrt(abs(x))',
                         'atan(x)*pi']
        for functionText in functionTexts:
            button = Button(functionText)
            subLayout.addWidget(button)
            button.clicked.connect(self.onFunctionButton)

    def onInfoButton(self):
        msgBox = QMessageBox()
        msgBox.setWindowTitle(self.sender().text())
        msgBox.setText('Иван Ершов, 2016.')
        msgBox.exec()

    def onGridButton(self):
        self.plotWidget.shouldDrawGrid ^= True
        self.plotWidget.update()

    def onFunctionButton(self):
        buttonText = self.sender().text()
        buttonText = buttonText.replace('^', '**')
        self.plotWidget.f = lambda x: eval(buttonText)
        self.plotWidget.update()

    def onSettingsButton(self):
        dialog = SettingsDialog(self.plotWidget)
        dialog.exec()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
