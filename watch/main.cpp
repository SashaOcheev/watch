#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <windows.h>  

const int win_size = 500;

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

sf::RectangleShape initLine(sf::Color color, sf::Vector2f size, sf::Vector2f position, float angle)
{
	sf::RectangleShape line;
	line.setFillColor(color);
	line.setSize(size);
	line.setPosition(position);
	line.setRotation(angle);
	return line;
}

struct Lines
{
	sf::RectangleShape hour = initLine(sf::Color::Black, sf::Vector2f(170, 2), sf::Vector2f(250, 250), 0.f);
	sf::RectangleShape min = initLine(sf::Color::Black, sf::Vector2f(180, 2), sf::Vector2f(250, 250), 0.f);
	sf::RectangleShape sec = initLine(sf::Color::Black, sf::Vector2f(190, 2), sf::Vector2f(250, 250), 0.f);
};

void getTime(Clock &clock)
{
	int seconds = int(time(NULL));
	clock.hour = (seconds / 3600 + 3) % 12;
	clock.min = seconds / 60 % 60;
	clock.sec = seconds % 60;
}

void setAngles(Clock &clock, Lines &arrows)
{
	arrows.sec.setRotation(-90.f + 6.f * clock.sec);
	arrows.min.setRotation(-90.f + 6.f * clock.min + 0.1 * clock.sec);
	arrows.hour.setRotation(-90.f + 30.f * clock.hour + 0.5 * clock.min);
}

void drawResections(sf::RenderWindow &window, sf::Color color, sf::Vector2f size, sf::Vector2f position, int count)
{
	for (int i = 0; i < count; i++)
	{
		float angle = -90.f + float(i) * 30.f;
		window.draw(initLine(color, size, position, angle));
	}
}

int main()
{
	Clock clock;

	sf::CircleShape watch_circle = initCircle(sf::Color::White, 200, sf::Color::Black, 3, sf::Vector2f(50, 50));

	Lines arrows;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(win_size, win_size), "watch", sf::Style::Default, settings);

	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		getTime(clock);
		std::cout << clock.hour << ':' << clock.min << ':' << clock.sec << std::endl;

		window.clear(sf::Color::White);

		setAngles(clock, arrows);

		window.draw(watch_circle);

		drawResections(window, sf::Color::Black, sf::Vector2f(200, 2), sf::Vector2f(250, 250), 12);
		window.draw(initCircle(sf::Color::White, 190, sf::Color::Black, 0, sf::Vector2f(60, 60)));

		window.draw(arrows.hour);
		window.draw(arrows.min);
		window.draw(arrows.sec);

		window.display();

	}
	return 0;
}