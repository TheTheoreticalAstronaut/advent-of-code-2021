#include "AoCProblem.h"
#include <string>
#include <map>

using pairs_t = std::map<std::string, ret_t>;
using rules_t = std::map<std::string, std::string>;
using counts_t = std::map<const char, ret_t>;

class Problem14 : public AoCProblem {
public:
	Problem14();

	virtual uint8_t getId() override { return 14; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	char first, last;
	pairs_t initPairs;
	rules_t subRules;

	pairs_t propagatePairs(uint8_t numSteps);
	counts_t countLetters(const pairs_t& pairs) const;
};
