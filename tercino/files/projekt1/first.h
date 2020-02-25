#pragma once
#include <vector>
#include "Movement.h"


std::vector<Point*> first_curve =
{
	new Point(50,50,200),
	new Point(100,50,50),
	new Point(120,50,50),
	new Point(50,50,200)
};

std::vector<Point*> second_curve =
{
	new Point(100,50,0),
	new Point(100,50,50),
	new Point(50,50,100),
	new Point(0,50,100),
	new Point(-50,50,100),
	new Point(-100,50,50),
	new Point(-100,50,0),
	new Point(-100,50,-50),
	new Point(-50,50,-100),
	new Point(0,50,-100),
	new Point(50,50,-100),
	new Point(100,50,-50)
	//new Point(-100,50,0),
};