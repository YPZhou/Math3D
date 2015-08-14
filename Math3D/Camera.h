#pragma once

#include "Classes.h"
#include "Vector.h"
#include "Matrix.h"

class Math3D::Utils::Camera
{
public:
	Camera();
	Camera(float rotX, float rotY, float rotZ, float transX, float transY, float transZ, const Math3D::Vector& camPos, const Math3D::Vector& targetPos, int fovH, int fovV, float near, float far);

	void setRotX(float rotX);
	void setRotY(float rotY);
	void setRotZ(float rotZ);

	void setTransX(float transX);
	void setTransY(float transY);
	void setTransZ(float transZ);

	void setCamPos(const Math3D::Vector& camPos);
	void setTargetPos(const Math3D::Vector& targetPos);

	void setFovH(int fovH);
	void setFovV(int fovV);

	void setNear(float near);
	void setFar(float far);

	Math3D::Matrix getMVP() const;

private:
	Math3D::Matrix lookat(const Math3D::Vector& vector, const Math3D::Vector& up) const;
	Math3D::Matrix translate(const Math3D::Vector& trans) const;
	Math3D::Matrix perspective(int fovH, int fovV, float near, float far) const;

	float m_rotX;
	float m_rotY;
	float m_rotZ;
	float m_transX;
	float m_transY;
	float m_transZ;

	Math3D::Vector m_camPos;
	Math3D::Vector m_targetPos;
	int m_fovH;
	int m_fovV;
	float m_near;
	float m_far;
};