#include "angle.h"

#include "constexpr_math.h"

#include <gtest/gtest.h>

namespace eyebeam
{

// NOLINTNEXTLINE
TEST(AngleTests, 180DegreesConvertsToPiRadians)
{
    // GIVEN:

    // WHEN:
    constexpr auto result = toRadians(Degrees(180.0F));

    // THEN:
    constexpr auto expected = Radians(constants::pi);
    EXPECT_TRUE(areEqual(result, expected));
}

// NOLINTNEXTLINE
TEST(AngleTests, 2PiRadiansConvertsTo360Degrees)
{
    // GIVEN:

    // WHEN:
    constexpr auto result = toDegrees(Radians(2.0F * constants::pi));

    // THEN:
    constexpr auto expected = Degrees(360.0F);
    EXPECT_TRUE(areEqual(result, expected));
}

} // namespace eyebeam
