#include "ManagementView.h"

ManagementView::ManagementView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ManagementView)
    , _models({
        new PatientTableModel(this),
        new DepartmentTableModel(this),
        new EmployeeTableModel(this),
        new MedicineTableModel(this),
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

    _ui->update_pushButton->setEnabled(0);
    _ui->delete_pushButton->setEnabled(0);

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

                QString title = "Xác nhận thêm nhân viên";
                QString msg = "Bạn có chắc chắn muốn thêm nhân viên?";
                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<EmployeeTableModel*>(model)->add(view.getEmployee());
                }
            }
            else if (modelIndex == ModelType::Department) {
                DepartmentRecordView view(qApp->styleSheet());

                QString title = "Xác nhận thêm khoa";
                QString msg = "Bạn có chắc chắn muốn thêm khoa?";
                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<DepartmentTableModel*>(model)->add(view.getDepartment());
                }
            }
            else if (modelIndex == ModelType::Patient) {
                PatientRecordView view(qApp->styleSheet());

                QString title = "Xác nhận thêm bệnh nhân";
                QString msg = "Bạn có chắc chắn muốn thêm bệnh nhân?";
                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<PatientTableModel*>(model)->add(view.getPatient());
                }
            }
            else if (modelIndex == ModelType::Medicine) {
                MedicineManagementView view(qApp->styleSheet());

                QString title = "Xác nhận thêm thuốc";
                QString msg = "Bạn có chắc chắn muốn thêm thuốc?";
                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<MedicineTableModel*>(model)->add(view.getMedicine());
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
            else if (modelIndex == ModelType::Patient) {
                PatientFilteringView view(qApp->styleSheet());
                if (view.exec() == QDialog::DialogCode::Accepted) {
                    static_cast<PatientTableModel*>(model)->find(view.getFilters());
                }
            }
            else if (modelIndex == ModelType::Medicine) {
                MedicineManagementView view(qApp->styleSheet(), Role::Filter);
                if (view.exec() == QDialog::DialogCode::Accepted) {
                    static_cast<MedicineTableModel*>(model)->find(view.getFilters());
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

                EmployeeRecordView view(qApp->styleSheet(), Role::Update);
                view.setEmployee(employee);

                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<EmployeeTableModel*>(model)->update(*view.getEmployee().get());
                }
            }
            else if (modelIndex == ModelType::Department) {
                auto department = static_cast<const Department*>(model->data(index, Qt::UserRole).value<void*>());

                DepartmentRecordView view(qApp->styleSheet(), Role::Update);
                view.setDepartment(department);

                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<DepartmentTableModel*>(model)->update(*view.getDepartment().get());
                }
            }
            else if (modelIndex == ModelType::Patient) {
                auto patient = static_cast<const Patient*>(model->data(index, Qt::UserRole).value<void*>());

                PatientRecordView view(qApp->styleSheet(), Role::Update);
                view.setPatient(patient);

                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<PatientTableModel*>(model)->update(*view.getPatient().get());
                }
            }
            else if (modelIndex == ModelType::Medicine) {
                auto medicine = static_cast<const Medicine*>(model->data(index, Qt::UserRole).value<void*>());

                MedicineManagementView view(qApp->styleSheet(), Role::Update);
                view.setMedicine(medicine);

                if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                    static_cast<MedicineTableModel*>(model)->update(*view.getMedicine().get());
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
            else if (modelIndex == ModelType::Patient && confirm(title, msg)) {
                static_cast<PatientTableModel*>(model)->removeByIds(ids);
            }
            else if (modelIndex == ModelType::Medicine && confirm(title, msg)) {
                static_cast<MedicineTableModel*>(model)->removeByIds(ids);
            }
        });
}

void ManagementView::changeModel(ModelType model) {
    if (auto currentModel = _ui->tableView->model()) {
        disconnect(currentModel, &QAbstractItemModel::modelReset, this, nullptr);
    }

    _ui->tableView->setModel(_models[(int)model]);
    static_cast<TableModel*>(_ui->tableView->model())->refresh();

    _ui->update_pushButton->setEnabled(0);
    _ui->delete_pushButton->setEnabled(0);

    static QVector<QString> titles = {
        "QUẢN LÝ BỆNH NHÂN",
        "QUẢN LÝ KHOA",
        "QUẢN LÝ NHÂN VIÊN",
        "KHO THUỐC",
    };
    _ui->title_label->setText(titles[(int)model]);

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
            _ui->update_pushButton->setEnabled(selectedRows.count() == 1);
            _ui->delete_pushButton->setEnabled(selectedRows.count());
        });

    connect(_ui->tableView->model(), &QAbstractItemModel::modelReset, this,
        [this]() {
            _ui->update_pushButton->setEnabled(0);
            _ui->delete_pushButton->setEnabled(0);
        });
}
