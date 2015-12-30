/*
 * Model.cpp
 *
 *  Created on: 2009/11/29
 *      Author: zwshen
 */

#include "Model.h"
#include "Circle.h"
//#include "Triangle.h"
#include <cstdlib>

using namespace std;

/*Model::Model() {
}

/*Model::~Model() {
	for (unsigned int i = 0; i < m_shapes.size(); i++)
		delete m_shapes[i];
}

Shape* Model::createShape(Shape::ShapeType st) {
	if (st == Shape::CircleType)
		return new Circle();
	else if (st == Shape::TriangleType)
		return new Triangle();
	return NULL; // or throw exception
}

void Model::addShape(Shape::ShapeType st) {
	m_shapes.push_back(createShape(st));
}

void Model::deleteLastShape() {
	m_shapes.pop_back();
}

string Model::toString() {
	string s("shapes: ");
	if (m_shapes.size() > 0) {
		for (unsigned int i = 0; i < m_shapes.size() - 1; i++)
			s += m_shapes[i]->toString() + " ";
		s += m_shapes[m_shapes.size() - 1]->toString();
	}
	return s;
}*/
