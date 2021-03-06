#include "AoCProblem.h"
#include <string>
#include <stack>

class Problem10 : public AoCProblem {
public:
	Problem10();

	virtual uint8_t getId() override { return 10; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	std::vector<std::string> lines;

	bool isLineCorrupted(const std::string& line, std::stack<char>& brackets) const;
};
