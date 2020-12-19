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

    for (auto s : state)
    {
        const auto result(randLeft + randRight);
    }
}

void benchmarkVector3OperatorMinus(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    Vector3 randRight(RandomGenerator::generateRandomVector3());

    for (auto s : state)
    {
        const auto result(randLeft - randRight);
    }
}

void benchmarkVector3OperatorMultiply(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    float scale = RandomGenerator::generateRandomFloat();

    for (auto s : state)
    {
        const auto result(randLeft * scale);
    }
}

void benchmarkVector3OperatorDivide(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    float scale = RandomGenerator::generateRandomFloat();

    for (auto s : state)
    {
        const auto result(randLeft / scale);
    }
}

void benchmarkVector3Negation(benchmark::State& state)
{
    Vector3 rand(RandomGenerator::generateRandomVector3());

    for (auto s : state)
    {
        const auto result(-rand);
    }
}

void benchmarkVector3DotProduct(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    Vector3 randRight(RandomGenerator::generateRandomVector3());

    for (auto s : state)
    {
        // NOLINTNEXTLINE(clang-analyzer-deadcode.DeadStores)
        const auto result = dot(randLeft, randRight);
    }
}

void benchmarkVector3CrossProduct(benchmark::State& state)
{
    Vector3 randLeft(RandomGenerator::generateRandomVector3());
    Vector3 randRight(RandomGenerator::generateRandomVector3());

    for (auto s : state)
    {
        const auto result = cross(randLeft, randRight);
    }
}

void benchmarkVector3LengthSquared(benchmark::State& state)
{
    Vector3 rand(RandomGenerator::generateRandomVector3());

    for (auto s : state)
    {
        // NOLINTNEXTLINE(clang-analyzer-deadcode.DeadStores)
        const auto result = lengthSquared(rand);
    }
}

void benchmarkVector3Length(benchmark::State& state)
{
    Vector3 rand(RandomGenerator::generateRandomVector3());

    for (auto s : state)
    {
        // NOLINTNEXTLINE(clang-analyzer-deadcode.DeadStores)
        const auto result = length(rand);
    }
}

void benchmarkVector3Norm(benchmark::State& state)
{
    Vector3 rand(RandomGenerator::generateRandomVector3());

    for (auto s : state)
    {
        const auto result = norm(rand);
    }
}

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3OperatorPlus);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3OperatorMinus);

// NOLINTNEXTLINE
BENCHMARK(benchmarkVector3OperatorMultiply);

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

BENCHMARK_MAIN();
