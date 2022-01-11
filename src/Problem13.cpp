#include "Problem13.h"
#include <fstream>
#include <iostream>
#include <algorithm>

Problem13::Problem13(){
	loadData();
}

void Problem13::loadData(){
	std::fstream inputFile("./resources/day13.dat", std::ios_base::in);
	std::string input;

	while(inputFile >> input) {
		if(input.find(",") != std::string::npos) {
			originalPoints.insert({stoi(input.substr(0,input.find(","))), stoi(input.substr(input.find(",") + 1))});
		}
		else if(input.find("=") != std::string::npos) {
			bool horizontal = input.substr(input.find("=")-1,input.find("=")) == "y" ? true : false;
			folds.emplace_back(horizontal, stoi(input.substr(input.find("=") + 1)));
		}
	}
}

ret_t Problem13::runPartOne(){
	return !folds.empty() ? foldPoints(folds[0], originalPoints).size() : 0;
}

ret_t Problem13::runPartTwo(){
	std::set<coords_t> foldedPoints{originalPoints};
	for(size_t i=0; i<folds.size(); i++) foldedPoints = foldPoints(folds[i], foldedPoints);
	return printCode(foldedPoints);
}

std::set<Problem13::coords_t> Problem13::foldPoints(const Fold& fold, const std::set<coords_t>& points) const {
	std::set<coords_t> newPoints;
	for(auto const& point : points) {
		if(fold.horizontal && point.second > fold.value) {
			newPoints.insert({point.first, 2*fold.value - point.second});
		}
		else if(!fold.horizontal && point.first > fold.value) {
			newPoints.insert({2*fold.value - point.first, point.second});
		}
		else { newPoints.insert(point); }
	}
	return newPoints;
}

ret_t Problem13::printCode(const std::set<coords_t>& points) const {
	auto xMax = std::max_element(points.begin(), points.end(), [](const auto& lhs, const auto& rhs){ return lhs.first < rhs.first;});
	auto yMax = std::max_element(points.begin(), points.end(), [](const auto& lhs, const auto& rhs){ return lhs.second < rhs.second;});
	std::cout << "\n";
	for(uint32_t y=0; y<=yMax->second; y++) {
		for(uint32_t x=0; x<=xMax->first; x++) {
			if(points.find({x,y}) != points.end()) std::cout << "#";
			else std::cout << ".";
		}
		std::cout << "\n";
	}
	return 0;
}