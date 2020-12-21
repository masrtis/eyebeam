#include "point3.h"

#include "random_generator.h"
#include "vector3.h"

#include <benchmark/benchmark.h>

namespace eyebeam
{

void benchmarkPoint3OperatorPlusVectorOnRight(benchmark::State& state)
{
    const Point3 randLeft(RandomGenerator::generateRandomPoint3());
    const Vector3 randRight(RandomGenerator::generateRandomVector3());

    for (auto s : state)
    {
        const auto result(randLeft + randRight);
    }
}

void benchmarkPoint3OperatorPlusVectorOnLeft(benchmark::State& state)
{
    const Vector3 randLeft(RandomGenerator::generateRandomVector3());
    const Point3 randRight(RandomGenerator::generateRandomPoint3());

    for (auto s : state)
    {
        const auto result(randLeft + randRight);
    }
}

void benchmarkPoint3OperatorMinus(benchmark::State& state)
{
    const Point3 randLeft(RandomGenerator::generateRandomPoint3());
    const Point3 randRight(RandomGenerator::generateRandomPoint3());

    for (auto s : state)
    {
        const auto result(randLeft - randRight);
    }
}

// NOLINTNEXTLINE
BENCHMARK(benchmarkPoint3OperatorPlusVectorOnRight);

// NOLINTNEXTLINE
BENCHMARK(benchmarkPoint3OperatorPlusVectorOnLeft);

// NOLINTNEXTLINE
BENCHMARK(benchmarkPoint3OperatorMinus);

} // namespace eyebeam
