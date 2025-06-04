#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "menace.hpp"

class menace_interne: public menace
{
    protected:
    bool m_intru;
    int m_zone;

    public:
        menace_interne();
        ~menace_interne();
};
