#include <SFML/Graphics.hpp>
#include "FonctionAlice.h"
#define FENETREHAUTEUR 750
#define FENETRELARGEUR 1200



using namespace sf;//teeeeeeeeeeeeest

void afficheRecettes(char recette[]);
void afficheAliments(int alimentsVisibles[]);
void empilerAliment(int assiettes[]);
void decor();
void deplacementTube(char alimentsVisibles[]);
void chuteAliments(char alimentsVisibles []);
int timer(int temps.secondes);
int timer(int secondes);
int alea(int aleaMax);
int recettesValidees(int recette[], int assiette[]);


typedef struct{
    int x;
    int y;
} Point;

int main()
{
    RenderWindow fenetre(VideoMode(FENETRELARGEUR, FENETREHAUTEUR), "Falling Food");

    Point p;

    int alimentsVisibles[3];
    int i;
    char alimentsTexture [20];

    int assiettes1[10];
    int assiettes2[10];
    int cheeseburger[6];
    int burger[3];
    int maxiDeluxeEdition[7]; //SI on ajoute les sauces
    int vege[4];

    while (fenetre.isOpen())
    {
        Texture texture;
        if (!texture.loadFromFile("image/exempleDecor.png"))
            return EXIT_FAILURE;
        Sprite decor(texture);

        Texture tubeImage;
        if (!tubeImage.loadFromFile("image/tube.png"))
            return EXIT_FAILURE;
        Sprite tube(tubeImage);
        tube.setPosition(500,0);

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
        for(i=0; i<3; i++)
        {
            //alimentsVisibles[i] = alea(aleaMax);
        }

        Texture alimentsImage[5];
        for(i=0; i<5; i++)
        {
            sprintf(alimentsTexture,"image/aliments/%i.gif",i);
            if (!alimentsImage[i].loadFromFile(alimentsTexture))
                printf("Probleme de chargement de l'image !\n");
        }


        Event event;
        while (fenetre.pollEvent(event))
        {
            //tempsImparti = timer(int secondes);

            //action de toucher une assiette



            if (event.type == Event::Closed)
                fenetre.close();
        }


        fenetre.clear();
        fenetre.draw(decor);
        fenetre.draw(tube);

        fenetre.display();
    }

    return EXIT_SUCCESS;
}


int alea(int aleaMax)
{
    int res;
    aleaMax = NBALIMENTS;

    return res;
}

/*int alea (int mini, int maxi)
{
    int res;
    res = rand()%(maxi-mini +1)+mini;
    return res;
}*/
