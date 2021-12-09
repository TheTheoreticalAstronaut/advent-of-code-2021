#include "Problem1.h"
#include <fstream>

Problem1::Problem1(){
	loadData();
}

void Problem1::loadData(){
	std::fstream inputFile("./resources/day1.dat", std::ios_base::in);

	uint32_t depth;
	while(inputFile >> depth){
		data.push_back(depth);
	}
}

uint32_t Problem1::runPartOne(){
	uint32_t increaseCounter{0};
	for(size_t depth=1; depth<data.size(); depth++) increaseCounter += (data[depth] > data[depth-1]);
	return increaseCounter;
}

uint32_t Problem1::runPartTwo(){
	uint32_t increaseCounter{0};
	for(size_t depth=3; depth<data.size(); depth++) increaseCounter += (data[depth] > data[depth-3]);
	return increaseCounter;
}
