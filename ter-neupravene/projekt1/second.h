#pragma once
#include <vector>
#include "Movement.h"



std::vector<Point*> infinity =
{
	new Point(0,1000,500),
	new Point(750,750,500),
	new Point(750,250,500),
	new Point(0,0,500),

	//new Point(0,500,0),
	new Point(-750,-250,500),
	new Point(-750,-750,500),
	new Point(0,-1000,500),

	//new Point(0,500,-1000),
	new Point(750,-750,500),
	new Point(750,-250,500),
	new Point(0,0,500),

	//new Point(0,500,0),
	new Point(-750,250,500),
	new Point(-750,500,500),
	new Point(0,1000,500)
};