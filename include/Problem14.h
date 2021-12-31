#include "AoCProblem.h"

class Problem14 : public AoCProblem {
public:
	Problem14();

	virtual uint8_t getId() override { return 14; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
};
