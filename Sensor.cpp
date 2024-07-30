#include "Sensor.h"

Sensor::Sensor(Dim2<int> sensorRes, int originalFocalLength)
{
	this->sensorResolution = sensorRes;
	this->originalFocalLength = originalFocalLength;
	this->diagonalFOV = calculateFOV(originalFocalLength);
}

float Sensor::calculateFOV(int focalLength)
{
	//Pythagorean theorem
	float diagonalLength = std::sqrtf(std::powf(sensorDim.width, 2) + std::powf(sensorDim.height, 2));

	float halfDiagonal = diagonalLength / 2.0f;

	float hypotenuseLength = sqrtf(std::powf(halfDiagonal, 2) + std::powf(focalLength, 2));

	//radians
	float halfAngle = acosf(focalLength / hypotenuseLength);

	//in degrees
	return 2 * halfAngle * 180.0f / M_PI;
}

Dim2<int> Sensor::getCroppedResolution(int croppedFocalLength)
{
	float croppedDiagonalFOV = calculateFOV(croppedFocalLength);

	float ratio = croppedDiagonalFOV / diagonalFOV;

	//similar triangles, so we can scale the catheti with the same ratio the hypotenuse got scaled by
	return sensorResolution * ratio;
}
