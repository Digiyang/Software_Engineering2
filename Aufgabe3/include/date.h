#pragma once

#include <cstdint>
#include <string>
#include <map>

using namespace std;

enum class Format {
    ISO8601,    // YYYYMMDD
    DIN5008     // DD.MM.YYYY
};
class ParamException {};
///////////////////
// Class under test for the Unit Test
class Date {

    // Note:
    // The following object state needs to be considered as input parameters to your functions under test a) and b)
    uint16_t year_;
    uint8_t month_;
    uint8_t day_;

    static const map<int, int> daysPerMonth;    // Lookup table for the number of days in each month of a common year

public:

    Date(int y, int m, int d) : year_(y), month_(m), day_(d) {}

    int year() const { return year_; }
    void year(int y) { year_ = y; }

    int month() const { return month_; }
    void month(int m) { month_ = m; }

    int day() const { return day_; }
    void day(int d) { day_ = d; }

    // Provides test for equality by overloaded == operator
    friend bool operator==(const Date& left, const Date& right) {
        return (left.year_ == right.year_ && left.month_ == right.month_ && left.day_ == right.day_);
    }


    ///////////////////////////////////////
    // a) Test this method using full path coverage
    // White Box test
    //////////////////

    // Checks for validity of a date
    // Year needs to be in the range 0 to 3000
    // Month needs to be in the range 1 to 12
    // Day needs to be in the range 1 to max number of days for a month (considers leap years)
    bool isValid() const;


    ///////////////////////////////////////
    // b) Test this method using equivalence classes
    // Black-Box Test with inputs year, month, day (each of type int), and format (of Type Format)
    //////////////////

    // Formats date as a string with given format specification
    // Performs validity check
    string toString(Format format) const;


    ///////////////////////////////////////
    // c) Test this method in a sensible way.
    // This is a unit test with no prescribed test case design method. Test in any way you see fit.
    // In any case, make sure to mock the ParserFactory / Parser dependency.
    //////////////////

    // Reads date from a string with given format specification
    // Performs validity check
    static Date parse(string input, Format format);
};
