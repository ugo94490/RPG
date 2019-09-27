/*
** EPITECH PROJECT, 2019
** CPool_Day04_2018
** File description:
** my_strlen
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_strcat(char *str1, char const *str2)
{
    int len = my_strlen(str1) + my_strlen(str2) + 1;
    int i = 0;
    char *newstr = malloc(sizeof(char) * len);

    if (newstr == NULL)
        return (NULL);
    for (; str1[i] != '\0'; i++)
        newstr[i] = str1[i];
    for (int j = 0; str2[j]; j++) {
        newstr[i] = str2[j];
        i++;
    }
    newstr[i] = '\0';
    free(str1);
    return (newstr);
}
