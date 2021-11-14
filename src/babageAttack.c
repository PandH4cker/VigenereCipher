//
// Created by drayr on 14/11/2021.
//
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "../includes/babageAttack.h"

float coincidence(char * message)
{
    size_t messageLength = strlen(message);
    float divider = ((float) (messageLength * (messageLength - 1)));
    int counter[26] = {0};
    for (int i = 0; message[i] != '\0'; ++i)
        ++counter[toupper(message[i]) - 'A'];

    float sum = 0;

    for (int i = 0; i < 26; ++i)
        sum += (float) (counter[i] * (counter[i] - 1));

    return sum/divider;
}