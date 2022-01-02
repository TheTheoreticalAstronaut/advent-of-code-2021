#include "AoCProblem.h"

class Problem11 : public AoCProblem {
public:
	Problem11();

	virtual uint8_t getId() override { return 11; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	uint32_t numOctopi{0};
	matrix_t<int32_t> initialOctopi;

	void increaseEnergyLevelsByOne(matrix_t<int32_t>& octopi, std::vector<std::pair<uint8_t,uint8_t>>& flashed) const;
	void flashOctopi(matrix_t<int32_t>& octopi, std::vector<std::pair<uint8_t,uint8_t>>& flashed) const;
	void clearFlashingOctopi(matrix_t<int32_t>& octopi, std::vector<std::pair<uint8_t,uint8_t>>& flashed) const;
};
