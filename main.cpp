#include <SFML/Graphics.hpp>
#include "fonctionanais.h"
#include "FonctionAlice.h"
#include <windows.h>

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

void afficheRecettes(char recette[]);

void empilerAliment(int assiettes[]);
//void decor();

void chuteAliments(char alimentsVisibles [] );
int timer(int seconde);

int recettesValidees(int recette[], int assiette[]);



typedef struct
{
    int x;
    int y;
} Point;
typedef struct
{
    Point tube;
    Point recette1;
    Point recette2;
    Point cadre;
    Point souris;
} Deco;



int main()
{

    RenderWindow fenetre(VideoMode(FENETRELARGEUR, FENETREHAUTEUR), "Falling Food");

    fenetre.setFramerateLimit(0);
    int test=0;
    Point p;
    Deco deco;
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
    int ordreAliment;
    srand(time(NULL));
    int mvt = 0;
    int position;
    int aleaMax;
    aleaMax = NBALIMENTS;
    deco.recette2.x = 1050; //pos recette1
    deco.recette2.y = 50; //pos recette1
    deco.cadre.x = 121;  //taille cadre
    deco.cadre.y = 129;  //taille cadre

    deco.recette1.x = 900; //pos recette2
    deco.recette1.y = 50; //pos recette2
    //int posTubeX = deco.tube.x;
    //int posTubeY = deco.tube.y;




    Texture texture;
    if (!texture.loadFromFile("image/exempleDecor.png"))
        return EXIT_FAILURE;
    Sprite decor(texture);

    Texture tubeImage;
    if (!tubeImage.loadFromFile("image/tube.png"))
        return EXIT_FAILURE;
    Sprite tube(tubeImage);
    tube.setPosition(deco.tube.x,deco.tube.y);

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

    Texture recette1Image;//recette1
    if (!recette1Image.loadFromFile("image/menu1.png"))
        return EXIT_FAILURE;
    Sprite recette1(recette1Image);
    recette1.setPosition(deco.recette1.x,deco.recette1.y);

    Texture recette2Image;//recette2
    if (!recette2Image.loadFromFile("image/menu1.png"))
        return EXIT_FAILURE;
    Sprite recette2(recette2Image);
    recette2.setPosition(deco.recette2.x,deco.recette2.y);



    RectangleShape cadre1(Vector2f(deco.cadre.x+10,deco.cadre.y+10 ));
    cadre1.setFillColor(Color::Black);
    cadre1.setPosition(deco.recette1.x-5, deco.recette1.y-5);


    RectangleShape cadre2(Vector2f(deco.cadre.x+10,deco.cadre.y+10 ));
    cadre2.setFillColor(Color::Black);
    cadre2.setPosition(deco.recette2.x-5, deco.recette2.y-5);

    ordreAliment = alea(NBALIMENTS);
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




    /*for(i=0; i<10; i++)
    {
        ordreAliment = alea(NBALIMENTS);

        tableauSprite[i]=ordreAliment;
        printf("%d ",tableauSprite[i]);
    }
    int all1 = alea(NBALIMENTS);
    printf("%i",all1);
    printf("%i",tableauSprite[8]);*/



    aliment.setPosition(deco.tube.x + 6,HAUTEUR_TUBE - 43);

    while (fenetre.isOpen())
    {
        //affTube(fenetre, position, mvt, posTubeX);
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
                        position = 3;
                        mvt = 1;
                    }
                    if (assietteGauche)
                    {
                        position = 2;
                        if(deco.tube.x<ASS1_XMIN )
                        {
                            mvt = 1;
                        }
                        if(deco.tube.x+LARGEUR_TUBE>ASS1_XMAX)
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
        //deco.tube.x=posTubeX;
        //deco.tube.y= posTubeY;
        if(deco.tube.x+LARGEUR_TUBE>ASS2_XMAX )
        {
            mvt = 0;
            deco.tube.x = ASS2_XMIN+14;
        }
        if(deco.tube.x<TROU_XMIN+26)
        {
            mvt = 0;
            deco.tube.x = TROU_XMIN+30;
        }
        if(position == 2 && deco.tube.x>ASS1_XMIN && deco.tube.x+LARGEUR_TUBE<ASS1_XMAX)
        {
            mvt = 0;
            deco.tube.x = ASS1_XMIN+14;
        }


        deco.tube.x = deco.tube.x + PAS * mvt;
        fenetre.clear();
        aliment.setPosition( deco.tube.x + 6,HAUTEUR_TUBE - 43);
        tube.setPosition(deco.tube.x,0);
        fenetre.draw(decor);
        fenetre.draw(aliment);
        fenetre.draw(cadre1);
        fenetre.draw(recette1);
        fenetre.draw(cadre2);
        fenetre.draw(recette2);
        fenetre.draw(tube);
        sleep( milliseconds(25));
        fenetre.display();
    }

    return EXIT_SUCCESS;
}

