#include <stdio.h>
#include "cs50.h"


bool valid_triangle(void)
{
    float a_side;
    float b_side;
    float c_side;
        
    do
    {
        a_side = get_float("Side a: ");
        b_side = get_float("Side b: ");
        c_side = get_float("Side c: ");
    }
    while (a_side <= 0 || b_side <= 0 || c_side <= 0);
    
    if (a_side+b_side < c_side || b_side+c_side<a_side || c_side+b_side<a_side)
    {
        return false;
    }
    return true;
}


int main(void)
{
    bool ans = valid_triangle();
    printf("%s", ans?"true":"false\n");
}


