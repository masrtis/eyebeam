#include "quadratic_solver.h"

#include "constexpr_math.h"

#include <array>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <utility>

namespace eyebeam
{

bool solveQuadratic(float a, float b, float c, QuadraticRoots& roots)
{
    if (areEqual(a, 0.0F))
    {
        throw std::domain_error("solveQuadratic() called with quadratic coefficient set to 0");
    }

    const auto aAsDouble = static_cast<double>(a);
    const auto bAsDouble = static_cast<double>(b);
    const auto cAsDouble = static_cast<double>(c);

    const auto discriminant = bAsDouble * bAsDouble - 4.0 * aAsDouble * cAsDouble;

    if (discriminant < 0.0)
    {
        return false;
    }

    const auto rootDiscriminant = std::sqrt(discriminant);

    const auto q = -0.5 * ((bAsDouble < 0.0) ? (bAsDouble - rootDiscriminant) : (bAsDouble + rootDiscriminant));

    roots[0] = static_cast<float>(q / aAsDouble);
    roots[1] = (std::abs(q) < std::numeric_limits<double>::epsilon()) ? roots[0] : static_cast<float>(cAsDouble / q);

    if (roots[0] > roots[1])
    {
        std::swap(roots[0], roots[1]);
    }

    return true;
}

} // namespace eyebeam
