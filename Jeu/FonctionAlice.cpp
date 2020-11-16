#include <SFML/Graphics.hpp>
#include "FonctionsTimo.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define NBALIMENTS 5
using namespace sf;

//fonction aléatoire pour les aliments
int alea(int aleaMax)
{
    int res;
    srand(time(NULL));
    aleaMax = NBALIMENTS-1;
    res = rand()%(NBALIMENTS);
    return res;
}
