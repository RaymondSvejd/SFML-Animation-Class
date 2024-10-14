#pragma once
#include<string>
#include<SFML/Graphics.hpp>
#include<ctime>
#include<iostream>
#include"TextureManager.h"
#include"Animation.h"

class Animated_Sprite
{

public:
	// Constructor
	Animated_Sprite();

	// Deconstructor
	~Animated_Sprite();

	//Render- Rednerar ut den angivna "Spriten"
	void render(sf::RenderTarget * win);

	//Accessors- setters
	void set_Texture(std::string path);
	void set_Sprite();
	void set_Playstate(bool playState);

	//Accessors- getters
	sf::Sprite & get_Sprite();
	std::string & get_Path();
	sf::Texture & get_Texture();
	bool & get_Playstate();

	//Protected gives inherited Classes access to functions and variables
protected:
	//Play Animation runs in Update.
	void play_animation(Animation & anim, float play_speed = 0.2f);
	void stop_animation();
	
	//Variables
	std::string m_path;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	//Can never be accesed outside the this class.  
private:

	//Timer
	sf::Time timer;

	//true if the animation is playing.
	bool Is_Playing = true;

	//The currect frame count in the vector.
	int current_frame = 0;
	
	//Clock baseclass
	sf::Clock Clock;
	
};

