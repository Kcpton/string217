/*--------------------------------------------------------------------*/
/* stra.c                                                        */
/* Author: Kevin Chen                                            */
/*--------------------------------------------------------------------*/

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
    assert(s1 != NULL && s2 != NULL);
    size_t index = 0;
    size_t s2len = 0;
    while (index < s2len) {
        s1[index] = s2[index];
        index++;
    }
    char* output = s1;
    return output;
}

char *strcat(char s1[], const char s2[]) {
    assert(s1 != NULL && s2 != NULL);
    size_t start = Str_getLength(s1);
    size_t end = Str_getLength(s2);
    size_t index = 0;
    while(index < end) {
        s1[start + index] = s2[index];
        index++;
    }
    char* output = s1;
    return output;
}

int strncmp(const char s1[], const char s2[], size_t n) {
    assert(s1 != NULL && s2 != NULL && n != NULL);
    size_t index = 0;
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
    assert(s1 != NULL && s2 != NULL);
    size_t s1len = Str_getLength(s1);
    size_t s2len = Str_getLength(s2);
    size_t index = 0;
    size_t index2 = 0;
    while(index + s2len < s1len) {
        index2 = 0;
        while(index2 < s2len && s1[index + index2] == s2[index2]) {
            index2++;
        }
        if (index2 == s2len) {
            return &s1[index];
        }
        index++;
    }
    char* output = s1;
    return output;
}