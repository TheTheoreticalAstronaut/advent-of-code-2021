#include "Problem9.h"
#include <fstream>
#include <numeric>
#include <queue>
#include <set>

Problem9::Problem9(){
	loadData();
}

void Problem9::loadData(){
	std::fstream inputFile("./resources/day9.dat", std::ios_base::in);
	std::string input;

	while(inputFile >> input) {
		std::vector<uint8_t> row(1, 9);
		for(char c : input) row.push_back(static_cast<uint8_t>(c-'0'));
		row.push_back(9);
		heightMap.emplace_back(std::move(row));
	}
	heightMap.insert(heightMap.begin(), std::vector<uint8_t>(input.size()+2, 9));
	heightMap.push_back(std::vector<uint8_t>(input.size()+2, 9));
}

ret_t Problem9::runPartOne(){
	std::vector<pair_t> minima = findMinima();
	return accumulate(minima.begin(), minima.end(), 0, [this](uint32_t sum, auto const& minimum) {
		return sum + heightMap[minimum.first][minimum.second] + 1;
	});
}

ret_t Problem9::runPartTwo(){
	std::vector<pair_t> minima = findMinima();
	std::vector<uint32_t> sizes;
	for(auto const& minimum : minima) {
		std::set<pair_t> visited;
		std::queue<pair_t> toVisit;
		toVisit.push(minimum);
		while(!toVisit.empty()) {
			auto [row, col] = toVisit.front();
			visited.insert({row, col});
			toVisit.pop();
			if(heightMap[row-1][col] != 9 && visited.find({row-1, col}) == visited.end()) toVisit.push({row-1, col});
			if(heightMap[row+1][col] != 9 && visited.find({row+1, col}) == visited.end()) toVisit.push({row+1, col});
			if(heightMap[row][col-1] != 9 && visited.find({row, col-1}) == visited.end()) toVisit.push({row, col-1});
			if(heightMap[row][col+1] != 9 && visited.find({row, col+1}) == visited.end()) toVisit.push({row, col+1});
		}
		sizes.push_back(visited.size());
	}
	std::sort(sizes.begin(), sizes.end(), std::greater<>());
	return std::accumulate(sizes.begin(), sizes.begin() + 3, 1, [](uint32_t prod, auto size){ return prod*size;});
}

std::vector<pair_t> Problem9::findMinima() const {
	std::vector<pair_t> minima;
	for(size_t row = 1; row < heightMap.size()-1; row++) {
		for(size_t col = 1; col < heightMap[row].size()-1; col++) {
			if(heightMap[row-1][col] <= heightMap[row][col] ||
			   heightMap[row+1][col] <= heightMap[row][col] ||
			   heightMap[row][col-1] <= heightMap[row][col] ||
			   heightMap[row][col+1] <= heightMap[row][col]) continue;
			minima.emplace_back(row, col);
		}
	}
	return minima;
}