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

/* BOUTON MENU */
#define BOUTON_MENU_X_MIN 40
#define BOUTON_MENU_X_MAX 194
#define BOUTON_MENU_Y_MIN 667
#define BOUTON_MENU_Y_MAX 717

/* BOUTON QUITTER */
#define BOUTON_QUITTER_X_MIN 986
#define BOUTON_QUITTER_X_MAX 1158
#define BOUTON_QUITTER_Y_MIN 667
#define BOUTON_QUITTER_Y_MAX 718




using namespace sf;

extern Deco deco;

int recettesValidees(int recette[], int assiette[], int tailleRecette)//fonction qui vérifie si le tableau de l'assiette est conforme à celui de la recette
{
    int i,nbIngredientValide,res;
    nbIngredientValide = 0;

    for(i=0; i<tailleRecette; i++)
    {
        if(recette[i]==assiette[i])
            nbIngredientValide++;
    }

    if(nbIngredientValide==tailleRecette)
        res=1;//la fonction renvoie 1 si le plat est conforme
    else
        res=0;//et 0 si il ne correspond pas
    return res;
}

void menu(RenderWindow &fenetre)//fonction qui permet d'afficher le menu principal
{
    bool menujouer, menuoptions, menuregles,boutonquitter;
    Sprite spfond,spjouer,spoptions,spregles,spquitter;
    Texture fondimg,jouerimg1,optionsimg1,reglesimg1,jouerimg2,optionsimg2,reglesimg2,quitterimg1,quitterimg2;
//charge toutes les images de sprites
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
    if (!quitterimg1.loadFromFile("image/menu/quitter1.png"))
        printf("Echec chargment\n");
    if (!quitterimg2.loadFromFile("image/menu/quitter2.png"))
        printf("Echec chargment\n");
//applique les images de bases
    spfond.setTexture(fondimg);
    spjouer.setTexture(jouerimg1);
    spoptions.setTexture(optionsimg1);
    spregles.setTexture(reglesimg1);
    spquitter.setTexture(quitterimg1);


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
                    deco.souris.x=event.mouseMove.x;//on récupère les valeurs de x et y et les stocke dans des variables
                    deco.souris.y=event.mouseMove.y;

                    menujouer = (deco.souris.x<=BOUTON_X_MAX && deco.souris.x>=BOUTON_X_MIN && deco.souris.y<=BOUTON_JOUER_Y_MAX && deco.souris.y>=BOUTON_JOUER_Y_MIN);//assigne les coordonnées a la variable booléenne correspondant au bouton
                    menuoptions = (deco.souris.x<=BOUTON_X_MAX && deco.souris.x>=BOUTON_X_MIN && deco.souris.y<=BOUTON_OPTIONS_Y_MAX && deco.souris.y>=BOUTON_OPTIONS_Y_MIN);
                    menuregles = (deco.souris.x<=BOUTON_X_MAX && deco.souris.x>=BOUTON_X_MIN && deco.souris.y<=BOUTON_REGLES_Y_MAX && deco.souris.y>=BOUTON_REGLES_Y_MIN);
                    boutonquitter = (deco.souris.x<=BOUTON_QUITTER_X_MAX && deco.souris.x>=BOUTON_QUITTER_X_MIN && deco.souris.y<=BOUTON_QUITTER_Y_MAX && deco.souris.y>=BOUTON_QUITTER_Y_MIN);


                    if(menujouer)//si on survole un bouton, on lui applique l'image 2
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
                    if(boutonquitter)
                        spquitter.setTexture(quitterimg2);
                    else
                        spquitter.setTexture(quitterimg1);

                }

                if (event.type == Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == Mouse::Left )
                    {



                        if (menujouer)
                        {
                            jouer=1;//permet de quitter la boucle fonction menu() et donc de continuer le main()
                        }
                        if (menuoptions)
                        {
                            options(fenetre);
                        }
                        if (menuregles)
                        {
                            regles(fenetre);
                        }
                        if (boutonquitter)
                        {
                            fenetre.close();//ferme la fenetre
                        }


                    }
                }
            }


            fenetre.clear();
            fenetre.draw(spfond);
            fenetre.draw(spjouer);
            fenetre.draw(spoptions);
            fenetre.draw(spregles);
            fenetre.draw(spquitter);
            fenetre.display();

        }
    break;//quitte la fonction
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
                    deco.souris.x=event.mouseMove.x;//on récupère les valeurs de x et y et les stocke dans des variables
                    deco.souris.y=event.mouseMove.y;
                    boutonretour = (deco.souris.x<=BOUTON_RETOUR_X_MAX && deco.souris.x>=BOUTON_RETOUR_X_MIN && deco.souris.y<=BOUTON_RETOUR_Y_MAX && deco.souris.y>=BOUTON_RETOUR_Y_MIN);

                    if(boutonretour)//si on survole un bouton, on lui applique l'image 2
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
                            optionsEtat=1;//permet de quitter la boucle fonction options() et donc de revenir dans la fonction menu()
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
                    deco.souris.x=event.mouseMove.x;//on récupère les valeurs de x et y et les stocke dans des variables
                    deco.souris.y=event.mouseMove.y;
                    boutonretour = (deco.souris.x<=BOUTON_RETOUR_X_MAX && deco.souris.x>=BOUTON_RETOUR_X_MIN && deco.souris.y<=BOUTON_RETOUR_Y_MAX && deco.souris.y>=BOUTON_RETOUR_Y_MIN);

                    if(boutonretour)//si on survole un bouton, on lui applique l'image 2
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
                            reglesEtat=1;//permet de quitter la boucle fonction regles() et donc de revenir dans la fonction menu()
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


