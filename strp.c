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
    char *pointer =s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*s2 != '\0') {
        *pointer = *s2;
        pointer++;
        s2++;
    }
    *pointer = '\0';
    return s1;
}

char *Str_concat (char s1[], const char s2[]) {
    char *pointer =s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*pointer != '\0') {
        pointer++;
    }
    while (*s2 != '\0') {
        *pointer = *s2;
        pointer++;
        s2++;
    }
    *pointer = '\0';
    return s1;
}

int Str_compare(const char s1[], const char s2[]) {
    char *pointer1 = (char*)s1;
    char *pointer2 = (char*)s2;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*pointer1 != '\0' && *pointer2 != '\0') {
        if((int) (*pointer1 - *pointer2) != 0) {
            return (int)(*pointer1 - *pointer2);
        }
        pointer1++;
        pointer2++;
    }
    if((int) (*pointer1 - *pointer2) != 0) {
        return (int) (*pointer1 - *pointer2);
    }
    return 0;
}

char *Str_search(const char s1[], const char s2[]) {
    char *pointer1 = (char*)s1;
    char *pointer2 = (char*)s2;
    char *pointer3 = (char*)s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    if (Str_getLength(s2) == 0) {
        return (char*) s1;
    }
    if (Str_getLength(s2) == 0) {
        return (char*) NULL;
    }
    while(*pointer1 != '\0') {
        pointer2 = (char*)s2;
        pointer3 = p1;
        while(*pointer3 == *pointer2 && *pointer3 != '\0' 
            && *pointer2 != '\0') {
            pointer3++;
            pointer2++;
        }
        if (*pointer2 == '\0') {
            return (char*) p1;
        }
        p1++;
    }
    
    return NULL;
}

