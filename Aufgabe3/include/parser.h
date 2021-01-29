#pragma once

#include <memory>
#include <string>
#include <vector>
#include <regex>
#include <map>

using namespace std;

enum class Format;  // Forward declaration, found in date.h


// Parser interface
class Parser {
public:
    virtual ~Parser() = default;
    // Returns a vector of three integers [year, month, day]
    virtual vector<int> parse(string) = 0;
};


// A singleton factory for parsers
// This is used by Date::parse() and needs to be mocked for exercise c)
class ParserFactory {

    // Stores all of the used parsers. One for each supported format
    map<Format, shared_ptr<Parser>> parsers_;

    // There can be only one instance of the class...
    /* Singleton is a creational design pattern, which ensures that only one object of its kind exists and provides
       a single point of access to it for any other code. Singleton has almost the same pros and cons as global variables.*/
    static ParserFactory singleton; 

    // ... because external creation is forbidden due to following private ctors
    ParserFactory();    // Called during implicit creation of static singleton instance
    ParserFactory( const ParserFactory& ) = default;
    ParserFactory & operator = (const ParserFactory &) = default;

public:

    // Yields a parser for the given format specification
    shared_ptr<Parser> retrieveParserForFormat(Format);

    // Retrieve the only available instance
    static ParserFactory& instance() { return ParserFactory::singleton; }
};
