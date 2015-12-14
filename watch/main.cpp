#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "const.h"
#include "clock.h"
#include "graph.h"
#include "init.h"

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