#include "AoCProblem.h"
#include <memory>
#include <vector>

class ResourceAllocator{
public:
    void addAllProblems();

    void addProblem(uint8_t problem);

    const std::vector<std::unique_ptr<AoCProblem>>& getProblems() const {
        return problems;
    }
private:
    std::vector<std::unique_ptr<AoCProblem>> problems;
};