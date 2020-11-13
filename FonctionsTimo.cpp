#include "FonctionsTimo.hpp"
#include <SFML/Graphics.hpp>
#define PAS 5
#define POSITION_Y_ASSIETTE 611

using namespace sf;

typedef struct{
    int x;
    int y;
} Coord;

Coord point;

void chuteAliments(int alimentsVisibles [], Texture alimentsImage [])
{
    Sprite aliment;
    int i;
    aliment.setTexture(alimentsImage[alimentsVisibles[1]]);
    aliment.setPosition(point.x,point.y);

    while(point.x<POSITION_Y_ASSIETTE)
    {
        point.x+=PAS;
        aliment.setPosition(point.x,point.y);
    }
}


int recettesValidees(int recette[], int assiette[])
{
    int i,nbIngredientValide,res;
    int tailleRecette = sizeof(recette)/sizeof(recette[0]);

    for(i=0;i<tailleRecette;i++)
    {
        if(recette[i]==assiette[i])
            nbIngredientValide++;
    }

    if(nbIngredientValide==tailleRecette)
        res=1;
    else
        res=0;
    return res;
}
