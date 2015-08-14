#pragma once

#include "Classes.h"

class Math3D::Matrix
{
public:
	Matrix();
	Matrix(float m0, float m1, float m2, float m3,
		   float m4, float m5, float m6, float m7,
		   float m8, float m9, float m10, float m11,
		   float m12, float m13, float m14, float m16);
	Matrix(const Math3D::Quaternion& quaternion);

	float& operator[](size_t i);

	__declspec(dllexport) friend Math3D::Matrix operator*(const Math3D::Matrix& lmat, const Math3D::Matrix& rmat);
	__declspec(dllexport) friend Math3D::Matrix operator*(const Math3D::Matrix& lmat, const Math3D::Vector& rvec);

	Math3D::Matrix transposed() const;
	Math3D::Matrix& transpose();

private:
	float m_m[16];
};