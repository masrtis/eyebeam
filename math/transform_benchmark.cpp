#include "transform.h"

#include "random_generator.h"

#include <benchmark/benchmark.h>

namespace eyebeam
{

namespace
{

void benchmarkTransformDefaultConstruction(benchmark::State& state)
{
    for ([[maybe_unused]] auto s : state)
    {
        const Transform t;
        benchmark::DoNotOptimize(t);
    }
}

void benchmarkTransformInverse(benchmark::State& state)
{
    const auto rAxisAngle(Transform::rotateAxisAngle(
        RandomGenerator::generateRandomVector3(),
        Radians(RandomGenerator::generateRandomFloat())));

    for ([[maybe_unused]] auto s : state)
    {
        const auto inverse(rAxisAngle.inverse());
        benchmark::DoNotOptimize(inverse);
    }
}

void benchmarkTransformTranspose(benchmark::State& state)
{
    const auto rAxisAngle(Transform::rotateAxisAngle(
        RandomGenerator::generateRandomVector3(),
        Radians(RandomGenerator::generateRandomFloat())));

    for ([[maybe_unused]] auto s : state)
    {
        const auto transpose(rAxisAngle.transpose());
        benchmark::DoNotOptimize(transpose);
    }
}

void benchmarkTransformTranslate(benchmark::State& state)
{
    const auto delta(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        const auto t(Transform::translate(delta));
        benchmark::DoNotOptimize(t);
    }
}

void benchmarkTransformScale(benchmark::State& state)
{
    const auto scaleFactors(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        const auto scale(Transform::scale(scaleFactors.x(), scaleFactors.y(), scaleFactors.z()));
        benchmark::DoNotOptimize(scale);
    }
}

void benchmarkTransformRotateX(benchmark::State& state)
{
    const Radians angle(RandomGenerator::generateRandomFloat());

    for ([[maybe_unused]] auto s : state)
    {
        const auto rX(Transform::rotateX(angle));
        benchmark::DoNotOptimize(rX);
    }
}

void benchmarkTransformRotateY(benchmark::State& state)
{
    const Radians angle(RandomGenerator::generateRandomFloat());

    for ([[maybe_unused]] auto s : state)
    {
        const auto rY(Transform::rotateY(angle));
        benchmark::DoNotOptimize(rY);
    }
}

void benchmarkTransformRotateZ(benchmark::State& state)
{
    const Radians angle(RandomGenerator::generateRandomFloat());

    for ([[maybe_unused]] auto s : state)
    {
        const auto rZ(Transform::rotateZ(angle));
        benchmark::DoNotOptimize(rZ);
    }
}

void benchmarkTransformRotateAxisAngle(benchmark::State& state)
{
    const auto axis(RandomGenerator::generateRandomVector3());
    const Radians angle(RandomGenerator::generateRandomFloat());

    for ([[maybe_unused]] auto s : state)
    {
        const auto rAxisAngle(Transform::rotateAxisAngle(axis, angle));
        benchmark::DoNotOptimize(rAxisAngle);
    }
}

void benchmarkTransformLookAt(benchmark::State& state)
{
    const auto cameraPosition(RandomGenerator::generateRandomPoint3());
    const auto lookAt(RandomGenerator::generateRandomPoint3());
    const auto upAxis(RandomGenerator::generateRandomVector3());

    for ([[maybe_unused]] auto s : state)
    {
        const auto worldToCamera(Transform::lookAt(cameraPosition, lookAt, upAxis));
        benchmark::DoNotOptimize(worldToCamera);
    }
}

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformDefaultConstruction);

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformInverse);

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformTranspose);

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformTranslate);

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformScale);

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformRotateX);

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformRotateY);

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformRotateZ);

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformRotateAxisAngle);

// NOLINTNEXTLINE
BENCHMARK(benchmarkTransformLookAt);

} // namespace

} // namespace eyebeam
