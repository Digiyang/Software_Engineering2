#include "date.h"
#include "parser.h"

#include <sstream>
#include <iomanip>
#include <map>
#include <memory>

// Lookup table
const map<int, int> Date::daysPerMonth = {
    {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
};

// a)
bool Date::isValid() const {

    // Check year
    if (year_ < 0 || year_ > 3000) {
        return false;
    }

    // Check month
    if (month_ < 1 || month_ > 12) {
        return false;
    }

    // Check days
    int num_days = daysPerMonth.at(month_);
    if (month_ == 2 && year_ % 4 == 0)  { // February and a leap year?
        if (year_ % 100 != 0 || year_ % 400 == 0) { // Only when not evenly divisible by 100 or evenly divisible by 400
            ++num_days;
        }
    }
    if (day_ < 1 || day_ > num_days) {
        return false;
    }

    // It's ok
    return true;
}

// b) The specific code is not relevant to the design of the test cases (Black Box)
string Date::toString(Format format) const {

   if (!isValid()) throw domain_error("Not a valid date");

   stringstream str;
   switch(format) {
   case Format::ISO8601:
       str << std::setfill('0') << std::setw(4) << year() << std::setw(2) << month() << std::setw(2) << day();
       break;
   case Format::DIN5008:
       str << std::setfill('0') << std::setw(2) << day() << '.' << std::setw(2) << month() << '.' << std::setw(4) << year();
       break;
   default:
       throw invalid_argument("Format needs to be either ISO8601 or DIN5008");
   }
   return str.str();
}

// c)
Date Date::parse(string input, Format format) {
    shared_ptr<Parser> parser = ParserFactory::instance().retrieveParserForFormat(format);
    vector<int> result = parser->parse(input);
    if (result.size() != 3) throw domain_error("Not a valid date: " + input);
    Date d = Date(result[0], result[1], result[2]);
    if (!d.isValid()) throw domain_error("Not a valid date: " + input);
    return d;
}
