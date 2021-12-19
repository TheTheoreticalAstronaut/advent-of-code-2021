#include "Problem2.h"
#include <fstream>
#include <iostream>

Problem2::Problem2(){
	loadData();
}

void Problem2::loadData(){
	std::fstream inputFile("./resources/day2.dat", std::ios_base::in);

	std::string instruction;
	uint32_t number;
	while(inputFile >> instruction >> number){
		data.push_back({instruction, number});
	}
}

ret_t Problem2::runPartOne(){
	uint32_t horizontalPosition{0};
	uint32_t depth{0};
	for(const auto& [instruction, number] : data){
		if(instruction == "forward"){ horizontalPosition += number; }
		else{ depth = (instruction == "down") ? depth+number : depth-number; }
	}
	return horizontalPosition * depth;
}

ret_t Problem2::runPartTwo(){
	uint32_t horizontalPosition{0};
	uint32_t depth{0};
	uint32_t aim{0};
	for(const auto& [instruction, number] : data){
		if(instruction == "forward"){
			horizontalPosition += number;
			depth += aim*number;
		}
		else{ aim = (instruction == "down") ? aim+number : aim-number; }
	}
	return horizontalPosition * depth;
}
