#include "utils.h"

bool confirm(const QString& title, const QString& msg) {
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

void notify(const QString& title, const QString& msg) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(msg);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void pad(QHeaderView* view, int padSize) {
    view->setSectionResizeMode(QHeaderView::ResizeToContents);
    QString headerText;
    for (int i = 0; i < view->count(); ++i) {
        headerText = view->model()
            ->headerData(i, view->orientation(), Qt::DisplayRole).toString();
        if (headerText.size()) {
            int width = view->sectionSize(i);
            view->setSectionResizeMode(i, QHeaderView::Interactive);
            view->resizeSection(i, width + padSize);
        }
    }
}

std::string createId(
    const std::vector<const Object*>& list,
    const std::string& format,
    int startAt
) {
    if (list.empty()) {
        int required = snprintf(nullptr, 0, format.c_str(), startAt) + 1;
        std::string newId;
        newId.resize(required);
        sprintf_s(newId.data(), newId.size(), format.c_str(), startAt);
        return newId;
    }

    std::vector<int> nums;
    nums.reserve(list.size());

    for (const auto& item : list) {
        int num;
        if (!sscanf_s(item->id().c_str(), format.c_str(), &num)) {
            continue;
        }
        nums.push_back(num);
    }

    std::sort(nums.begin(), nums.end());

    int prev = startAt - 1;
    for (int cur : nums) {
        if (cur - prev > 1) {
            break;
        }
        prev = cur;
    }

    int required = snprintf(nullptr, 0, format.c_str(), prev + 1) + 1;
    std::string newId;
    newId.resize(required);
    sprintf_s(newId.data(), newId.size(), format.c_str(), prev + 1);
    return newId;
}
