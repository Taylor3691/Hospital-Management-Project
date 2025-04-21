#include <iostream>
#include "utils/Time.h"

int main() {
    // Test different constructors
    std::cout << "Testing constructors:\n";
    Time t1;  // Default constructor
    Time t2(3661);  // Seconds constructor (1h 1m 1s)
    Time t3(1, 1);  // Minutes, seconds constructor
    Time t4(1, 1, 1);  // Hours, minutes, seconds constructor
    Time t5("02:30:45");  // String constructor

    std::cout << "t1 (default): " << t1.toString() << "\n";
    std::cout << "t2 (3661s): " << t2.toString() << "\n";
    std::cout << "t3 (1m 1s): " << t3.toString() << "\n";
    std::cout << "t4 (1h 1m 1s): " << t4.toString() << "\n";
    std::cout << "t5 (02:30:45): " << t5.toString() << "\n\n";

    // Test static methods
    std::cout << "Testing static methods:\n";
    std::cout << "toString(3661): " << Time::toString(3661) << "\n";
    std::cout << "toSec(01:01:01): " << Time::toSec("01:01:01") << "\n";
    std::cout << "Current time: " << Time::getCurrentTime().toString() << "\n\n";

    // Test comparison operator
    std::cout << "Testing comparison operator:\n";
    Time earlier(1, 0, 0);
    Time later(2, 0, 0);
    std::cout << "1:00:00 < 2:00:00: " << (earlier < later) << "\n";
    std::cout << "2:00:00 < 1:00:00: " << (later < earlier) << "\n\n";

    // Test subtraction operator
    std::cout << "Testing subtraction operator:\n";
    try {
        int diff = later - earlier;
        std::cout << "2:00:00 - 1:00:00 = " << diff << " seconds\n";
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    try {
        int diff = earlier - later;  // This should throw an exception
        std::cout << "1:00:00 - 2:00:00 = " << diff << " seconds\n";
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
