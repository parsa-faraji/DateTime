#ifndef TIME_H
#define TIME_H

#include <string>

class Time {
public:
    // construcor
    Time(int hours, int minutes, int seconds);
    
    // method declarations
    void addSeconds(int seconds);
    void addMinutes(int minutes);
    void addHours(int hours);
    void subtractSeconds(int seconds);
    void subtractMinutes(int minutes);
    void subtractHours(int hours);

    int secondsDifference(const Time& other) const;
    std::string toString() const;

    // attributes
private:
    int hours;
    int minutes;
    int seconds;

    void normalize();
};

#endif // TIME_H
