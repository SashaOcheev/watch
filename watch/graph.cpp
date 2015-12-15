#include <SFML/Graphics.hpp>

#include "const.h"
#include "clock.h"
#include "graph.h"


sf::CircleShape initCircle(sf::Color color, float radius, sf::Color outline_color, float outline_thickness, sf::Vector2f position)
{
	sf::CircleShape circle(radius, WATCH.ANGLE_COUNT);
	circle.setFillColor(color);
	circle.setOutlineColor(outline_color);
	circle.setOutlineThickness(outline_thickness);
	circle.setPosition(position);
	return circle;
}

sf::RectangleShape initLine(sf::Color color, sf::Vector2f size, sf::Vector2f position, float angle)
{
	sf::RectangleShape line;
	line.setFillColor(color);
	line.setSize(size);
	line.setPosition(position);
	line.setRotation(angle);
	return line;
}

void setResections(sf::RectangleShape resections[RESECTION_COUNT], int count, sf::Color color, sf::Vector2f size, sf::Vector2f position)
{
	for (int i = 0; i < count; i++)
	{
		float angle = ANGLE_MEASURE.SHIFT + float(i) * ANGLE_MEASURE.FULL / float(count);
		resections[i] = initLine(color, size, position, angle);
	}
}

void setAngles(Clock &clock, Arrows &arrows)
{
	arrows.sec.setRotation(ANGLE_MEASURE.SHIFT + ANGLE_MEASURE.SEC.UNIT * clock.sec);
	arrows.min.setRotation(ANGLE_MEASURE.SHIFT + ANGLE_MEASURE.MIN.UNIT * clock.min + ANGLE_MEASURE.MIN.FRACTION * clock.sec);
	arrows.hour.setRotation(ANGLE_MEASURE.SHIFT + ANGLE_MEASURE.HOUR.UNIT * clock.hour + ANGLE_MEASURE.HOUR.FRACTION * clock.min);
}

sf::Vector2f getCirclePos(int area_size, float circle_size)
{
	float pos = (float(area_size) / 2 - circle_size);
	return sf::Vector2f(pos, pos);
}

sf::Vector2f getLinePos(int area_size)
{
	float pos = (float(area_size / 2));
	return sf::Vector2f(pos, pos);
}