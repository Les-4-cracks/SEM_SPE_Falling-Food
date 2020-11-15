#include "fonctionanais.h"
#include <SFML/Graphics.hpp>
#define FENETREHAUTEUR 750
#define FENETRELARGEUR 1200
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
#define HAUTEUR_TUBE 228
#define PAS 20
#define NBALIMENTS 5



using namespace sf;
/*
void affTube(RenderWindow &fenetre,int position , int mvt, int posTubeX)
{
    int posX=0;//position souris
    int posY=0;//position souris
    bool assietteDroite, assietteGauche, poubelle;


    Event event;
    while (fenetre.pollEvent(event))
    {
        if (event.type == Event::Closed)
            fenetre.close();

        if  (event.type == Event::MouseMoved)
        {
            posX=event.mouseMove.x;
            posY=event.mouseMove.y;

            assietteDroite = (posX<=ASS2_XMAX && posX>= ASS2_XMIN &&  posY<=ASS_YMAX &&  posY>=ASS_YMIN);
            assietteGauche = (posX<=ASS1_XMAX && posX>= ASS1_XMIN && posY<=ASS_YMAX && posY>=ASS_YMIN);
            poubelle = (posX<=TROU_XMAX && posX>= TROU_XMIN && posY<=TROU_YMAX &&  posY>=TROU_YMIN);

        }

        if (event.type == Event::MouseButtonPressed)
        {


            if (event.mouseButton.button == Mouse::Left )
            {
                printf("%i  ",posX);

                if ( assietteDroite)
                {
                    position = 3;
                    mvt = 1;
                    printf("OK");
                }
                if (assietteGauche)
                {
                    position = 2;
                    if(posTubeX<ASS1_XMIN )
                    {
                        mvt = 1;
                    }
                    if(posTubeX+LARGEUR_TUBE>ASS1_XMAX)
                    {
                        mvt = -1;
                    }
                }
                if ( poubelle)
                {
                    position = 1;
                    mvt = -1;
                }
            }

        }
    }
}*/
