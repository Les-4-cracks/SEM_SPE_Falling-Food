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

/*void videAssiette (RenderWindow &fenetre, int assiettes1[], int assiettes2[])
{
    int i;
    bool bouton1,bouton2;

    if  (event.type == Event::MouseMoved)
    {
        deco.souris.x=event.mouseMove.x;
        deco.souris.y=event.mouseMove.y;
        bouton1 = (deco.souris.x<=BOUTON1_XMAX && deco.souris.x<=BOUTON1_XMIN && deco.souris.y<=BOUTON_YMAX && deco.souris.y<=BOUTON_YMIN);
        bouton2 = (deco.souris.x<=BOUTON2_XMAX && deco.souris.x<=BOUTON2_XMIN && deco.souris.y<=BOUTON_YMAX && deco.souris.y<=BOUTON_YMIN);

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left )
            {
                if (bouton1)
                {
                    for(i=0; i<10; i++)
                    {
                        assiettes1[i]=-1;
                    }
                }
                if (bouton2)
                {
                    for(i=0; i<10; i++)
                    {
                        assiettes2[i]=-1;
                    }
                }
            }
        }
    }
    fenetre.clear();
    fenetre.display();

}*/
