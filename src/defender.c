// Standard headers
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Internal headers
#include "../include/direction.h"
#include "../include/position.h"
#include "../include/spy.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter
#define LENGTH 7

bool rise();
bool moved_def(position_t center, direction_t direction);

// direções tomadas pelo deffender em ordem de prioridade
int DIRECTIONS_DEFENDER[LENGTH][2] = { DIR_DOWN,       
                                       DIR_DOWN_LEFT,  
                                       DIR_LEFT,       
                                       DIR_UP_LEFT,    
                                       DIR_UP_RIGHT,   
                                       DIR_RIGHT,      
                                       DIR_DOWN_RIGHT };

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

bool moved_def(position_t center, direction_t direction)
{
    position_t new_position = move_position(center, direction);

    // caso o defender se movimentou, retorna a direção para 'cima'
    if (!equal_positions(center, new_position))
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

    srand(time(NULL));
    
    // TODO: unused parameters, remove these lines later
    UNUSED(attacker_spy);

    // sorteia para decidir se deve subir
    if (rise() && moved_def(defender_position, (direction_t) DIR_UP))
    {
        return (direction_t) DIR_UP;
    }

    direction_t direction;

    // caso contrario, primeiramente tenta descer, senão tenta ir para alguma outra direção
    for (int i = 0; i < LENGTH-1; i++)
    {
        direction = (direction_t) {DIRECTIONS_DEFENDER[i][0], DIRECTIONS_DEFENDER[i][1]};

        // Caso haja movimentação do attacker retorna a direção
        if (moved_def(defender_position, direction))
        {
            return direction;
        }
    }

    direction = (direction_t) {DIRECTIONS_DEFENDER[LENGTH-1][0], DIRECTIONS_DEFENDER[LENGTH-1][1]};

    return direction;
}

/*----------------------------------------------------------------------------*/