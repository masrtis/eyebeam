#include "normal3.h"

#include "direction_typed_test.h"

#include <gtest/gtest.h>

namespace eyebeam
{

// NOLINTNEXTLINE
INSTANTIATE_TYPED_TEST_SUITE_P(InstantiateNormal3, DirectionTests, Normal3);

} // namespace eyebeam
