#pragma once

#include "gameboard_type.h"

/**
 * @brief Check if the game has been won.
 * @param unit the coord of unit.
 * @return return 0 if done successfully.
 *         return -1 if the x exceedes the limit.
 *         return -2 if the y exceedes the limit.
 *         return -3 if the x and y exceedes the limit.
 *         return -4 if the specific stone is null.
 *         return -5 if not win.
 * @author SCR
 */
char checker_gameboard(const int x, const int y);
