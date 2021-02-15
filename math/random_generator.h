#ifndef INCLUDED_RANDOM_GENERATOR_H_
#define INCLUDED_RANDOM_GENERATOR_H_

#include "normal3.h"
#include "point3.h"
#include "ray3.h"
#include "vector3.h"

namespace eyebeam
{

class RandomGenerator
{
public:
    static float generateRandomFloat();
    static float generateRandomPositiveFloat();
    static Vector3 generateRandomVector3();
    static Point3 generateRandomPoint3();
    static Ray3 generateRandomRay3();
    static Normal3 generateRandomNormal3();
};

template <typename T>
class TypedRandomGenerator;

template <>
class TypedRandomGenerator<float>
{
public:
    static auto generate()
    {
        return RandomGenerator::generateRandomFloat();
    }
};

template <>
class TypedRandomGenerator<Vector3>
{
public:
    static auto generate()
    {
        return RandomGenerator::generateRandomVector3();
    }
};

template <>
class TypedRandomGenerator<Point3>
{
public:
    static auto generate()
    {
        return RandomGenerator::generateRandomPoint3();
    }
};

template <>
class TypedRandomGenerator<Ray3>
{
public:
    static auto generate()
    {
        return RandomGenerator::generateRandomRay3();
    }
};

template <>
class TypedRandomGenerator<Normal3>
{
public:
    static auto generate()
    {
        return RandomGenerator::generateRandomNormal3();
    }
};

} // namespace eyebeam

#endif // INCLUDED_RANDOM_GENERATOR_H_
