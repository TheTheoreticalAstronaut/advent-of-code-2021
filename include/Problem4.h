#include "AoCProblem.h"
#include <array>

class Problem4 : public AoCProblem {

public:
	Problem4();

	virtual uint8_t getId() override { return 4; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	static const uint8_t N{5};
	struct Board{
		Board(){
			marked.fill(false);
		}
		std::array<uint32_t, N*N> numbers;
		std::array<bool, N*N> marked;
		bool winning{false};
	};
	std::vector<uint32_t> draw;
	std::vector<Board> boards;

	void updateWinningBoards(Board *& latestWinningBoard);
	bool checkIfAllBoardsAreWinning() const;
};
