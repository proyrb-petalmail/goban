#include "checker.h"
#include "debug.h"
#include "gameboard.h"

char checker_gameboard(const int x, const int y)
{
    char return_value = 0;
    if (coord_set_x(x))
    {
        Debug(Warn_Level, "the x exceedes the limit\n");
        return_value |= (1 << 0);
    }
    if (coord_set_y(y))
    {
        Debug(Warn_Level, "the y exceedes the limit\n");
        return_value |= (1 << 1);
    }
    if (return_value)
        return return_value;

    const stone base_stone = stone_get();

    if (Null == base_stone)
        return return_value = -4;

    int count = 1;

    /* '\' */
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (coord_set_x(x - index) || coord_set_y(y - index))
            continue;

        if (stone_get() == base_stone)
            ++count;
        else
            break;
    }
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (coord_set_x(x + index) || coord_set_y(y + index))
            continue;

        if (stone_get() == base_stone)
            ++count;
        else
            break;
    }
    if (count > 4)
        return 0;
    else
        count = 1;

    /* '/' */
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (coord_set_x(x - index) || coord_set_y(y + index))
            continue;

        if (stone_get() == base_stone)
            ++count;
        else
            break;
    }
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (coord_set_x(x + index) || coord_set_y(y - index))
            continue;
        if (stone_get() == base_stone)
            ++count;
        else
            break;
    }
    if (count > 4)
        return 0;
    else
        count = 1;

    /* '-' */
    coord_set_y(y);
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (coord_set_x(x - index))
            continue;

        if (stone_get() == base_stone)
            ++count;
        else
            break;
    }
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (coord_set_x(x + index))
            continue;
        if (stone_get() == base_stone)
            ++count;
        else
            break;
    }
    if (count > 4)
        return 0;
    else
        count = 1;

    /* '|' */
    coord_set_x(x);
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (coord_set_y(y + index))
            continue;

        if (stone_get() == base_stone)
            ++count;
        else
            break;
    }
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (coord_set_y(y - index))
            continue;
        if (stone_get() == base_stone)
            ++count;
        else
            break;
    }
    if (count > 4)
        return 0;
    else
        count = 1;

    return -5;
}
