//#include "App.h"
#include "models/TxtParserFactory.h"


int main(int argc, char* argv[]) {
    //App app(argc, argv);
    //return app.run();
    std::string record = "HS-001|Hoàng Ngọc|BN-001|PHG-001|BS-001|2|MEUSE-001,Amoxicillin Delayed Release,ME-009,3000.00,10,Uống 1 ngày 2 lần sau bữa|MEUSE-002,Ibuprofen SR,ME-011,2000.00,10,Uống 2 ngày 1 lần|2|CLSUSE-001,Chụp XQuang bàn tay oblique,CLS-087,90000.00,Sắp chết,1|CLSUSE-002,Chụp XQuang cẳng chân AP/Lateral,CLS-088,105000.00,nghiêm trọng,0|Ngã xe đa chấn thương chỉnh hình|12/12/2000|12:12:00|WaitingState";
    IParser* parse = new TxtMedicalRecordParser();
    std::stringstream os;
    MedicalRecord* sample = dynamic_cast<MedicalRecord*>(parse->parse(record));
    IWritingVisitor* visitor = new TxtWritingVisitor();
    sample->acceptWrite(visitor, std::cout);

    std::cout << std::endl;
    std::cout << "___________________" << std::endl;
    sample->acceptWrite(visitor, os);
    std::cout << os.str();
    std::cout << std::endl;
    std::cout << os.str().size() << std::endl;
    std::cout << "___________________" << std::endl;
    for (int i = 0; i < os.str().size(); i++) {
        if (os.str()[i] != record[i]) {
            std::cout << "dkjashjk " << i << std::endl;
        }
    }
}
