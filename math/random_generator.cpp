#include "random_generator.h"

#include "point3.h"
#include "vector3.h"

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
    return Vector3(generateRandomFloat(), generateRandomFloat(), generateRandomFloat());
}

Point3 RandomGenerator::generateRandomPoint3()
{
    return Point3(generateRandomFloat(), generateRandomFloat(), generateRandomFloat());
}

} // namespace eyebeam
