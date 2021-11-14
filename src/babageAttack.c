//
// Created by drayr on 14/11/2021.
//
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "../includes/babageAttack.h"
#include "../includes/utils.h"

float coincidence(char * message)
{
    size_t messageLength = strlen(message);
    float divider = ((float) (messageLength * (messageLength - 1)));
    int counter[26] = {0};
    for (int i = 0; message[i] != '\0'; ++i)
        if (isalpha(message[i]))
            ++counter[toupper(message[i]) - 'A'];

    float sum = 0;

    for (int i = 0; i < 26; ++i)
        sum += (float) (counter[i] * (counter[i] - 1));

    return sum/divider;
}

int findKeyLength(char * message)
{
    float currCoinc = 0;
    int potentialLength;
    char ** splitted = NULL;
    for (int i = 1; i < strlen(message) - 1; ++i)
    {
        splitted = splitInParts(message, i);

        float totalCoincidence = 0;
        for (int j = 0; j < i; ++j)
            totalCoincidence += coincidence(splitted[j]);

        totalCoincidence /= (float) i;
        if (currCoinc == 0 || (currCoinc <= totalCoincidence && totalCoincidence <= FRENCH_COINCIDENCE))
        {
            currCoinc = totalCoincidence;
            potentialLength = i;
        }
    }
    /*if (splitted)
    {
        for (int j = 0; j < strlen(message); ++j)
            if (splitted[j])
                free(splitted[j]);
        free(splitted);
    }*/
    return potentialLength;
}