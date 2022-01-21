#include <stdio.h>
#include "cs50.h"
// #include "../libcs50-10.1.1/build/include/cs50.h"

void print_spaces(int diff)
{
    for (int i=0; i<(diff); i++)
    {
        printf(" ");
    }
}

void print_bricks(int bricks)
{
    for (int i=0; i<(bricks); i++)
    {
        printf("#");
    }
}

int main(void)
{
    int height;
    
    do
    {
        height = get_int("Height: ");
    }
    
    while (height>9 || 0>=height);
    
    int bricks = 1;
    while (bricks <= height)
    {
        int diff = height-bricks;
        print_spaces(diff);
        print_bricks(bricks);
        printf(" ");
        print_bricks(bricks);
        print_spaces(diff);
        printf("\n");
        bricks++;
    }
}
