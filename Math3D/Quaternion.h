#pragma once

#include "Classes.h"

class Math3D::Quaternion
{
public:
	Quaternion();
	Quaternion(float x, float y, float z, float w);
	Quaternion(const Math3D::Vector& axis, float angle);

	float& operator[](size_t i);

	__declspec(dllexport) friend Math3D::Quaternion operator*(const Math3D::Quaternion& lquat, const Math3D::Quaternion& rquat);

	float lengthSquare() const;
	float length() const;
	Math3D::Quaternion normalized() const;
	Math3D::Quaternion& normalize();

	float& x;
	float& y;
	float& z;
	float& w;

private:
	float m_q[4];
};