#pragma once
#include <iostream>


template<typename T>
struct Dim2 {
	T width, height;
};

template<typename T>
Dim2<T> operator*(Dim2<T> obj, float multiplier) {
	return Dim2<T>{T(obj.width * multiplier), T(obj.height * multiplier)};
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, Dim2<T>& obj) {
	return os << int(obj.width) << "x" << int(obj.height);
}