#include "Problem11.h"
#include <fstream>

Problem11::Problem11(){
	loadData();
}

void Problem11::loadData(){
	std::fstream inputFile("./resources/day11.dat", std::ios_base::in);
	std::string input;

	while(inputFile >> input) {
		std::vector<int32_t> row(1, -1);
		for(char c : input) row.push_back(c-'0');
		row.push_back(-1);
		initialOctopi.emplace_back(std::move(row));
	}
	initialOctopi.insert(initialOctopi.begin(), std::vector<int32_t>(input.size() + 2, -1));
	initialOctopi.emplace_back(input.size() + 2, -1);
	numOctopi = initialOctopi.size()*initialOctopi.size() - 4*(initialOctopi.size() - 1);
}

ret_t Problem11::runPartOne(){
	const uint32_t NUM_STEPS{100};
	matrix_t<int32_t> octopi = initialOctopi;

	ret_t numFlashes{0};
	for(uint32_t step=0; step<NUM_STEPS; step++) {
		std::vector<std::pair<uint8_t,uint8_t>> flashed;
		increaseEnergyLevelsByOne(octopi, flashed);
		flashOctopi(octopi, flashed);
		clearFlashingOctopi(octopi, flashed);
		numFlashes += flashed.size();
	}
	return numFlashes;
}

ret_t Problem11::runPartTwo(){
	const uint32_t LIM_NUM_STEPS{100000};
	matrix_t<int32_t> octopi = initialOctopi;

	for(uint32_t step=0; step<LIM_NUM_STEPS; step++) {
		std::vector<std::pair<uint8_t,uint8_t>> flashed;
		increaseEnergyLevelsByOne(octopi, flashed);
		flashOctopi(octopi, flashed);
		if(flashed.size() == numOctopi) return step+1;
		clearFlashingOctopi(octopi, flashed);
	}
	return 0;
}

void Problem11::increaseEnergyLevelsByOne(matrix_t<int32_t>& octopi, std::vector<std::pair<uint8_t,uint8_t>>& flashed) const {
	for(auto row=1; row < octopi.size()-1; row++){
		for(auto col=1; col < octopi[row].size()-1; col++){
			if(++octopi[row][col] == 10) flashed.emplace_back(row, col);
		}
	}
}

void Problem11::flashOctopi(matrix_t<int32_t>& octopi, std::vector<std::pair<uint8_t,uint8_t>>& flashed) const {
	for(auto i=0; i<flashed.size(); i++) {
		for(auto r=flashed[i].first-1; r<=flashed[i].first+1; r++) {
			for(auto c=flashed[i].second-1; c<=flashed[i].second+1; c++) {
				if(octopi[r][c] == -1 || (r==flashed[i].first && c==flashed[i].second)) continue;
				if(++octopi[r][c] == 10) flashed.emplace_back(r,c);
			}
		}
	}
}

void Problem11::clearFlashingOctopi(matrix_t<int32_t>& octopi, std::vector<std::pair<uint8_t,uint8_t>>& flashed) const {
	for(auto const& f : flashed) octopi[f.first][f.second] = 0;
}