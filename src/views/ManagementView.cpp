#include "ManagementView.h"

ManagementView::ManagementView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ManagementView)
    , _models({
        new EmployeeTableModel(
            {
                "ID",
                "Tên",
                "Ngày sinh",
                "Giới tính",
                "Điện thoại",
                "Địa chỉ",
                "Học vị",
                "Lương cơ bản",
            },
            {
                new Employee("BS-001", "Nguyen Van An", Date("01/01/1999"), "Nam", "Ho Chi Minh", "0123456789", "Tien Si Y Hoc", 4000000),
                new Employee("BS-002", "Tran Thi Lan", Date("15/03/1985"), "Nu", "Da Nang", "0912345678", "Tien Si Y Hoc", 5000000),
            },
            this
        ),
    })
{
    _ui->setupUi(this);
}

ManagementView::~ManagementView() {
    delete _ui;
}

void ManagementView::changeModel(Model model) {
    _ui->tableView->setModel(_models[(int)Model::Patient]); // Just a placeholder
    switch (model) {
    case Model::Patient:
        _ui->add_pushButton->setText("Thêm bệnh nhân");
        _ui->delete_pushButton->setText("Xóa bệnh nhân");
        break;
    case Model::Department:
        _ui->add_pushButton->setText("Thêm khoa");
        _ui->delete_pushButton->setText("Xóa khoa");
        break;
    case Model::Employee:
        _ui->add_pushButton->setText("Thêm nhân viên");
        _ui->delete_pushButton->setText("Xóa nhân viên");
        break;
    }
}
