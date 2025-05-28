//#include "App.h"
#include "models/TxtParserFactory.h"
#include "models/TxtMedicineRepository.h"

int main(int argc, char* argv[]) {
    //App app(argc, argv);
    //return app.run();
    IMedicineRepository* repo = new TxtMedicineRepository("../database/medicines.txt",'|');
    std::cout << repo->data().size();
}
