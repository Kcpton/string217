/*--------------------------------------------------------------------*/
/* strp.c                                                        */
/* Author: Kevin Chen                                            */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char s1[], const char s2[]) {
    char *p =s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*s2 != '\0') {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;
}

char *Str_concat (char s1[], const char s2[]) {
    char *p =s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*p != '0') {
        p++;
    }
    while (*s2 != '\0') {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;
}

int Str_compare(const char s1[], const char s2[]) {
    size_t index = 0;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while(s1[index] != '\0' && s2[index] != '\0') {
        if (s1[index] - s2[index] != 0) {
            return s1[index] - s2[index];
        }
     index++;
    }
    if (s1[index] == '\0' && s2[index] != '\0') {
        return -1;
    }
    if (s2[index] == '\0'&& s1[index] != '\0') {
        return 1;
    }
    return 0;
}

char *Str_search(const char s1[], const char s2[]) {
    size_t s1len = Str_getLength(s1);
    size_t s2len = Str_getLength(s2);
    size_t index = 0;
    size_t index2 = 0;
    const char* output;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while(index + s2len <= s1len) {
        index2 = 0;
        while(index2 < s2len && s1[index + index2] == s2[index2]) {
            index2++;
        }
        if (index2 == s2len) {
            output = &s1[index];
            return (char*) output;
        }
        index++;
    }
    if (s1len == 0 && s2len == 0) {
        return (char*) s1;
    }
    return NULL;
}

