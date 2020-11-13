#include <SFML/Graphics.hpp>
#include "FonctionAlice.h"
#define FENETREHAUTEUR 750
#define FENETRELARGEUR 1200
#define NBALIMENTS 5

using namespace sf;

void afficheRecettes(char recette[]);

void empilerAliment(int assiettes[]);
void deplacementTube(char alimentsVisibles[]);
void chuteAliments(char alimentsVisibles []);
int timer(int secondes);

int recettesValidees(int recette[], int assiette[]);


typedef struct
{
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
    int ordreAliment;
    ordreAliment = alea(NBALIMENTS);
    printf("%i",ordreAliment);
    Sprite aliment;

    int aleaMax;
    aleaMax = NBALIMENTS;


    while (fenetre.isOpen())
    {
        Texture texture;//decor
        if (!texture.loadFromFile("image/exempleDecor.png"))
            return EXIT_FAILURE;
        Sprite decor(texture);

        Texture tubeImage;//tube
        if (!tubeImage.loadFromFile("image/tube.png"))
            return EXIT_FAILURE;
        Sprite tube(tubeImage);
        tube.setPosition(500,0);

        Texture aliment0Image;//tomate
        aliment0Image.loadFromFile("image/aliments/0.png");

        Texture aliment1Image;//steak
        aliment1Image.loadFromFile("image/aliments/1.png");
        Sprite aliment;

        Texture aliment2Image;//fromage
        aliment2Image.loadFromFile("image/aliments/2.png");

        Texture aliment3Image;//salade
        aliment3Image.loadFromFile("image/aliments/3.png");

        Texture aliment4Image;//pain
        aliment4Image.loadFromFile("image/aliments/4.png");

        switch (ordreAliment)
        {
        case 0:
            aliment.setTexture(aliment0Image);
            break;
        case 1:
            aliment.setTexture(aliment1Image);
            break;
        case 2:
            aliment.setTexture(aliment2Image);
            break;
        case 3:
            aliment.setTexture(aliment3Image);
            break;
        case 4:
            aliment.setTexture(aliment4Image);
            break;
        }

        //afficheRecettes(recette[]);
        /*for(i=0; i<3; i++)
        {
            alimentsVisibles[i] = alea(aleaMax);
        }*/

        Event event;
        while (fenetre.pollEvent(event))
        {
            //tempsImparti = timer(secondes);

            //action de toucher une assiette

            if (event.type == Event::Closed)
                fenetre.close();
        }


        aliment.setPosition(400,400);

        //fenetre.clear();
        fenetre.draw(decor);
        fenetre.draw(tube);
        fenetre.draw(aliment);

        fenetre.display();
    }

    return EXIT_SUCCESS;
}
