/*--------------------------------------------------------------------*/
/* str.h                                                       */
/* Author: Kevin Chen                                            */
/*--------------------------------------------------------------------*/


#ifndef strH
#define strH
#include <stddef.h>

/* Returns the length, in size_t, of the string pcSrc */
size_t Str_getLength(const char pcSrc[]);

/* Copies the string s2 into the string s1, returns a pointer to s1 */
char *Str_copy(char s1[], const char s2[]);

/* Copies the string s2 and add it to the end of the string s1.
    Returns a pointer to s1 */
char *Str_concat(char s1[], const char s2[]);

/* Returns a positive int if string s1 is larger than s2, negative int 
    if s1 is less than s2. If they are equal, return 0. */
int Str_compare(const char s1[], const char s2[]);

/* Finds a substring, s2, in string s1. Returns a pointer to the start
    of the substring in s1. If no substring exist, return NULL. */
char *Str_search(const char s1[], const char s2[]);

#endif