#pragma once

#include "gameboard_type.h"

////////// gameboard //////////
/**
 * @brief make a new gameboard in specific size.
 * @param max_width the max limit of width of the new gameboard, that means the value of width range [0, max_width - 1];
 * @param max_height the max limit of height of the new gameboard, that means the value of height range [0, max_height - 1];
 * @return return 0 if done successfully.
 *         return -1 if the chessboard has been initialized.
 *         return -2 if the size is out of range.
 *         return -3 if malloc failed.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
extern char gameboard_make(const int max_width, const int max_height);

/**
 * @brief get the address of the data.
 * @return return the address if done successfully.
 *         return 0 if done unsuccessfully.
 * @version 1.0
 * @date 2024/10/1
 * @author ProYRB
 */
extern gameboard_data gameboard_get_data(void);

/**
 * @brief get the width of the gameboard.
 * @return return the width if done successfully.
 *         return 0 if done unsuccessfully.
 * @version 1.0
 * @date 2024/10/1
 * @author ProYRB
 */
extern unsigned int gameboard_get_width(void);

/**
 * @brief get the width of the gameboard.
 * @return return the width if done successfully.
 *         return 0 if done unsuccessfully.
 * @version 1.0
 * @date 2024/10/1
 * @author ProYRB
 */
extern unsigned int gameboard_get_height(void);

/**
 * @brief recycle the current gameboard and free the memory.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
extern void gameboard_recycle(void);

////////// coord //////////
/**
 * @brief get a specific coord.
 * @param y_of_height the y coord on height.
 * @param x_of_width the x coord on width.
 * @return return the address of coord at specific value.
 *         return 0 if done unsuccessfully.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
extern gameboard_unit_coord *const gameboard_get_coord(const int y_of_height, const int x_of_width);

/**
 * @brief set the coord to be a specific value.
 * @param coord the coord to be modified.
 * @param y_of_height the y coord on height.
 * @param x_of_width the x coord on width.
 * @return return 0 if done successfully.
 *         return -1 if the y is out of height range [0, max_height - 1].
 *         return -2 if the x is out of width range [0, max_width - 1].
 *         return -3 if the y and x are out of range.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
extern char gameboard_set_coord(gameboard_unit_coord *const coord, const int y_of_height, const int x_of_width);

/**
 * @brief recycle the coord.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
extern void gameboard_recycle_coord(gameboard_unit_coord *const coord);

////////// stone //////////
/**
 * @brief get the enum of stone at specific coord.
 * @param coord the coord of unit.
 * @return return the enum value if done successfully.
 *         return -1 if the coord is out of range.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
extern gameboard_unit_stone gameboard_get_stone_at_coord(const gameboard_unit_coord *const coord);

/**
 * @brief set the enum of stone at specific coord.
 * @param coord the coord of unit.
 * @param stone the enum you want to be set.
 * @return return 0 if done successfully.
 *         return -1 if the unit has the same stone.
 *         return -2 if the unit has the another stone.
 * @version 1.0
 * @date 2024/9/28
 * @author ProYRB
 */
extern char gameboard_set_stone_at_coord(const gameboard_unit_stone stone, const gameboard_unit_coord *const coord);

////////// unit //////////
/**
 * @brief get the coord of specific unit.
 * @param unit the specific unit.
 * @return return the address of coord if done successfully.
 *         return 0 if unit is error.
 * @version 1.0
 * @date 2024/10/1
 * @author ProYRB
 */
extern gameboard_unit_coord *gameboard_get_coord_of_unit(gameboard_unit *const unit);

/**
 * @brief get the stone of specific unit.
 * @param unit the specific unit.
 * @return return the address of stone if done successfully.
 *         return 0 if unit is error.
 * @version 1.0
 * @date 2024/10/1
 * @author ProYRB
 */
extern gameboard_unit_stone *gameboard_get_stone_of_unit(gameboard_unit *const unit);
