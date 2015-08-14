#include <iostream>
#include "Vector.h"

int main(int argc, char* argv)
{
	Math3D::Vector v1(1, 2, 3);
	std::cout << "V1 " << v1.x << " " << v1.y << " " << v1.z << std::endl;

	Math3D::Vector v2(4, 5, 6);
	std::cout << "V2 " << v2[0] << " " << v2[1] << " " << v2[2] << std::endl;

	Math3D::Vector v3 = v1 + v2;
	std::cout << "V3 " << v3[0] << " " << v3[1] << " " << v3[2] << std::endl;

	Math3D::Vector v4 = v1 - v2;
	std::cout << "V4 " << v4[0] << " " << v4[1] << " " << v4[2] << std::endl;

	float d = v3 * v1;
	std::cout << "Dot " << d << std::endl;

	Math3D::Vector v5 = v1 * d;
	std::cout << "V5 " << v5.x << " " << v5.y << " " << v5.z << std::endl;

	Math3D::Vector v6 = d * v2;
	std::cout << "V6 " << v6.x << " " << v6.y << " " << v6.z << std::endl;

	system("pause");
	return 0;
}