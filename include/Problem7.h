#include "AoCProblem.h"
#include <map>

class Problem7 : public AoCProblem {
public:
	Problem7();

	virtual uint8_t getId() override { return 7; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	std::map<uint32_t, uint32_t> crabs;
	uint32_t numCrabs{0};
	uint32_t maxPos{0};
};
