#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        //limpia las materias actuales
        for (int i = 0; i < 4; ++i)
        {
            if (_templates[i]) {
                delete _templates[i];
                _templates[i] = NULL;
            }
        }

        //clona las materias del otro objeto
        for (int i = 0; i < 4; ++i)
        {
            if (other._templates[i])
                _templates[i] = other._templates[i]->clone();
            else
                _templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        if (_templates[i])
            delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!_templates[i])
        {
            _templates[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return 0;
}
