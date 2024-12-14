#include "Time.hpp"
#include <sstream>

Time::Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {
    normalize();
}

void Time::addSeconds(int seconds) {
    this->seconds += seconds;
    normalize();
}

void Time::addMinutes(int minutes) {
    this->minutes += minutes;
    normalize();
}

void Time::addHours(int hours) {
    this->hours += hours;
    normalize();
}

void Time::subtractSeconds(int seconds) {
    this->seconds -= seconds;
    normalize();
}

void Time::subtractMinutes(int minutes) {
    this->minutes -= minutes;
    normalize();
}

void Time::subtractHours(int hours) {
    this->hours -= hours;
    normalize();
}

int Time::secondsDifference(const Time& other) const {
    int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
    int totalSeconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
    return totalSeconds1 - totalSeconds2;
}

std::string Time::toString() const {
    std::ostringstream oss;
    oss << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds;
    return oss.str();
}

void Time::normalize() {
    while (seconds < 0) {
        seconds += 60;
        minutes--;
    }
    while (seconds >= 60) {
        seconds -= 60;
        minutes++;
    }
    while (minutes < 0) {
        minutes += 60;
        hours--;
    }
    while (minutes >= 60) {
        minutes -= 60;
        hours++;
    }
    while (hours < 0) {
        hours += 24;
    }
    hours %= 24;
}
