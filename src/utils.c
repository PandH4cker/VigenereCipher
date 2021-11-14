//
// Created by drayr on 14/11/2021.
//

#include <string.h>
#include <stdlib.h>

char ** splitInParts(char * s, int parts)
{
    size_t strSize = strlen(s), partSize;
    partSize = (strSize + (strSize % 2 ? 1 : 0)) / parts;

    char ** splitted = malloc(parts * sizeof (char *));
    for (int i = 0; i < parts; ++i)
        splitted[i] = malloc(partSize + 1);

    int curr = 0;
    for (int i = 0; i < parts; ++i)
        for (; s[curr] != '\0'; ++curr)
        {
            if (!(curr % partSize) && curr != 0) {
                s += curr;
                curr = 0;
                break;
            }
            strncat(splitted[i], &s[curr], 1);
        }

    return splitted;
}