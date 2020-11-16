#include <SFML/Graphics.hpp>
#include "fonctionanais.h"
#include "FonctionAlice.h"
#include "FonctionsTimo.hpp"
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
#define TAILLE_EMPILEMENT 20
#define TEMPO 25
#define BOUTON1_XMIN 434
#define BOUTON1_XMAX 474
#define BOUTON2_XMIN 703
#define BOUTON2_XMAX 743
#define BOUTON_YMIN 680
#define BOUTON_YMAX 720
#define TEMPS 50



using namespace sf;

void afficheRecettes(char recette[]);

void empilerAliment(int assiettes[]);
//void decor();
int deplacementTubeDroit(int posTubeX,Sprite tube);
void deplacementTubeGauche(int posTubeX);
void chuteAliments(char alimentsVisibles [] );
int timer(int seconde);

int recettesValidees(int recette[], int assiette[]);


Deco deco;

int main()
{

    RenderWindow fenetre(VideoMode(FENETRELARGEUR, FENETREHAUTEUR), "Falling Food");
    //fenetre.setFramerateLimit(0);
    menu(fenetre);
    int test=0;
    Point p;
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
    int ordreAliment = 0;
    srand(time(NULL));
    int mvtX = 0; //mouvement tube/aliments en x
    int mvtY = 0; //mouvement aliments en y
    int position = 1;
    int aleaMax;
    int vider = 0;
    aleaMax = NBALIMENTS;
    deco.recette2.x = 1050; //pos recette1
    deco.recette2.y = 50; //pos recette1
    deco.cadre.x = 121;  //taille cadre
    deco.cadre.y = 129;  //taille cadre

    deco.recette1.x = 900; //pos recette2
    deco.recette1.y = 50; //pos recette2

    bool deplacementAliment = false;
    bool afficheAlimentTube = true;
    bool genererAliment = true;
    bool bouton1,bouton2;

    for(i=0; i<10; i++)     // Initialisation des tableaux pour g�rer le pb de l'aliment 0
    {
        assiettes1[i]=-1;
        assiettes2[i]=-1;
    }

    int tempsImparti;
    int seconde;
    seconde = TEMPS;
    int compteur;
    compteur = 1;

    char chaineTimer[4];
    Font font; //chargement de la police
    if (!font.loadFromFile("arial.ttf"))
        printf("PB de chargement de la police d'ecriture !\n");
    Text texte;
    texte.setFont(font);


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
    Sprite alimentTube;
    Sprite alimentsAssiette[3][10] ;
    int indiceAliment = 0;

    Texture aliment2Image;//fromage
    aliment2Image.loadFromFile("image/aliments/2.png");

    Texture aliment3Image;//salade
    aliment3Image.loadFromFile("image/aliments/3.png");

    Texture aliment4Image;//pain
    aliment4Image.loadFromFile("image/aliments/4.png");
    printf("%i",ordreAliment);

    Texture vide;
    vide.loadFromFile("image/aliments/-1.png");

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



    RectangleShape cadre1(Vector2f(deco.cadre.x+10,deco.cadre.y+10 )); //cadre recette1
    cadre1.setFillColor(Color::Black);
    cadre1.setPosition(deco.recette1.x-5, deco.recette1.y-5);


    RectangleShape cadre2(Vector2f(deco.cadre.x+10,deco.cadre.y+10 ));  //cadre recette2
    cadre2.setFillColor(Color::Black);
    cadre2.setPosition(deco.recette2.x-5, deco.recette2.y-5);

    alimentTube.setPosition(deco.tube.x + 12,HAUTEUR_TUBE - 43);

    while (fenetre.isOpen())
    {
        compteur ++;
        if (compteur ==1000/TEMPO)
        {
            printf("seconde :%i\n", seconde);
            seconde --;
            compteur =1;
            if(seconde <0)
            {
                break;
            }
        }
        if (genererAliment)
        {
            ordreAliment = alea(NBALIMENTS);

            switch (ordreAliment)
            {
            case 0:
                alimentTube.setTexture(aliment0Image);
                break;
            case 1:
                alimentTube.setTexture(aliment1Image);
                break;
            case 2:
                alimentTube.setTexture(aliment2Image);
                break;
            case 3:
                alimentTube.setTexture(aliment3Image);
                break;
            case 4:
                alimentTube.setTexture(aliment4Image);
                break;
            }
            genererAliment = false;
            afficheAlimentTube = true;
            deco.aliment.y = HAUTEUR_TUBE - 43;

        }
        sprintf(chaineTimer, "%i",seconde);
        texte.setString(chaineTimer);
        texte.setCharacterSize(50);
        texte.setColor(Color::Black);
        texte.setStyle(Text::Bold);

        Event event;
        while (fenetre.pollEvent(event))
        {

            if (event.type == Event::Closed)
                fenetre.close();

            if  (event.type == Event::MouseMoved)
            {
                deco.souris.x = event.mouseMove.x; //pour position souris en x
                deco.souris.y = event.mouseMove.y; //pour position souris en y
            }

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left &&deplacementAliment == false)
                {
                    bool assietteDroite, assietteGauche, poubelle;
                    assietteDroite = (deco.souris.x<=ASS2_XMAX && deco.souris.x>= ASS2_XMIN && deco.souris.y<=ASS_YMAX && deco.souris.y>=ASS_YMIN); //si cliquer dans assiette droite
                    assietteGauche = (deco.souris.x<=ASS1_XMAX && deco.souris.x>= ASS1_XMIN && deco.souris.y<=ASS_YMAX && deco.souris.y>=ASS_YMIN); //si cliquer dans assiette gauche
                    poubelle = (deco.souris.x<=TROU_XMAX && deco.souris.x>= TROU_XMIN && deco.souris.y<=TROU_YMAX && deco.souris.y>=TROU_YMIN);  //si cliquer dans la poubelle
                    bouton1 = (deco.souris.x<=BOUTON1_XMAX && deco.souris.x>=BOUTON1_XMIN && deco.souris.y<=BOUTON_YMAX && deco.souris.y>=BOUTON_YMIN);  //si cliquer sur le bouton pour vider assiette gauche
                    bouton2 = (deco.souris.x<=BOUTON2_XMAX && deco.souris.x>=BOUTON2_XMIN && deco.souris.y<=BOUTON_YMAX && deco.souris.y>=BOUTON_YMIN);  //si cliquer sur le bouton pour vider assiette droite
                    if (bouton1)
                    {
                        printf("B1");
                        vider = 1;
                    }
                    if (bouton2)
                    {
                        printf("B2");
                        vider = 2;
                    }
                    if ( assietteDroite)
                    {
                        position = 3;
                        mvtX = 1; // avance a droite
                    }
                    if (assietteGauche)
                    {
                        position = 2;
                        if(deco.tube.x<ASS1_XMIN )
                        {
                            mvtX = 1; // avance a droite
                        }
                        if(deco.tube.x+LARGEUR_TUBE>ASS1_XMAX)
                        {
                            mvtX = -1; // avance a gauche
                        }
                    }
                    if ( poubelle)
                    {
                        position = 1;
                        mvtX = -1;  // avance a gauche
                        indiceAliment = 0; // On force la position � 0 pour la poubelle, car on ne garde aucun aliment
                    }
                    if (assietteDroite || assietteGauche || poubelle)
                    {
                        deplacementAliment = true;
                        afficheAlimentTube = false;
                        for (i=0; i < 10; i++)
                        {
                            if (position == 2)
                                if (assiettes1[i] == -1)
                                {
                                    assiettes1[i] = ordreAliment;
                                    indiceAliment = i;

                                    break;
                                }
                            if (position == 3)
                            {
                                if (assiettes2[i] == -1)
                                {
                                    assiettes2[i] = ordreAliment;
                                    indiceAliment = i;
                                    break;
                                }
                            }
                        }

                        switch (ordreAliment)
                        {
                        case 0:
                            alimentsAssiette[position-1][indiceAliment].setTexture(aliment0Image);
                            break;
                        case 1:
                            alimentsAssiette[position-1][indiceAliment].setTexture(aliment1Image);
                            break;
                        case 2:
                            alimentsAssiette[position-1][indiceAliment].setTexture(aliment2Image);
                            break;
                        case 3:
                            alimentsAssiette[position-1][indiceAliment].setTexture(aliment3Image);
                            break;
                        case 4:
                            alimentsAssiette[position-1][indiceAliment].setTexture(aliment4Image);
                            break;
                        }
                        alimentsAssiette[position-1][indiceAliment].setPosition(deco.tube.x + 12, HAUTEUR_TUBE - 43);
                    }
                }
            }
        }
        if(deco.tube.x+LARGEUR_TUBE>ASS2_XMAX ) //tube s'arrete au dessus de l'assiette2
        {
            mvtX = 0;
            deco.tube.x = ASS2_XMIN+14;
        }
        if(deco.tube.x<TROU_XMIN+26) //tube s'arrete au dessus de la pubelle
        {
            mvtX = 0;
            deco.tube.x = TROU_XMIN+30;
        }
        if(position == 2 && deco.tube.x>ASS1_XMIN && deco.tube.x+LARGEUR_TUBE<ASS1_XMAX)//tube s'arrete au dessus de l'assiette1
        {
            mvtX = 0;
            deco.tube.x = ASS1_XMIN+14;
        }
        if(mvtX == 0 && deplacementAliment == true)
        {
            mvtY = 1;
            if (alimentsAssiette[position-1][indiceAliment].getPosition().y > 600 - indiceAliment * TAILLE_EMPILEMENT)
            {
                mvtY = 0;
                deplacementAliment = false;
                afficheAlimentTube = true;
                genererAliment = true;
                if(position == 1)
                {
                    alimentsAssiette[position-1][indiceAliment].setTexture(vide);

                }
            }
        }

        deco.tube.x = deco.tube.x + PAS * mvtX; // deplacement tube
        fenetre.clear();
        if (vider == 1)
        {
            for (i=0; i<10; i++)
            {
                assiettes1[i]=-1;
            }


                for (int j=0; j < 10; j++)
                {
                    alimentsAssiette[1][j].setTexture(vide);;
                    //printf("i: %i, j: %i, x: %f, y: %f\n", i, j, alimentsAssiette[i][j].getPosition().x, alimentsAssiette[i][j].getPosition().y);
                }

        }
        if (vider == 2)
        {
            for (i=0; i<10; i++)
            {
                assiettes2[i]=-1;
            }


                for (int j=0; j < 10; j++)
                {
                    alimentsAssiette[2][j].setTexture(vide);;
                    //printf("i: %i, j: %i, x: %f, y: %f\n", i, j, alimentsAssiette[i][j].getPosition().x, alimentsAssiette[i][j].getPosition().y);
                }

        }
        vider = 0;
        alimentsAssiette[position-1][indiceAliment].setPosition( deco.tube.x + 12, alimentsAssiette[position - 1][indiceAliment].getPosition().y + PAS * mvtY);
        tube.setPosition(deco.tube.x,0);
        fenetre.draw(decor);
        if (afficheAlimentTube)
        {
            alimentTube.setPosition(deco.tube.x+12,deco.aliment.y);
            fenetre.draw(alimentTube);
        }
        for (i=0; i <3; i++)
        {
            for (int j=0; j < 10; j++)
            {
                fenetre.draw(alimentsAssiette[i][j]);
                //printf("i: %i, j: %i, x: %f, y: %f\n", i, j, alimentsAssiette[i][j].getPosition().x, alimentsAssiette[i][j].getPosition().y);
            }
        }
        fenetre.draw(tube);
        fenetre.draw(cadre1);
        fenetre.draw(recette1);
        fenetre.draw(cadre2);
        fenetre.draw(recette2);
        fenetre.draw(tube);
        fenetre.draw(texte);
        sleep( milliseconds(TEMPO));
        fenetre.display();
        //    printf("indice aliment tomb� %i\n", indiceAliment);

    }
    return EXIT_SUCCESS;
}
