#ifndef FIELDS_H
#define FIELDS_H

/// the 4 directions : up(0), right(1), down(2), left(3)
#define NB_DIRECTIONS 4

#include "app_data.h"

/// @brief typedef for functions binded to fields
typedef int Func(App_datas*);

/**
 * @brief list the four directions
 */
typedef enum Directions Directions;
enum Directions
{
    /// @brief upwards
    UP = 0,
    /// @brief rightwards
    RIGHT = 1,
    /// @brief downwards
    DOWN = 2,
    /// @brief leftwards
    LEFT = 3,
    /// @brief no direction: this object cannot move
    NO_DIR = -1
};

/**
 * @brief One field, = one zone the user might select, and with which TODO:[it] can perform action
 */
typedef struct Field Field;
struct Field
{
    /// @brief id of this field ; i.e indice of this field in the Fields::fields array
    int id;
    /// @brief coordinates of the first char of this field
    int y, x;
    /// @brief list of the fields accessible by pressing one of the four direction keys
    int next_id[NB_DIRECTIONS];

    ///@brief bind to the function called when this field is entered
    Func* action;
};

#endif