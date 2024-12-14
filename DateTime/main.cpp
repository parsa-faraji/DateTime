#include "Date.hpp"
#include "Time.hpp"
#include "DateTime.hpp"
#include <iostream>

int main() {
    
    // object initialization
    Date date1(2024, 12, 13);
    Date date2(2024, 11, 15);

    Time time1(23, 30, 0);
    Time time2(12, 15, 45);

    DateTime dt1(date1, time1);
    DateTime dt2(date2, time2);

    std::cout << "Date difference: " << dt1.totalDaysDifference(dt2) << " days\n";
    std::cout << "Time difference: " << dt1.totalSecondsDifference(dt2) << " seconds\n";

    std::cout << dt1.format("Today is YYYY-MM-DD, and the time is HH:MM:SS") << std::endl;

    return 0;
}
