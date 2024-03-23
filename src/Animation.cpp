#include "../include/Animation.hpp"

Animation::Animation()
{
    m_name = "";
    m_frames = {};
    m_nb_frame = 0;
}

Animation::Animation(std::string given_name, std::vector<int> given_frames)
{
    m_name = given_name;
    m_frames = given_frames;
    m_nb_frame = given_frames.size();
}

int Animation::first()
{
    if (m_frames.size() == 0)
        return -1;
    return m_frames[0];
}

int Animation::last()
{
    int i = 0;
    int size = m_frames.size();

    if (size == 0)
        return -1;
    for (; i < size; i++);
    return m_frames[i];
}
