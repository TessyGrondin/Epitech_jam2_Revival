#pragma once
#include "Sprite.hpp"
#include "LayerMap.hpp"

class Map
{
private:
    unsigned int          m_width;
    unsigned int          m_height;
    unsigned int          m_square;
    std::vector<LayerMap> m_layers;
public:
    Map(unsigned int height, unsigned int width, unsigned int tilesize);
    ~Map() = default;
    bool add_layer(std::string name, std::string path, std::string asset_path);
    void draw(sf::RenderWindow &win);
};
