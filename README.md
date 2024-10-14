# SFML Animated Sprite Class
This project contains a basic framework for handling animated sprites in SFML. This was created as a side project to get familiar with SFML and C++. The animation system allows for sprite textures to be dynamically updated frame-by-frame using an Animation class, while the Animated_Sprite class manages the display and play state of animations.

## Getting Started

#### Prerequisites
To use this project, you will need:

* SFML library installed. 
* C++ compiler that supports C++11 or later.

#### Files Overview
* Animated_Sprite.h & Animated_Sprite.cpp: Handles the rendering of the sprite, setting the texture, playing/stopping animations, and managing the current frame.
* Animation.h & Animation.cpp: Defines the frames of an animation, allowing you to add individual frames or rows of frames.
* TextureManager.h & TextureManager.cpp: Manages loading and caching textures to prevent redundant loading of the same texture file.

## Class Descriptions

#### Animated_Sprite
This class controls the display of an animated sprite. It allows for setting a texture, handling animations, and controlling the play state.

#### Animation
This class is responsible for defining an animation sequence by storing frames in a container.

#### TextureManager
This utility class handles loading and caching textures. It prevents reloading the same texture multiple times by caching textures in a map.

## Example

```
#include "Animated_Sprite.h"
#include "Animation.h"
#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Animation");

    // Create an Animated_Sprite and Animation
    Animated_Sprite animSprite;
    Animation anim;

    // Set up the animation frames (from a sprite sheet)
    anim.add_Row(0, 4, 64, 64); // Row 0, 4 columns, 64x64 frame size

    // Set up the sprite texture
    animSprite.set_Texture("path_to_sprite_sheet.png");
    animSprite.set_Sprite();

    // Set the sprite to play the animation
    animSprite.set_Playstate(true);

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Play the animation
        animSprite.play_animation(anim, 0.1f);

        // Render the sprite
        animSprite.render(&window);

        // Display everything
        window.display();
    }

    return 0;
}
```

#### License
Use this as you see fit.
