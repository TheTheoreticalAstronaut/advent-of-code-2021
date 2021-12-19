#include "AoCProblem.h"
#include <vector>

class Problem5 : public AoCProblem {
public:
	Problem5();

	virtual uint8_t getId() override { return 5; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	enum LineType{
		H,
		V,
		O
	};
	struct Line{
		Line() = delete;
		Line(uint32_t p0x, uint32_t p0y, uint32_t p1x, uint32_t p1y){
			p0 = {p0x, p0y};
			p1 = {p1x, p1y};
			if(p0x == p1x){
				type = V;
				if(p0y > p1y){
					p0 = {p1x, p1y};
					p1 = {p0x, p0y};
				}
			}
			else if(p0y == p1y){
				type = H;
				if(p0x > p1x){
					p0 = {p1x, p1y};
					p1 = {p0x, p0y};
				}
			}
			else{
				type = O;
				if(p0x > p1x){
					p0 = {p1x, p1y};
					p1 = {p0x, p0y};
				}
			}
		}
		std::pair<uint32_t, uint32_t> p0, p1;
		LineType type;
	};

	std::vector<Line> lines;
	uint32_t sizeX{0}, sizeY{0};
};
