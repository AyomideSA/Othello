/*
 * Date: 18/5/21
 */

#include <string.h>


void removeNewline(char array[])
{
    size_t lastCharPos = strlen(array) - 1;

    if (array[lastCharPos] == '\n')
        array[lastCharPos] = '\0';

}