#include "constexpr_math.h"

#include "random_generator.h"

#include <benchmark/benchmark.h>

#include <cmath>

namespace eyebeam
{

namespace
{

void benchmarkStdAbs(benchmark::State& state)
{
    const auto rand(RandomGenerator::generateRandomFloat());

    for (auto s : state)
    {
        // NOLINTNEXTLINE(clang-analyzer-deadcode.DeadStores)
        const auto result = std::abs(rand);
    }
}

void benchmarkStdSqrt(benchmark::State& state)
{
    const auto rand(RandomGenerator::generateRandomFloat());

    for (auto s : state)
    {
        // NOLINTNEXTLINE(clang-analyzer-deadcode.DeadStores)
        const auto result = std::sqrt(rand);
    }
}

void benchmarkConstexprSqrt(benchmark::State& state)
{
    const auto rand(RandomGenerator::generateRandomFloat());

    for (auto s : state)
    {
        // NOLINTNEXTLINE(clang-analyzer-deadcode.DeadStores)
        const auto result = sqrt(rand);
    }
}

void benchmarkConstexprAbs(benchmark::State& state)
{
    const auto rand(RandomGenerator::generateRandomFloat());

    for (auto s : state)
    {
        // NOLINTNEXTLINE(clang-analyzer-deadcode.DeadStores)
        const auto result = abs(rand);
    }
}

// NOLINTNEXTLINE
BENCHMARK(benchmarkStdSqrt);

// NOLINTNEXTLINE
BENCHMARK(benchmarkStdAbs);

// NOLINTNEXTLINE
BENCHMARK(benchmarkConstexprSqrt);

// NOLINTNEXTLINE
BENCHMARK(benchmarkConstexprAbs);

} // namespace

} // namespace eyebeam
