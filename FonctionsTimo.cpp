#include "FonctionsTimo.hpp"
#include <SFML/Graphics.hpp>
#define PAS 5
#define POSITION_Y_ASSIETTE 611
#define POSITION_Y_ALIMENT_TUBE 185

using namespace sf;

typedef struct{
    int x;
    int y;
} Coord;

Coord point;

void chuteAliments(Sprite aliment, int positionX)
{
    point.y=POSITION_Y_ALIMENT_TUBE;
    aliment.setPosition(positionX,point.y);
    while(point.y<POSITION_Y_ASSIETTE)
    {
        point.y+=PAS;
        aliment.setPosition(positionX,point.y);
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
