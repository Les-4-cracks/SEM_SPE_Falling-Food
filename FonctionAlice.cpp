#include <SFML/Graphics.hpp>
#include "FonctionAlice.h"
#include <time.h>
#define NBALIMENTS 5
using namespace sf;

int alea(int aleaMax)
{
    //srand(time(NULL));
    int res,i;

    aleaMax = NBALIMENTS-1;
    res = rand()%(NBALIMENTS);


    return res;
}
