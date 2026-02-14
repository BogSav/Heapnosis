#include <gtest/gtest.h>

#include "Geometry.hpp"

namespace
{

TEST(GeometryTests, Matrix2DIdentity)
{
	auto id = algorithms::Matrix2D::Identity();
	EXPECT_FLOAT_EQ(id.m[0][0], 1.0f);
	EXPECT_FLOAT_EQ(id.m[1][1], 1.0f);
	EXPECT_FLOAT_EQ(id.m[2][2], 1.0f);
	EXPECT_FLOAT_EQ(id.m[0][1], 0.0f);
}

TEST(GeometryTests, Matrix3DIdentity)
{
	auto id = algorithms::Matrix3D::Identity();
	EXPECT_FLOAT_EQ(id.m[0][0], 1.0f);
	EXPECT_FLOAT_EQ(id.m[1][1], 1.0f);
	EXPECT_FLOAT_EQ(id.m[2][2], 1.0f);
	EXPECT_FLOAT_EQ(id.m[3][3], 1.0f);
}

TEST(GeometryTests, DISABLED_Rotate2DReturnsMatrix)
{
	auto rot = algorithms::Rotate2D(0.0f);
	// Identity rotation (0 radians) should be ~identity
	EXPECT_NEAR(rot.m[0][0], 1.0f, 1e-5f);
	EXPECT_NEAR(rot.m[1][1], 1.0f, 1e-5f);
}

TEST(GeometryTests, DISABLED_Scale2DReturnsMatrix)
{
	auto scale = algorithms::Scale2D(2.0f, 3.0f);
	EXPECT_FLOAT_EQ(scale.m[0][0], 2.0f);
	EXPECT_FLOAT_EQ(scale.m[1][1], 3.0f);
}

TEST(GeometryTests, DISABLED_Translate2DReturnsMatrix)
{
	auto trans = algorithms::Translate2D(10.0f, 20.0f);
	EXPECT_FLOAT_EQ(trans.m[0][2], 10.0f);
	EXPECT_FLOAT_EQ(trans.m[1][2], 20.0f);
}

TEST(GeometryTests, DISABLED_RotateX3DAtZero)
{
	auto rot = algorithms::RotateX3D(0.0f);
	EXPECT_NEAR(rot.m[1][1], 1.0f, 1e-5f);
	EXPECT_NEAR(rot.m[2][2], 1.0f, 1e-5f);
}

TEST(GeometryTests, DISABLED_Scale3DReturnsMatrix)
{
	auto scale = algorithms::Scale3D(2.0f, 3.0f, 4.0f);
	EXPECT_FLOAT_EQ(scale.m[0][0], 2.0f);
	EXPECT_FLOAT_EQ(scale.m[1][1], 3.0f);
	EXPECT_FLOAT_EQ(scale.m[2][2], 4.0f);
}

}  // namespace
