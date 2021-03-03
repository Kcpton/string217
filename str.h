#ifndef strH
#define strH

size_t Str_getLength(const char pcSrc[]);

char *strcpy(char s1[], const char s2[]);

char *strcat(char s1[], const char s2[]);

int strncmp(const char s1[], const char s2[], size_t n);

char *strstr(const char s1[], const char s2[]);

#endif