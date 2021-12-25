#include "AoCProblem.h"

class Problem8 : public AoCProblem {
public:
	Problem8();

	virtual uint8_t getId() override { return 8; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
};
