#pragma once

#include <QMainWindow>

class QSyntaxHighlighter;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initMenu();
    void newFile();
    void openFile();

    /// Returns true on successful save operation.
    /// Calls "Save As" dialog if the file being edited is not present on disk.
    bool saveNewOrExistingFile();

    /// Returns true on successful save operation.
    /// name is a full file name with its path.
    /// Shows error message if something goes wrong.
    bool saveFile(const QString &name);

    /// Returns true on successful save operation.
    /// For example, closing the dialog will result in this function returning false.
    bool saveFileAs();

    /// Notify the user about unsaved changes in the current file if there are any.
    /// Returns true if there were no pending changes.
    /// Also returns true if these changes are successfully saved.
    /// Returns false otherwise. For example, if there was an error while saving a file.
    bool handleUnsavedChanges();

    void updateWindowTitle();
    void setFileName(const QString &fileName);
    void closeEvent(QCloseEvent *event) override;

    void changeFont(int pixelSize);

private:
    Ui::MainWindow *_ui;

    /// Full path of the file being edited. Empty if not saved on disk yet.
    QString _fileName = "";

    QSyntaxHighlighter *_highlighter = nullptr;
};
