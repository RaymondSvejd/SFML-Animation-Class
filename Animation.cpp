#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::add_frame(int left, int top, int hight, int width)
{
	sf::IntRect m_frame = sf::IntRect(left, top, hight, width);
	Animation_container.push_back(m_frame);
}

void Animation::add_frame(sf::Vector2i location, sf::Vector2i size)
{
	sf::IntRect m_frame = sf::IntRect(location, size);
	Animation_container.push_back(m_frame);
}

void Animation::add_Row(int Row, int Colums, int hight, int width)
{
	for (int i = 0; i < Colums; i++)
	{
		sf::IntRect m_frame = sf::IntRect(i*width, hight*Row, width, hight);
		Animation_container.push_back(m_frame);
	}
	
}

int Animation::get_animation_size()
{
	return this->Animation_container.size();
}

sf::IntRect & Animation::get_frame(int n)
{
	return Animation_container[n];
}
