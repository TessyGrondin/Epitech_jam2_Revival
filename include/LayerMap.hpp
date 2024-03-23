#pragma once
#include "SpriteSheet.hpp"
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>

class LayerMap
{
private:
    std::string        m_name;
    sf::VertexArray    m_vertices;
    unsigned int       m_height;
    unsigned int       m_width;
    std::vector<int>   m_indexes;
    sf::Texture        m_tileset;
    int                m_tilesize = 16;
    bool               m_drawable = true;
public:
    LayerMap(std::string name ,unsigned int height, unsigned int width, int tilesize);
    ~LayerMap() = default;
    sf::VertexArray get_vertices() {return m_vertices;}
    bool load(std::string path, std::string asset_path);
    bool parse_csv(std::string path, std::string asset_path);
    void fill_vertex(unsigned int x, unsigned int y);
    void set_draw(bool drawable) {m_drawable = drawable;}
    void draw(sf::RenderWindow& win);
};
