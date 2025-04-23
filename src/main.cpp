#include <iostream>
#include "utils/Time.h"
#include "utils/Date.h"
#include "models/Medicine.h"
using std::endl;
using std::cout;
int main() {
    Medicine md1 = Medicine("M001", "Paracetamol", "Tablet", 100, 50.0, 30, 12, 2025);
    Medicine md2 = Medicine("M002", "Ibuprofen", "Tablet", 200, 75.0);
    Medicine md3 = Medicine("M003", "Aspirin", "Tablet", 150, 30.0, "31/12/2024");
    Medicine md4 = Medicine("M004", "Amoxicillin", "Capsule", 50, 120.0, Date::getDate());
    Medicine md5 = Medicine("M005", "Cough Syrup", "Liquid", 75, 25.0, 15);
    Medicine md6 = Medicine("M006", "Vitamin C", "Tablet", 300, 10.0, Date(15, 5, 2023));
    md1.getMedicineDetail();
    cout<<endl;
    md2.getMedicineDetail();
    cout<<endl;
    md3.getMedicineDetail();
    cout<<endl;
    md4.getMedicineDetail();
    cout<<endl;
    md5.getMedicineDetail();
    cout<<endl;
    md6.getMedicineDetail();
    return 0;
}
