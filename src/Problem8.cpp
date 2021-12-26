#include "Problem8.h"
#include <fstream>
#include <map>
#include <numeric>
#include <algorithm>

const uint8_t NUM_DIGITS{4}; 

Problem8::Problem8(){
	loadData();
}

void Problem8::loadData(){
	std::fstream inputFile("./resources/day8.dat", std::ios_base::in);
	std::string input;

	Entry entry;
	while(inputFile >> input){
		if(input == "|"){
			for(uint8_t i=0; i<NUM_DIGITS; i++) {
				inputFile >> input;
				sort(input.begin(), input.end());
				entry.digits.emplace_back(input);
			}
			entries.emplace_back(std::move(entry));
			entry.segments.clear();
			entry.digits.clear();
			continue;
		}
		sort(input.begin(), input.end());
		entry.segments.emplace_back(input);
	}
}

ret_t Problem8::runPartOne(){
	return std::accumulate(entries.begin(), entries.end(), 0, [](uint32_t sum, auto const& entry){
		return sum + std::count_if(entry.digits.begin(), entry.digits.end(),
			[](auto const& digit){ return digit.size() < 5 || digit.size() > 6; });
	});
}

ret_t Problem8::runPartTwo(){
	uint32_t sum{0};
	for(auto const& entry : entries) {
		std::map<std::string, uint32_t> codeToDigit;
		std::string codeOfOne, codeOfFour;
		for(auto const& segment : entry.segments) {
			switch(segment.size()) {
				case 2:
					codeOfOne = segment;
					codeToDigit[segment] = 1;
					break;
				case 3:
					codeToDigit[segment] = 7;
					break;
				case 4:
					codeOfFour = segment;
					codeToDigit[segment] = 4;
					break;
				case 7:
					codeToDigit[segment] = 8;
					break;
				default:
					break;
			}
		}

		for(auto const& segment : entry.segments) {
			if(segment.size() == 5) codeToDigit[segment] = processSizeFive(segment, codeOfOne, codeOfFour);
			if(segment.size() == 6) codeToDigit[segment] = processSizeSix(segment, codeOfOne, codeOfFour);
		}

		sum += std::accumulate(entry.digits.begin(), entry.digits.end(), 0, [&codeToDigit](uint32_t sum, auto const& code) {
			return 10*sum + codeToDigit[code];
		});
	}
	return sum;
}

uint32_t Problem8::processSizeFive(const std::string& code, const std::string& codeOfOne, const std::string& codeOfFour) const {
	if(numberOfMatchingChars(code, codeOfOne) == codeOfOne.size()) return 3;
	if(numberOfMatchingChars(code, codeOfFour) == 3) return 5;
	return 2;
}

uint32_t Problem8::processSizeSix(const std::string& code, const std::string& codeOfOne, const std::string& codeOfFour) const {
	if(numberOfMatchingChars(code, codeOfOne) == codeOfOne.size()) {
		return numberOfMatchingChars(code, codeOfFour) == codeOfFour.size() ? 9 : 0;
	}
	return 6;
}

uint32_t Problem8::numberOfMatchingChars(const std::string& str0, const std::string& str1) const {
	return count_if(str0.begin(), str0.end(), [&str1](char c){ return str1.find(c) != std::string::npos;});
}