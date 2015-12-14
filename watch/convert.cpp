/*
#include <ctime> 
#include <SFML/Graphics.hpp>

#include "convert.h"
#include "shapes.h"

void getTime(Clock &clock)
{
	int seconds = int(time(NULL));
	clock.hour = (seconds / 3600 + 3) % 12;
	clock.min = seconds / 60 % 60;
	clock.sec = seconds % 60;
}

void setAngles(Clock &clock, Lines &arrows)
{
	arrows.sec.setRotation(float(90 + 360 / 60) * clock.sec);
	arrows.min.setRotation(float(90 + 360 / 60) * clock.min + arrows.sec.getRotation() / 60);
	arrows.hour.setRotation(float(90 + 360 / 24) * clock.hour + arrows.min.getRotation() / 60);
}
*/