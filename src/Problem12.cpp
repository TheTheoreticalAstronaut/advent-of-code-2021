#include "Problem12.h"
#include <fstream>
#include <algorithm>

Problem12::Problem12(){
	loadData();
}

void Problem12::loadData(){
	std::fstream inputFile("./resources/day12.dat", std::ios_base::in);
	std::string input;

	while(inputFile >> input) {
		auto dash = input.find("-");
		std::string node0 = input.substr(0, dash);
		std::string node1 = input.substr(dash+1);
		if(nodes.find(node0) == nodes.end()) {
			Node node;
			if(std::all_of(node0.begin(), node0.end(), [](char c){ return isupper(c);})) node.repeatable = true;
			nodes[node0] = std::move(node);
		}
		nodes[node0].neighbours.push_back(node1);

		if(nodes.find(node1) == nodes.end()) {
			Node node;
			if(std::all_of(node1.begin(), node1.end(), [](char c){ return isupper(c);})) node.repeatable = true;
			nodes[node1] = std::move(node);
		}
		nodes[node1].neighbours.push_back(node0);
	}
}

ret_t Problem12::runPartOne(){
	ret_t numPaths{0};
	std::vector<std::string> path;
	findPaths(numPaths, path, "start", true);
	return numPaths;
}

ret_t Problem12::runPartTwo(){
	ret_t numPaths{0};
	std::vector<std::string> path;
	findPaths(numPaths, path, "start", false);
	return numPaths;
}

void Problem12::findPaths(ret_t& numPaths, std::vector<std::string>& path, const std::string& currentNode, const bool smallCaveVisited) {
	path.push_back(currentNode);

	if(currentNode == "end") {
		++numPaths;
		return;
	}

	size_t sizePath = path.size();
	for(auto const& node : nodes[currentNode].neighbours) {
		path.resize(sizePath);
		if(!nodes[node].repeatable && (std::find(path.begin(), path.end(), node) != path.end())) {
			if(smallCaveVisited || node=="start") continue;
			findPaths(numPaths, path, node, true);
		}
		else {
			findPaths(numPaths, path, node, smallCaveVisited);
		}
	}
}