#include "matrix4.h"

#include <benchmark/benchmark.h>

namespace eyebeam
{

void benchmarkMatrix4DefaultCtor(benchmark::State& state)
{
    for ([[maybe_unused]] auto s : state)
    {
        Matrix4 identity;
        benchmark::DoNotOptimize(identity);
    }
}

void benchmarkMatrix4Transpose(benchmark::State& state)
{
    Matrix4 rotation(AlignedMatrixStorage{
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        -1.0F,
        0.0F,
        0.0F,
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        1.0F});

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(rotation.transpose());
    }
}

void benchmarkMatrix4MultiplyMatrices(benchmark::State& state)
{
    Matrix4 rotation(AlignedMatrixStorage{
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        -1.0F,
        0.0F,
        0.0F,
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        1.0F});

    Matrix4 translation(AlignedMatrixStorage{
        1.0F,
        0.0F,
        0.0F,
        -2.0F,
        0.0F,
        1.0F,
        0.0F,
        3.0F,
        0.0F,
        0.0F,
        1.0F,
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        1.0F});

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(translation.multiply(rotation));
    }
}

void benchmarkMatrix4MultiplyVector(benchmark::State& state)
{
    Matrix4 rotation(AlignedMatrixStorage{
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        -1.0F,
        0.0F,
        0.0F,
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        1.0F});

    Vector3 origin;

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(rotation.multiply(origin));
    }
}

void benchmarkMatrix4InverseRotation(benchmark::State& state)
{
    Matrix4 rotation(AlignedMatrixStorage{
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        -1.0F,
        0.0F,
        0.0F,
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        1.0F});

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(rotation.inverse());
    }
}

void benchmarkMatrix4InverseTranslation(benchmark::State& state)
{
    Matrix4 translation(AlignedMatrixStorage{
        1.0F,
        0.0F,
        0.0F,
        -2.0F,
        0.0F,
        1.0F,
        0.0F,
        3.0F,
        0.0F,
        0.0F,
        1.0F,
        1.0F,
        0.0F,
        0.0F,
        0.0F,
        1.0F});

    for ([[maybe_unused]] auto s : state)
    {
        benchmark::DoNotOptimize(translation.inverse());
    }
}

// NOLINTNEXTLINE
BENCHMARK(benchmarkMatrix4DefaultCtor);

// NOLINTNEXTLINE
BENCHMARK(benchmarkMatrix4Transpose);

// NOLINTNEXTLINE
BENCHMARK(benchmarkMatrix4MultiplyMatrices);

// NOLINTNEXTLINE
BENCHMARK(benchmarkMatrix4MultiplyVector);

// NOLINTNEXTLINE
BENCHMARK(benchmarkMatrix4InverseRotation);

// NOLINTNEXTLINE
BENCHMARK(benchmarkMatrix4InverseTranslation);

} // namespace eyebeam
