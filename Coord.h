/*
 * Coord.h
 *
 *  Created on: 2017¦~12¤ë26¤é
 *      Author: Jake
 */

#ifndef COORD_H_
#define COORD_H_
#include <iostream>
using namespace std;

template<typename T> class Coord;
template<typename T> ostream& operator<< (ostream&, const Coord<T>&);

template<typename T = uint16_t>
class Coord {
public:
	Coord();
	Coord(const T, const T);
	template <class U>
	Coord(Coord<U>);
	~Coord();

	T x;
	T y;

	Coord<T> operator+(const Coord<T>&);
	Coord<T> operator-(const Coord<T>&);
	Coord<T>& operator+=(const Coord<T>&);
	Coord<T>& operator-=(const Coord<T>&);
	friend ostream& operator<< <>(ostream&, const Coord<T>&);

	T getDistance(const Coord<T>*);
	T getMDistance(const Coord<T>*);
	T getSlope(const Coord<T>*);
	T getTriangleArea(const Coord<T>*, const Coord<T>*);
	T getRadius(Coord<T>*, Coord<T>*);

	static float fsqrt(float);

private:

};

#include "Coord.tpp"
#endif /* COORD_H_ */
