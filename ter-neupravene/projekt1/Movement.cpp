#include "Movement.h"
#include <glm\ext\matrix_float3x3.hpp>



Movement::Movement(Point* startPoint, glm::vec3 directVector)
{
	this->IsCurveMovable = false;
	this->startPoint = startPoint;
	this->directVector = directVector;
}

Movement::Movement(std::vector<Point*> points)
{
	this->points = points;
	this->IsCurveMovable = true;
	this->startPoint = points[0];
}

Movement::~Movement()
{
}

void Movement::setSpeed(float sp)
{
	this->speed = sp;
}

glm::vec3 Movement::move()
{
	if (this->IsCurveMovable) {
		return moveBezier();
	}
	else {
		return moveLine();
	}
}

glm::vec3 Movement::moveBezier() {

	if (direct) {
		if (t >= 1) {
			unsigned int order = seq * 4 + 4;
			if (order < this->points.size() - 1) {
				t = 0;
				seq++;
				/*Point* a2 = this->points[seq * 3];
				Point* b2 = this->points[seq * 3 + 1];
				Point* c2 = this->points[seq * 3 + 2];
				Point* d2 = this->points[seq * 3 + 3];
				printf("point 1: %f, %f, %f \n", a2->x, a2->y, a2->z);
				printf("point 2: %f, %f, %f \n", b2->x, b2->y, b2->z);
				printf("point 3: %f, %f, %f \n", c2->x, c2->y, c2->z);
				printf("point 4: %f, %f, %f \n", d2->x, d2->y, d2->z);*/
			}
			else if (order == this->points.size()) {
				direct = false;
				this->speed *= (-1);
			}
			else {
				this->IsCurveMovable = false;
				int l = this->points.size() - 1;
				this->directVector = glm::vec3(
					this->points[0]->x - this->points[l]->x,
					this->points[0]->y - this->points[l]->y,
					this->points[0]->z - this->points[l]->x);
			}
		}
	}
	else {
		if (t <= 0) {
			if (seq > 0) {
				t = 1;
				seq--;
			}
			else {
				direct = true;
				this->speed *= (-1);
				t = 0;
			}
		}
	}

	Point* a = this->points[seq * 3];
	Point* b = this->points[seq * 3 + 1];
	Point* c = this->points[seq * 3 + 2];
	Point* d = this->points[seq * 3 + 3];

	glm::vec4 parameter = glm::vec4(pow(t, 3), pow(t, 2), t, 1);
	glm::mat4 bezier = glm::mat4(glm::vec4(-1, 3, -3, 1), glm::vec4(3, -6, 3, 0), glm::vec4(-3, 3, 0, 0), glm::vec4(1, 0, 0, 0));
	glm::mat4x3 curveMat = glm::mat4x3(
		glm::vec3(a->x, a->y, a->z),
		glm::vec3(b->x, b->y, b->z),
		glm::vec3(c->x, c->y, c->z),
		glm::vec3(d->x, d->y, d->z));

	this->t += this->speed;

	return parameter * bezier * curveMat;
}

glm::vec3 Movement::moveLine()
{
	Point endPoint;
	if (direct) {
		this->t += this->speed;
		endPoint.x = this->startPoint->x + t * this->directVector.x;
		endPoint.y = this->startPoint->y + t * this->directVector.y;
		endPoint.z = this->startPoint->z + t * this->directVector.z;
		if (t >= 1) {
			direct = false;
		}
	}
	else {
		this->t -= this->speed;
		endPoint.x = this->startPoint->x + t * this->directVector.x;
		endPoint.y = this->startPoint->y + t * this->directVector.y;
		endPoint.z = this->startPoint->z + t * this->directVector.z;
		if (t <= 0) {
			direct = true;
		}
	}
	glm::vec3 moveVector = glm::vec3(endPoint.x - this->startPoint->x, endPoint.y - this->startPoint->y, endPoint.z - this->startPoint->z);
	return moveVector;
}

Point::Point()
{
}
