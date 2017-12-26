/*
 * main.cpp
 *
 *  Created on: 2017¦~12¤ë26¤é
 *      Author: Jake
 */
#include <iostream>
#include <typeinfo>
#include "Coord.h"
using namespace std;


int main(){
	Coord<float> *c1 = new Coord<float>(0.5, 0.5);
	Coord<float> *c2 = new Coord<float>(1.5, 1.5);
	Coord<float> *c3 = new Coord<float>(2.5, 0.5);

	cout << "c1:\t\t" << *c1;
	cout << "c2:\t\t" << *c2;
	cout << "c1 + c2:\t" << *c1 + *c2;
	cout << "c1 - c2:\t" << *c1 - *c2;
	*c1 += *c2;
	cout << "c1:\t\t" << *c1;
	*c1 -= *c2;
	cout << "c1:\t\t" << *c1;
	cout << endl;

	cout << "c1->getDistance(c2)\t\t" << c1->getDistance(c2) << endl;
	cout << "c1->getMDistance(c2)\t\t" << c1->getMDistance(c2) << endl;
	cout << "c1->getSlope(c2)\t\t" << c1->getSlope(c2) << endl;
	cout << "c1->getTriangleArea(c2, c3)\t" << c1->getTriangleArea(c2, c3) << endl;
	cout << "c1->getRadius(c2, c3)\t\t" << c1->getRadius(c2, c3) << endl;
	cout << endl;

	cout << "convert" << endl;
	Coord<int> c4 = *c1;
	cout << "c4:\t\t" << c4;

}


