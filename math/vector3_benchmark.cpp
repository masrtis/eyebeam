#include "vector3.h"

#include "random_generator.h"

#include <benchmark/benchmark.h>

namespace eyebeam
{

namespace
{

void benchmarkVector3OperatorPlus(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    Vector3 randRight(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(randLeft + randRight);
    }
}

void benchmarkVector3OperatorMinus(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    Vector3 randRight(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(randLeft - randRight);
    }
}

void benchmarkVector3OperatorMultiplyScaleOnRight(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    float scale = RandomGenerator::generateRandomFloat();

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(randLeft * scale);
    }
}

void benchmarkVector3OperatorMultiplyScaleOnLeft(benchmark::State& state)
{
    Vector3 randRight(RandomGenerator::generateRandomVector3());
    float scale = RandomGenerator::generateRandomFloat();

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(scale * randRight);
    }
}

void benchmarkVector3OperatorDivide(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    float scale = RandomGenerator::generateRandomFloat();

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(randLeft / scale);
    }
}

void benchmarkVector3Negation(benchmark::State& state)
{
    Vector3 rand(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(-rand);
    }
}

void benchmarkVector3DotProduct(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    Vector3 randRight(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(dot(randLeft, randRight));
    }
}

void benchmarkVector3CrossProduct(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    Vector3 randRight(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(cross(randLeft, randRight));
    }
}

void benchmarkVector3LengthSquared(benchmark::State& state)
{
    Vector3 rand(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(lengthSquared(rand));
    }
}

void benchmarkVector3Length(benchmark::State& state)
{
    Vector3 rand(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(length(rand));
    }
}

void benchmarkVector3Norm(benchmark::State& state)
{
    Vector3 rand(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(norm(rand));
    }
}

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3OperatorPlus);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3OperatorMinus);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3OperatorMultiplyScaleOnRight);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3OperatorMultiplyScaleOnLeft);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3OperatorDivide);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3Negation);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3DotProduct);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3CrossProduct);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3LengthSquared);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3Length);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3Norm);

} // namespace
} // namespace eyebeam
