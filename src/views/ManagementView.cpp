#include "ManagementView.h"

ManagementView::ManagementView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ManagementView)
    , _models({
        nullptr,
        nullptr,
        new EmployeeTableModel(this),
    })
{
    setup();
    setConnections();
}

ManagementView::~ManagementView() {
    delete _ui;
}

void ManagementView::setup() {
    _ui->setupUi(this);

    _ui->update_pushButton->setVisible(0);
    _ui->delete_pushButton->setVisible(0);

    _ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void ManagementView::setConnections() {
    connect(_ui->add_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            auto model = _ui->tableView->model();
            auto index = (ModelType)_models.indexOf(qobject_cast<QAbstractTableModel*>(model), 0);
            if (index == ModelType::Employee) {
                EmployeeRecordView view(qApp->styleSheet());
                view.setWindowTitle("Thêm nhân viên");
                view.setAcceptButtonText("Thêm");

                if (view.exec() == QDialog::DialogCode::Accepted) {
                    static_cast<EmployeeTableModel*>(model)->add(view.getEmployee());
                }
            }
        });

    connect(_ui->update_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            auto index = _ui->tableView->selectionModel()->selectedRows()[0];
            auto model = _ui->tableView->model();

            auto modelIndex = (ModelType)_models.indexOf(qobject_cast<QAbstractTableModel*>(model), 0);
            if (modelIndex == ModelType::Employee) {
                auto employee = static_cast<const Employee*>(model->data(index, Qt::UserRole).value<void*>());

                EmployeeRecordView view(qApp->styleSheet());
                view.setWindowTitle("Cập nhật thông tin");
                view.setAcceptButtonText("Lưu");
                view.setEmployee(employee);
                view.disableNotEditableFields();

                if (view.exec() == QDialog::DialogCode::Accepted) {
                    static_cast<EmployeeTableModel*>(model)->update(*view.getEmployee().get());
                }
            }
            else if (modelIndex == ModelType::Department) {

            }
            else {

            }
        });

    connect(_ui->delete_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            std::vector<std::string> ids;
            auto model = _ui->tableView->model();
            for (const auto& index : _ui->tableView->selectionModel()->selectedRows()) {
                auto obj = static_cast<const Object*>(model->data(index, Qt::UserRole).value<void*>());
                ids.push_back(obj->id());
            }
            static_cast<EmployeeTableModel*>(model)->removeByIds(ids);
        });
}

void ManagementView::changeModel(ModelType model) {
    if (auto currentModel = _ui->tableView->model()) {
        disconnect(currentModel, &QAbstractItemModel::dataChanged, this, nullptr);
    }

    _ui->tableView->setModel(_models[(int)model]);
    _ui->update_pushButton->setVisible(0);
    _ui->delete_pushButton->setVisible(0);

    connect(_ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this,
        [this](const QItemSelection&, const QItemSelection&) {
            QModelIndexList selectedRows = _ui->tableView->selectionModel()->selectedRows();
            _ui->update_pushButton->setVisible(selectedRows.count() == 1);
            _ui->delete_pushButton->setVisible(selectedRows.count());
        });

    connect(_ui->tableView->model(), &QAbstractItemModel::modelReset, this,
        [this]() {
            _ui->update_pushButton->setVisible(0);
            _ui->delete_pushButton->setVisible(0);
        });
}
