#include "../include/SpriteSheet.hpp"
#include <iostream>

SpriteSheet::SpriteSheet()
{
}

SpriteSheet::SpriteSheet(std::string path, int width_given) :
Sprite(path)
{
    m_width = width_given;
    m_current_animation = "";
    sf::IntRect r = m_sprite.getTextureRect();
    r.width = width_given;
    m_sprite.setTextureRect(r);
}

void SpriteSheet::load(std::string path, int width_given)
{
    set_texture(path);
    m_width = width_given;
    m_current_animation = "";
    sf::IntRect r = m_sprite.getTextureRect();
    r.width = width_given;
    m_sprite.setTextureRect(r);
}

int SpriteSheet::locate_animation(std::string anim)
{
    int limit = m_animations.size();

    if (anim == "" || m_animations.empty()) {
        m_frame = 0;
        return -1;
    }
    for (int i = 0; !anim.empty() && i < limit; i++)
        if (anim == m_animations[i].get_name() && !(!m_animations[i].get_loop() && m_frame >= (int)m_animations[i].get_frames().size()))
            return i;
    return -1;
}

void SpriteSheet::play_animation(std::string anim)
{
    float timing = m_clock.getElapsedTime().asSeconds();
    sf::IntRect rect = m_sprite.getTextureRect();
    int anim_used = locate_animation(anim);

    if (anim_used == -1)
        return;
    if (anim != m_current_animation) {
        m_frame = 0;
        m_current_animation = anim;
    }
    if (timing >= 0.10) {
        if ((m_frame >= (int)m_animations[anim_used].get_frames().size() && m_animations[anim_used].get_loop())) {
            m_frame = 0;
            rect.left = m_animations[anim_used].first() * m_width;
        } else {
            rect.left = m_width * m_animations[anim_used].get_frames()[m_frame];
        }
        m_frame++;
        m_sprite.setTextureRect(rect);
        m_clock.restart();
    }
}

void SpriteSheet::add_animation(std::string new_anim, std::vector<int> frames)
{
    int exist = locate_animation(new_anim);
    if (new_anim.empty())
        return;
    if (m_animations.empty()) {
        Animation animation;
        animation.set_name(new_anim);
        animation.set_frames(frames);
        m_animations.push_back(animation);
    } else if (exist != -1)
        m_animations[exist].set_frames(frames);
    else
        m_animations.push_back(Animation(new_anim, frames));
}
