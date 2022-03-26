// Standard headers
#include <stdio.h>

// Internal headers
#include "../include/direction.h"
#include "../include/position.h"
#include "../include/spy.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter
#define LENGTH 8

// Vetor ordenado pelas prioridades. Ordenando as direções em ordem horaria
int DIRECTIONS_ATTACKER[LENGTH][2] = {DIR_UP_RIGHT,   
                                      DIR_RIGHT,      
                                      DIR_DOWN_RIGHT, 
                                      DIR_DOWN,       
                                      DIR_DOWN_LEFT,  
                                      DIR_LEFT,       
                                      DIR_UP_LEFT,    
                                      DIR_UP};

/*----------------------------------------------------------------------------*/
/*
PRIVATE FUNCTIONS
*/
/*----------------------------------------------------------------------------*/

bool moved_atack(position_t center, direction_t direction)
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

direction_t execute_attacker_strategy 
        (position_t attacker_position, Spy defender_spy) {

    // TODO: unused parameters, remove these lines later
    UNUSED(defender_spy);

    direction_t direction;

    for (int i = 0; i < LENGTH-1; i++)
    {
        direction = (direction_t) {DIRECTIONS_ATTACKER[i][0], DIRECTIONS_ATTACKER[i][1]};

        // Caso haja movimentação do attacker retorna a direção
        if (moved_atack(attacker_position, direction))
        {
            return direction;
        }
    }

    direction = (direction_t) {DIRECTIONS_ATTACKER[LENGTH-1][0], DIRECTIONS_ATTACKER[LENGTH-1][1]};

    return direction;
}


/*----------------------------------------------------------------------------*/