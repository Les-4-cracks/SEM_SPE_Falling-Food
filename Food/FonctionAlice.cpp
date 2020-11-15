#include <SFML/Graphics.hpp>
#include "FonctionAlice.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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

int timer(int seconde)
{
    seconde = 5;
    do
    {
        printf("temps :%03i\n",seconde);
        seconde--;
        Sleep(1000);
    }while(seconde >0);
    /*while (seconde >0)
    {
        printf("temps :%03i\n",seconde);
        seconde--;
        Sleep(1000);
    }*/
}
