#include <vector>
#include <algorithm>
#include <cmath>
#include "VariationGenerator.h"
#include <iostream> 

VariationGenerator::VariationGenerator()
{
}

std::vector<float> VariationGenerator::getInterpolation(
    const std::vector<float> &start,
    const std::vector<float> &end,
    float progress,
    InterpolationMode interType)
{
    std::vector<float> inter = {0,0,0,0};

    return inter; 
}

std::vector<float> VariationGenerator::getVariation(
    const std::vector<float> &input,
    const std::vector<float> &multipliers,
    PatternSortMode patternSort,
    PatternConstructMode constructMode,
    // the actual pattern in binary e.g. 101010 etc.
    unsigned short pattern)
{
    std::vector<float> variation{};
    return variation;

}
std::vector<std::vector<float>> VariationGenerator::getAllInterpolations(
       const std::vector<float> &start,
      const std::vector<float> &end,
      InterpolationMode interType)
{
    // first do the length adjustment 
    std::vector<std::vector<float>> inters; 
    if (start.size() < end.size()){
        // shrink
    }

    return inters; 
}

std::vector<std::vector<float>> VariationGenerator::getShrinkInterpolations(
       const std::vector<float> &start,
      const std::vector<float> &end)
{
    std::vector<std::vector<float>> inters; 
    if (end.size() >= start.size()) {
        return inters; // return nothing if no shrink needed
    }
    int diff = start.size() - end.size();
    if (diff > 1){ // need some more steps other than just start and end 
        for (int i=start.size()-1;i>end.size();--i){// i=end index-1
        // get start[0 -> i]
            inters.push_back(std::vector<float> (start.begin(), start.begin() + i));
        }
    }
    return inters; 
}

std::vector<std::vector<float>> VariationGenerator::getGrowInterpolations(
       const std::vector<float> &start,
      const std::vector<float> &end)
{
    std::vector<std::vector<float>> inters; 
    if (end.size() <= start.size()) {
        inters.push_back(end);
        return inters; // return nothing if no grow needed
    }
    int diff = end.size() - start.size();
    // how many elements to add to start in each interpolation? 
    // 1,2.. diff
    for (int to_add=1;to_add<=diff;++to_add){
       std::vector<float> inter{start.begin(), start.end()}; // start with start...
       for (int i=0;i<to_add;++i){
            int ind = (start.size() + i) % start.size();
            inter.push_back(start[ind]); 
       }
       inters.push_back(inter);
    }    
   
    return inters; 
}


std::vector<std::vector<float>> VariationGenerator::getSwapInterpolations (
       const std::vector<float> &start,
      const std::vector<float> &end)
{
    std::vector<std::vector<float>> inters;
    if (start.size() != end.size()) return inters; // give up if not same size. could throw an exception here
    // iterate over items in start and do pairwise comparison with end
    // if a pair differs, swap start element for end element and add it to the inters
    std::vector<float> inter{start.begin(), start.end()}; // start with start...
    for (int i=0;i<start.size()-1; ++i){
        if (inter[i] != end[i]){
            inter[i] = end[i];// update inter 
            // push back a copy of the updated version
            inters.push_back(std::vector<float> (inter.begin(), inter.end()));
        }
    }

    return inters; 
}    






// setters for control values for pattern generation
//
void PatternController::setStartValues(std::vector<float> start)
{
}
void PatternController::setEndValues(std::vector<float> end)
{
}
void PatternController::setInterpolateProgress(float progress)
{
}
void PatternController::setInterpolationMode(InterpolationMode iMode)
{
}
void PatternController::setPatternSortMode(PatternSortMode pMode)
{
}
void PatternController::setPatternConstructMode(PatternConstructMode cMode)
{
}
void PatternController::setMultipliers(std::vector<float> multipliers)
{
}
void PatternController::setPattern(unsigned short pattern)
{
}
// generates a pattern based on the start and end pattern and the interpolation progress
std::vector<float> PatternController::getCurrentPattern()
{
    std::vector<float> res; 
    return res; 
}
// generates a pattern based on the start and end pattern, the interpolation progress
// using this->getCurrentPattern and then applies a variation to it
std::vector<float> PatternController::getCurrentPatternVariation()
{
    std::vector<float> res; 
    return res; 
}


