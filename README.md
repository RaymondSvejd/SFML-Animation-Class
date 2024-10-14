SFML Animated Sprite Class
This project contains a basic framework for handling animated sprites in SFML (Simple and Fast Multimedia Library). The animation system allows for sprite textures to be dynamically updated frame-by-frame using an Animation class, while the Animated_Sprite class manages the display and play state of animations.

Getting Started
Prerequisites
To use this project, you will need:

SFML library installed (SFML official website)
C++ compiler that supports C++11 or later.
Files Overview
Animated_Sprite.h & Animated_Sprite.cpp: Handles the rendering of the sprite, setting the texture, playing/stopping animations, and managing the current frame.
Animation.h & Animation.cpp: Defines the frames of an animation, allowing you to add individual frames or rows of frames.
TextureManager.h & TextureManager.cpp: Manages loading and caching textures to prevent redundant loading of the same texture file.
Class Descriptions
Animated_Sprite
This class controls the display of an animated sprite. It allows for setting a texture, handling animations, and controlling the play state.

Public Methods:
void render(sf::RenderTarget *win): Renders the sprite to the target window.
void set_Texture(std::string path): Sets the texture for the sprite using the path to the texture file.
void set_Sprite(): Updates the sprite to use the current texture.
void set_Playstate(bool playState): Toggles whether the animation is playing or paused.
void play_animation(Animation &anim, float play_speed): Plays the given animation at the specified speed.
void stop_animation(): Stops the animation and resets to the first frame.
Animation
This class is responsible for defining an animation sequence by storing frames in a container.

Public Methods:
void add_frame(int left, int top, int hight, int width): Adds a single frame to the animation using specific rectangle dimensions.
void add_Row(int Row, int Columns, int hight, int width): Adds a row of frames for a sprite sheet.
sf::IntRect &get_frame(int n): Retrieves a specific frame from the animation.
int get_animation_size(): Returns the total number of frames in the animation.
TextureManager
This utility class handles loading and caching textures. It prevents reloading the same texture multiple times by caching textures in a map.

Public Methods:
sf::Texture &GetTexture(const std::string& filename): Retrieves the texture associated with the filename. If it hasn't been loaded yet, it loads and caches it.
void Clear(): Clears all loaded textures from memory.
