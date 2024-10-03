#pragma once

#include <stdio.h>
#include <string.h>

#define Extract_FileName(input) ((strrchr(input, '/') ? strrchr(input, '/') + 1 : input))

#define Message_Level           3
#define Notice_Level            2
#define Warn_Level              1
#define Error_Level             0

/**
 * @brief output debug on specific level.
 * @param level the level of log. range: { Error_Level, Warn_Level, Notice_Level, Message_Level }.
 * @param ... what you want to output.
 * @author ProYRB
 */
#define Debug(level, ...)                                                                                                      \
    do                                                                                                                         \
    {                                                                                                                          \
        switch (level)                                                                                                         \
        {                                                                                                                      \
        case 0:                                                                                                                \
            printf("\033[1;31m");                                                                                              \
            break;                                                                                                             \
        case 1:                                                                                                                \
            printf("\033[1;33m");                                                                                              \
            break;                                                                                                             \
        case 2:                                                                                                                \
            printf("\033[0;32m");                                                                                              \
            break;                                                                                                             \
        case 3:                                                                                                                \
            printf("\033[0;30m");                                                                                              \
            break;                                                                                                             \
        default:                                                                                                               \
            printf("\033[0;30m");                                                                                              \
            break;                                                                                                             \
        }                                                                                                                      \
        printf("[%s:%d]", Extract_FileName(__FILE__), __LINE__);                                                               \
        printf(__VA_ARGS__);                                                                                                   \
        printf("\033[0m");                                                                                                     \
    }                                                                                                                          \
    while (0)
