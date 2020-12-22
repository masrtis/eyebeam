#include "ray3.h"

#include "point3.h"
#include "random_generator.h"
#include "vector3.h"

#include <benchmark/benchmark.h>

namespace eyebeam
{

namespace
{

void benchmarkRay3Construction(benchmark::State& state)
{
    const auto randomOrigin(RandomGenerator::generateRandomPoint3());
    const auto randomDirection(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(Ray3(randomOrigin, randomDirection));
    }
}

void benchmarkRay3Evaluate(benchmark::State& state)
{
    const auto randomRay(RandomGenerator::generateRandomRay3());
    const auto randomT(RandomGenerator::generateRandomFloat());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(evaluate(randomRay, randomT));
    }
}

// NOLINTNEXTLINE
BENCHMARK(benchmarkRay3Construction);

// NOLINTNEXTLINE
BENCHMARK(benchmarkRay3Evaluate);

} // namespace

} // namespace eyebeam
