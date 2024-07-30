#include <iostream>

#include "Helper Functions.h"
#include "Dim2.h"
#include "Sensor.h"

int main() {

	//std::cout << "Input number is: " << getNumberInput() << "\n";

	std::cout << "Enter the horizontal resolution of the camera sensor!\n";
	int width = getNumberInput();

	std::cout << "Enter the vertical resolution of the camera sensor!\n";
	int height = getNumberInput();

	std::cout << "Enter the lens' focal length with which the original image was captured!\n";
	int originalFocalLength = getNumberInput();

	std::cout << "Enter the focal length which you want to crop to!\n";
	int croppedFocalLength = getNumberInput();

	Sensor sensor(Dim2<int>{ width, height }, originalFocalLength);

	Dim2<int> croppedResolution = sensor.getCroppedResolution(croppedFocalLength);
	int totalNumberOfPixels = croppedResolution.width * croppedResolution.height;

	std::cout << croppedResolution << " which is approximately " << totalNumberOfPixels / int(1e6) << "." << totalNumberOfPixels % 10 << " Megapixels.";
}
