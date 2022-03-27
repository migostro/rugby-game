// Standard headers
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Internal headers
#include "../include/direction.h"
#include "../include/position.h"
#include "../include/spy.h"

/* Fica sorteando se vai pra cima ou para bixo */

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter
#define LENGTH 7

bool rise();
bool moved_def(position_t center, direction_t direction);

/*----------------------------------------------------------------------------*/
/*
PRIVATE FUNCTIONS
*/
/*----------------------------------------------------------------------------*/

/* Sorteia se o proximo movimento será para cima
*/
bool rise()
{
    int r = rand();

    if (r % 2 == 1)
    {
        return true;
    }
    
    return false;
}

/*----------------------------------------------------------------------------*/
/*
PUBLIC FUNCTIONS
*/
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy 
        (position_t defender_position, Spy attacker_spy) {

    direction_t direction;
    
    // TODO: unused parameters, remove these lines later
    UNUSED(attacker_spy);
    UNUSED(defender_position);

    // sorteia para decidir se deve subir
    if (rise())
        direction = (direction_t) DIR_UP;
    else
        direction = (direction_t) DIR_DOWN;

    return direction;
}

/*----------------------------------------------------------------------------*/