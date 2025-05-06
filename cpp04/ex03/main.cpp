#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "=== CREACIÓN DE MATERIA SOURCE ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); //duplicar para probars la capacidad
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); //debería ignorarse ya que el slot ya está lleno

    std::cout << "\n=== CREACIÓN DE PERSONAJE PRINCIPAL ===" << std::endl;
    ICharacter* me = new Character("Marina");

    std::cout << "\n=== CREACIÓN Y EQUIPAMIENTO DE MATERIAS ===" << std::endl;
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    tmp = src->createMateria("ice");
    me->equip(tmp); //ek inventario esta lleno no debería hacer na

    std::cout << "\n=== USO DE MATERIAS ===" << std::endl;
    ICharacter* bob = new Character("Bob");
    me->use(0, *bob); // ice
    me->use(1, *bob); // cure
    me->use(2, *bob); // ice
    me->use(3, *bob); // cure
    me->use(4, *bob); // invalid index

    std::cout << "\n=== DESEQUIPAR Y VOLVER A USAR ===" << std::endl;
    me->unequip(1); //me quito cure
    me->use(1, *bob); //no hace nada

    std::cout << "\n=== TEST DE COPIA DE PERSONAJES ===" << std::endl;
    Character* clone = new Character(*dynamic_cast<Character*>(me));
    clone->use(0, *bob);
    clone->use(2, *bob);
    clone->use(3, *bob); //el slot 3 tiene que tener cure porque se ha copiado
    clone->use(1, *bob); //el slot 1 debería estar vacio porque lo he quitado antes

    std::cout << "\n=== LIMPIEZA ===" << std::endl;
    delete bob;
    delete me;
    delete clone;
    delete src;

    return 0;
}

// int main ()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }
