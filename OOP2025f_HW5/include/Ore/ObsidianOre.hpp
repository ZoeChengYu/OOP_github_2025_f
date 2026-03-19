#ifndef OBSIDIANORE_HPP
#define OBSIDIANORE_HPP
#include "Ore.hpp"

class ObsidianOre final:public Ore{
public:
    explicit ObsidianOre();
    ~ObsidianOre() override=default;
    float GetBreakExp() override;
};

#endif
