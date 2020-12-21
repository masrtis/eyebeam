#ifndef INCLUDED_RANDOM_GENERATOR_H_
#define INCLUDED_RANDOM_GENERATOR_H_

#include "point3.h"
#include "vector3.h"

namespace eyebeam
{

class RandomGenerator
{
public:
    static float generateRandomFloat();
    static Vector3 generateRandomVector3();
    static Point3 generateRandomPoint3();
};

} // namespace eyebeam

#endif // INCLUDED_RANDOM_GENERATOR_H_
