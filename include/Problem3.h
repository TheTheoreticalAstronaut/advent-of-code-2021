#include "AoCProblem.h"
#include <vector>
#include <string>

class Problem3 : public AoCProblem {

public:
	Problem3();

	virtual void loadData() override;

	virtual uint32_t runPartOne() override;

	virtual uint32_t runPartTwo() override;

private:
	std::vector<std::string> data;
	uint32_t bitSize{0};
	uint32_t mask{0x0};

	uint32_t determinePartTwoRates(std::vector<std::string>& remainingData, uint8_t bit, bool selectMostCommon) const;
};