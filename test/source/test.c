#include "test.h"
#include "checker.h"
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
    result = gameboard_set_stone_at_coord(White, coord);
    gameboard_set_coord(coord, 1, 1);
    result = gameboard_set_stone_at_coord(White, coord);
    gameboard_set_coord(coord, 2, 2);
    result = gameboard_set_stone_at_coord(White, coord);
    gameboard_set_coord(coord, 3, 3);
    result = gameboard_set_stone_at_coord(White, coord);
    gameboard_set_coord(coord, 4, 4);
    result = gameboard_set_stone_at_coord(White, coord);
    print_gameboard();

    gameboard_set_coord(coord, 0, 0);
    result = checker_determine(coord);
    Debug(Message_Level, "result:%d\n", result);

    gameboard_set_coord(coord, 1, 1);
    result = checker_determine(coord);
    Debug(Message_Level, "result:%d\n", result);

    gameboard_set_coord(coord, 2, 2);
    result = checker_determine(coord);
    Debug(Message_Level, "result:%d\n", result);

    gameboard_set_coord(coord, 3, 3);
    result = checker_determine(coord);
    Debug(Message_Level, "result:%d\n", result);

    gameboard_set_coord(coord, 4, 4);
    result = checker_determine(coord);
    Debug(Message_Level, "result:%d\n", result);

    result = gameboard_set_stone_at_coord(Black, coord);
    Debug(Warn_Level, "set result:%d\n", result);
    Debug(Warn_Level, "stone:%d\n", gameboard_get_stone_at_coord(coord));
    print_gameboard();

    gameboard_set_coord(coord, 4, 4);
    result = checker_determine(coord);
    Debug(Message_Level, "result:%d\n", result);

    gameboard_recycle_coord(coord);
    gameboard_recycle();

    return 0;
}