// CppTutorial19Regex.cpp : Defines the entry point for the console application.
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

void PrintMatches(std::string str, std::regex reg) {
	std::smatch matches;
	std::cout << std::boolalpha;
	while (std::regex_search(str, matches, reg)) {
		std::cout << "Is there a match : " << matches.ready() << "\n";
		std::cout << "Are there no matches : " << matches.empty() << "\n";
		std::cout << "Number of matches : " << matches.size() << "\n";
		std::cout << "Match : " << matches.str(1) << "\n";
		str = matches.suffix().str();
		std::cout << "\n";
	}
}

void PrintMatches2(std::string str, std::regex reg) {
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
	std::sregex_iterator lastMatch;
	while (currentMatch != lastMatch) {
		std::smatch match = *currentMatch;
		std::cout << match.str() << "\n";
		currentMatch++;
	}
	std::cout << std::endl;
}
int main()
{
	//// [^ ] means not a space, ? means maybe, so maybe not a space, maybe a space 
	//std::string str = "The ape was at the apex";
	//std::regex reg ("(ape[^ ]?)");
	//PrintMatches(str, reg);

	//// + means more than one char, so maybe more than one not a space
	//std::string str2 = "I picked the pickle";
	//std::regex reg2 ("(pick([^ ]+)?)");
	//PrintMatches2(str2, reg2);

	// std::string str3 = "Cat rat mat fat pat";

	//// [crmfp] means c or r or m, etc..., then its followed by at
	//std::regex reg3 ("([crmfp]at)");
	//PrintMatches2(str3, reg3);

	//// [C-F] means C through F [c-f] means c though f
	//std::regex reg4("([C-Fc-f]at)");
	//PrintMatches2(str3, reg4);

	//// [^Cr] means not C or r
	//std::regex reg4("[^Cr]at");
	//PrintMatches2(str3, reg4);

	//  \. is a period, . is any character, [^ ] is any character thats not a space
	/*std::string str7 = "F.B.I. I.R.S. CIA";
	std::regex reg7("([^ ]\..\..\.)");
	PrintMatches2(str7, reg7);*/

	//// Replaces Cat and rat with Owl
	//std::regex reg6 ("([Cr]at)");
	//std::string owlFood = std::regex_replace(str3, reg6, "Owl");
	//std::cout << owlFood << "\n";

	//std::string str8 = "This is a\n multiline string\n" "that has many lines";
	//std::regex reg8("\n");
	//std::string noLBStr = std::regex_replace(str8, reg8, " ");
	//std::cout << noLBStr << "\n";

	//// You can also replace
	//// \b : Backspace
	//// \f : Form Feed
	//// \r : Carriage Return
	//// \t : Tab
	//// \v : Vertical Tab

	//// \d can be used instead of [0-9]
	//// \D is the same as [^0-9]
	//std::string str9 = "12345";
	//std::regex reg9("\\d"); // Does the whole string
	//PrintMatches2(str9, reg9);

	//// Match values that are between 5 and 7 digits
	//std::string str10 = "123 12345 123456 1234567";
	//std::regex reg10("\\d{5,7}");
	//PrintMatches2(str10, reg10);

	// \w is the same as [a-zA-Z0-9_]
	// \W is the same as [^a-zA-Z0-9_]
	/*std::string str11 = "412-555-1212";
	std::regex reg11("\\w{3}-\\w{3}-\\w{4}");
	PrintMatches2(str11, reg11);*/

	// \s is the same as [\f\n\r\t\v]
	// \S is the same as [^\f\n\r\t\v]

	// Check if its a valid name
	/*std::string str12 = "Toshio Muramatsu";
	std::regex reg12("\\w{2,20}\\s\\w{2,20}");
	PrintMatches2(str12, reg12);

	std::string str13 = "a as ape bug";
	std::regex reg13("a[a-z]+");
	PrintMatches2(str13, reg13);*/

	std::string str14 = "db@aol.com m@.com @apple.com db@.com";
	std::regex reg14("[\\w\\.%\\+-]{1,20}@[\\w\\.-]{2,20}\\.[A-Za-z]{2,3}");
	PrintMatches2(str14, reg14);
	
    return 0;
}