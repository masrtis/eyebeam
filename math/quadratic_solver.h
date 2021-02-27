#ifndef INCLUDED_QUADRATIC_SOLVER_H_
#define INCLUDED_QUADRATIC_SOLVER_H_

#include <array>

namespace eyebeam
{

using QuadraticRoots = std::array<float, 2>;

[[nodiscard]] bool solveQuadratic(float a, float b, float c, QuadraticRoots& roots);

} // namespace eyebeam

#endif // INCLUDED_QUADRATIC_SOLVER_H_
