#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <windows.h>  

const int win_size = 500;
const int resection_count = 12;

struct Clock
{
	int hour;
	int min;
	int sec;
};

sf::CircleShape initCircle(sf::Color color, float radius, sf::Color outline_color, float outline_thickness, sf::Vector2f position)
{
	sf::CircleShape circle(radius, 64);
	circle.setFillColor(color);
	circle.setOutlineColor(outline_color);
	circle.setOutlineThickness(outline_thickness);
	circle.setPosition(position);
	return circle;
}

struct Watch
{
	sf::CircleShape main = initCircle(sf::Color::White, 200, sf::Color::Black, 3, sf::Vector2f(50, 50));
	sf::CircleShape inside = initCircle(sf::Color::White, 190, sf::Color::White, 0, sf::Vector2f(60, 60));
	sf::CircleShape center = initCircle(sf::Color::Black, 5, sf::Color::White, 0, sf::Vector2f(245, 245));
};

sf::RectangleShape initLine(sf::Color color, sf::Vector2f size, sf::Vector2f position, float angle)
{
	sf::RectangleShape line;
	line.setFillColor(color);
	line.setSize(size);
	line.setPosition(position);
	line.setRotation(angle);
	return line;
}

struct Arrows
{
	sf::RectangleShape hour = initLine(sf::Color::Black, sf::Vector2f(150, 4), sf::Vector2f(250, 250), 0.f);
	sf::RectangleShape min = initLine(sf::Color::Green, sf::Vector2f(170, 3), sf::Vector2f(250, 250), 0.f);
	sf::RectangleShape sec = initLine(sf::Color::Red, sf::Vector2f(190, 2), sf::Vector2f(250, 250), 0.f);
};

void getTime(Clock &clock)
{
	int seconds = int(time(NULL));
	clock.hour = (seconds / 3600 + 3) % 12;
	clock.min = seconds / 60 % 60;
	clock.sec = seconds % 60;
}

void setAngles(Clock &clock, Arrows &arrows)
{
	arrows.sec.setRotation(-90.f + 6.f * clock.sec);
	arrows.min.setRotation(-90.f + 6.f * clock.min + 0.1 * clock.sec);
	arrows.hour.setRotation(-90.f + 30.f * clock.hour + 0.5 * clock.min);
}

void setResections(sf::RectangleShape resections[resection_count], int count, sf::Color color, sf::Vector2f size, sf::Vector2f position)
{
	for (int i = 0; i < count; i++)
	{
		float angle = -90.f + float(i) * 360 / float(count);
		resections[i] = initLine(color, size, position, angle);
	}
}

void drawResections(sf::RenderWindow &window, sf::RectangleShape resections[resection_count], int count)
{
	for (int i = 0; i < count; i++)
		window.draw(resections[i]);
}

void drawElements(sf::RenderWindow &window, Init &init)
{
	window.clear(sf::Color::White);

	window.draw(init.watch.main);

	drawResections(window, init.resections, resection_count);

	window.draw(init.watch.inside);

	getTime(init.clock);
	setAngles(init.clock, init.arrows);
	window.draw(init.arrows.hour);
	window.draw(init.arrows.min);
	window.draw(init.arrows.sec);

	window.draw(init.watch.center);

	window.display();
}

struct Init
{
	Clock clock;
	Watch watch;
	Arrows arrows;
	sf::RectangleShape resections[resection_count];
};

void setEvent(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
		if (event.type == sf::Event::Closed)
			window.close();
}

int main()
{
	Init init;
	setResections(init.resections, resection_count, sf::Color::Black, sf::Vector2f(200, 2), sf::Vector2f(250, 250));

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(win_size, win_size), "watch", sf::Style::Default, settings);

	while (window.isOpen())
	{
		setEvent(window);
		drawElements(window, init);
	}
	return 0;
}