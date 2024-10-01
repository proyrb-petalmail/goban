#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "gameboard.h"
#include "gameboard_type.h"

/**
 * @brief the coord of data.
 * @param x the x coord of point.
 * @param y the y coord.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
struct gameboard_unit_coord
{
    unsigned int x_of_width;
    unsigned int y_of_height;
};

/**
 * @brief the data of gameboard.
 * @param coord the coord of data.
 * @param man the enum of man.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
struct gameboard_unit
{
    gameboard_unit_coord coord;
    gameboard_unit_stone stone;
};

/**
 * @brief the gameboard struct.
 * @param data the address of the gameboard.
 * @param width the width of the gameboard.
 * @param height the height of the gameboard.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
struct gameboard
{
    gameboard_data data;
    unsigned int width;
    unsigned int height;
};

static gameboard static_gameboard = {0, 0, 0};

#define Min_Size 5
#define Max_Size 32

char gameboard_make(const int max_width, const int max_height)
{
    if (0 != static_gameboard.data)
    {
        Debug(Warn_Level, "have had a gameboard\n");
        return -1;
    }

    if ((max_width < Min_Size || max_width > Max_Size) || (max_height < Min_Size || max_height > Max_Size))
    {
        Debug(Warn_Level, "the size is out range\n");
        return -2;
    }

    if (0 == (static_gameboard.data = malloc(sizeof(gameboard_unit *) * max_height)))
    {
        Debug(Warn_Level, "have failed to malloc\n");
        return -3;
    }

    for (unsigned int at_height = 0; at_height < max_height; ++at_height)
    {
        if (0 == (static_gameboard.data[at_height] = malloc(sizeof(gameboard_unit) * max_width)))
            return -3;
        for (unsigned int at_width = 0; at_width < max_width; ++at_width)
        {
            static_gameboard.data[at_height][at_width].coord.x_of_width = at_width;
            static_gameboard.data[at_height][at_width].coord.y_of_height = at_height;
            static_gameboard.data[at_height][at_width].stone = Null;
        }
    }

    static_gameboard.width = max_width;
    static_gameboard.height = max_height;

    Debug(Notice_Level, "have made a gameboard\n");
    return 0;
}

inline gameboard_data gameboard_get_data(void)
{
    if (0 == static_gameboard.data)
        return 0;
    return static_gameboard.data;
}

inline unsigned int gameboard_get_width(void) { return static_gameboard.width; }

inline unsigned int gameboard_get_height(void) { return static_gameboard.height; }

inline void gameboard_recycle(void)
{
    free(static_gameboard.data);
    static_gameboard.width = static_gameboard.height = 0;
    Debug(Notice_Level, "have recycled the gameboard\n");
}

gameboard_unit_coord *const gameboard_get_coord(const int y_of_height, const int x_of_width)
{
    gameboard_unit_coord *const coord = malloc(sizeof(gameboard_unit_coord));

    if (0 == coord)
        return 0;
    Debug(Message_Level, "have malloced a coord\n");

    if (gameboard_set_coord(coord, y_of_height, x_of_width))
    {
        gameboard_recycle_coord(coord);
        return 0;
    }
    else
    {
        Debug(Message_Level, "have gotten the coord\n");
        return coord;
    }
}

char gameboard_set_coord(gameboard_unit_coord *const coord, const int y_of_height, const int x_of_width)
{
    char return_value = 0;

    if (y_of_height < 0 || y_of_height > (static_gameboard.height - 1))
    {
        Debug(Warn_Level, "y of the coord is out of range\n");
        return_value |= (1 << 0);
    }

    if (x_of_width < 0 || x_of_width > (static_gameboard.width - 1))
    {
        Debug(Warn_Level, "x of the coord is out of range\n");
        return_value |= (1 << 1);
    }

    if (return_value)
        return return_value;
    else
    {
        coord->y_of_height = y_of_height;
        coord->x_of_width = x_of_width;
        Debug(Message_Level, "have set the coord\n");
        return 0;
    }
}

inline void gameboard_recycle_coord(gameboard_unit_coord *const coord)
{
    free(coord);
    Debug(Message_Level, "have recycled the coord\n");
}

inline gameboard_unit_stone gameboard_get_stone_at_coord(const gameboard_unit_coord *const coord)
{
    return static_gameboard.data[coord->y_of_height][coord->x_of_width].stone;
}

char gameboard_set_stone_at_coord(const gameboard_unit_stone stone, const gameboard_unit_coord *const coord)
{
    char return_value = 0;
    gameboard_unit_stone stone_of_coord;

    switch (stone_of_coord = gameboard_get_stone_at_coord(coord))
    {
    case Null:
    {
        static_gameboard.data[coord->y_of_height][coord->x_of_width].stone = stone;
        break;
    }
    default:
    {
        if (stone_of_coord == static_gameboard.data[coord->y_of_height][coord->x_of_width].stone)
            return_value = -1;
        else
            return_value = -2;
        break;
    }
    }

    Debug(Message_Level, "have set the stone\n");
    return return_value;
}

inline gameboard_unit_coord *gameboard_get_coord_of_unit(gameboard_unit *const data)
{
    if (0 == data)
        return 0;
    return &(data->coord);
}

inline gameboard_unit_stone *gameboard_get_stone_of_unit(gameboard_unit *const data)
{
    if (0 == data)
        return 0;
    return &(data->stone);
}
