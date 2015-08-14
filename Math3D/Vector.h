#pragma once

#include "Classes.h"

class Math3D::Vector
{
public:
	Vector();
	Vector(float x, float y, float z);
	Vector(const Math3D::Vector& vector);

	float& operator[](size_t i);
	Math3D::Vector& operator=(const Math3D::Vector& vector);

	__declspec(dllexport) friend Math3D::Vector operator+(const Math3D::Vector lvec, const Math3D::Vector& rvec);
	__declspec(dllexport) friend Math3D::Vector operator-(const Math3D::Vector lvec, const Math3D::Vector& rvec);
	__declspec(dllexport) friend float operator*(const Math3D::Vector& lvec, const Math3D::Vector& rvec);
	__declspec(dllexport) friend Math3D::Vector operator*(const Math3D::Vector lvec, float rscale);
	__declspec(dllexport) friend Math3D::Vector operator*(float lscale, const Math3D::Vector rvec);

	float lengthSquare() const;
	float length() const;
	float dot(const Math3D::Vector& vector) const;
	Math3D::Vector cross(const Math3D::Vector& vector) const;
	Math3D::Vector scaled(float scale) const;
	Math3D::Vector& scale(float scale);
	Math3D::Vector normalized() const;
	Math3D::Vector& normalize();

	static Math3D::Vector zero();
	static Math3D::Vector one();
	static Math3D::Vector up();
	static Math3D::Vector forward();
	static Math3D::Vector right();

	float& x;
	float& y;
	float& z;

private:
	float m_v[3];
};