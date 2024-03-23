#pragma once
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Animation
{
private:
    std::string         m_name;
    std::vector<int>    m_frames;
    int                 m_nb_frame;
    bool                m_loop = true;
public:
    Animation();
    Animation(std::string, std::vector<int>);
    ~Animation() = default;
    std::string get_name() {return m_name;}
    std::vector<int> get_frames() {return m_frames;}
    int first();
    int last();
    void set_name(std::string new_name) {m_name = new_name;}
    void set_frames(std::vector<int> new_frames) {m_frames = new_frames;}
    void set_loop(bool new_loop) {m_loop = new_loop;}
    bool get_loop() {return m_loop;}
};
