#include "Problem14.h"
#include <fstream>
#include <algorithm>

Problem14::Problem14(){
	loadData();
}

void Problem14::loadData(){
	std::fstream inputFile("./resources/day14.dat", std::ios_base::in);

	std::string initialTemplate;
	inputFile >> initialTemplate;
	for(size_t c = 0; c < initialTemplate.size()-1 ; c++) ++initPairs[initialTemplate.substr(c,2)];
	first = initialTemplate.front();
	last = initialTemplate.back();

	std::string key, arrow, value;
	while(inputFile >> key >> arrow >> value) {
		subRules[key] = value;
	}
}

ret_t Problem14::runPartOne(){
	auto pairs = propagatePairs(10);

	auto counts = countLetters(pairs);

	auto minMax = std::minmax_element(counts.begin(), counts.end(), [](const auto& c0, const auto& c1) { return c0.second < c1.second; });
	return (minMax.second)->second - (minMax.first)->second;
}

ret_t Problem14::runPartTwo(){
	auto pairs = propagatePairs(40);

	auto counts = countLetters(pairs);

	auto minMax = std::minmax_element(counts.begin(), counts.end(), [](const auto& c0, const auto& c1) { return c0.second < c1.second; });
	return (minMax.second)->second - (minMax.first)->second;
}

pairs_t Problem14::propagatePairs(uint8_t numSteps) {
	pairs_t currentPairs{initPairs}, nextPairs;
	for(uint8_t step = 0; step < numSteps; step++) {
		nextPairs.clear();
		for(auto const& p : currentPairs) {
			nextPairs[p.first.front() + subRules[p.first]] += p.second;
			nextPairs[subRules[p.first] + p.first.back()] += p.second;
		}
		currentPairs = std::move(nextPairs);
	}
	return currentPairs;
}

counts_t Problem14::countLetters(const pairs_t& pairs) const {
	counts_t counts;
	for(auto const& p : pairs) {
		counts[p.first.front()] += p.second;
		counts[p.first.back()] += p.second;
	}

	for(auto& p : counts) p.second = p.second/2 + (p.first==first) + (p.first==last);
	return counts;
}