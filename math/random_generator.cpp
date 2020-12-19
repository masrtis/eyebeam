#include "random_generator.h"

#include <random>

namespace eyebeam
{

namespace
{

auto& getRng()
{
    static std::random_device s_seedGenerator;
    static std::mt19937 s_rng(s_seedGenerator());
    return s_rng;
}

} // namespace

float RandomGenerator::generateRandomFloat()
{
    static std::uniform_real_distribution<float> s_uniformDistribution;
    return s_uniformDistribution(getRng());
}

Vector3 RandomGenerator::generateRandomVector3()
{
    return {generateRandomFloat(), generateRandomFloat(), generateRandomFloat()};
}

} // namespace eyebeam
