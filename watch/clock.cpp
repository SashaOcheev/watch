#include <SFML/Graphics.hpp>

#include "const.h"
#include "clock.h"

void getTime(Clock &clock)
{
	int seconds = int(time(NULL));
	clock.hour = (seconds / TIME_MEASURE.MIN / TIME_MEASURE.SEC + TIME_MEASURE.GMT) % TIME_MEASURE.HOUR;
	clock.min = seconds / TIME_MEASURE.MIN % TIME_MEASURE.SEC;
	clock.sec = seconds % TIME_MEASURE.SEC;
}