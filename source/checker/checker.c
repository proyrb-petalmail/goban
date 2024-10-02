#include "checker.h"
#include "debug.h"
#include "gameboard.h"

char checker_determine(gameboard_unit_coord *const coord)
{
    const gameboard_unit_stone base_stone = gameboard_get_stone_at_coord(coord);

    if (Null == base_stone)
        return -1;

    /* '\' */
    int count = 1;
    gameboard_unit_coord *const new_coord = gameboard_get_coord(0, 0);
    // 0 = gameboard_set_coord( coord, , x_of_width)
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (gameboard_get_stone_at_coord(new_coord) == base_stone)
            ++count;
        else
            break;
    }
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (5 == count)
        {
            gameboard_recycle_coord(coord);
            return 0;
        }
        if (gameboard_get_stone_at_coord(new_coord) == base_stone)
            ++count;
        else
            break;
    }

    gameboard_recycle_coord(coord);
    return -2;

    /* '/' */
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (gameboard_get_stone_at_coord(new_coord) == base_stone)
        {
            ++count;
        }
        else
            break;
    }
    for (unsigned char index = 1; index < 5; ++index)
    {
        gameboard_unit_coord *const new_coord = {coord->y_of_height + index, coord->x_of_width - index};
        if (gameboard_get_stone_at_coord(new_coord) == base_stone)
            ++count;
        else
            break;
        if (count > 4)
            return 0;
    }
    gameboard_recycle_coord(coord);
    return -2;
}