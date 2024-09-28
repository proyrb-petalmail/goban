#pragma once

/**
 * @brief the enum of stone.
 * @param Null null stone.
 * @param White white stone.
 * @param Black black stone.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
typedef enum gameboard_unit_stone
{
    Null = 0,
    White,
    Black,
} gameboard_unit_stone;

/**
 * @brief the coord of unit.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
typedef struct gameboard_unit_coord gameboard_unit_coord;

/**
 * @brief the unit of gameboard.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
typedef struct gameboard_unit gameboard_unit;

/**
 * @brief the gameboard struct.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
typedef struct gameboard gameboard;
