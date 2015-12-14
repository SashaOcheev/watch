sf::CircleShape initCircle(sf::Color color, float radius, sf::Color outline_color, float outline_thickness, sf::Vector2f position);

struct Watch
{
	sf::CircleShape main = initCircle(sf::Color::White, 200, sf::Color::Black, 3, sf::Vector2f(50, 50));
	sf::CircleShape inside = initCircle(sf::Color::White, 190, sf::Color::White, 0, sf::Vector2f(60, 60));
	sf::CircleShape center = initCircle(sf::Color::Black, 5, sf::Color::White, 0, sf::Vector2f(245, 245));
};

sf::RectangleShape initLine(sf::Color color, sf::Vector2f size, sf::Vector2f position, float angle);

struct Arrows
{
	sf::RectangleShape hour = initLine(sf::Color::Black, sf::Vector2f(150, 4), sf::Vector2f(250, 250), 0.f);
	sf::RectangleShape min = initLine(sf::Color::Green, sf::Vector2f(170, 3), sf::Vector2f(250, 250), 0.f);
	sf::RectangleShape sec = initLine(sf::Color::Red, sf::Vector2f(190, 2), sf::Vector2f(250, 250), 0.f);
};

void setAngles(Clock &clock, Arrows &arrows);
void setResections(sf::RectangleShape resections[resection_count], int count, sf::Color color, sf::Vector2f size, sf::Vector2f position);