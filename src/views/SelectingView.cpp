#include "SelectingView.h"

SelectingView::SelectingView(QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::SelectingView)
{
    _ui->setupUi(this);

    setStyleSheet("");

    connect(_ui->close_pushButton, &QPushButton::clicked, this, &QDialog::close);
}

SelectingView::~SelectingView() {
    delete _ui;
}

void SelectingView::setModel(SelectableTableModel* model) {
    disconnect(_ui->selectAll_pushButton, &QPushButton::clicked, nullptr, nullptr);
    disconnect(_ui->clearAll_pushButton, &QPushButton::clicked, nullptr, nullptr);

    _ui->tableView->setModel(model);
    pad(_ui->tableView->horizontalHeader());

    connect(
        _ui->selectAll_pushButton, &QPushButton::clicked,
        static_cast<SelectableTableModel*>(_ui->tableView->model()),
        &SelectableTableModel::selectAll
    );

    connect(
        _ui->clearAll_pushButton, &QPushButton::clicked,
        static_cast<SelectableTableModel*>(_ui->tableView->model()),
        &SelectableTableModel::clearAll
    );
}
