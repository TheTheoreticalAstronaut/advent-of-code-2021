#include "AoCProblem.h"
#include <map>

class Problem6 : public AoCProblem {
public:
	Problem6();

	virtual uint8_t getId() override { return 6; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	std::map<uint8_t, uint64_t> initialJellyfish{{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}};

	uint64_t propagateJellyfish(uint32_t numDays);
};
