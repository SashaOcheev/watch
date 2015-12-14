#include <SFML/Graphics.hpp>

#include "const.h"
#include "clock.h"
#include "graph.h"


sf::CircleShape initCircle(sf::Color color, float radius, sf::Color outline_color, float outline_thickness, sf::Vector2f position)
{
	sf::CircleShape circle(radius, 64);
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

void setResections(sf::RectangleShape resections[resection_count], int count, sf::Color color, sf::Vector2f size, sf::Vector2f position)
{
	for (int i = 0; i < count; i++)
	{
		float angle = -90.f + float(i) * 360 / float(count);
		resections[i] = initLine(color, size, position, angle);
	}
}

void setAngles(Clock &clock, Arrows &arrows)
{
	arrows.sec.setRotation(-90.f + 6.f * clock.sec);
	arrows.min.setRotation(-90.f + 6.f * clock.min + float(0.1) * clock.sec);
	arrows.hour.setRotation(-90.f + 30.f * clock.hour + float(0.5) * clock.min);
}