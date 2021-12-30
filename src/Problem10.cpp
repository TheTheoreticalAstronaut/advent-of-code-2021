#include "Problem10.h"
#include <fstream>
#include <algorithm>
#include <numeric>

Problem10::Problem10(){
	loadData();
}

void Problem10::loadData(){
	std::fstream inputFile("./resources/day10.dat", std::ios_base::in);
	std::string input;
	while(inputFile >> input) lines.push_back(input);
}

ret_t Problem10::runPartOne(){
	return std::accumulate(lines.begin(), lines.end(), 0, [&](ret_t errorScore, const auto& line){
		std::stack<char> brackets;
		if(isLineCorrupted(line, brackets)) {
			if(brackets.top() == ')') return errorScore + 3;
			else if(brackets.top() == ']') return errorScore + 57;
			else if(brackets.top() == '}') return errorScore + 1197;
			else if(brackets.top() == '>') return errorScore + 25137;
		}
		return errorScore;
	});
}

ret_t Problem10::runPartTwo(){
	std::vector<ret_t> incompleteScores;
	for(const auto& line : lines) {
		std::stack<char> brackets;
		if(!isLineCorrupted(line, brackets)) {
			ret_t score{0};
			while(!brackets.empty()) {
				score *= 5;
				if(brackets.top() == '(') score += 1;
				else if(brackets.top() == '[') score += 2;
				else if(brackets.top() == '{') score += 3;
				else if(brackets.top() == '<') score += 4;
				brackets.pop();
			}
			incompleteScores.push_back(score);
		}
	}
	std::sort(incompleteScores.begin(), incompleteScores.end());
	return incompleteScores[incompleteScores.size()/2];
}

bool Problem10::isLineCorrupted(const std::string& line, std::stack<char>& brackets) const {
	for(char c : line) {
		if(c == '(' || c == '[' || c == '{' || c == '<') brackets.push(c);
		else {
			if((c == ')' && brackets.top() != '(') ||
			   (c == ']' && brackets.top() != '[') ||
			   (c == '}' && brackets.top() != '{') ||
			   (c == '>' && brackets.top() != '<')) {
				   brackets.push(c);
				   return true;
			   }
			brackets.pop();
		}
	}
	return false;
}