//
// Created by User on 22.09.2024.
//
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

static double get_side(const char* side_name)
{
    double side = 0;
    int valid_input = 0;

    while (valid_input == 0)
    {
        printf("Enter the side (%s) of triangle:\n", side_name);
        scanf("%lf", &side);
        fflush(stdin);
        if (side < 0.001 || side > 1000)
        {
            printf("Invalid input, try again\n");
            fflush(stdin);
        }
        else
        {
            valid_input++;
        }
    }
    return side;
}

static unsigned get_decimal_places()
{
    unsigned n = 0;
    int valid_input = 0;
    while (valid_input == 0)
    {
        printf("Enter the number of decimal places (from 1 to 12):\n");
        scanf("%u", &n);
        fflush(stdin);
        if (n < 1 || n > 12)
        {
            printf("Invalid number of decimal places, try again\n");
            fflush(stdin);
        }
        else
        {
            valid_input++;
        }
    }
    return n;
}

#endif //FUNCTIONS_H
