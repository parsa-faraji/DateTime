// datetime.h
#ifndef DATETIME_H
#define DATETIME_H

#include "Date.hpp"
#include "Time.hpp"
#include <string>

class DateTime {
public:
    // constructor
    DateTime(const Date& date, const Time& time);

    // method declarations
    int totalDaysDifference(const DateTime& other) const;
    int totalSecondsDifference(const DateTime& other) const;

    std::string format(const std::string& formatString) const;

private:
    Date date;
    Time time;
};

#endif // DATETIME_H
