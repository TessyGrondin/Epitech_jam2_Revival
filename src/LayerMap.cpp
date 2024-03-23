#include "../include/LayerMap.hpp"

LayerMap::LayerMap(std::string name, unsigned int height, unsigned int width, int tilesize = 16)
{
    m_name = name;
    m_height = height;
    m_width = width;
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(m_width * m_height * 4);
    m_tilesize = tilesize;
}

bool LayerMap::parse_csv(std::string path, std::string asset_path)
{
    std::fstream source_file;
    std::string line;
    std::string content;
    int j = 0;
    int i = 0;

    if (!m_height || !m_width || !m_tileset.loadFromFile(asset_path))
        return false;
    source_file.open(path);
    if (source_file.is_open()) {
        while (source_file.good()) {
            std::getline(source_file, line);
            content.append(line);
            content.pop_back();
        }
    }
    source_file.close();
    while (!content.empty()) {
        i = content.find(',');
        line = content.substr(j, i);
        m_indexes.push_back(std::stoi(line));
        content = content.substr(i + 1);
        j = i;
    }
    return true;
}

void LayerMap::fill_vertex(unsigned int x, unsigned int y)
{
    int tile_number = m_indexes[x + y * m_width];
    sf::Vector2u size = m_tileset.getSize();
    int tu = tile_number % (size.x / m_tilesize);
    int tv = 0;
    sf::Vertex *quad;

    if (m_indexes[y *m_width + x] == -1)
        return;
    quad = &m_vertices[(x + y * m_width) * 4];
    quad[0].position = {x * (float)m_tilesize, y * (float)m_tilesize};
    quad[1].position = {(x + 1) * (float)m_tilesize, y * (float)m_tilesize};
    quad[2].position = {(x + 1) * (float)m_tilesize, (y + 1) * (float)m_tilesize};
    quad[3].position = {x * (float)m_tilesize, (y + 1) * (float)m_tilesize};
    quad[0].texCoords = {tu * (float)m_tilesize, tv * (float)m_tilesize};
    quad[1].texCoords = {(tu + 1) * (float)m_tilesize, tv * (float)m_tilesize};
    quad[2].texCoords = {(tu + 1) * (float)m_tilesize, (tv + 1) * (float)m_tilesize};
    quad[3].texCoords = {tu * (float)m_tilesize, (tv + 1) * (float)m_tilesize};
}

bool LayerMap::load(std::string path, std::string asset_path)
{
    if (!parse_csv(path, asset_path))
        return false;
    for (unsigned int i = 0; i < m_width; i++)
        for (unsigned int j = 0; j < m_height; j++)
            fill_vertex(i, j);
    return true;
}

void LayerMap::draw(sf::RenderWindow& win)
{
    if (!m_drawable)
        return;
    sf::RenderStates states;
    states.blendMode = sf::BlendAlpha;
    states.transform = sf::Transform::Identity;
    states.texture = &m_tileset;
    win.draw(m_vertices, states);
}
