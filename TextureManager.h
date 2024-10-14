#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<vector>
#include<sstream>


class TextureManager {
public:

    // Get a reference to a texture with the given filename
    static sf::Texture & GetTexture(const std::string& filename);

    // Clear all loaded textures
    static void Clear();

private:
    
    TextureManager() {}

    // A map to store loaded textures
    static std::map<std::string, sf::Texture> textures;
};