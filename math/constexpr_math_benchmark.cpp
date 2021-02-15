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

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(std::abs(rand));
    }
}

void benchmarkStdSqrt(benchmark::State& state)
{
    const auto rand(std::abs(RandomGenerator::generateRandomPositiveFloat()));

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(std::sqrt(rand));
    }
}

void benchmarkConstexprSqrt(benchmark::State& state)
{
    const auto rand(RandomGenerator::generateRandomPositiveFloat());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(sqrt(rand));
    }
}

void benchmarkConstexprAbs(benchmark::State& state)
{
    const auto rand(RandomGenerator::generateRandomFloat());

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(abs(rand));
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
