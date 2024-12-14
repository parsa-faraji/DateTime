#include "Date.hpp"
#include <stdexcept>
#include <sstream>

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
    if (month < 1 || month > 12 || day < 1 || day > daysInMonth(year, month)) {
        throw std::invalid_argument("Invalid date");
    }
}

void Date::addDays(int days) {
    day += days;
    while (day > daysInMonth(year, month)) {
        day -= daysInMonth(year, month);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::addMonths(int months) {
    month += months;
    while (month > 12) {
        month -= 12;
        year++;
    }
    if (day > daysInMonth(year, month)) {
        day = daysInMonth(year, month);
    }
}

void Date::addYears(int years) {
    year += years;
    if (month == 2 && day == 29 && !isLeapYear(year)) {
        day = 28;
    }
}

void Date::subtractDays(int days) {
    day -= days;
    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += daysInMonth(year, month);
    }
}

void Date::subtractMonths(int months) {
    month -= months;
    while (month < 1) {
        month += 12;
        year--;
    }
    if (day > daysInMonth(year, month)) {
        day = daysInMonth(year, month);
    }
}

void Date::subtractYears(int years) {
    year -= years;
    if (month == 2 && day == 29 && !isLeapYear(year)) {
        day = 28;
    }
}

int Date::daysDifference(const Date& other) const {
    int totalDays1 = year * 360 + month * 30 + day;
    int totalDays2 = other.year * 360 + other.month * 30 + other.day;
    return totalDays1 - totalDays2;
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day;
    return oss.str();
}

bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int year, int month) const {
    static const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysPerMonth[month - 1];
}
