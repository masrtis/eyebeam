#include "quadratic_solver.h"

#include "random_generator.h"

#include <tuple>

#include <benchmark/benchmark.h>

namespace eyebeam
{

namespace
{

auto generateRandomQuadraticCoefficients()
{
    auto a = RandomGenerator::generateRandomFloat();
    while (areEqual(a, 0.0F))
    {
        a = RandomGenerator::generateRandomFloat();
    }

    const auto b = RandomGenerator::generateRandomFloat();
    const auto c = RandomGenerator::generateRandomFloat();

    return std::make_tuple(a, b, c);
}

} // namespace

void benchmarkQuadraticSolver(benchmark::State& state)
{
    QuadraticRoots roots;
    const auto [a, b, c] = generateRandomQuadraticCoefficients();

    for ([[maybe_unused]] auto s : state)
    {
        const auto result = solveQuadratic(a, b, c, roots);

        benchmark::DoNotOptimize(result);
        benchmark::DoNotOptimize(roots);
    }
}

// NOLINTNEXTLINE
BENCHMARK(benchmarkQuadraticSolver);

} // namespace eyebeam
