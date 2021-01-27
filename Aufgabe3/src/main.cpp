#include <iostream>
#include <stdexcept>
#include "date.h"

using namespace std;


// Demonstrates usage of the three methods (parse(), isValid(), toString())
int main() {  

    try {

        Date d = Date::parse("24.12.2020", Format::DIN5008);

        if (d.isValid()) {
            cout << "ISO: " << d.toString(Format::ISO8601) << endl;
            cout << "DIN: " << d.toString(Format::DIN5008) << endl;
        }

    } catch (invalid_argument &argex) {
        cerr << "Malformed date string - " << argex.what() << endl;
    } catch (domain_error &domerr) {
        cerr << "Bad date given - " << domerr.what() << endl;
    }

    return 1;
}
