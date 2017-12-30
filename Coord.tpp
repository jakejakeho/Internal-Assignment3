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
Coord<T>::Coord(Coord<U> c){
	this->x = c.x;
	this->y = c.y;
}

template<typename T>
Coord<T>::~Coord() {}

// operator overloading
template<typename T>
Coord<T> Coord<T>::operator+(const Coord<T>& c){
	Coord<T> *newC = new Coord<T>;
	newC->y = (this->x + c.x);
	newC->y = (this->y + c.y);
	return *newC;
}

template<typename T>
Coord<T> Coord<T>::operator-(const Coord<T>& c){
	Coord<T> *newC = new Coord<T>;
	newC->y = (this->x - c.x);
	newC->y = (this->y - c.y);
	return *newC;
}

template<typename T>
Coord<T>& Coord<T>::operator+=(const Coord<T>& c){
	this->x += c.x;
	this->y += c.y;
	return *this;
}

template<typename T>
Coord<T>& Coord<T>::operator-=(const Coord<T>& c){
	this->x -= c.x;
	this->y -= c.y;
	return *this;
}

template<typename T>
ostream& operator<<( ostream& os, const Coord<T>& c){
    os << "x: " << c.x << " y: " << c.y << endl;
    return os;
}


// methods
template<typename T>
T Coord<T>::getDistance(const Coord<T>* c){
	return fsqrt(pow((c->x - this->x),2) + pow((c->y - this->y),2));
}

template<typename T>
T Coord<T>::getMDistance(const Coord<T>* c){
	return abs((c->x - this->x)) + abs((c->y - this->y));
}

template<typename T>
T Coord<T>::getSlope(const Coord<T>* c){
	return pow((c->x - this->x),2) / pow((c->y - this->y),2);
}

template<typename T>
T Coord<T>::getTriangleArea(const Coord<T>* b, const Coord<T>* c){
	return abs((this->x * (b->y - c->y) + b->x * (c->y - this->y) + c->x * (this->y - b->y)) / 2);
}

template<typename T>
T Coord<T>::getRadius(Coord<T>* b, Coord<T>* c){
	return this->getMDistance(b) *b->getMDistance(c) * c->getMDistance(this) / (4 * getTriangleArea(b,c));
}

template<typename T>
float Coord<T>::fsqrt(float x){
	unsigned int i = *(unsigned int*) &x;
	// adjust bias
	i  += 127 << 23;
	// approximation of square root
	i >>= 1;
	return *(float*) &i;
}
