#include "DateTime.hpp"
#include <sstream>

DateTime::DateTime(const Date& date, const Time& time) : date(date), time(time) {}

int DateTime::totalDaysDifference(const DateTime& other) const {
    return date.daysDifference(other.date);
}

int DateTime::totalSecondsDifference(const DateTime& other) const {
    return date.daysDifference(other.date) * 86400 + time.secondsDifference(other.time);
}

std::string DateTime::format(const std::string& formatString) const {
    std::ostringstream result;
    for (size_t i = 0; i < formatString.size(); ++i) {
        if (formatString[i] == 'Y' && i + 3 < formatString.size() && formatString.substr(i, 4) == "YYYY") {
            result << date.toString().substr(0, 4);
            i += 3;
        } else if (formatString[i] == 'M' && i + 1 < formatString.size() && formatString.substr(i, 2) == "MM") {
            result << date.toString().substr(5, 2);
            i += 1;
        } else if (formatString[i] == 'D' && i + 1 < formatString.size() && formatString.substr(i, 2) == "DD") {
            result << date.toString().substr(8, 2);
            i += 1;
        } else if (formatString[i] == 'H' && i + 1 < formatString.size() && formatString.substr(i, 2) == "HH") {
            result << time.toString().substr(0, 2);
            i += 1;
        } else if (formatString[i] == 'S' && i + 1 < formatString.size() && formatString.substr(i, 2) == "SS") {
            result << time.toString().substr(6, 2);
            i += 1;
        } else {
            result << formatString[i];
        }
    }
    return result.str();
}
