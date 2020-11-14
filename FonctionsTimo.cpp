#include "FonctionsTimo.hpp"
#include <SFML/Graphics.hpp>

#define BOUTON_X_MIN 95
#define BOUTON_X_MAX 309
#define BOUTON_JOUER_Y_MIN 290
#define BOUTON_JOUER_Y_MAX 385


#define BOUTON_OPTIONS_Y_MIN 422
#define BOUTON_OPTIONS_Y_MAX 498


#define BOUTON_REGLES_Y_MIN 558
#define BOUTON_REGLES_Y_MAX 633



typedef struct
{
    int x;
    int y;
} Point;
typedef struct
{
    Point souris;
} Deco;

Deco deco;

using namespace sf;



int recettesValidees(int recette[], int assiette[])
{
    int i,nbIngredientValide,res;
    int tailleRecette = sizeof(recette)/sizeof(recette[0]);

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
    Sprite spfond,spjouer,spoptions,spregles;
    Texture fondimg,jouerimg,optionsimg,reglesimg;
    if (!fondimg.loadFromFile("image/menu/menu.png"))
        printf("Echec chargment\n");
    if (!jouerimg.loadFromFile("image/menu/menuJouer1.png"))
        printf("Echec chargment\n");
    if (!optionsimg.loadFromFile("image/menu/menuOptions1.png"))
        printf("Echec chargment\n");
    if (!reglesimg.loadFromFile("image/menu/menuRègles1.png"))
        printf("Echec chargment\n");
    spfond.setTexture(fondimg);
    spjouer.setTexture(jouerimg);
    spoptions.setTexture(optionsimg);
    spregles.setTexture(reglesimg);


    int jouer=0;
    while(jouer==0)
    {
        while (fenetre.isOpen())
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

                }

                    if (event.type == Event::MouseButtonPressed)
                    {
                        if (event.mouseButton.button == Mouse::Left )
                        {

                            bool menujouer, menuoptions, menuregles;
                            menujouer = (deco.souris.x<=BOUTON_X_MAX && deco.souris.x>=BOUTON_X_MIN && deco.souris.y<=BOUTON_JOUER_Y_MAX && deco.souris.y>=BOUTON_JOUER_Y_MIN);
                            menuoptions = (deco.souris.x<=BOUTON_X_MAX && deco.souris.x>=BOUTON_X_MIN && deco.souris.y<=BOUTON_OPTIONS_Y_MAX && deco.souris.y>=BOUTON_OPTIONS_Y_MIN);
                            menuregles = (deco.souris.x<=BOUTON_X_MAX && deco.souris.x>=BOUTON_X_MIN && deco.souris.y<=BOUTON_REGLES_Y_MAX && deco.souris.y>=BOUTON_REGLES_Y_MIN);
                            if (menujouer)
                            {
                                jouer=1;
                                printf("jouer");
                            }
                            if (menuoptions)
                            {
                                jouer=2;
                                printf("options");
                            }
                            if (menuregles)
                            {
                                jouer=3;
                                printf("regles");
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
    }


}
