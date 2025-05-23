#include "utils.h"

bool confirm(const QString& title, const QString msg) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(msg);
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.button(QMessageBox::Yes)->setText("Có");
    msgBox.button(QMessageBox::No)->setText("Không");
    return msgBox.exec() == QMessageBox::Yes;
}
