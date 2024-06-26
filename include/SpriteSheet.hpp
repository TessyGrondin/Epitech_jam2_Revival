#pragma once
#include "Sprite.hpp"
#include "Animation.hpp"

class SpriteSheet : public Sprite
{
protected:
    int                    m_frame = 0;
    int                    m_width;
    std::vector<Animation> m_animations;
    std::string            m_current_animation;
    sf::Clock              m_clock;
public:
    SpriteSheet();
    SpriteSheet(std::string path, int width_given);
    ~SpriteSheet() = default;
    void add_animation(std::string, std::vector<int>);
    void play_animation(std::string anim);
    int locate_animation(std::string ref);
    void load(std::string path, int width_given);
    void set_loop(std::string anime, bool l);
    int get_frame() {return m_frame;}
};
