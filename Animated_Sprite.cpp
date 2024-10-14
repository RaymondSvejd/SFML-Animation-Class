#include "Animated_Sprite.h"

Animated_Sprite::Animated_Sprite()
{
}

Animated_Sprite::~Animated_Sprite()
{
}


void Animated_Sprite::render(sf::RenderTarget * win)
{

		win->draw(this->m_sprite);
	
}

void Animated_Sprite::set_Texture(std::string path)
{
	this->m_path = path;
	m_texture = TextureManager::GetTexture(path);
	
}

void Animated_Sprite::set_Sprite()
{
	this->m_sprite.setTexture(this->m_texture);
}

void Animated_Sprite::set_Playstate(bool playState)
{
	this->Is_Playing = playState;
}

sf::Sprite & Animated_Sprite::get_Sprite()
{
	return this-> m_sprite;
}

std::string & Animated_Sprite::get_Path()
{
	return this->m_path;
}

sf::Texture & Animated_Sprite::get_Texture()
{
	return TextureManager::GetTexture(m_path); 
}

bool & Animated_Sprite::get_Playstate()
{
	return this->Is_Playing;
}

void Animated_Sprite::play_animation(Animation & anim, float play_speed)
{
	//timer that gets alapsed time
		timer = this->Clock.getElapsedTime();

		this->m_sprite.setTextureRect(anim.get_frame(current_frame));
		if (timer.asSeconds() >= play_speed && Is_Playing == true)
		{
			this->current_frame++;
			timer = this->Clock.restart();
			if (current_frame > anim.get_animation_size() - 1)
			{
				current_frame = 0;
			}
		}
		
}

void Animated_Sprite::stop_animation()
{
	current_frame = 0;
}

