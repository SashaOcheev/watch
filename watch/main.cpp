#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

const int WINDOW_SIZE = 500;
const int ANTIALIASING_LEVEL = 8;
const int RESECTION_COUNT = 12;

//         clock         ///////////////////////////////////
struct clock_init
{
	int hour;
	int min;
	int sec;

	const struct Time_meausre
	{
		int HOUR = 12;
		int MIN = 60;
		int SEC = 60;
		int GMT = 3;
	};

	void setTime()
	{
		Time_meausre time_meausre;
		int seconds = int(time(NULL));
		hour = (seconds / time_meausre.MIN / time_meausre.SEC + time_meausre.GMT) % time_meausre.HOUR;
		min = seconds / time_meausre.MIN % time_meausre.SEC;
		sec = seconds % time_meausre.SEC;
	}
};
////////////////////////////////////////////////////////////

//     Circle     /////////////////////////////////////////////
struct circle_params
{
	sf::Color color;
	int angle_count;
	float radius;
	sf::Color outline_color;
	float outline_thickness;
	sf::Vector2f position;
};

sf::CircleShape setCircle(circle_params &params)
{
	sf::CircleShape circle(params.radius, params.angle_count);
	circle.setFillColor(params.color);
	circle.setOutlineColor(params.outline_color);
	circle.setOutlineThickness(params.outline_thickness);
	circle.setPosition(params.position);
	return circle;
}

struct circles_init
{
	circle_params big = { sf::Color::White, 64, 200, sf::Color::Black, 3, sf::Vector2f(0 ,0) };
	circle_params middle = { sf::Color::White, 64, 190, sf::Color::White, 0, sf::Vector2f(0, 0) };
	circle_params small = { sf::Color::Black, 64, 7, sf::Color::White, 0, sf::Vector2f(0 ,0) };

	circles_init(int area_size)
	{
		float temp = float(area_size) / 2;
		big.position = sf::Vector2f(temp - big.radius, temp - big.radius);
		middle.position = sf::Vector2f(temp - middle.radius, temp - middle.radius);
		small.position = sf::Vector2f(temp - small.radius, temp - small.radius);
	}
};
////////////////////////////////////////////////////////////

//         arrows      /////////////////////////////////////
struct rectangle_params
{
	sf::Color color;
	sf::Vector2f size;
	sf::Color outline_color;
	float outline_thickness;
	sf::Vector2f position;
	float angle;
};

sf::RectangleShape setRectangle(rectangle_params &params)
{
	sf::RectangleShape rectangle;
	rectangle.setFillColor(params.color);
	rectangle.setSize(params.size);
	rectangle.setOutlineColor(params.outline_color);
	rectangle.setOutlineThickness(params.outline_thickness);
	rectangle.setPosition(params.position);
	rectangle.setRotation(params.angle);
	return rectangle;
}

struct arrows_init
{
	rectangle_params hour = { sf::Color::Black, sf::Vector2f(150, 4), sf::Color::Black, 0.f, sf::Vector2f(0 ,0), 0.f };
	rectangle_params min = { sf::Color::Green, sf::Vector2f(170, 3), sf::Color::Black, 0.f, sf::Vector2f(0 ,0), 0.f };
	rectangle_params sec = { sf::Color::Red, sf::Vector2f(190, 2), sf::Color::Black, 0.f, sf::Vector2f(0 ,0), 0.f };

	arrows_init(int area_size)
	{
		float pos = (float(area_size / 2));
		hour.position = sf::Vector2f(pos, pos);
		min.position = sf::Vector2f(pos, pos);
		sec.position = sf::Vector2f(pos, pos);
	};

	void setAngles(clock_init &clock)
	{
		hour.angle = -90.f + 30.f * clock.hour + float(0.5) * clock.min;
		min.angle = -90.f + 6.f * clock.min + float(0.1) * clock.sec;
		sec.angle = -90.f + 6.f * clock.sec;
	}
};
////////////////////////////////////////////////////////////

struct Shapes
{
	sf::CircleShape big_circle;
	sf::CircleShape middle_circle;
	sf::CircleShape small_circle;

	sf::RectangleShape hour_arrow;
	sf::RectangleShape min_arrow;
	sf::RectangleShape sec_arrow;

	sf::RectangleShape resections[RESECTION_COUNT];

	Shapes(circles_init &circles, arrows_init &arrows, rectangle_params &resection_params)
	{
		big_circle = setCircle(circles.big);
		middle_circle = setCircle(circles.middle);
		small_circle = setCircle(circles.small);

		hour_arrow = setRectangle(arrows.hour);
		min_arrow = setRectangle(arrows.min);
		sec_arrow = setRectangle(arrows.sec);

		for (int i = 0; i < RESECTION_COUNT; i++)
		{
			resection_params.angle = i * 30.f;
			resections[i] = setRectangle(resection_params);
		}
	}

	void setArrowsRotation(arrows_init &arrows)
	{
		hour_arrow.setRotation(arrows.hour.angle);
		min_arrow.setRotation(arrows.min.angle);
		sec_arrow.setRotation(arrows.sec.angle);
	}
	
};

void drawElements(sf::RenderWindow &window, Shapes &shapes)
{
	window.clear(sf::Color::White);
	window.draw(shapes.big_circle);
	for (int i = 0; i < RESECTION_COUNT; i++)
		window.draw(shapes.resections[i]);
	window.draw(shapes.middle_circle);
	window.draw(shapes.hour_arrow);
	window.draw(shapes.min_arrow);
	window.draw(shapes.sec_arrow);
	window.draw(shapes.small_circle);
	window.display();
}

int main()
{
	clock_init clock;
	arrows_init arrows(WINDOW_SIZE);
	circles_init circles(WINDOW_SIZE);
	rectangle_params resection_params = { sf::Color::Black, sf::Vector2f(200, 2), sf::Color::Black, 0.f, sf::Vector2f(250, 250), 0.f };
	Shapes shapes(circles, arrows, resection_params);

	sf::ContextSettings settings;
	settings.antialiasingLevel = ANTIALIASING_LEVEL;
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "watch", sf::Style::Default, settings);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		clock.setTime();
		arrows.setAngles(clock);
		shapes.setArrowsRotation(arrows);

		drawElements(window, shapes);
	}
	return 0;
}