struct Init
{
	Clock clock;
	Watch watch;
	Arrows arrows;
	sf::RectangleShape resections[RESECTION_COUNT];
};

void drawElements(sf::RenderWindow &window, Init &init);
void drawResections(sf::RenderWindow &window, sf::RectangleShape resections[RESECTION_COUNT], int count);
void setEvent(sf::RenderWindow &window);
