#include "Problem3.h"
#include <fstream>
#include <cstdlib>
#include <algorithm>

Problem3::Problem3(){
	loadData();
}

void Problem3::loadData(){
	std::fstream inputFile("./resources/day3.dat", std::ios_base::in);

	std::string number;
	while(inputFile >> number){
		data.push_back(number);
	}

	if(!data.empty()){
		bitSize = data[0].size();
		mask = (0x1 << bitSize) - 1;
	}
}

uint32_t Problem3::runPartOne(){
	std::vector<uint32_t> bitCounts(bitSize, 0);
	for(const auto& bin : data){
		for(size_t c = 0; c < bin.size(); c++) bitCounts[c] += (bin[c] == '1');
	}

	std::string gammaRateStr;
	for(const auto count : bitCounts) gammaRateStr += (2*count > data.size()) ? "1" : "0";

	uint32_t gammaRate = (strtoul(gammaRateStr.c_str(), nullptr, 2) & mask);
	return gammaRate * (~gammaRate & mask);
}

uint32_t Problem3::runPartTwo(){
	std::vector<std::string> dataO2(data), dataCO2(data);
	return determinePartTwoRates(dataO2, 0, true) * determinePartTwoRates(dataCO2, 0, false);
}

uint32_t Problem3::determinePartTwoRates(std::vector<std::string>& remainingData, uint8_t bit, bool selectMostCommon) const{
	if(remainingData.size() == 1) return strtoul(remainingData[0].c_str(), nullptr, 2);

	uint32_t bitCount{0};
	for(const auto& bin : remainingData) bitCount += (bin[bit] == '1');
	char selectedBit = (selectMostCommon && (2*bitCount < remainingData.size())) || (!selectMostCommon && (2*bitCount >= remainingData.size())) ? '0' : '1';

	auto itEnd = std::remove_if(remainingData.begin(), remainingData.end(), [&](auto binNum){ return binNum[bit] != selectedBit; });
	remainingData.erase(itEnd, remainingData.end());
	return determinePartTwoRates(remainingData, ++bit, selectMostCommon);
}
