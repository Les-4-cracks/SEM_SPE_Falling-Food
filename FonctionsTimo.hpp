#ifndef FONCTIONSTIMO_HPP_INCLUDED
#define FONCTIONSTIMO_HPP_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;

typedef struct
{
    int x;
    int y;
} Point;
typedef struct
{
    Point tube;
    Point aliment;
    Point assiettes;
    Point poubelle;
    Point recette;
    Point souris;
    Point recette1;
    Point recette2;
    Point cadre;
} Deco;

void menu(RenderWindow &fenetre);
void options(RenderWindow &fenetre);
void regles(RenderWindow &fenetre);
void perdu(RenderWindow &fenetre);
void gagne(RenderWindow &fenetre);
int recettesValidees(int recette[], int assiette[], int tailleRecette);

#endif // FONCTIONSTIMO_HPP_INCLUDED
