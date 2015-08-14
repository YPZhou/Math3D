#define _USE_MATH_DEFINES
#include <math.h>
#include "Quaternion.h"
#include "Vector.h"

Math3D::Quaternion::Quaternion() : x(m_q[0]), y(m_q[1]), z(m_q[2]), w(m_q[3])
{
	for (size_t i = 0; i < 4; i++)
		m_q[i] = 0;
}

Math3D::Quaternion::Quaternion(float x, float y, float z, float w) : x(m_q[0]), y(m_q[1]), z(m_q[2]), w(m_q[3])
{
	m_q[0] = x;
	m_q[1] = y;
	m_q[2] = z;
	m_q[3] = w;
}

Math3D::Quaternion::Quaternion(const Math3D::Vector& axis, float angle) : x(m_q[0]), y(m_q[1]), z(m_q[2]), w(m_q[3])
{
	float rad = angle / 360 * (float)M_PI;
	float sinRad = sinf(rad);
	float cosRad = cosf(rad);
	m_q[0] = axis.x * sinRad;
	m_q[1] = axis.y * sinRad;
	m_q[2] = axis.z * sinRad;
	m_q[3] = cosRad;
	normalize();
}

Math3D::Quaternion::Quaternion(const Math3D::Quaternion & quaternion) : x(m_q[0]), y(m_q[1]), z(m_q[2]), w(m_q[3])
{
	m_q[0] = quaternion.x;
	m_q[1] = quaternion.y;
	m_q[2] = quaternion.z;
	m_q[3] = quaternion.w;
}

float & Math3D::Quaternion::operator[](size_t i)
{
	if (i >= 4) return m_q[0];
	return m_q[i];
}

Math3D::Quaternion & Math3D::Quaternion::operator=(const Math3D::Quaternion & quaternion)
{
	m_q[0] = quaternion.x;
	m_q[1] = quaternion.y;
	m_q[2] = quaternion.z;
	m_q[3] = quaternion.w;
	return *this;
}

float Math3D::Quaternion::lengthSquare() const
{
	return powf(m_q[0], 2) + powf(m_q[1], 2) + powf(m_q[2], 2) + powf(m_q[3], 2);
}

float Math3D::Quaternion::length() const
{
	return sqrtf(lengthSquare());
}

Math3D::Quaternion Math3D::Quaternion::normalized() const
{
	float len = length();
	return Math3D::Quaternion(m_q[0] / len, m_q[1] / len, m_q[2] / len, m_q[3] / len);
}

Math3D::Quaternion & Math3D::Quaternion::normalize()
{
	float len = length();
	m_q[0] /= len;
	m_q[1] /= len;
	m_q[2] /= len;
	m_q[3] /= len;
	return *this;
}

namespace Math3D
{
	Math3D::Quaternion operator*(const Math3D::Quaternion& lquat, const Math3D::Quaternion & rquat)
	{
		return Math3D::Quaternion(lquat.m_q[3] * rquat.m_q[0] + lquat.m_q[0] * rquat.m_q[3] + lquat.m_q[1] * rquat.m_q[2] - lquat.m_q[2] * rquat.m_q[1],
								  lquat.m_q[3] * rquat.m_q[1] + lquat.m_q[1] * rquat.m_q[3] + lquat.m_q[2] * rquat.m_q[0] - lquat.m_q[0] * rquat.m_q[2],
								  lquat.m_q[3] * rquat.m_q[2] + lquat.m_q[2] * rquat.m_q[3] + lquat.m_q[0] * rquat.m_q[1] - lquat.m_q[1] * rquat.m_q[0],
								  lquat.m_q[3] * rquat.m_q[3] - lquat.m_q[0] * rquat.m_q[0] - lquat.m_q[1] * rquat.m_q[1] - lquat.m_q[2] * rquat.m_q[2]);
	}
}
