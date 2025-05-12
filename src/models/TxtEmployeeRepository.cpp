#include "TxtEmployeeRepository.h"

TxtEmployeeRepository::TxtEmployeeRepository()
    : _doctorFile("doctors.txt"), _nurseFile("nurses.txt"),
    _receptionistFile("receptionist.txt") {}

TxtEmployeeRepository::TxtEmployeeRepository(
    const std::string& doctorFile,
    const std::string& nurseFile,
    const std::string& receptionistFile
) : _doctorFile(doctorFile), _nurseFile(nurseFile),
    _receptionistFile(receptionistFile) {}

void TxtEmployeeRepository::load() {  
   std::string buffer;  

   std::ifstream fd(_doctorFile);
   if (!fd.is_open()) {  
       throw std::runtime_error("Cannot open doctor file for reading");
   }

   while (std::getline(fd, buffer, '|')) {
       auto doctor = std::make_unique<Doctor>();
       doctor->setId(buffer);

       std::getline(fd, buffer, '|');
       doctor->setName(buffer);

       std::getline(fd, buffer, '|');
       doctor->setDob(buffer);

       std::getline(fd, buffer, '|');
       doctor->setGender(buffer);

       std::getline(fd, buffer, '|');
       doctor->setPhone(buffer);

       std::getline(fd, buffer, '|');
       doctor->setAddress(buffer);

       std::getline(fd, buffer, '|');
       doctor->setEducation(buffer);

       std::getline(fd, buffer, '|');
       doctor->setBaseSalary(stod(buffer));

       std::getline(fd, buffer, '|');
       doctor->setSpecialty(buffer);

       std::getline(fd, buffer);
       doctor->setLicense(buffer);

       _employees.push_back(std::move(doctor));
   }
   fd.close();

   std::ifstream fn(_nurseFile);
   if (!fn.is_open()) {
       throw std::runtime_error("Cannot open nurse file for reading");
   }

   while (std::getline(fn, buffer, '|')) {
       auto nurse = std::make_unique<Nurse>();
       nurse->setId(buffer);

       std::getline(fn, buffer, '|');
       nurse->setName(buffer);

       std::getline(fn, buffer, '|');
       nurse->setDob(buffer);

       std::getline(fn, buffer, '|');
       nurse->setGender(buffer);

       std::getline(fn, buffer, '|');
       nurse->setPhone(buffer);

       std::getline(fn, buffer, '|');
       nurse->setAddress(buffer);

       std::getline(fn, buffer, '|');
       nurse->setEducation(buffer);

       std::getline(fn, buffer, '|');
       nurse->setBaseSalary(stod(buffer));

       std::getline(fn, buffer);
       nurse->setDuty(buffer);

       _employees.push_back(std::move(nurse));
   }
   fn.close();

   std::ifstream fr(_receptionistFile);
   if (!fr.is_open()) {
       throw std::runtime_error("Cannot open receptionist file for reading");
   }

   while (std::getline(fr, buffer, '|')) {
       auto receptionist = std::make_unique<Receptionist>();
       receptionist->setId(buffer);

       std::getline(fr, buffer, '|');
       receptionist->setName(buffer);

       std::getline(fr, buffer, '|');
       receptionist->setDob(buffer);

       std::getline(fr, buffer, '|');
       receptionist->setGender(buffer);

       std::getline(fr, buffer, '|');
       receptionist->setPhone(buffer);

       std::getline(fr, buffer, '|');
       receptionist->setAddress(buffer);

       std::getline(fr, buffer, '|');
       receptionist->setEducation(buffer);

       std::getline(fr, buffer, '|');
       receptionist->setBaseSalary(stod(buffer));

       std::getline(fr, buffer, '|');
       receptionist->setSubsidies(stod(buffer));

       std::getline(fr, buffer);
       receptionist->setWorkingDays(stoi(buffer));

       _employees.push_back(std::move(receptionist));
   }
   fr.close();
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
            fd << doctor->id().c_str() << "|"
                << doctor->name().c_str() << "|"
                << doctor->dob() << "|"
                << doctor->gender().c_str() << "|"
                << doctor->phone().c_str() << "|"
                << doctor->address().c_str() << "|"
                << doctor->education().c_str() << "|"
                << std::to_string(doctor->baseSalary()).c_str() << "|"
                << doctor->specialty().c_str() << "|"
                << doctor->license().c_str() << "\n";
        }
        else if (auto nurse = dynamic_cast<Nurse*>(employee.get())) {
            fn << nurse->id().c_str() << "|"
                << nurse->name().c_str() << "|"
                << nurse->dob() << "|"
                << nurse->gender().c_str() << "|"
                << nurse->phone().c_str() << "|"
                << nurse->address().c_str() << "|"
                << nurse->education().c_str() << "|"
                << std::to_string(nurse->baseSalary()).c_str() << "|"
                << nurse->duty().c_str() << "\n";
        }
        else if (auto receptionist = dynamic_cast<Receptionist*>(employee.get())) {
            fr << receptionist->id().c_str() << "|"
                << receptionist->name().c_str() << "|"
                << receptionist->dob() << "|"
                << receptionist->gender().c_str() << "|"
                << receptionist->phone().c_str() << "|"
                << receptionist->address().c_str() << "|"
                << receptionist->education().c_str() << "|"
                << std::to_string(receptionist->baseSalary()).c_str() << "|"
                << std::to_string(receptionist->subsidies()).c_str() << "|"
                << std::to_string(receptionist->workingDays()).c_str() << "\n";
        }
    }

    fd.close();
    fn.close();
    fr.close();
}

void TxtEmployeeRepository::add(std::unique_ptr<Employee> employee) {
    _employees.push_back(std::move(employee));
}

void TxtEmployeeRepository::removeById(const std::string& id) {
    from(_employees).where(&Employee::id, id).deleteOne();
}

void TxtEmployeeRepository::update(const Employee& employee) {
    auto ptr = from(_employees).where(&Employee::id, employee.id()).findOne();

    if (ptr) {
        *ptr = employee;
    }
}

std::vector<const Employee*> TxtEmployeeRepository::findAll() const {
    return std::vector<const Employee*>(_employees.begin(), _employees.end());
}
