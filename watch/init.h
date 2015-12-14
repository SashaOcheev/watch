struct Init
{
	Clock clock;
	Watch watch;
	Arrows arrows;
	sf::RectangleShape resections[resection_count];
};

void drawElements(sf::RenderWindow &window, Init &init);
void drawResections(sf::RenderWindow &window, sf::RectangleShape resections[resection_count], int count);
void setEvent(sf::RenderWindow &window);
