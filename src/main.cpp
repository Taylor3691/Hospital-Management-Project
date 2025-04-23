#include <iostream>

#include "models/Doctor.h"
#include "models/Shift.h"
#include "models/Assignment.h"

int main() {
    Doctor* d1 = new Doctor("DR01", "Nam", Date(), Department(), Date(), "");
    Doctor* d2 = new Doctor("DR02", "Linh", Date(), Department(), Date(), "");

    Shift* s1 = new Shift("SF01", Date("2025-04-20"), "08:00 - 12:00");
    Shift* s2 = new Shift("SF02", Date("2025-04-21"), "20:00 - 00:00");
    Shift* s3 = new Shift("SF03", Date("2025-04-30"), "14:00 - 18:00");

    Assignment* a1 = new Assignment(d1, s1);
    Assignment* a2 = new Assignment(d1, s2, true);
    Assignment* a3 = new Assignment(d2, s1);
    Assignment* a4 = new Assignment(d2, s3, false, true);

    // Hiển thị
    d1->showShifts();

    d2->showShifts();

    s1->showEmployees();

    s2->showEmployees();
}
