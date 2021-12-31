#include "AoCProblem.h"

class Problem13 : public AoCProblem {
public:
	Problem13();

	virtual uint8_t getId() override { return 13; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
};
