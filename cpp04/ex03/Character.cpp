#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; ++i)
        _dropped[i] = NULL; //aseguramos así que el array de las materias que dejo también se inicializa en null
}

Character::Character(const Character & other) : _name(other._name)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    for (int i = 0; i < 100; ++i)
        _dropped[i] = NULL; //si hay materias que he dejado entonces también se copian
}

Character & Character::operator=(Character const & other)
{
    if (this != &other)
    {
        _name = other._name;
        
        //libero materia existnte
        for (int i = 0; i < 4; ++i)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
        }

        //copio desde el objeto other
        for (int i = 0; i < 4; ++i)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }

        //copio materias que están dejadas
        for (int i = 0; i < 100; ++i)
            _dropped[i] = other._dropped[i];
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        if (_inventory[i])
            delete _inventory[i];

    for (int i = 0; i < 100; ++i)
        if (_dropped[i])
            delete _dropped[i];
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    //buscar espacio vacío en el inventario (4)
    for (int i = 0; i < 4; ++i)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;

    //buscar espacio vacio en dropped (100)
    for (int i = 0; i < 100; ++i)
    {
        if (!_dropped[i])
        {
            _dropped[i] = _inventory[idx];
            break;
        }
    }

    //borro materia del inventario
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}
