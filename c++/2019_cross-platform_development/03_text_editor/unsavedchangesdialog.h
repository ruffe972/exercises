#pragma once

#include <QDialog>

namespace Ui {
class UnsavedChangesDialog;
}

enum class ChangesDialogCode {
    Rejected,
    AcceptedWithSaving,
    AcceptedWithoutSaving
};

class UnsavedChangesDialog : public QDialog {
    Q_OBJECT

public:
    explicit UnsavedChangesDialog(QWidget *parent = 0);
    ~UnsavedChangesDialog();
    ChangesDialogCode customExec();

private:
    Ui::UnsavedChangesDialog *_ui;
    ChangesDialogCode _result = ChangesDialogCode::Rejected;
};
