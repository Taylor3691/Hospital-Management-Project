#ifndef UTILS_H
#define UTILS_H

#include <cstdio>
#include <vector>
#include <algorithm>
#include <QString>
#include <QMessageBox>
#include <QPushButton>
#include <QHeaderView>
#include "../models/Object.h"

enum class Role {
    Add,
    Update,
    Filter,
};

bool confirm(const QString& title, const QString& msg);
void notify(const QString& title, const QString& msg,
    QMessageBox::Icon icon = QMessageBox::Information);
void pad(QHeaderView* view, int padSize = 20);
std::string createId(const std::vector<const Object*>& list,
    const std::string& format, int startAt = 1);

#endif // !UTILS_H
