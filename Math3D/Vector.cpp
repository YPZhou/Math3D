#include <math.h>
#include "Vector.h"

Math3D::Vector::Vector() : x(m_v[0]), y(m_v[1]), z(m_v[2])
{
	for (size_t i = 0; i < 3; i++)
		m_v[i] = 0;
}

Math3D::Vector::Vector(float x, float y, float z) : x(m_v[0]), y(m_v[1]), z(m_v[2])
{
	m_v[0] = x;
	m_v[1] = y;
	m_v[2] = z;
}

Math3D::Vector::Vector(const Math3D::Vector & vector) : x(m_v[0]), y(m_v[1]), z(m_v[2])
{
	m_v[0] = vector.x;
	m_v[1] = vector.y;
	m_v[2] = vector.z;
}

float& Math3D::Vector::operator[](size_t i)
{
	if (i >= 3) return m_v[0];
	return m_v[i];
}

const float & Math3D::Vector::operator[](size_t i) const
{
	if (i >= 3) return m_v[0];
	return m_v[i];
}

Math3D::Vector & Math3D::Vector::operator=(const Math3D::Vector & vector)
{
	m_v[0] = vector.x;
	m_v[1] = vector.y;
	m_v[2] = vector.z;
	return *this;
}

float Math3D::Vector::lengthSquare() const
{
	return powf(m_v[0], 2) + powf(m_v[1], 2) + powf(m_v[2], 2);
}

float Math3D::Vector::length() const
{
	return sqrtf(lengthSquare());
}

float Math3D::Vector::dot(const Math3D::Vector & vector) const
{
	return m_v[0] * vector.m_v[0] + m_v[1] * vector.m_v[1] + m_v[2] * vector.m_v[2];
}

Math3D::Vector Math3D::Vector::cross(const Math3D::Vector & vector) const
{
	return Math3D::Vector(m_v[1] * vector.m_v[2] - m_v[2] * vector.m_v[1],
						  m_v[2] * vector.m_v[0] - m_v[0] * vector.m_v[2],
						  m_v[0] * vector.m_v[1] - m_v[1] * vector.m_v[0]);
}

Math3D::Vector Math3D::Vector::scaled(float scale) const
{
	return *this * scale;
}

Math3D::Vector& Math3D::Vector::scale(float scale)
{
	m_v[0] *= scale;
	m_v[1] *= scale;
	m_v[2] *= scale;
	return *this;
}

Math3D::Vector Math3D::Vector::normalized() const
{
	return scaled(1 / length());
}

Math3D::Vector & Math3D::Vector::normalize()
{
	scale(1 / length());
	return *this;
}

Math3D::Vector Math3D::Vector::zero()
{
	return Math3D::Vector(0, 0, 0);
}

Math3D::Vector Math3D::Vector::one()
{
	return Math3D::Vector(1, 1, 1);
}

Math3D::Vector Math3D::Vector::up()
{
	return Math3D::Vector(0, 1, 0);
}

Math3D::Vector Math3D::Vector::forward()
{
	return Math3D::Vector(0, 0, 1);
}

Math3D::Vector Math3D::Vector::right()
{
	return Math3D::Vector(1, 0, 0);
}

namespace Math3D
{
	Math3D::Vector operator+(const Math3D::Vector lvec, const Math3D::Vector& rvec)
	{
		return Math3D::Vector(lvec.m_v[0] + rvec.m_v[0], lvec.m_v[1] + rvec.m_v[1], lvec.m_v[2] + rvec.m_v[2]);
	}

	Math3D::Vector operator-(const Math3D::Vector lvec, const Math3D::Vector& rvec)
	{
		return Math3D::Vector(lvec.m_v[0] - rvec.m_v[0], lvec.m_v[1] - rvec.m_v[1], lvec.m_v[2] - rvec.m_v[2]);
	}

	float operator*(const Math3D::Vector& lvec, const Math3D::Vector& rvec)
	{
		return lvec.m_v[0] * rvec.m_v[0] + lvec.m_v[1] * rvec.m_v[1] + lvec.m_v[2] * rvec.m_v[2];
	}

	Math3D::Vector operator*(const Math3D::Vector lvec, float rscale)
	{
		return Math3D::Vector(lvec.m_v[0] * rscale, lvec.m_v[1] * rscale, lvec.m_v[2] * rscale);
	}

	Math3D::Vector operator*(float lscale, const Math3D::Vector rvec)
	{
		return rvec * lscale;
	}
}
