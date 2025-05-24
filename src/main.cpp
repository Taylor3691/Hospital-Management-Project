#include "TxtDoctorParser.h"
#include "TxtPatientRepository.h"
#include <filesystem>

int main() {
    std::string filePath = "patient_temp_repo.txt";
    std::ofstream os(filePath, std::ios::trunc);
    os << "BN-001|Nguyen Van Anh Kiet|Nam|Ha Noi|0329886393|20/05/1985|HI123456,01/01/2020,01/01/2025,80|Sot,Ho Khan,Kho tho";
    os.close();
    TxtPatientRepository repo(filePath, '|');
    std::cout<<repo.data().size();
   std::filesystem::remove(filePath);
}
