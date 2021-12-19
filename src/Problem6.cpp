#include "Problem6.h"
#include <fstream>
#include <sstream>
#include <numeric>

Problem6::Problem6(){
	loadData();
}

void Problem6::loadData(){
	std::fstream inputFile("./resources/day6.dat", std::ios_base::in);
	std::string inputLine;
	
	getline(inputFile, inputLine);
	std::stringstream initialDistribution(inputLine);
	uint32_t number;
	while(initialDistribution >> number){
		++initialJellyfish[number];
		initialDistribution.ignore();
	}
}

ret_t Problem6::runPartOne(){
	return propagateJellyfish(80);
}

ret_t Problem6::runPartTwo(){
	return propagateJellyfish(256);
}

uint64_t Problem6::propagateJellyfish(uint32_t numDays){
	auto jellyfish = initialJellyfish;
	for(uint32_t day=0; day<numDays; day++){
		uint64_t jellyfishZero = jellyfish[0];
		for(uint8_t age=0; age<8; age++){
			jellyfish[age] = jellyfish[age+1];
		}
		jellyfish[6] += jellyfishZero;
		jellyfish[8] = jellyfishZero;
	}
	return std::accumulate(jellyfish.begin(), jellyfish.end(), uint64_t(0), [](uint64_t sum, auto num){ return sum+num.second;});
}