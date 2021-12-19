#include "Problem5.h"
#include <fstream>
#include <sstream>
#include <algorithm>

Problem5::Problem5(){
	loadData();
}

void Problem5::loadData(){
	std::fstream inputFile("./resources/day5.dat", std::ios_base::in);
	std::string inputLine;

	while(getline(inputFile, inputLine)){
		std::stringstream drawSS(inputLine);
		uint32_t p0x, p0y, p1x, p1y;
		drawSS >> p0x;
		drawSS.ignore(1);
		drawSS >> p0y;
		drawSS.ignore(4);
		drawSS >> p1x;
		drawSS.ignore(1);
		drawSS >> p1y;
		lines.emplace_back(p0x, p0y, p1x, p1y);
		sizeX = sizeX > p0x ? sizeX : p0x;
		sizeX = sizeX > p1x ? sizeX : p1x;
		sizeY = sizeY > p0y ? sizeY : p0y;
		sizeY = sizeY > p1y ? sizeY : p1y;
	}
	sizeX++;
	sizeY++;
}

ret_t Problem5::runPartOne(){
	std::vector<uint8_t> visited(sizeX * sizeY, 0);
	for(const auto& line : lines){
		if(line.type == H){
			for(uint32_t x = line.p0.first; x <= line.p1.first; x++) ++visited[x + line.p0.second*sizeX];
		}
		else if(line.type == V){
			for(uint32_t y = line.p0.second; y <= line.p1.second; y++) ++visited[line.p0.first + y*sizeX];
		}
	}
	return std::count_if(visited.begin(), visited.end(), [](auto count){ return (count > 1);});
}

ret_t Problem5::runPartTwo(){
	std::vector<uint8_t> visited(sizeX * sizeY, 0);
	for(const auto& line : lines){
		if(line.type == H){
			for(uint32_t x = line.p0.first; x <= line.p1.first; x++) ++visited[x + line.p0.second*sizeX];
		}
		else if(line.type == V){
			for(uint32_t y = line.p0.second; y <= line.p1.second; y++) ++visited[line.p0.first + y*sizeX];
		}
		else{
			for(uint32_t x = 0; x <= (line.p1.first - line.p0.first); x++){
				if(line.p1.second > line.p0.second){ ++visited[line.p0.first+x + (line.p0.second + x)*sizeX]; }
				else{ ++visited[line.p0.first+x + (line.p0.second - x)*sizeX]; }
			}
		}
	}
	return std::count_if(visited.begin(), visited.end(), [](auto count){ return (count > 1);});
}