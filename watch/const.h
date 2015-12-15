const struct
{
	int SIZE = 500;
	int ANTIALIASING_LEVEL = 8;
} WINDOW;

struct watch_params
{
	float RADIUS;
	float OUTLINE_THICKNESS;
};

const struct
{
	watch_params MAIN = { 200, 3 };
	watch_params INSIDE = { 190, 0 };
	watch_params CENTER = { 5, 0 };
	int ANGLE_COUNT = 64;
} WATCH;

const struct
{
	sf::Vector2f HOUR = sf::Vector2f(150, 4);
	sf::Vector2f MIN = sf::Vector2f(190, 3);
	sf::Vector2f SEC = sf::Vector2f(170, 2);
	sf::Vector2f RESECTION = sf::Vector2f(200, 2);
} LINE_SIZES;

const struct
{
	int HOUR = 12;
	int MIN = 60;
	int SEC = 60;
	int GMT = 3;
} TIME_MEASURE;

struct angle_unit
{
	float UNIT;
	float FRACTION;
};

const struct
{
	float SHIFT = -90.f;
	float FULL = 360.f;
	angle_unit SEC = {6.f, 0.f};
	angle_unit MIN = {6.f, float(0.1)};
	angle_unit HOUR = {30.f, float(0.5)};
} ANGLE_MEASURE;

const int RESECTION_COUNT = 12;

