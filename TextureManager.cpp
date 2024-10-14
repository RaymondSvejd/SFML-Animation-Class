#include "TextureManager.h"

// Get a reference to a texture with the given filename
sf::Texture & TextureManager::GetTexture(const std::string& filename) {
    auto& textureMap = TextureManager::textures;
    auto found = textureMap.find(filename);

    // If the texture has already been loaded, return it
    if (found != textureMap.end()) {
        return found->second;
    }

    // Otherwise, load the texture from file and add it to the map
    auto& texture = textureMap[filename];
    texture.loadFromFile(filename);

    return texture;
}

// Clear all loaded textures
void TextureManager::Clear() {
    auto& textureMap = TextureManager::textures;

    // Loop through all textures and free up memory
    for (auto it = textureMap.begin(); it != textureMap.end(); it++) {
        it->second.~Texture();
    }

    // Clear the map
    textureMap.clear();
}

std::map<std::string, sf::Texture> TextureManager::textures;