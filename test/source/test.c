#include "test.h"
// #include "checker.h"
#include "debug.h"
#include "gameboard.h"
// #include "printer.h"

int main(void)
{
    char result = gameboard_initialize(10, 10);
    Debug(Message_Level, "width of gameboard: %d\n", gameboard_get_width());
    Debug(Message_Level, "height of gameboard: %d\n", gameboard_get_height());

    coord_set_x(0);
    coord_set_y(0);
    stone_set(White);
    Debug(Notice_Level, "stone: %d at (%d, %d)\n", stone_get(), coord_get_x(), coord_get_y());

    coord_set_x(1);
    coord_set_y(1);
    stone_set(Black);
    Debug(Notice_Level, "stone: %d at (%d, %d)\n", stone_get(), coord_get_x(), coord_get_y());

    coord_set_x(2);
    coord_set_y(2);
    stone_set(White);
    Debug(Notice_Level, "stone: %d at (%d, %d)\n", stone_get(), coord_get_x(), coord_get_y());

    coord_set_x(3);
    coord_set_y(3);
    stone_set(Black);
    Debug(Notice_Level, "stone: %d at (%d, %d)\n", stone_get(), coord_get_x(), coord_get_y());

    coord_set_x(4);
    coord_set_y(4);
    stone_set(White);
    Debug(Notice_Level, "stone: %d at (%d, %d)\n", stone_get(), coord_get_x(), coord_get_y());

    gameboard_recycle();

    return 0;
}