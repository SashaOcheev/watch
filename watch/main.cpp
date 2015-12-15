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
	setResections(init.resections, RESECTION_COUNT, sf::Color::Black, LINE_SIZES.RESECTION, getLinePos(WINDOW.SIZE));

	sf::ContextSettings settings;
	settings.antialiasingLevel = WINDOW.ANTIALIASING_LEVEL;
	sf::RenderWindow window(sf::VideoMode(WINDOW.SIZE, WINDOW.SIZE), "watch", sf::Style::Default, settings);

	while (window.isOpen())
	{
		setEvent(window);
		drawElements(window, init);
	}
	return 0;
}