sf::CircleShape initCircle(sf::Color color, float radius, sf::Color outline_color, float outline_thickness, sf::Vector2f position);
sf::Vector2f getCirclePos(int area_size, float circle_size);

struct Watch
{
	sf::CircleShape main = initCircle(sf::Color::White, WATCH.MAIN.RADIUS, sf::Color::Black,
		WATCH.MAIN.OUTLINE_THICKNESS, getCirclePos(WINDOW.SIZE, WATCH.MAIN.RADIUS));
	sf::CircleShape inside = initCircle(sf::Color::White, WATCH.INSIDE.RADIUS, sf::Color::White,
		WATCH.INSIDE.OUTLINE_THICKNESS, getCirclePos(WINDOW.SIZE, WATCH.INSIDE.RADIUS));
	sf::CircleShape center = initCircle(sf::Color::Black, WATCH.CENTER.RADIUS, sf::Color::White,
		WATCH.CENTER.OUTLINE_THICKNESS, getCirclePos(WINDOW.SIZE, WATCH.CENTER.RADIUS));
};

sf::RectangleShape initLine(sf::Color color, sf::Vector2f size, sf::Vector2f position, float angle);
sf::Vector2f getLinePos(int area_size);

struct Arrows
{
	sf::RectangleShape hour = initLine(sf::Color::Black, LINE_SIZES.HOUR, getLinePos(WINDOW.SIZE), 0.f);
	sf::RectangleShape min = initLine(sf::Color::Green, LINE_SIZES.MIN, getLinePos(WINDOW.SIZE), 0.f);
	sf::RectangleShape sec = initLine(sf::Color::Red, LINE_SIZES.SEC, getLinePos(WINDOW.SIZE), 0.f);
};

void setAngles(Clock &clock, Arrows &arrows);
void setResections(sf::RectangleShape resections[RESECTION_COUNT], int count, sf::Color color, sf::Vector2f size, sf::Vector2f position);