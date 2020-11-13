#include <SFML/Graphics.hpp>
#include "FonctionAlice.h"
#include <time.h>
#define NBALIMENTS 5
using namespace sf;

int alea(int aleaMax)
{
    int res;
    srand(time(NULL));
    aleaMax = NBALIMENTS-1;
    res = rand()%(NBALIMENTS);
    return res;
}
