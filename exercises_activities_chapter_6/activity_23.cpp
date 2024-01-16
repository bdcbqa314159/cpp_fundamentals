#include <iostream>
#include <string>

const char nl = '\n';

struct Position
{
    std::string identifier{};
    Position() {}
    Position(const std::string &pos) : identifier(pos)
    {
    }
};

class Character
{
public:
    Character() {}
    void movedTo(const Position &position)
    {
        std::cout << "moved to " << position.identifier << nl;
    }
};

class Spell
{
public:
    Spell(std::string name) : d_name(name) {}

    std::string name() const { return d_name; }

private:
    std::string d_name{};
};

class Hero : public Character
{
public:
    void cast_spell(const Spell &spell)
    {
        std::cout << "casting: " << spell.name() << nl;
    }
};

class Enemy : public Character
{
public:
    void swinging_sword()
    {
        std::cout << "sword swinging" << nl;
    }
};

int main()
{
    Position enemy_castle("enemy castle");
    Hero hero;
    Enemy enemy;

    Spell spell("fire ball");

    std::cout << "The hero goes to the castle" << nl;
    std::cout << "So the enemy" << nl;

    hero.movedTo(enemy_castle);
    enemy.movedTo(enemy_castle);

    std::cout << "The hero fights the enemy" << nl;

    hero.cast_spell(spell);
    enemy.swinging_sword();

    return 0;
}
