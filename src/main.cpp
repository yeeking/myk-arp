#include "VariationGenerator.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <numeric>

void printVec(std::vector<float>& inter){
        std::string printableString = std::accumulate(inter.begin(), inter.end(), std::string(""), [](const std::string& result, float value) { return result + (result.empty() ? "" : ", ") + std::to_string(value); });
       std::cout << printableString << std::endl;

}

bool test1()
{
   // test 1: does it crash on a basic function call?
    std::vector<float> start = {1, 2, 3, 4};
    std::vector<float> end = {4, 5, 6, 7};
    VariationGenerator::getInterpolation(start, end, 0.5, InterpolationMode::matchLengthThenSwap);
    return true; 
}

bool test2()
{
    // testing interpolation steps counting  
    std::vector<float> start1 = {1, 2, 3, 4};
    std::vector<float> end1 = {1,2,3,4};
    std::vector<std::vector<float>> res = VariationGenerator::getShrinkInterpolations(start1, end1);
    if (res.size() != 0) {printf("Res should be 0 but is %lu", res.size()); return false; }
    return true; 
}
bool test3()
{
    // testing interpolation steps counting  
    std::vector<float> start1 = {1, 2, 3, 4, 5};
    std::vector<float> end1 = {1,2,3,4};// so start and end is a one step shrink which is different from a one stop shrink
    std::vector<std::vector<float>> res = VariationGenerator::getShrinkInterpolations(start1, end1);
    if (res.size() != 0) {printf("Res should be 0 but is %lu", res.size()); return false; }
    return true; 
}


bool test4()
{
    // testing interpolation steps counting  
    std::vector<float> start1 = {1, 2, 3, 4, 5,6};
    std::vector<float> end1 = {1,2,3,4};
    std::vector<std::vector<float>> res = VariationGenerator::getShrinkInterpolations(start1, end1);
    if (res.size() != 1) {printf("Res should be 1 but is %lu", res.size()); return false; }
    return true; 
}
bool test5()
{
    // testing interpolation steps counting  
    std::vector<float> start1 = {1, 2, 3, 4, 5,6};
    std::vector<float> end1 = {1,2,3,4};
    std::vector<std::vector<float>> res = VariationGenerator::getShrinkInterpolations(start1, end1);
    if (res[0].size() != 5) {printf("Res [0] should be 5 but is %lu", res[0].size()); return false; }
    if (res[0][4] != 5) {printf("Res [0][4] should be 5 but is %f", res[0][4]); return false; }    
    return true; 
}

bool test6()
{
    // testing interpolation steps counting  
    std::vector<float> start1 = {1, 2, 3, 4};
    std::vector<float> end1 = {1,2,3,4,5,6}; // no shrink! only grow
    std::vector<std::vector<float>> res = VariationGenerator::getShrinkInterpolations(start1, end1);
    if (res.size() != 0) {printf("Res should be 0 but is %lu", res.size()); return false; }

    return true; 
}

bool test7()
{
    // testing interpolation steps counting  
    std::vector<float> start1 = {1, 2, 3, 4};
    std::vector<float> end1 = {1,2,3,4,5,6};
    // interims should be 1,2,3,4,1, 1,2,3,4,1,2
    
    std::vector<std::vector<float>> res = VariationGenerator::getGrowInterpolations(start1, end1);
    // for (std::vector<float>& fs : res) printVec(fs);
    
    if (res.size() != 2) {printf("Res should be 2 but is %lu", res.size()); return false; }
    if (res[0].size() != 5) {printf("Res [0] should be 5 but is %lu", res[0].size()); return false; }
    if (res[0][4] != 1) {printf("Res [0][4] should be 1 but is %f", res[0][4]); return false; }    
    if (res[1].size() != 6) {printf("Res [1] should be 6 but is %lu", res[1].size()); return false; }
    if (res[1][5] != 2) {printf("Res [1][5] should be 2 but is %f", res[1][5]); return false; }    
    
    return true; 
}

bool test8()
{
    // testing interpolation steps counting  
    std::vector<float> start1 = {1, 2, 3, 4};
    std::vector<float> end1 = {1,2,3,4,5,6,7,8};
    // interims should be 1,2,3,4,1, 1,2,3,4,1,2
    
    std::vector<std::vector<float>> res = VariationGenerator::getGrowInterpolations(start1, end1);
    for (std::vector<float>& fs : res) printVec(fs);
    
    if (res.size() != 4) {printf("Res should be 4 but is %lu", res.size()); return false; }

    return true; 
}

// bool test5()
// {
//     // testing interpolation steps counting  
//     std::vector<float> start1 = {1, 2, 3, 4};
//     std::vector<float> end1 = {1,2,3,4};
//    std::vector<std::vector<float>> res = VariationGenerator::getAllInterpolations(start1, end1, InterpolationMode::matchLengthThenSwap);
//     // assert(("res should be zero ", res==0));
//     if (res.size() != 0) {printf("Res should be zero but is %i", res.size()); return false; }
//     return true; 
// }

// bool test6()
// {
//     // testing interpolation steps counting  
//     std::vector<float> start1 = {1, 2, 3, 4};
//     std::vector<float> end1 = {1,2,3,4, 5};
//    std::vector<std::vector<float>> res = VariationGenerator::getAllInterpolations(start1, end1, InterpolationMode::matchLengthThenSwap);
//     // assert(("res should be zero ", res==0));
//     if (res.size() != 2) {printf("Res should be 2 but is %i", res.size()); return false; }
//     return true; 
// }

// bool test7()
// {
//     // testing interpolation steps counting  
//     std::vector<float> start1 = {1, 2, 3, 5};
//     std::vector<float> end1 = {1,2,3,5, 5};
//    std::vector<std::vector<float>> res = VariationGenerator::getAllInterpolations(start1, end1, InterpolationMode::matchLengthThenSwap);
//     // assert(("res should be zero ", res==0));
//     if (res.size() != 1) {printf("Res should be 1 but is %i", res.size()); return false; }
//     return true; 
// }

bool testN()
{
    // test 2: does it return the right thing? 
    std::vector<float> start1 = {1, 2, 3, 4};
    std::vector<float> end1 = {4, 5, 6, 7};
    std::vector<float> res1 = VariationGenerator::getInterpolation(start1, end1, 0.5, InterpolationMode::matchLengthThenSwap);
    // want 1,2,6,7
    if (res1[0] != 1) return false; 
    if (res1[1] != 2) return false; 
    if (res1[2] != 6) return false; 
    if (res1[3] != 7) return false; 
    return true; 
}

int main()
{
 
    if (!test1()) printf("Test 1 failed\n");
    else printf("Test 1 passed\n");
    
    if (!test2()) printf("Test 2 failed\n");
    else printf("Test 2 passed\n");

    if (!test3()) printf("Test 3 failed\n");
    else printf("Test 3 passed\n");
    
    if (!test4()) printf("Test 4 failed\n");
    else printf("Test 4 passed\n");
    
    if (!test5()) printf("Test 5 failed\n");
    else printf("Test 5 passed\n");
    
    if (!test6()) printf("Test 6 failed\n");
    else printf("Test 6 passed\n");
    
    if (!test7()) printf("Test 7 failed\n");
    else printf("Test 7 passed\n");
         
    if (!test8()) printf("Test 8 failed\n");
    else printf("Test 8 passed\n");
}