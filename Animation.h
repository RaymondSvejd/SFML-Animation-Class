#pragma once
#include <SFML/Graphics/Rect.hpp>
#include <vector>

class Animation
{
public:
	//Constructor 
	Animation();
	//Deconstructors 
	~Animation();

	//add Frame
	void add_frame(int left, int top, int hight, int width);
	void add_frame(sf::Vector2i location, sf::Vector2i size);

	//Add a row of images
	void add_Row(int Row, int Colums, int hight = 32, int width = 32);

	//get total animation frames.
	int get_animation_size();
	
	//get a frame from the animation.
	sf::IntRect & get_frame(int n);
	

private:
	//Store all frames in this vector
	std::vector<sf::IntRect> Animation_container;
};

