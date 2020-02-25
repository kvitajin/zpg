#pragma once

#include <glm/vec3.hpp> // glm::vec3
#include <vector>

struct Point {
	float x;
	float y;
	float z;

	Point();
	Point(float v_x, float v_y, float v_z) {
		x = v_x;
		y = v_y;
		z = v_z;
	}
};

class Movement
{
private:
	float t = 0.0f;
	bool direct = true;
	bool IsCurveMovable;
	float speed = 0.005f;
	int seq = 0;

	glm::vec3 directVector;
	Point* startPoint;
	std::vector<Point*> points;

	glm::vec3 moveBezier();
	glm::vec3 moveLine();

public:
	Movement(Point* startPoint, glm::vec3 directVector);
	Movement(std::vector<Point*> points);
	~Movement();

	void setSpeed(float sp);
	glm::vec3 move();
};

