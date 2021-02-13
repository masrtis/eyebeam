#include "random_generator.h"

#include "normal3.h"
#include "point3.h"
#include "ray3.h"
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
    static std::normal_distribution<float> s_normalDistribution;
    return s_normalDistribution(getRng());
}

Vector3 RandomGenerator::generateRandomVector3()
{
    return Vector3(generateRandomFloat(), generateRandomFloat(), generateRandomFloat());
}

Point3 RandomGenerator::generateRandomPoint3()
{
    return Point3(generateRandomFloat(), generateRandomFloat(), generateRandomFloat());
}

Ray3 RandomGenerator::generateRandomRay3()
{
    return Ray3(generateRandomPoint3(), generateRandomVector3());
}

Normal3 RandomGenerator::generateRandomNormal3()
{
    return Normal3(generateRandomVector3());
}

} // namespace eyebeam
