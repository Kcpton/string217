/*--------------------------------------------------------------------*/
/* stra.c                                                        */
/* Author: Kevin Chen                                            */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <string.h>
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

char *Str_copy(char s1[], const char s2[]) {
    size_t index = 0;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while(s2[index] != '\0') {
        s1[index] = s2[index];
        index++;
    }
    s1[index] = '\0';
    return s1;
}

char *Str_concat(char s1[], const char s2[]) {
    size_t start = Str_getLength(s1);
    size_t end = Str_getLength(s2);
    size_t index = 0;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while(index < end) {
        s1[start + index] = s2[index];
        index++;
    }
    s1[index + start] = '\0';
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
    assert(s1 != NULL && s2 != NULL);
    while(index + s2len < s1len) {
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

/*
int main(int argc, char const *argv[]) {
    char a[10] = "byeasdfs";
    char b[10] = "as";
    char* d = Str_search(a,b);
    printf("%s", d);
    return 0;
}
*/



