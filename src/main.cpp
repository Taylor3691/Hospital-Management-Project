#include <iostream>
#include "utils/Time.h"
#include "utils/Date.h"
int main() {
    // Test Date class
    Date date1(367, 10, 2024);
    std::cout << date1;
    Date date2("50/12/2025");
    std::cout << date2;

    return 0;
}
