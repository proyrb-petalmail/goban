#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "gameboard.h"
#include "gameboard_type.h"

#define Min_Size 5
#define Max_Size 32

/**
 * @brief the coord of unit.
 * @param x the x coord.
 * @param y the y coord.
 * @version 2.0
 * @date 2024/10/2
 * @author ProYRB
 */
typedef struct coord
{
    unsigned int x;
    unsigned int y;
} coord;

/**
 * @brief the unit of gameboard.
 * @param coord the coord.
 * @param stone the stone.
 * @version 2.0
 * @date 2024/10/2
 * @author ProYRB
 */
typedef struct unit
{
    coord coord;
    stone stone;
} unit;

/**
 * @brief the gameboard struct.
 * @param unit_pointer the address of the gameboard.
 * @param width the width of the gameboard.
 * @param height the height of the gameboard.
 * @version 2.0
 * @date 2024/10/2
 * @author ProYRB
 */
typedef struct gameboard
{
    unit **unit_pointer;
    unsigned int width;
    unsigned int height;
} gameboard;

////////// gameboard //////////

gameboard static_gameboard = {0, 0, 0};

char gameboard_initialize(const int width, const int height)
{
    if (0 != static_gameboard.unit_pointer)
    {
        Debug(Warn_Level, "had initialized the gameboard\n");
        return -1;
    }

    if ((width < Min_Size || width > Max_Size) || (height < Min_Size || height > Max_Size))
    {
        Debug(Error_Level, "the size exceedes the limit\n");
        return -2;
    }

    if (0 == (static_gameboard.unit_pointer = malloc(sizeof(unit *) * height)))
    {
        Debug(Error_Level, "malloc failed\n");
        return -3;
    }

    for (unsigned int at_height = 0; at_height < height; ++at_height)
    {
        if (0 == (static_gameboard.unit_pointer[at_height] = malloc(sizeof(unit) * width)))
            return -3;
        for (unsigned int at_width = 0; at_width < width; ++at_width)
        {
            static_gameboard.unit_pointer[at_height][at_width].coord.x = at_width;
            static_gameboard.unit_pointer[at_height][at_width].coord.y = at_height;
            static_gameboard.unit_pointer[at_height][at_width].stone = Null;
        }
    }

    static_gameboard.width = width;
    static_gameboard.height = height;

    Debug(Notice_Level, "initialized the gameboard successfully\n");
    return 0;
}

inline unsigned int gameboard_get_width(void) { return static_gameboard.width; }

inline unsigned int gameboard_get_height(void) { return static_gameboard.height; }

void gameboard_recycle(void)
{
    free(static_gameboard.unit_pointer);
    static_gameboard.width = static_gameboard.height = 0;
    Debug(Notice_Level, "have recycled the gameboard\n");
}

////////// coord //////////

coord static_coord = {0, 0};

char coord_set_x(const int x)
{
    if (x < 0 || x > (gameboard_get_width() - 1))
        return -1;
    static_coord.x = x;
    return 0;
}

char coord_set_y(const int y)
{
    if (y < 0 || y > (gameboard_get_height() - 1))
        return -1;
    static_coord.y = y;
    return 0;
}

inline unsigned int coord_get_x(void) { return static_coord.x; }

inline unsigned int coord_get_y(void) { return static_coord.y; }

////////// stone //////////

char stone_set(const stone new_stone)
{
    if (new_stone < Null || new_stone > Black)
        return -1;
    stone *const base = &(static_gameboard.unit_pointer[coord_get_y()][coord_get_x()].stone);
    Debug((Null == *base) ? Message_Level : Warn_Level, "set [%s] stone at (%d, %d)\n",
          (Null == *base) ? "Null" : ((White == *base) ? "White" : "Balck"), coord_get_x(), coord_get_y());
    *base = new_stone;
    return 0;
}

inline stone stone_get(void) { return static_gameboard.unit_pointer[coord_get_y()][coord_get_x()].stone; }
