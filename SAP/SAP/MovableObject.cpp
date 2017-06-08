#include "MovableObject.h"



MovableObject::MovableObject()
{

}


MovableObject::MovableObject(const int x, const int y, const Orientation orientation, const unsigned int speed, const unsigned int radius)
{
	_objectRadius = radius;
	_objectSpeed = speed;
	_point = Point2D(x, y);
	_orientation = orientation;
}


MovableObject::MovableObject(const Point2D point, const Orientation orientation, const unsigned int speed, const unsigned int radius)
{
	_objectRadius = radius;
	_objectSpeed = speed;
	_point = point;
	_orientation = orientation;
}


MovableObject::~MovableObject()
{
}


Point2D MovableObject::getLocation() const
{
	return _point;
}


Orientation MovableObject::getOrientation() const
{
	return _orientation;
}


unsigned int MovableObject::getSpeed() const
{
	return _objectSpeed;
}


unsigned int MovableObject::getRadius() const
{
	return _objectRadius;
}


void MovableObject::move()
{
	Point2D unitPoint = Point2D::orientationToPoint(_orientation);
	_point = _point + unitPoint;
}


bool MovableObject::collision(const MovableObject* object) const
{
	double distance = this->_point.distanceToPoint(object->getLocation());
	return distance < (this->_objectRadius + object->getRadius());
}
