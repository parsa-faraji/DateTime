#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    // constructor
    Date(int year, int month, int day);

    // method declaration
    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);
    void subtractDays(int days);
    void subtractMonths(int months);
    void subtractYears(int years);

    int daysDifference(const Date& other) const;
    std::string toString() const;

    // attributes
private:
    int year;
    int month;
    int day;

    bool isLeapYear(int year) const;
    int daysInMonth(int year, int month) const;
};

#endif // DATE_H
