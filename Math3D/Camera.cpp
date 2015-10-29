#define _USE_MATH_DEFINES
#include <math.h>
#include "Camera.h"
#include "Quaternion.h"

Math3D::Utils::Camera::Camera()
{
	m_rotX = 0;
	m_rotY = 0;
	m_rotZ = 0;

	m_transX = 0;
	m_transY = 0;
	m_transZ = 0;

	m_camPos = Math3D::Vector::zero();
	m_targetPos = Math3D::Vector::forward();

	m_fovH = 120;
	m_fovV = 120;

	m_near = 0.01f;
	m_far = 100;
}

Math3D::Utils::Camera::Camera(float rotX, float rotY, float rotZ, float transX, float transY, float transZ, const Math3D::Vector& camPos, const Math3D::Vector& targetPos, int fovH, int fovV, float near, float far)
{
	m_rotX = rotX;
	m_rotY = rotY;
	m_rotZ = rotZ;

	m_transX = transX;
	m_transY = transY;
	m_transZ = transZ;

	m_camPos = camPos;
	m_targetPos = targetPos;

	m_fovH = fovH;
	m_fovV = fovV;

	m_near = near;
	m_far = far;
}

void Math3D::Utils::Camera::setRotX(float rotX)
{
	m_rotX = rotX;
}

void Math3D::Utils::Camera::setRotY(float rotY)
{
	m_rotY = rotY;
}

void Math3D::Utils::Camera::setRotZ(float rotZ)
{
	m_rotZ = rotZ;
}

void Math3D::Utils::Camera::setTransX(float transX)
{
	m_transX = transX;
}

void Math3D::Utils::Camera::setTransY(float transY)
{
	m_transY = transY;
}

void Math3D::Utils::Camera::setTransZ(float transZ)
{
	m_transZ = transZ;
}

void Math3D::Utils::Camera::setCamPos(const Math3D::Vector& camPos)
{
	m_camPos = camPos;
}

void Math3D::Utils::Camera::setTargetPos(const Math3D::Vector& targetPos)
{
	m_targetPos = targetPos;
}

void Math3D::Utils::Camera::setFovH(int fovH)
{
	m_fovH = fovH;
}

void Math3D::Utils::Camera::setFovV(int fovV)
{
	m_fovV = fovV;
}

void Math3D::Utils::Camera::setNear(float near)
{
	m_near = near;
}

void Math3D::Utils::Camera::setFar(float far)
{
	m_far = far;
}

Math3D::Matrix Math3D::Utils::Camera::getMVP() const
{
	Math3D::Quaternion qX(Math3D::Vector::right(), m_rotX);
	Math3D::Quaternion qY(Math3D::Vector::up(), m_rotY);
	Math3D::Quaternion qZ(Math3D::Vector::forward(), m_rotZ);
	Math3D::Matrix rotMat((qX * qY * qZ).normalized());

	Math3D::Matrix viewMat = lookat((m_camPos - m_targetPos).normalized(), Math3D::Vector::up());
	Math3D::Matrix transMat = translate(Math3D::Vector(-m_camPos.x - m_transX, -m_camPos.y - m_transY, -m_camPos.z - m_transZ));

	Math3D::Matrix modelViewMat = viewMat * (transMat * rotMat);

	return perspective(m_fovH, m_fovV, m_near, m_far) * modelViewMat;
}

Math3D::Matrix Math3D::Utils::Camera::lookat(const Math3D::Vector& vector, const Math3D::Vector& up) const
{
	Math3D::Vector z = vector.normalized();
	Math3D::Vector y = up;
	Math3D::Vector x = up.cross(z);
	y = z.cross(x);
	x.normalize();
	y.normalize();
	return Math3D::Matrix(x[0], x[1], x[2], 0,
						  y[0], y[1], y[2], 0,
						  z[0], z[1], z[2], 0,
						  0, 0, 0, 1);
}

Math3D::Matrix Math3D::Utils::Camera::translate(const Math3D::Vector & trans) const
{
	return Math3D::Matrix(1, 0, 0, trans[0],
						  0, 1, 0, trans[1],
						  0, 0, 1, trans[2],
						  0, 0, 0, 1);
}

Math3D::Matrix Math3D::Utils::Camera::perspective(int fovH, int fovV, float near, float far) const
{
	float r = tanf(fovH / 360.0f * (float)M_PI);
	float t = tanf(fovV / 360.0f * (float)M_PI);
	return Math3D::Matrix(1 / r, 0, 0, 0,
						  0, 1 / t, 0, 0,
						  0, 0, -(far + near) / (far - near), -(2 * far * near) / (far - near),
						  0, 0, -1, 0);
}


