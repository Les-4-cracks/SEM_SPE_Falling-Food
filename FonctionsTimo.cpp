#include "FonctionsTimo.hpp"
#include <SFML/Graphics.hpp>

/* BOUTONS DU MENU PRINCIPAL */
#define BOUTON_X_MIN 95
#define BOUTON_X_MAX 309
#define BOUTON_JOUER_Y_MIN 290
#define BOUTON_JOUER_Y_MAX 385

#define BOUTON_OPTIONS_Y_MIN 422
#define BOUTON_OPTIONS_Y_MAX 498

#define BOUTON_REGLES_Y_MIN 558
#define BOUTON_REGLES_Y_MAX 633

/* BOUTON RETOUR */
#define BOUTON_RETOUR_X_MIN 25
#define BOUTON_RETOUR_X_MAX 210
#define BOUTON_RETOUR_Y_MIN 662
#define BOUTON_RETOUR_Y_MAX 717


using namespace sf;

extern Deco deco;

int recettesValidees(int recette[], int assiette[], int tailleRecette)
{
    int i,nbIngredientValide,res;
    nbIngredientValide = 0;

    for(i=0; i<tailleRecette; i++)
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

void menu(RenderWindow &fenetre)
{
    bool menujouer, menuoptions, menuregles;
    Sprite spfond,spjouer,spoptions,spregles;
    Texture fondimg,jouerimg1,optionsimg1,reglesimg1,jouerimg2,optionsimg2,reglesimg2;

    if (!fondimg.loadFromFile("image/menu/menu.png"))
        printf("Echec chargment\n");
    if (!jouerimg1.loadFromFile("image/menu/menuJouer1.png"))
        printf("Echec chargment\n");
    if (!optionsimg1.loadFromFile("image/menu/menuOptions1.png"))
        printf("Echec chargment\n");
    if (!reglesimg1.loadFromFile("image/menu/menuRègles1.png"))
        printf("Echec chargment\n");
    if (!jouerimg2.loadFromFile("image/menu/menuJouer2.png"))
        printf("Echec chargment\n");
    if (!optionsimg2.loadFromFile("image/menu/menuOptions2.png"))
        printf("Echec chargment\n");
    if (!reglesimg2.loadFromFile("image/menu/menuRègles2.png"))
        printf("Echec chargment\n");

    spfond.setTexture(fondimg);
    spjouer.setTexture(jouerimg1);
    spoptions.setTexture(optionsimg1);
    spregles.setTexture(reglesimg1);


    int jouer=0;
    while(fenetre.isOpen())
    {
        while (jouer==0)
        {
            Event event;
            while (fenetre.pollEvent(event))
            {

                if (event.type == Event::Closed)
                    fenetre.close();

                if  (event.type == Event::MouseMoved)
                {
                    deco.souris.x=event.mouseMove.x;
                    deco.souris.y=event.mouseMove.y;
                    menujouer = (deco.souris.x<=BOUTON_X_MAX && deco.souris.x>=BOUTON_X_MIN && deco.souris.y<=BOUTON_JOUER_Y_MAX && deco.souris.y>=BOUTON_JOUER_Y_MIN);
                    menuoptions = (deco.souris.x<=BOUTON_X_MAX && deco.souris.x>=BOUTON_X_MIN && deco.souris.y<=BOUTON_OPTIONS_Y_MAX && deco.souris.y>=BOUTON_OPTIONS_Y_MIN);
                    menuregles = (deco.souris.x<=BOUTON_X_MAX && deco.souris.x>=BOUTON_X_MIN && deco.souris.y<=BOUTON_REGLES_Y_MAX && deco.souris.y>=BOUTON_REGLES_Y_MIN);

                    if(menujouer)
                        spjouer.setTexture(jouerimg2);
                    else
                        spjouer.setTexture(jouerimg1);
                    if(menuoptions)
                        spoptions.setTexture(optionsimg2);
                    else
                        spoptions.setTexture(optionsimg1);
                    if(menuregles)
                        spregles.setTexture(reglesimg2);
                    else
                        spregles.setTexture(reglesimg1);

                }

                if (event.type == Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == Mouse::Left )
                    {



                        if (menujouer)
                        {
                            jouer=1;
                        }
                        if (menuoptions)
                        {
                            options(fenetre);
                        }
                        if (menuregles)
                        {
                            regles(fenetre);
                        }


                    }
                }
            }


            fenetre.clear();
            fenetre.draw(spfond);
            fenetre.draw(spjouer);
            fenetre.draw(spoptions);
            fenetre.draw(spregles);
            fenetre.display();

        }
    break;
    }


}


