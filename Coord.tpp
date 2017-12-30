/*
 * Coord.cpp
 *
 *  Created on: 2017¦~12¤ë26¤é
 *      Author: Jake
 */

#include "Coord.h"
#include <math.h>
using namespace std;

// constructors
template<typename T>
Coord<T>::Coord():x((T)0),y((T)0){}

template<typename T>
Coord<T>::Coord(const T X, const T Y):x(X),y(Y) {}

template<typename T>
template <class U>
Coord<T>::Coord(Coord<U> c) {
	this->x = c.x;
	this->y = c.y;
}

template<typename T>
Coord<T>::~Coord() {}

// operator overloading
template<typename T>
Coord<T> Coord<T>::operator+(const Coord<T>& c) {
	Coord<T> *newC = new Coord<T>;
	newC->x = (this->x + c.x);
	newC->y = (this->y + c.y);
	return *newC;
}

template<typename T>
Coord<T> Coord<T>::operator-(const Coord<T>& c) {
	Coord<T> *newC = new Coord<T>;
	newC->x = (this->x - c.x);
	newC->y = (this->y - c.y);
	return *newC;
}

template<typename T>
Coord<T>& Coord<T>::operator+=(const Coord<T>& c) {
	this->x += c.x;
	this->y += c.y;
	return *this;
}

template<typename T>
Coord<T>& Coord<T>::operator-=(const Coord<T>& c) {
	this->x -= c.x;
	this->y -= c.y;
	return *this;
}

template<typename T>
ostream& operator<<(ostream& os, const Coord<T>& c) {
    os << "(" << c.x << ", " << c.y << ")" << endl;
    return os;
}


// methods
template<typename T>
T Coord<T>::getDistance(const Coord<T>* c) {
 	T dx = (c->x - this->x);
 	T dy = (c->y - this->y);
	return fsqrt(pow(dx,2) + pow(dy,2));
}

template<typename T>
T Coord<T>::getMDistance(const Coord<T>* c) {
	T dx = (c->x - this->x);
	T dy = (c->y - this->y);
	return abs(dx) + abs(dy);
}

template<typename T>
T Coord<T>::getSlope(const Coord<T>* c) {
	T dx = (c->x - this->x);
	T dy = (c->y - this->y);
	return dy/dx;
}

template<typename T>
T Coord<T>::getTriangleArea(const Coord<T>* b, const Coord<T>* c) {
	T ByCyDiff = b->y - c->y;
	T CyAyDiff = c->y - this->y;
	T AyByDiff = this->y - b->y;
	return abs((this->x * ByCyDiff + b->x * CyAyDiff + c->x * AyByDiff) / 2);
}

template<typename T>
T Coord<T>::getRadius(Coord<T>* b, Coord<T>* c) {
	T AB = this->getDistance(b);
	T BC = b->getDistance(c);
	T CA = c->getDistance(this);
	T areaABC = getTriangleArea(b,c);
	return  (AB * BC * CA) / (4 * areaABC);
}

template<typename T>
float Coord<T>::fsqrt(float x) {
	unsigned int i = *(unsigned int*) &x;
	// adjust bias
	i  += 127 << 23;
	// approximation of square root
	i >>= 1;
	return *(float*) &i;
}
