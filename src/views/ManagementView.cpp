#include "ManagementView.h"

ManagementView::ManagementView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ManagementView)
    , _models({
        new PatientTableModel(this),
        new DepartmentTableModel(this),
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
    _ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section { padding-right: 10px; }");
}

void ManagementView::setConnections() {
    connect(_ui->add_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            auto model = _ui->tableView->model();
            auto modelIndex = (ModelType)_models.indexOf(qobject_cast<QAbstractTableModel*>(model), 0);
            if (modelIndex == ModelType::Employee) {
                EmployeeRecordView view(qApp->styleSheet());
                view.setWindowTitle("Thêm nhân viên");
                view.setAcceptButtonText("Thêm");

                QString title = "Xác nhận thêm nhân viên";
                QString msg = "Bạn có chắc chắn muốn thêm nhân viên?";
                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<EmployeeTableModel*>(model)->add(view.getEmployee());
                }
            }
            else if (modelIndex == ModelType::Department) {
                DepartmentRecordView view(qApp->styleSheet());
                view.setWindowTitle("Thêm nhân viên");
                view.setAcceptButtonText("Thêm");

                QString title = "Xác nhận thêm nhân viên";
                QString msg = "Bạn có chắc chắn muốn thêm nhân viên?";
                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<DepartmentTableModel*>(model)->add(view.getDepartment());
                }
            }
            else {
                PatientRecordView view(qApp->styleSheet());
                view.setWindowTitle("Thêm nhân viên");
                view.setAcceptButtonText("Thêm");

                QString title = "Xác nhận thêm nhân viên";
                QString msg = "Bạn có chắc chắn muốn thêm nhân viên?";
                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<PatientTableModel*>(model)->add(view.getPatient());
                }
            }
        });

    connect(_ui->find_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            auto model = _ui->tableView->model();
            auto modelIndex = (ModelType)_models.indexOf(qobject_cast<QAbstractTableModel*>(model), 0);
            if (modelIndex == ModelType::Employee) {
                EmployeeFilteringView view(qApp->styleSheet());
                if (view.exec() == QDialog::DialogCode::Accepted) {
                    static_cast<EmployeeTableModel*>(model)->find(view.getFilters());
                }
            }
            else if (modelIndex == ModelType::Department) {
                DepartmentFilteringView view(qApp->styleSheet());
                if (view.exec() == QDialog::DialogCode::Accepted) {
                    static_cast<DepartmentTableModel*>(model)->find(view.getFilters());
                }
            }
            else {
                PatientFilteringView view(qApp->styleSheet());
                if (view.exec() == QDialog::DialogCode::Accepted) {
                    static_cast<PatientTableModel*>(model)->find(view.getFilters());
                }
            }
        });

    connect(_ui->update_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            auto index = _ui->tableView->selectionModel()->selectedRows()[0];
            auto model = _ui->tableView->model();

            QString title = "Xác nhận cập nhật thông tin";
            QString msg = "Bạn có chắc chắn muốn lưu những cập nhật?";
            auto modelIndex = (ModelType)_models.indexOf(qobject_cast<QAbstractTableModel*>(model), 0);
            if (modelIndex == ModelType::Employee) {
                auto employee = static_cast<const Employee*>(model->data(index, Qt::UserRole).value<void*>());

                EmployeeRecordView view(qApp->styleSheet());
                view.setWindowTitle("Cập nhật thông tin");
                view.setAcceptButtonText("Lưu");
                view.setEmployee(employee);
                view.disableNotEditableFields();

                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<EmployeeTableModel*>(model)->update(*view.getEmployee().get());
                }
            }
            else if (modelIndex == ModelType::Department) {
                auto department = static_cast<const Department*>(model->data(index, Qt::UserRole).value<void*>());

                DepartmentRecordView view(qApp->styleSheet());
                view.setWindowTitle("Cập nhật thông tin");
                view.setAcceptButtonText("Lưu");
                view.setDepartment(department);
                view.disableNotEditableFields();

                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<DepartmentTableModel*>(model)->update(*view.getDepartment().get());
                }
            }
            else {
                auto patient = static_cast<const Patient*>(model->data(index, Qt::UserRole).value<void*>());

                PatientRecordView view(qApp->styleSheet());
                view.setWindowTitle("Cập nhật thông tin");
                view.setAcceptButtonText("Lưu");
                view.setPatient(patient);
                view.disableNotEditableFields();

                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<PatientTableModel*>(model)->update(*view.getPatient().get());
                }
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

            QString title = "Xác nhận xóa";
            QString msg = "Bạn có chắc chắn muốn xóa những dòng đã chọn?";
            auto modelIndex = (ModelType)_models.indexOf(qobject_cast<QAbstractTableModel*>(model), 0);
            if (modelIndex == ModelType::Employee && confirm(title, msg)) {
                static_cast<EmployeeTableModel*>(model)->removeByIds(ids);
            }
            else if (modelIndex == ModelType::Department && confirm(title, msg)) {
                static_cast<DepartmentTableModel*>(model)->removeByIds(ids);
            }
            else if (confirm(title, msg)) {
                static_cast<PatientTableModel*>(model)->removeByIds(ids);
            }
        });
}

void ManagementView::changeModel(ModelType model) {
    if (auto currentModel = _ui->tableView->model()) {
        disconnect(currentModel, &QAbstractItemModel::dataChanged, this, nullptr);
    }

    _ui->tableView->setModel(_models[(int)model]);
    _ui->update_pushButton->setVisible(0);
    _ui->delete_pushButton->setVisible(0);

    _ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    auto header = _ui->tableView->horizontalHeader();
    for (int i = 0; i < header->count(); ++i) {
        int width = header->sectionSize(i);
        header->setSectionResizeMode(i, QHeaderView::Interactive);
        header->resizeSection(i, width + 20);
    }

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
