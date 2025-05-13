#include "TxtEmployeeRepository.h"

TxtEmployeeRepository::TxtEmployeeRepository()
    : TxtEmployeeRepository("doctors.txt",
        "nurses.txt", "receptionists.txt") {}

TxtEmployeeRepository::TxtEmployeeRepository(
    const std::string& doctorFile,
    const std::string& nurseFile,
    const std::string& receptionistFile,
    char delim
) : _doctorFile(doctorFile), _nurseFile(nurseFile),
    _receptionistFile(receptionistFile), _delim(delim) {}

void TxtEmployeeRepository::serialize(
    std::ofstream& file, const Employee* employee
) {
    file << employee->id() << "|"
        << employee->name() << "|"
        << employee->dob() << "|"
        << employee->gender() << "|"
        << employee->phone() << "|"
        << employee->address() << "|"
        << employee->education() << "|"
        << std::to_string(employee->baseSalary());
}

void TxtEmployeeRepository::serialize(
    std::ofstream& file, const Doctor* doctor
) {
    serialize(file, static_cast<const Employee*>(doctor));

    file << "|" << doctor->specialty() << "|"
        << doctor->license();
}

void TxtEmployeeRepository::serialize(
    std::ofstream& file, const Nurse* nurse
) {
    serialize(file, static_cast<const Employee*>(nurse));

    file << "|" << nurse->duty();
}

void TxtEmployeeRepository::serialize(
    std::ofstream& file, const Receptionist* receptionist
) {
    serialize(file, static_cast<const Employee*>(receptionist));

    file << "|" << std::to_string(receptionist->subsidies()) << "|"
        << std::to_string(receptionist->workingDays());
}

void TxtEmployeeRepository::deserialize(
    std::ifstream& file, Employee* employee, std::string& buffer
) {
    employee->setId(buffer);

    std::getline(file, buffer, '|');
    employee->setName(buffer);

    std::getline(file, buffer, '|');
    employee->setDob(buffer);

    std::getline(file, buffer, '|');
    employee->setGender(buffer);

    std::getline(file, buffer, '|');
    employee->setPhone(buffer);

    std::getline(file, buffer, '|');
    employee->setAddress(buffer);

    std::getline(file, buffer, '|');
    employee->setEducation(buffer);

    std::getline(file, buffer, '|');
    employee->setBaseSalary(stod(buffer));
}

void TxtEmployeeRepository::deserialize(
    std::ifstream& file, Doctor* doctor, std::string& buffer
) {
    deserialize(file, static_cast<Employee*>(doctor), buffer);

    std::getline(file, buffer, '|');
    doctor->setSpecialty(buffer);

    std::getline(file, buffer);
    doctor->setLicense(buffer);
}

void TxtEmployeeRepository::deserialize(
    std::ifstream& file, Nurse* nurse, std::string& buffer
) {
    deserialize(file, static_cast<Employee*>(nurse), buffer);

    std::getline(file, buffer);
    nurse->setDuty(buffer);
}

void TxtEmployeeRepository::deserialize(
    std::ifstream& file, Receptionist* receptionist, std::string& buffer
) {
    deserialize(file, static_cast<Employee*>(receptionist), buffer);

    std::getline(file, buffer, '|');
    receptionist->setSubsidies(stod(buffer));

    std::getline(file, buffer);
    receptionist->setWorkingDays(stoi(buffer));
}

void TxtEmployeeRepository::load() {
    _employees.clear();
    load<Doctor>(_doctorFile, "Cannot open doctor file for reading");
    load<Nurse>(_nurseFile, "Cannot open nurse file for reading");
    load<Receptionist>(_receptionistFile, "Cannot open receptionist file for reading");
}

void TxtEmployeeRepository::save() const {
    std::ofstream fd(_doctorFile, std::ios::trunc);
    if (!fd.is_open()) {
        throw std::runtime_error("Cannot open doctor file for writing");
    }

    std::ofstream fn(_nurseFile, std::ios::trunc);
    if (!fn.is_open()) {
        fd.close();
        throw std::runtime_error("Cannot open nurse file for writing");
    }

    std::ofstream fr(_receptionistFile, std::ios::trunc);
    if (!fr.is_open()) {
        fd.close();
        fn.close();
        throw std::runtime_error("Cannot open receptionist file for writing");
    }

    for (const auto& employee : _employees) {
        if (auto doctor = dynamic_cast<Doctor*>(employee.get())) {
            serialize(fd, doctor);
            fd << "\n";
        }
        else if (auto nurse = dynamic_cast<Nurse*>(employee.get())) {
            serialize(fn, nurse);
            fn << "\n";
        }
        else if (auto receptionist = dynamic_cast<Receptionist*>(employee.get())) {
            serialize(fr, receptionist);
            fr << "\n";
        }
    }

    fd.close();
    fn.close();
    fr.close();
}

void TxtEmployeeRepository::add(std::unique_ptr<Employee> employee) {
    _employees.push_back(std::move(employee));
    save();
}

void TxtEmployeeRepository::removeById(const std::string& id) {
    from(_employees).where(&Employee::id, id).deleteOne();
    save();
}

void TxtEmployeeRepository::update(const Employee& employee) {
    auto ptr = from(_employees)
        .where(&Employee::id, employee.id()).findOne();
    if (ptr) {
        *ptr = employee;
    }
    save();
}

std::vector<const Employee*> TxtEmployeeRepository::data() const {
    std::vector<const Employee*> result;
    result.reserve(_employees.size());
    for (const auto& emp : _employees) {
        result.push_back(emp.get());
    }
    return result;
}
