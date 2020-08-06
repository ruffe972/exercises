#include "unsavedchangesdialog.h"

#include "ui_unsavedchangesdialog.h"
#include <QDebug>

UnsavedChangesDialog::UnsavedChangesDialog(QWidget *parent) :
        QDialog(parent),
        _ui(new Ui::UnsavedChangesDialog) {
    _ui->setupUi(this);
    setFixedSize(minimumSizeHint());

    connect(_ui->cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    connect(_ui->noSaveButton, &QAbstractButton::clicked, this, [=]() {
        _result = ChangesDialogCode::AcceptedWithoutSaving;
        accept();
    });

    connect(_ui->saveButton, &QAbstractButton::clicked, this, [=]() {
        _result = ChangesDialogCode::AcceptedWithSaving;
        accept();
    });
}

UnsavedChangesDialog::~UnsavedChangesDialog() {
    delete _ui;
}

ChangesDialogCode UnsavedChangesDialog::customExec() {
    if (QDialog::exec() == QDialog::Rejected) {
        return ChangesDialogCode::Rejected;
    }
    return _result;
}
