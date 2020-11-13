#include "fonctionanais.h"
#include <SFML/Graphics.hpp>
#define ASS1_XMIN 372
#define ASS1_XMAX 536
#define ASS2_XMIN 641
#define ASS2_XMAX 805
#define ASS_YMIN 611
#define ASS_YMAX 659
#define TROU_YMIN 607
#define TROU_YMAX 662
#define TROU_XMIN 72
#define TROU_XMAX 260
#define LARGEUR_TUBE 133
#define PAS 1


using namespace sf;

int deplacementTubeDroit(int posTubeX,Sprite tube)
{

    while(posTubeX<ASS2_XMIN )
    {
        posTubeX = posTubeX + PAS;
        tube.setPosition(posTubeX,0);
        return posTubeX;

    }
    while(posTubeX+LARGEUR_TUBE>ASS2_XMIN)
    {
        posTubeX = posTubeX - PAS;
        tube.setPosition(posTubeX,0);
        return posTubeX;
    }

}
void deplacementTubeGauche(int posTubeX)
{

}
