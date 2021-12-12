#include "Problem4.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>

Problem4::Problem4(){
	loadData();
}

void Problem4::loadData(){
	std::fstream inputFile("./resources/day4.dat", std::ios_base::in);
	std::string inputLine;

	getline(inputFile, inputLine);
	std::stringstream drawSS(inputLine);
	uint32_t number;
	while(drawSS >> number){
		draw.push_back(number);
		drawSS.ignore();
	}

	Board board;
	size_t counter{0};
	while(inputFile >> number){
		board.numbers[counter++] = number;
		if(counter == N*N){
			counter = 0;
			boards.push_back(board);
		}
	}
}

uint32_t Problem4::runPartOne(){
	Board* latestWinningBoard{nullptr};
	for(auto number : draw){
		for(auto& board : boards){
			auto it = std::find(board.numbers.begin(), board.numbers.end(), number);
			if(it != board.numbers.end()) board.marked[it - board.numbers.begin()] = true;
		}
		updateWinningBoards(latestWinningBoard);
		if(latestWinningBoard){
			uint32_t sum{0};
			for(uint8_t i=0; i<N*N; i++) sum += (!latestWinningBoard->marked[i])*latestWinningBoard->numbers[i];
			return sum * number;

		}
	}
	return 0;
}

uint32_t Problem4::runPartTwo(){
	Board* latestWinningBoard;
	uint32_t drawLWB{0};
	for(auto number : draw){
		for(auto& board : boards){
			auto it = std::find(board.numbers.begin(), board.numbers.end(), number);
			if(it != board.numbers.end()) board.marked[it - board.numbers.begin()] = true;
		}
		updateWinningBoards(latestWinningBoard);
		if(checkIfAllBoardsAreWinning()){
			drawLWB = number;
			break;
		}
	}

	uint32_t sum{0};
	for(uint8_t i=0; i<N*N; i++) sum += (!latestWinningBoard->marked[i])*latestWinningBoard->numbers[i];
	return sum * drawLWB;
	return 0;
}

void Problem4::updateWinningBoards(Board*& latestWinningBoard){
	for(auto& board : boards){
		if(board.winning) continue;
		for(uint8_t i=0; i<N; i++){
			bool rowWin{true}, colWin{true};
			for(uint8_t j=0; j<N; j++){
				rowWin = (rowWin && board.marked[j+i*N]);
				colWin = (colWin && board.marked[i+j*N]);
			}
			if(rowWin || colWin){
				board.winning = true;
				latestWinningBoard = &board;
			}
		}
	}
}

bool Problem4::checkIfAllBoardsAreWinning() const{
	for(const auto& board : boards){
		if(!board.winning) return false;
	}
	return true;
}
