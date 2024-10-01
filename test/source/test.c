#include "test.h"
#include "debug.h"
#include "gameboard.h"
#include "printer.h"

int main(void)
{
    char result = gameboard_make(10, 10);
    if (result)
    {
        Debug(Error_Level, "failed to make gameboard\n");
        return result;
    }

    print_gameboard();
    gameboard_unit_coord *const coord = gameboard_get_coord(0, 0);
    result = gameboard_get_stone_at_coord(coord);
    result = gameboard_set_stone_at_coord(White, coord);
    result = gameboard_get_stone_at_coord(coord);
    gameboard_recycle_coord(coord);
    gameboard_recycle();

    return 0;
}