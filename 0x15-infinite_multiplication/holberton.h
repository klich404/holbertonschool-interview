#ifndef HOLBERTON_H
#define HOLBERTON_H

int _putchar(char c);
int error(void);
int _strlen(char *str);
void *memeset(void *a, int c, int size);
void *_calloc(unsigned int nmemb, unsigned int size);
void ar_fill(char *args, int *arr, int len);
void put_ar(int *arr, int len);
int *ar_times(int *arr2, int mul, int len2, int len3);
void ar_add(int *arr3, int *arr4, int len3, int tens);
void ar_mul(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3);

#endif /* HOLBERTON_H*/