void perdu(RenderWindow &fenetre)
{
    bool boutonmenu, boutonquitter;
    Sprite spfond,spmenu, spquitter;
    Texture fondimg,menuimg1,menuimg2,quitterimg1,quitterimg2;

    if (!fondimg.loadFromFile("image/menu/perdu.png"))
        printf("Echec chargment\n");
    if (!menuimg1.loadFromFile("image/menu/menu1.png"))
        printf("Echec chargment\n");
    if (!menuimg2.loadFromFile("image/menu/menu2.png"))
        printf("Echec chargment\n");
    if (!quitterimg1.loadFromFile("image/menu/quitter1.png"))
        printf("Echec chargment\n");
    if (!quitterimg2.loadFromFile("image/menu/quitter2.png"))
        printf("Echec chargment\n");


    spfond.setTexture(fondimg);
    spmenu.setTexture(menuimg1);
    spquitter.setTexture(quitterimg1);

    int perduEtat = 0;

    while(perduEtat==0)
    {

            Event event;
            while (fenetre.pollEvent(event))
            {

                if (event.type == Event::Closed)
                    fenetre.close();

                if  (event.type == Event::MouseMoved)
                {
                    deco.souris.x=event.mouseMove.x;//on récupère les valeurs de x et y et les stocke dans des variables
                    deco.souris.y=event.mouseMove.y;
                    boutonmenu = (deco.souris.x<=BOUTON_MENU_X_MAX && deco.souris.x>=BOUTON_MENU_X_MIN && deco.souris.y<=BOUTON_MENU_Y_MAX && deco.souris.y>=BOUTON_MENU_Y_MIN);
                    boutonquitter = (deco.souris.x<=BOUTON_QUITTER_X_MAX && deco.souris.x>=BOUTON_QUITTER_X_MIN && deco.souris.y<=BOUTON_QUITTER_Y_MAX && deco.souris.y>=BOUTON_QUITTER_Y_MIN);


                    if(boutonmenu)//si on survole un bouton, on lui applique l'image 2
                        spmenu.setTexture(menuimg2);
                    else
                        spmenu.setTexture(menuimg1);

                    if(boutonquitter)
                        spquitter.setTexture(quitterimg2);
                    else
                        spquitter.setTexture(quitterimg1);

                }

                if (event.type == Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == Mouse::Left )
                    {

                        if (boutonmenu)
                        {
                            menu(fenetre);//lance la fonction menu()
                            perduEtat=1;//permet de quitter la boucle fonction perdu() et donc de revenir dans le main()
                        }


                        if (boutonquitter)
                        {
                            fenetre.close();//ferme la fenetre
                        }


                    }
                }
            }


            fenetre.clear();
            fenetre.draw(spfond);
            fenetre.draw(spmenu);
            fenetre.draw(spquitter);
            fenetre.display();


    }


}


void gagne(RenderWindow &fenetre)
{
    bool boutonmenu, boutonquitter;
    Sprite spfond,spmenu, spquitter;
    Texture fondimg,menuimg1,menuimg2,quitterimg1,quitterimg2;

    if (!fondimg.loadFromFile("image/menu/gagné.png"))
        printf("Echec chargment\n");
    if (!menuimg1.loadFromFile("image/menu/menu1.png"))
        printf("Echec chargment\n");
    if (!menuimg2.loadFromFile("image/menu/menu2.png"))
        printf("Echec chargment\n");
    if (!quitterimg1.loadFromFile("image/menu/quitter1.png"))
        printf("Echec chargment\n");
    if (!quitterimg2.loadFromFile("image/menu/quitter2.png"))
        printf("Echec chargment\n");


    spfond.setTexture(fondimg);
    spmenu.setTexture(menuimg1);
    spquitter.setTexture(quitterimg1);

    int perduEtat = 0;

    while(perduEtat==0)
    {

            Event event;
            while (fenetre.pollEvent(event))
            {

                if (event.type == Event::Closed)
                    fenetre.close();

                if  (event.type == Event::MouseMoved)
                {
                    deco.souris.x=event.mouseMove.x;//on récupère les valeurs de x et y et les stocke dans des variables
                    deco.souris.y=event.mouseMove.y;
                    boutonmenu = (deco.souris.x<=BOUTON_MENU_X_MAX && deco.souris.x>=BOUTON_MENU_X_MIN && deco.souris.y<=BOUTON_MENU_Y_MAX && deco.souris.y>=BOUTON_MENU_Y_MIN);
                    boutonquitter = (deco.souris.x<=BOUTON_QUITTER_X_MAX && deco.souris.x>=BOUTON_QUITTER_X_MIN && deco.souris.y<=BOUTON_QUITTER_Y_MAX && deco.souris.y>=BOUTON_QUITTER_Y_MIN);


                    if(boutonmenu)//si on survole un bouton, on lui applique l'image 2
                        spmenu.setTexture(menuimg2);
                    else
                        spmenu.setTexture(menuimg1);

                    if(boutonquitter)
                        spquitter.setTexture(quitterimg2);
                    else
                        spquitter.setTexture(quitterimg1);

                }

                if (event.type == Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == Mouse::Left )
                    {

                        if (boutonmenu)
                        {
                            menu(fenetre);//lance la fonction menu()
                            perduEtat=1;//permet de quitter la boucle fonction gagnr() et donc de revenir dans le main()
                        }


                        if (boutonquitter)
                        {
                            fenetre.close();//ferme la fenetre
                        }


                    }
                }
            }


            fenetre.clear();
            fenetre.draw(spfond);
            fenetre.draw(spmenu);
            fenetre.draw(spquitter);
            fenetre.display();


    }


}
