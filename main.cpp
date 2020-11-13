#include <SFML/Graphics.hpp>
#include "fonctionanais.h"
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
#define PAS 1




using namespace sf;

void afficheRecettes(char recette[]);
void afficheAliments(int alimentsVisibles[]);
void empilerAliment(int assiettes[]);
//void decor();
int deplacementTubeDroit(int posTubeX,Sprite tube);
void deplacementTubeGauche(int posTubeX);
void chuteAliments(char alimentsVisibles [] );
int timer(int seconde);
int alea(int aleaMax);
int recettesValidees(int recette[], int assiette[]);


typedef struct
{
    int x;
    int y;
} Point;
typedef struct
{
    Point tube;
    Point assiettes;
    Point poubelle;
    Point recette;
    Point souris;
} Deco;



int main()
{
    RenderWindow fenetre(VideoMode(FENETRELARGEUR, FENETREHAUTEUR), "Falling Food");
    int test=0;
    Point p;
    Deco deco;
    int posTubeX = deco.tube.x;
    deco.tube.x = 520;
    deco.tube.y = 0;
    int alimentsVisibles[3];
    int i;
    char alimentsTexture [20];
    int coorXtube;
    int assiettes1[10];
    int assiettes2[10];
    int cheeseburger[6];
    int burger[3];
    int maxiDeluxeEdition[7]; //SI on ajoute les sauces
    int vege[4];



    Texture texture;
    if (!texture.loadFromFile("image/exempleDecor.png"))
        return EXIT_FAILURE;
    Sprite decor(texture);

    Texture tubeImage;
    if (!tubeImage.loadFromFile("image/tube.png"))
        return EXIT_FAILURE;
    Sprite tube(tubeImage);
    tube.setPosition(deco.tube.x,deco.tube.y);

    while (fenetre.isOpen())
    {



        /*Texture aliment1Image;
        if (!aliment1.loadFromFile("image/fromage.png"))
            return EXIT_FAILURE;
        Sprite aliment1(aliment1Image);


        Texture aliment2Image;
        if (!aliment2.loadFromFile("image/tomate.png"))
            return EXIT_FAILURE;
        Sprite aliment2(aliment2Image);


        Texture aliment3Image;
        if (!aliment3.loadFromFile("image/salade.png"))
            return EXIT_FAILURE;
        Sprite aliment3(aliment3Image);*/


        //afficheRecettes(recette[]);
        /*for(i=0; i<3; i++)
        {
            alimentsVisibles[i] = alea(aleaMax);
        }*/

        /*Texture alimentsImage[5];
        for(i=0; i<5; i++)
        {
            sprintf(alimentsTexture,"image/aliments/%i.gif",i);
            if (!alimentsImage[i].loadFromFile(alimentsTexture))
                printf("Probleme de chargement de l'image !\n");
        }*/


        Event event;
        while (fenetre.pollEvent(event))
        {
            //tempsImparti = timer(secondes);

            //action de toucher une assiette

            if (event.type == Event::Closed)
                fenetre.close();


            if  (event.type == Event::MouseMoved)
            {


                deco.souris.x = event.mouseMove.x;
                deco.souris.y = event.mouseMove.y;

            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left )
                {
                    bool assietteDroite, assietteGauche, poubelle;
                    assietteDroite = (deco.souris.x<=ASS2_XMAX && deco.souris.x>= ASS2_XMIN && deco.souris.y<=ASS_YMAX && deco.souris.y>=ASS_YMIN);
                    assietteGauche = (deco.souris.x<=ASS1_XMAX && deco.souris.x>= ASS1_XMIN && deco.souris.y<=ASS_YMAX && deco.souris.y>=ASS_YMIN);
                    poubelle = (deco.souris.x<=TROU_XMAX && deco.souris.x>= TROU_XMIN && deco.souris.y<=TROU_YMAX && deco.souris.y>=TROU_YMIN);
                    if ( assietteDroite)
                    {
                        //tube.setPosition(deplacementTubeDroit(deco.tube.x, tube),0) ;
                        tube.setPosition(ASS2_XMIN+14,0);
                        /*while(deco.tube.x<ASS2_XMIN )
                        {
                            deco.tube.x = deco.tube.x + PAS;

                            tube.setPosition(deco.tube.x,0);
                            printf("OK + ");


                        }
                        while(deco.tube.x+LARGEUR_TUBE>ASS2_XMAX)
                        {
                            deco.tube.x = deco.tube.x - PAS;
                            tube.setPosition(deco.tube.x,0);

                        }*/
                    }
                    if ( assietteGauche)
                    {
                        tube.setPosition(ASS1_XMIN+14,0);
                    }
                    if ( poubelle)
                    {
                        tube.setPosition(TROU_XMIN+30,0);
                    }

                }
            }



        }


        fenetre.clear();

        fenetre.draw(decor);
        fenetre.draw(tube);

        fenetre.display();
    }

    return EXIT_SUCCESS;
}

