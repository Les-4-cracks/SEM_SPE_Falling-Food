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
//fonction aléatoire aliments
int alea(int aleaMax);
#endif // FONCTIONSTIMO_HPP_INCLUDED
