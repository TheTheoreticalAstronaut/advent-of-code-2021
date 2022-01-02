#include "AoCProblem.h"

class Problem1 : public AoCProblem {

public:
	Problem1();

	virtual uint8_t getId() override { return 1; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	std::vector<uint32_t> data;
};
