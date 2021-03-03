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
    while (*p != '\0') {
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
    char *p1 = (char*)s1;
    char *p2 = (char*)s2;
    while (*p1 != '\0' && *p2 != '\0') {
        if((int) (*p1 - *p2) != 0) {
            return (int)(*p1 - *p2);
        }
        p1++;
        p2++;
    }
    if((int) (*p1 - *p2) != 0) {
        return (int) (*p1 - *p2);
    }
    return 0;
}

char *Str_search(const char s1[], const char s2[]) {
    char *p1 = (char*)s1;
    char *p2 = (char*)s2;
    char *p3 = (char*)s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    if (Str_getLength(s2) == 0) {
        return (char*) s1;
    }
    if (Str_getLength(s2) == 0) {
        return (char*) NULL;
    }
    while(*p1 != '\0') {
        p2 = (char*)s2;
        p3 = p1;
        while(*p3 == *p2 && *p3 != '\0' && *p2 != '\0') {
            p3++;
            p2++;
        }
        if (*p2 == '\0') {
            return (char*) p1;
        }
        p1++;
    }
    
    return NULL;
}

