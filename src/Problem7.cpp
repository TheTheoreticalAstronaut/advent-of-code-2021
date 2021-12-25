#include "Problem7.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <numeric>

Problem7::Problem7(){
	loadData();
}

void Problem7::loadData(){
	std::fstream inputFile("./resources/day7.dat", std::ios_base::in);
	std::string inputLine;
	
	getline(inputFile, inputLine);
	std::stringstream positions(inputLine);
	uint32_t number;
	while(positions >> number){
		++crabs[number];
		++numCrabs;
		maxPos = maxPos > number ? maxPos : number;
		positions.ignore();
	}
}

ret_t Problem7::runPartOne(){
	uint32_t lowerFuel{0};
	uint32_t upperFuel = std::accumulate(crabs.begin(), crabs.end(), 0,
	                        [](uint32_t sum, const auto& pos){ return sum+pos.first*pos.second;});
	uint32_t lowerCrabs = crabs[0];
	uint32_t upperCrabs = numCrabs - crabs[0];

	uint32_t minFuel{upperFuel};
	for(uint32_t pos = 1; pos<=maxPos; pos++){
		lowerFuel += lowerCrabs;
		upperFuel -= upperCrabs;
		lowerCrabs += crabs[pos];
		upperCrabs -= crabs[pos];
		minFuel = minFuel < (lowerFuel + upperFuel) ? minFuel : lowerFuel + upperFuel;
	}
	return minFuel;
}

ret_t Problem7::runPartTwo(){
	uint32_t minFuel = std::accumulate(crabs.begin(), crabs.end(), 0,
	                        [](uint32_t sum, const auto& pos){ return sum+((pos.first)*(pos.first + 1))/2*pos.second;});
	for(uint32_t pos = 1; pos<=maxPos; pos++){
		uint32_t posFuel = std::accumulate(crabs.begin(), crabs.end(), 0,
	                        [pos](uint32_t sum, const auto& crab){
								uint32_t diff = pos > crab.first ? pos-crab.first : crab.first-pos;
								return sum + (diff*(diff+1))/2*crab.second;
							});
		minFuel = minFuel < posFuel ? minFuel : posFuel;
	}
	return minFuel;
}