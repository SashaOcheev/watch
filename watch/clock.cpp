#include <SFML/Graphics.hpp>

#include "clock.h"

void getTime(Clock &clock)
{
	int seconds = int(time(NULL));
	clock.hour = (seconds / 3600 + 3) % 12;
	clock.min = seconds / 60 % 60;
	clock.sec = seconds % 60;
}