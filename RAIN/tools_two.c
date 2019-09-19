/*
** EPITECH PROJECT, 2019
** tools_two.c
** File description:
** tools_two.c
*/

#include "my_rpg.h"

int my_strlen92(char *str)
{
    int k = 0;

    while (str[k] != '\0') {
        k++;
    }
    return (k-1);
}

void my_revstr(char *str)
{
    int g = my_strlen92(str);
    int j;
    int p = 0;

    while (p <= g/2) {
        j = str[p];
        str[p] = str[g - p];
        str[g - p] = j;
        p++;
    }
}

int my_int(int nb)
{
    int len = 0;
    int compteur = nb;

    while (compteur > 0) {
        compteur /= 10;
        len++;
    }
    len++;
    return (len);
}

char* my_itoa(int nb, char *nbr)
{
    bool sign = false;
    int tmp = 0;
    int i = 0;

    if (nb == 0)
        return ("0");
    if (nb < 0) {
        sign = true;
        nb = -nb;
    }
    for (i = 0; nb != 0; i++) {
        tmp = nb % 10;
        nbr[i] = tmp + '0';
        nb = nb / 10;
    }
    if (sign == true)
        nbr[i] = '-';
    nbr[i] = '\0';
    my_revstr(nbr);
    return (nbr);
}
