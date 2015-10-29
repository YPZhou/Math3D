#include <math.h>
#include "Matrix.h"
#include "Quaternion.h"
#include "Vector.h"

Math3D::Matrix::Matrix()
{
	for (size_t i = 0; i < 16; i++)
		m_m[i] = 0;
}

Math3D::Matrix::Matrix(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)
{
	m_m[0] = m0; m_m[1] = m1; m_m[2] = m2; m_m[3] = m3;
	m_m[4] = m4; m_m[5] = m5; m_m[6] = m6; m_m[7] = m7;
	m_m[8] = m8; m_m[9] = m9; m_m[10] = m10; m_m[11] = m11;
	m_m[12] = m12; m_m[13] = m13; m_m[14] = m14; m_m[15] = m15;
}

Math3D::Matrix::Matrix(const Math3D::Quaternion& quaternion)
{
	float x2 = powf(quaternion.x, 2);
	float y2 = powf(quaternion.y, 2);
	float z2 = powf(quaternion.z, 2);
	float xy = quaternion.x * quaternion.y;
	float xz = quaternion.x * quaternion.z;
	float yz = quaternion.y * quaternion.z;
	float wx = quaternion.w * quaternion.x;
	float wy = quaternion.w * quaternion.y;
	float wz = quaternion.w * quaternion.z;

	m_m[0] = 1 - 2 * (y2 + z2); m_m[1] = 2 * (xy - wz); m_m[2] = 2 * (xz + wy); m_m[3] = 0;
	m_m[4] = 2 * (xy + wz); m_m[5] = 1 - 2 * (x2 + z2); m_m[6] = 2 * (yz - wx); m_m[7] = 0;
	m_m[8] = 2 * (xz - wy); m_m[9] = 2 * (yz + wx); m_m[10] = 1 - 2 * (x2 + y2); m_m[11] = 0;
	m_m[12] = 0; m_m[13] = 0; m_m[14] = 0; m_m[15] = 1;
}

float & Math3D::Matrix::operator[](size_t i)
{
	if (i >= 16) return m_m[0];
	return m_m[i];
}

const float & Math3D::Matrix::operator[](size_t i) const
{
	if (i >= 16) return m_m[0];
	return m_m[i];
}

Math3D::Matrix Math3D::Matrix::transposed() const
{
	return Math3D::Matrix(m_m[0], m_m[4], m_m[8], m_m[12],
						  m_m[1], m_m[5], m_m[9], m_m[13],
						  m_m[2], m_m[6], m_m[10], m_m[14],
						  m_m[3], m_m[7], m_m[11], m_m[15]);
}

Math3D::Matrix & Math3D::Matrix::transpose()
{
	Math3D::Matrix transpose(m_m[0], m_m[4], m_m[8], m_m[12],
							 m_m[1], m_m[5], m_m[9], m_m[13],
							 m_m[2], m_m[6], m_m[10], m_m[14],
							 m_m[3], m_m[7], m_m[11], m_m[15]);
	for (size_t i = 0; i < 16; i++)
	{
		m_m[i] = transpose[i];
	}
	return *this;
}

namespace Math3D
{
	Math3D::Matrix operator*(const Math3D::Matrix & lmat, const Math3D::Matrix & rmat)
	{
		Math3D::Matrix res;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				res[i * 4 + j] = lmat[i * 4] * rmat[j] + lmat[i * 4 + 1] * rmat[j + 4] + lmat[i * 4 + 2] * rmat[j + 8] + lmat[i * 4 + 3] * rmat[j + 12];
		return res;
	}

	Math3D::Vector operator*(const Math3D::Matrix & lmat, const Math3D::Vector & rvec)
	{
		Math3D::Vector res;
		for (int i = 0; i < 4; i++)
			res[i] = lmat[i * 4] * rvec[0] + lmat[i * 4 + 1] * rvec[1] + lmat[i * 4 + 2] * rvec[2] + lmat[i * 4 + 3] * rvec[3];
		return res;
	}
}
