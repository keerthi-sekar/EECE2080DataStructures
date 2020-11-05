#include "Character.h"
#include <vector>

template <class Character> // Indicates this is a template definition

class Party
{
public:
    Party(Character *char1, Character *char2, Character *char3, Character *char4)
    {
        m_character1 = char1;
        m_character2 = char2;
        m_character3 = char3;
        m_character4 = char4;

        frontrow = {m_character1, m_character2};
        backrow = {m_character3, m_character4};
    }

    std::vector<Character *> frontrow;
    std::vector<Character *> backrow;

    Character *GetCharacter1() { return m_character1; }
    Character *GetCharacter2() { return m_character2; }
    Character *GetCharacter3() { return m_character3; }
    Character *GetCharacter4() { return m_character4; }

private:
    Character *m_character1;
    Character *m_character2;
    Character *m_character3;
    Character *m_character4;
};