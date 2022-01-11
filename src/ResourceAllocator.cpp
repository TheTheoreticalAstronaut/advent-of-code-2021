#include "ResourceAllocator.h"
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"
#include "Problem7.h"
#include "Problem8.h"
#include "Problem9.h"
#include "Problem10.h"
#include "Problem11.h"
#include "Problem12.h"
#include "Problem13.h"
#include "Problem14.h"
#include "Problem15.h"

void ResourceAllocator::addAllProblems(){
    problems.push_back(std::make_unique<Problem1>());
    problems.push_back(std::make_unique<Problem2>());
    problems.push_back(std::make_unique<Problem3>());
    problems.push_back(std::make_unique<Problem4>());
    problems.push_back(std::make_unique<Problem5>());
    problems.push_back(std::make_unique<Problem6>());
    problems.push_back(std::make_unique<Problem7>());
    problems.push_back(std::make_unique<Problem8>());
    problems.push_back(std::make_unique<Problem9>());
    problems.push_back(std::make_unique<Problem10>());
    problems.push_back(std::make_unique<Problem11>());
    problems.push_back(std::make_unique<Problem12>());
    problems.push_back(std::make_unique<Problem13>());
    problems.push_back(std::make_unique<Problem14>());
    problems.push_back(std::make_unique<Problem15>());
}

void ResourceAllocator::addProblem(uint8_t problem) {
    switch (problem) {
    case 1:
        problems.push_back(std::make_unique<Problem1>());
        break;
    case 2:
        problems.push_back(std::make_unique<Problem2>());
        break;
    case 3:
        problems.push_back(std::make_unique<Problem3>());
        break;
    case 4:
        problems.push_back(std::make_unique<Problem4>());
        break;
    case 5:
        problems.push_back(std::make_unique<Problem5>());
        break;
    case 6:
        problems.push_back(std::make_unique<Problem6>());
        break;
    case 7:
        problems.push_back(std::make_unique<Problem7>());
        break;
    case 8:
        problems.push_back(std::make_unique<Problem8>());
        break;
    case 9:
        problems.push_back(std::make_unique<Problem9>());
        break;
    case 10:
        problems.push_back(std::make_unique<Problem10>());
        break;
    case 11:
        problems.push_back(std::make_unique<Problem11>());
        break;
    case 12:
        problems.push_back(std::make_unique<Problem12>());
        break;
    case 13:
        problems.push_back(std::make_unique<Problem13>());
        break;
    case 14:
        problems.push_back(std::make_unique<Problem14>());
        break;
    case 15:
        problems.push_back(std::make_unique<Problem15>());
        break;
    default:
        break;
    }
}