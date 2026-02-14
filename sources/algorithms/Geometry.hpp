#pragma once

#include <array>
#include <cmath>
#include <stdexcept>

namespace algorithms
{

// ── 2D Matrices (3×3 homogeneous) ──────────────────────────────────────

/// @brief 3×3 matrix for 2D transformations (homogeneous coordinates).
struct Matrix2D
{
	std::array<std::array<float, 3>, 3> m{};

	/// @brief Return the 3×3 identity matrix.
	static Matrix2D Identity()
	{
		Matrix2D mat{};
		mat.m[0][0] = 1.0f;
		mat.m[1][1] = 1.0f;
		mat.m[2][2] = 1.0f;
		return mat;
	}
};

/// @brief Create a 2D rotation matrix (counter-clockwise, radians).
inline Matrix2D Rotate2D(float /*angleRadians*/)
{
	// TODO: implement
	return Matrix2D::Identity();
}

/// @brief Create a 2D scale matrix.
inline Matrix2D Scale2D(float /*sx*/, float /*sy*/)
{
	// TODO: implement
	return Matrix2D::Identity();
}

/// @brief Create a 2D translation matrix.
inline Matrix2D Translate2D(float /*tx*/, float /*ty*/)
{
	// TODO: implement
	return Matrix2D::Identity();
}

/// @brief Multiply two 2D matrices.
inline Matrix2D Multiply2D(const Matrix2D& /*a*/, const Matrix2D& /*b*/)
{
	// TODO: implement matrix multiplication
	return Matrix2D::Identity();
}

/// @brief Change of coordinate system in 2D.
/// @details Computes the transformation matrix from one coordinate system to another.
inline Matrix2D ChangeCoordSystem2D(
	const Matrix2D& /*fromBasis*/,
	const Matrix2D& /*toBasis*/)
{
	// TODO: implement
	return Matrix2D::Identity();
}

// ── 3D Matrices (4×4 homogeneous) ──────────────────────────────────────

/// @brief 4×4 matrix for 3D transformations (homogeneous coordinates).
struct Matrix3D
{
	std::array<std::array<float, 4>, 4> m{};

	/// @brief Return the 4×4 identity matrix.
	static Matrix3D Identity()
	{
		Matrix3D mat{};
		mat.m[0][0] = 1.0f;
		mat.m[1][1] = 1.0f;
		mat.m[2][2] = 1.0f;
		mat.m[3][3] = 1.0f;
		return mat;
	}
};

/// @brief Create a 3D rotation matrix around the X axis (radians).
inline Matrix3D RotateX3D(float /*angleRadians*/)
{
	// TODO: implement
	return Matrix3D::Identity();
}

/// @brief Create a 3D rotation matrix around the Y axis (radians).
inline Matrix3D RotateY3D(float /*angleRadians*/)
{
	// TODO: implement
	return Matrix3D::Identity();
}

/// @brief Create a 3D rotation matrix around the Z axis (radians).
inline Matrix3D RotateZ3D(float /*angleRadians*/)
{
	// TODO: implement
	return Matrix3D::Identity();
}

/// @brief Create a 3D scale matrix.
inline Matrix3D Scale3D(float /*sx*/, float /*sy*/, float /*sz*/)
{
	// TODO: implement
	return Matrix3D::Identity();
}

/// @brief Multiply two 3D matrices.
inline Matrix3D Multiply3D(const Matrix3D& /*a*/, const Matrix3D& /*b*/)
{
	// TODO: implement matrix multiplication
	return Matrix3D::Identity();
}

/// @brief Change of coordinate system in 3D.
inline Matrix3D ChangeCoordSystem3D(
	const Matrix3D& /*fromBasis*/,
	const Matrix3D& /*toBasis*/)
{
	// TODO: implement
	return Matrix3D::Identity();
}

}  // namespace algorithms
