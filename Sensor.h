#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include "Dim2.h"
#include "Helper Functions.h"


class Sensor
{
private:
	//Full frame sensor size in millimeters
	Dim2<float> sensorDim{ 36.0f, 24.0f };
	Dim2<int> sensorResolution;

	int originalFocalLength;

	float diagonalFOV;

public:
	Sensor(Dim2<int> sensorRes, int originalFocalLength);

	float calculateFOV(int focalLength);

	Dim2<int> getCroppedResolution(int croppedFocalLength);
};

