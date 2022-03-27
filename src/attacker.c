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

/* sorteia, com pesos, a direção que o atacante ira retornar
*/
direction_t chose_direction()
{
    int num = rand()%100;

    direction_t direction;

    if (num < 30)
        direction = (direction_t) {DIRECTIONS_ATTACKER[0][0], DIRECTIONS_ATTACKER[0][1]};
    else if (num < 60)
        direction = (direction_t) {DIRECTIONS_ATTACKER[1][0], DIRECTIONS_ATTACKER[1][1]};
    else if (num < 90)
        direction = (direction_t) {DIRECTIONS_ATTACKER[2][0], DIRECTIONS_ATTACKER[2][1]};
    else if (num < 92)
        direction = (direction_t) {DIRECTIONS_ATTACKER[3][0], DIRECTIONS_ATTACKER[3][1]};
    else if (num < 94)
        direction = (direction_t) {DIRECTIONS_ATTACKER[4][0], DIRECTIONS_ATTACKER[4][1]};
    else if (num < 96)
        direction = (direction_t) {DIRECTIONS_ATTACKER[5][0], DIRECTIONS_ATTACKER[5][1]};
    else if (num < 98)
        direction = (direction_t) {DIRECTIONS_ATTACKER[6][0], DIRECTIONS_ATTACKER[6][1]};
    else
        direction = (direction_t) {DIRECTIONS_ATTACKER[7][0], DIRECTIONS_ATTACKER[7][1]};
    
    return direction;
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
    UNUSED(attacker_position);

    direction_t direction;

    direction = chose_direction();

    return direction;
}


/*----------------------------------------------------------------------------*/