#include <SFML/Graphics.hpp>

#include "const.h"
#include "clock.h"
#include "graph.h"
#include "init.h"


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

void setEvent(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
		if (event.type == sf::Event::Closed)
			window.close();
}