void options(RenderWindow &fenetre)
{
    bool boutonretour;
    Sprite spfond,spretour;
    Texture fondimg,retourimg1,retourimg2;

    if (!fondimg.loadFromFile("image/menu/options.png"))
        printf("Echec chargment\n");
    if (!retourimg1.loadFromFile("image/menu/retour1.png"))
        printf("Echec chargment\n");
    if (!retourimg2.loadFromFile("image/menu/retour2.png"))
        printf("Echec chargment\n");

    spfond.setTexture(fondimg);
    spretour.setTexture(retourimg1);

    int optionsEtat = 0;

    while(optionsEtat==0)
    {

            Event event;
            while (fenetre.pollEvent(event))
            {

                if (event.type == Event::Closed)
                    fenetre.close();

                if  (event.type == Event::MouseMoved)
                {
                    deco.souris.x=event.mouseMove.x;
                    deco.souris.y=event.mouseMove.y;
                    boutonretour = (deco.souris.x<=BOUTON_RETOUR_X_MAX && deco.souris.x>=BOUTON_RETOUR_X_MIN && deco.souris.y<=BOUTON_RETOUR_Y_MAX && deco.souris.y>=BOUTON_RETOUR_Y_MIN);

                    if(boutonretour)
                        spretour.setTexture(retourimg2);
                    else
                        spretour.setTexture(retourimg1);

                }

                if (event.type == Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == Mouse::Left )
                    {



                        if (boutonretour)
                        {
                            optionsEtat=1;
                        }


                    }
                }
            }


            fenetre.clear();
            fenetre.draw(spfond);
            fenetre.draw(spretour);
            fenetre.display();


    }


}


void regles(RenderWindow &fenetre)
{
    bool boutonretour;
    Sprite spfond,spretour;
    Texture fondimg,retourimg1,retourimg2;

    if (!fondimg.loadFromFile("image/menu/regles.png"))
        printf("Echec chargment\n");
    if (!retourimg1.loadFromFile("image/menu/retour1.png"))
        printf("Echec chargment\n");
    if (!retourimg2.loadFromFile("image/menu/retour2.png"))
        printf("Echec chargment\n");

    spfond.setTexture(fondimg);
    spretour.setTexture(retourimg1);

    int reglesEtat = 0;

    while(reglesEtat==0)
    {

            Event event;
            while (fenetre.pollEvent(event))
            {

                if (event.type == Event::Closed)
                    fenetre.close();

                if  (event.type == Event::MouseMoved)
                {
                    deco.souris.x=event.mouseMove.x;
                    deco.souris.y=event.mouseMove.y;
                    boutonretour = (deco.souris.x<=BOUTON_RETOUR_X_MAX && deco.souris.x>=BOUTON_RETOUR_X_MIN && deco.souris.y<=BOUTON_RETOUR_Y_MAX && deco.souris.y>=BOUTON_RETOUR_Y_MIN);

                    if(boutonretour)
                        spretour.setTexture(retourimg2);
                    else
                        spretour.setTexture(retourimg1);

                }

                if (event.type == Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == Mouse::Left )
                    {



                        if (boutonretour)
                        {
                            reglesEtat=1;
                        }


                    }
                }
            }


            fenetre.clear();
            fenetre.draw(spfond);
            fenetre.draw(spretour);
            fenetre.display();


    }


}
