#pragma once

#include "gameboard_type.h"

////////// gameboard //////////

/**
 * @brief generate a rectangular gameboard of specified size and initialize it as an empty gameboard.
 * @param width the width of the gameboard.
 * @param height the height of the gameboard.
 * @return return 0 if done successfully.
 *         return -1 if the gameboard has been initialized.
 *         Return -2 if the size exceedes the limit.
 *         return -3 if malloc failed.
 * @author ProYRB
 */
extern char gameboard_initialize(const int width, const int height);

/**
 * @brief get the width of the gameboard.
 * @return return the width if done successfully.
 * @author ProYRB
 */
extern unsigned int gameboard_get_width(void);

/**
 * @brief get the width of the gameboard.
 * @return return the height if done successfully.
 * @author ProYRB
 */
extern unsigned int gameboard_get_height(void);

/**
 * @brief recycle the gameboard.
 * @author ProYRB
 */
extern void gameboard_recycle(void);

////////// coord //////////

/**
 * @brief set x coord.
 * @param x the x coord on width.
 * @return return 0 if done unsuccessfully.
 *         return -1 if the value exceedes the limit.
 * @author ProYRB
 */
extern char coord_set_x(const int x);

/**
 * @brief set y coord.
 * @param y the y coord on height.
 * @return return 0 if done unsuccessfully.
 *         return -1 if the value exceedes the limit.
 * @author ProYRB
 */
extern char coord_set_y(const int y);

/**
 * @brief get x coord.
 * @return return x of the coord.
 * @author ProYRB
 */
extern unsigned int coord_get_x(void);

/**
 * @brief get y coord.
 * @return return y of the coord.
 * @author ProYRB
 */
extern unsigned int coord_get_y(void);

////////// stone //////////

/**
 * @brief set the stone at current coord.
 * @param new_stone the type of stone.
 * @return return 0 if done successfully.
 *         return -1 if the new_stone exceedes the limit.
 * @author ProYRB
 */
extern char stone_set(const stone new_stone);

/**
 * @brief get the stone.
 * @return return the enum value if done successfully.
 * @author ProYRB
 */
extern stone stone_get(void);
