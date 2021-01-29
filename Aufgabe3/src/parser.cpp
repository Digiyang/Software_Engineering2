#include "parser.h"
#include "date.h"


//////////////////////////
// ISO Parser

// A parser for the ISO formatting specification
class IsoParser : public Parser {
    regex expression_;
    smatch matches_;
public:
    IsoParser() : expression_("(\\d{4})(\\d{2})(\\d{2})") {} //constructor
    virtual ~IsoParser() = default; //destructor
    virtual vector<int> parse(string input) {
        if (regex_match(input, matches_, expression_) && matches_.size() == 4)
        	// string to integer
            return {stoi(matches_[1].str()), stoi(matches_[2].str()), stoi(matches_[3].str())};
        throw invalid_argument("Syntax Error. Needs to be a YYYYMMDD pattern.");
    }
};


//////////////////////////
// DIN Parser

// A parser for the DIN formatting specification
class DinParser : public Parser {
    regex expression_; //regular expression
    /*smatch is an instantiation of the match_results class template for matches on string objects.
	  Functions that can be called using smatch:
      str(), position(), and length() member functions of the match_results object can be called
      to get the text that was matched, or the starting position and its length of the match relative
      to the subject string.*/
    smatch matches_;
public:
    DinParser() : expression_("(\\d{2})\\.(\\d{2})\\.(\\d{4})") {} //constructor
    virtual ~DinParser() = default; //destructor
    virtual vector<int> parse(string input) {
        // attempts to match a regular expression to an entire character sequence
    	if (regex_match(input, matches_, expression_) && matches_.size() == 4)
            //string to integer
        	return {stoi(matches_[3].str()), stoi(matches_[2].str()), stoi(matches_[1].str())};
        throw invalid_argument("Syntax Error. Needs to be a DD.MM.YYYY pattern.");
    }
};

//////////////////////////
// Factory

ParserFactory ParserFactory::singleton;

ParserFactory::ParserFactory() {
    parsers_[Format::ISO8601] = shared_ptr<Parser>(new IsoParser());    // Using a shared_ptr for memory management
    parsers_[Format::DIN5008] = shared_ptr<Parser>(new DinParser());    // "
}

shared_ptr<Parser> ParserFactory::retrieveParserForFormat(Format format) {
    auto & parsers = ParserFactory::singleton.parsers_;
    if (parsers.find(format) != parsers.end()) {
        return parsers.at(format);
    } else throw invalid_argument("Unknown format");
}
