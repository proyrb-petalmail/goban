#pragma once

#include "gameboard_type.h"

/**
 * @brief Check if the game has been won.
 * @param unit the coord of unit.
 * @return return 0 if Achieving Victory
 *         return -1 if Invalid piece
 * @version 1.0
 * @date 2024/10/1
 * @author SCR
 */
char checker_determine(gameboard_unit_coord *const coord);
