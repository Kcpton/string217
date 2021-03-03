/*--------------------------------------------------------------------*/
/* stra.c                                                        */
/* Author: Kevin Chen                                            */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char *strcpy(char s1[], const char s2[]) {
    size_t index = 0;
    size_t s2len = 0;
    char* output = s1;
    assert(s1 != NULL && s2 != NULL);
    while (index < s2len) {
        s1[index] = s2[index];
        index++;
    }
    return output;
}

char *strcat(char s1[], const char s2[]) {
    size_t start = Str_getLength(s1);
    size_t end = Str_getLength(s2);
    size_t index = 0;
    char* output = s1;
    assert(s1 != NULL && s2 != NULL);
    while(index < end) {
        s1[start + index] = s2[index];
        index++;
    }
    return output;
}

int strncmp(const char s1[], const char s2[], size_t n) {
    size_t index = 0;
    assert(s1 != NULL && s2 != NULL);
    while(index < n) {
        if (s1[index] > s2[index]) {
            return 1;
        }
        else if (s1[index] < s2[index]) {
            return -1;
        }
        index++;
    }
    return 0;
}

char *strstr(const char s1[], const char s2[]) {
    size_t s1len = Str_getLength(s1);
    size_t s2len = Str_getLength(s2);
    size_t index = 0;
    size_t index2 = 0;
    char* output;
    assert(s1 != NULL && s2 != NULL);
    while(index + s2len < s1len) {
        index2 = 0;
        while(index2 < s2len && s1[index + index2] == s2[index2]) {
            index2++;
        }
        if (index2 == s2len) {
            output = (char*) &s1[index];
            return output;
        }
        index++;
    }
    output = (char*) &s1;
    return output;
}