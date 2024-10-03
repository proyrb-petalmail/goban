#include "debug.h"
#include "gameboard.h"

#define TEMPLATE_LENGTH 256

void print_gameboard(void)
{
    static char template[TEMPLATE_LENGTH];
    const unsigned int width = gameboard_get_width();
    const unsigned int height = gameboard_get_height();

    printf(" ┌─");
    for (unsigned char index_x = 0; index_x < width; ++index_x)
    {
        printf("%-4d", index_x);
    }
    printf("\bx\n");

    for (unsigned char index_y = 0; index_y < (width * 2 - 1); ++index_y)
    {
        if (1 == index_y % 2)
        {
            printf("   ");
            for (unsigned char index_x = 0; index_x < width; ++index_x)
                printf("|   ");
            printf("\n");
        }
        else
        {
            memset(template, '\0', TEMPLATE_LENGTH);
            printf("%2d ", index_y / 2);
            coord_set_y(index_y / 2);
            if (0 == index_y)
            {
                for (unsigned char index_x = 0; index_x < width; ++index_x)
                {
                    coord_set_x(index_x);
                    if (0 == index_x)
                    {
                        switch (stone_get())
                        {
                        case White:
                            strcat(template, "● ─");
                            break;
                        case Black:
                            strcat(template, "○ ─");
                            break;
                        default:
                            strcat(template, "┌──");
                            break;
                        }
                    }
                    else if ((width - 1) == index_x)
                    {
                        switch (stone_get())
                        {
                        case White:
                            strcat(template, " ●");
                            break;
                        case Black:
                            strcat(template, " ○");
                            break;
                        default:
                            strcat(template, "─┐");
                            break;
                        }
                    }
                    else
                    {
                        switch (stone_get())
                        {
                        case White:
                            strcat(template, " ● ─");
                            break;
                        case Black:
                            strcat(template, " ○ ─");
                            break;
                        default:
                            strcat(template, "─┬──");
                            break;
                        }
                    }
                }
                strcat(template, "\n");
            }
            else if ((width - 1) == (index_y / 2))
            {
                for (unsigned char index_x = 0; index_x < width; ++index_x)
                {
                    coord_set_x(index_x);
                    if (0 == index_x)
                    {
                        switch (stone_get())
                        {
                        case White:
                            strcat(template, "● ─");
                            break;
                        case Black:
                            strcat(template, "○ ─");
                            break;
                        default:
                            strcat(template, "└──");
                            break;
                        }
                    }
                    else if ((width - 1) == index_x)
                    {
                        switch (stone_get())
                        {
                        case White:
                            strcat(template, " ●");
                            break;
                        case Black:
                            strcat(template, " ○");
                            break;
                        default:
                            strcat(template, "─┘");
                            break;
                        }
                    }
                    else
                    {
                        switch (stone_get())
                        {
                        case White:
                            strcat(template, " ● ─");
                            break;
                        case Black:
                            strcat(template, " ○ ─");
                            break;
                        default:
                            strcat(template, "─┴──");
                            break;
                        }
                    }
                }
                strcat(template, "\n");
            }
            else
            {
                for (unsigned char index_x = 0; index_x < width; ++index_x)
                {
                    coord_set_x(index_x);
                    if (0 == index_x)
                    {
                        switch (stone_get())
                        {
                        case White:
                            strcat(template, "● ─");
                            break;
                        case Black:
                            strcat(template, "○ ─");
                            break;
                        default:
                            strcat(template, "├──");
                            break;
                        }
                    }
                    else if ((width - 1) == index_x)
                    {
                        switch (stone_get())
                        {
                        case White:
                            strcat(template, " ●");
                            break;
                        case Black:
                            strcat(template, " ○");
                            break;
                        default:
                            strcat(template, "─┤");
                            break;
                        }
                    }
                    else
                    {
                        switch (stone_get())
                        {
                        case White:
                            strcat(template, " ● ─");
                            break;
                        case Black:
                            strcat(template, " ○ ─");
                            break;
                        default:
                            strcat(template, "─┼──");
                            break;
                        }
                    }
                }
                strcat(template, "\n");
            }
            printf("%s", template);
        }
    }
    printf(" y\n");
    Debug(Notice_Level, "have printed gameboard\n");
}