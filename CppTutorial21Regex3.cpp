// CppTutorial21Regex3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <ctime>

#include <regex>


// [ ]   : Match what is in the brackets
// [^ ]  : Match anything not in the brackets
// ( )   : Return surrounded submatch
// .     : Match any 1 character or space
// +     : Match 1 or more of what proceeds
// ?     : Match 0 or 1
// *     : Match 0 or More
// *?    : Lazy match the smallest match
// \b    : Word boundary
// ^     : Beginning of String
// $     : End of String
// \n    : Newline
// \d    : Any 1 number
// \D    : Anything but a number
// \w    : Same as [a-zA-Z0-9_]
// \W    : Same as [^a-zA-Z0-9_]
// \s    : Same as [\f\n\r\t\v]
// \S    : Same as [^\f\n\r\t\v]
// {5}   : Match 5 of what proceeds the curly brackets
// {5,7} : Match values that are between 5 and 7 in length

void PrintMatches(std::string str,
	std::regex reg) {

	// Used when your searching a string
	std::smatch matches;

	// Determines if there is a match and match results are returned in matches
	while (std::regex_search(str, matches, reg)) {

		// Get the first match
		std::cout << matches.str(1) << "\n";

		// Eliminate the previous match and create a new string to search
		str = matches.suffix().str();
	}
	std::cout << "\n";
}

int main()
{
	std::string str1 = "The cat cat fell out of the window";
	std::regex reg1("(\\b\\w+)\\s+\\1");
	PrintMatches(str1, reg1);

	std::string str2 = "<a href='#'><b>The Link</b></a>";
	std::regex reg2("<b>(.*?)</b>");
	std::string result;
	std::regex_replace(std::back_inserter(result), str2.begin(), str2.end(), reg2, "$1");
	std::cout << result << "\n";

	std::string str3 = "412-555-1212";
	std::regex reg3("([\\d]{3})-([\\d]{3}-[\\d]{4})");
	std::string res3;

	// The output is the area code surrounded with () and then the 2nd subexpression
	std::regex_replace(std::back_inserter(res3), str3.begin(), str3.end(), reg3, "($1)$2");
	std::cout << res3 << "\n";

	std::string str4 = "https://www.youtube.com ""http://www.google.com";
	std::regex reg4("(https?://([\\w.]+))");
	std::string res4;
	std::regex_replace(std::back_inserter(res4), str4.begin(), str4.end(), reg4, "<a href='$1'>$2</a>\n");
	std::cout << res4 << "\n";

	// ?= looks ahead to the next bit
	std::string str5 = " one two three four ";
	std::regex reg5("(\\w+(?=\\b))");
	PrintMatches(str5, reg5);

	std::string str6 = "1. Dog 2. Cat 3. Turtle";
	std::regex reg6("\\d\\.\\s(Dog|Cat)");
	PrintMatches(str6, reg6);

	std::string str7 = "12345 12345-1234 1234 12346-333";
	std::regex reg7("(\\d{5}-\\d{4}|\\d{5}\\s)");
	PrintMatches(str7, reg7);

	std::string str8 = "14125551212 4125551212 "
		"(412)5551212 412 555 1212 412-555-1212 "
		"1-412-555-1212";

	std::regex reg8("((1?)(-| ?)(\\()?(\\d{3})(\\)|-| |\\)-|\\) )?(\\d{3})(-| )?(\\d{4}|\\d{4}))");
	PrintMatches(str8, reg8);

    return 0;
}