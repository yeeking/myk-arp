#include<vector>

// pow(16, 2)12
// pattern sorting: fairly self explanatory pattern sort types
enum class PatternSortMode
{
  none,
  up,
  down,
  upDown,
  downUp,
  random
};
// when constructing the variation, what order to do the steps in
// if you go multiplyFirst, it'll generate the long sequence with the multipliers
// first, then sort
enum class PatternConstructMode
{
  sortFirst,
  multiplyFirst
};

// matchLengthThenSwap means first match array lengths by repeating or removing
// then interpolate to the new array by swapping
// not sure how else you'd do it ...
// e.g 1234,56789
// 1234
// 12344 - match length
// 52344 - swap
// 56344 - swap
// 56744 - swap
// 56784 - swap
// 56789 - swap
enum class InterpolationMode
{
  matchLengthThenSwap
};

// class enum PatternType{}

class VariationGenerator
{
public:
  VariationGenerator();
  // compute an interpolation between the start array and the end array
  // which might be different lengths
  // progress dictates how far from start to end the interpolation is
  // so e.g. 1234,5678,0.5,matchLengthThenSwap  -> matchLengthThenSwap half of it -> 5634

  // interType is the way the interpolation should be done
  static std::vector<float> getInterpolation(
      const std::vector<float> &start,
      const std::vector<float> &end,
      float progress,
      InterpolationMode interType);
  /** compute all stages of the interpolation between start and end. 
   * The first element will always be 'start' the last will always be 'end' 
  */
  static std::vector<std::vector<float>> getAllInterpolations(
       const std::vector<float> &start,
      const std::vector<float> &end,
      InterpolationMode interType);
  
  /** compute the interim stages required to shrink from start to end.
   * e.g. 
   * if {1,2,3,4,5} -> {1,2,3} = {{1,2,3,4,5}, {1,2,3,4}, {1,2,3}}}
   * So the interim stage returned is {{1,2,3,4}}
   * if end length >= start length (no shrink needed) returns {{}}
  */
  static std::vector<std::vector<float>> getShrinkInterpolations(
       const std::vector<float> &start,
      const std::vector<float> &end);

    /** compute the interim stages required to grow from start to end by looping round start to fill in the gaps
   * e.g. {1,2,3} -> {1,2,3,4,5} = {{1,2,3}, {1,2,3,1}, {1,2,3,1,2}}}
   * so returns {{1,2,3,1}}
   * if end length <= start length (no grow needed) returns {{}}
  */
  static std::vector<std::vector<float>> getGrowInterpolations(
       const std::vector<float> &start,
      const std::vector<float> &end);
  
  /** works out how to interpolate from start to end using swaps. 
   * Assumes they are the same length. Only returns interim steps 
   * {1,2,3} -> {4,5,6} -> {{1,2,3}, {4,2,3}, {4,5,3}, {4,5,6}} 
   * so -> return {4,2,3}, {4,5,3}
  */
  static std::vector<std::vector<float>> getSwapInterpolations (
       const std::vector<float> &start,
      const std::vector<float> &end);
    
  // generate a variation of the sent input vector
  // mutlipliers: use these to specify mutipliers used to generate variations
  //  if {1} -> just one variation
  static std::vector<float> getVariation(
      const std::vector<float> &input,
      const std::vector<float> &multipliers,
      PatternSortMode patternSort,
      PatternConstructMode constructMode,
      // the actual pattern in binary e.g. 101010 etc.
      unsigned short pattern);


private:

  // loop control variables
  static std::vector<float> sortUp(const std::vector<float> &input);
  static std::vector<float> sortDown(const std::vector<float> &input);
  // apply the sent pattern to the sent input up to the sent length
  // e.g. 1,2,3 101010 -> 1,0,2,0,3,0
  static std::vector<float> getPattern(std::vector<float> input, unsigned short pattern);
};

//
class PatternController
{
public:
  PatternController();

  // setters for control values for pattern generation
  //
  void setStartValues(std::vector<float> start);
  void setEndValues(std::vector<float> end);
  void setInterpolateProgress(float progress);
  void setInterpolationMode(InterpolationMode iMode);
  void setPatternSortMode(PatternSortMode pMode);
  void setPatternConstructMode(PatternConstructMode cMode);
  void setMultipliers(std::vector<float> multipliers);
  void setPattern(unsigned short pattern);
  // generates a pattern based on the start and end pattern and the interpolation progress
  std::vector<float> getCurrentPattern();
  // generates a pattern based on the start and end pattern, the interpolation progress
  // using this->getCurrentPattern and then applies a variation to it
  std::vector<float> getCurrentPatternVariation();

private:
  // when computing interpolations, this is the start pattern
  std::vector<float> startValues;
  // when computing interpolations, this is the end pattern
  std::vector<float> endValues;
  // when computing interpolations, this is position through the inpolation steps
  // to return at
  float interpolateProgress;
  // the method used to comppute interpolations
  InterpolationMode interpolationMode;
  // used to scale up the values when generating variations
  std::vector<float> multipliers;
  // the method used to apply sorting to the pattern when generating variations
  PatternSortMode patternSortMode;
  // the order in which processes are carried out when constructing the pattern variatoins
  PatternConstructMode patternConstructMode;
  unsigned short pattern;
};
