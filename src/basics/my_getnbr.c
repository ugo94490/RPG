/*
** EPITECH PROJECT, 2019
** CPool_Day04_2018
** File description:
** my_getnbr
*/

static int analyse(char const *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0' && (nbr <= 0 ||
    (str[i] <= '9' && str[i] >= '0')); i = i + 1) {
        if (str[i] >= '0' && str[i] <= '9')
            nbr = nbr + 1;
    }
    return (nbr);
}

static int where_to_start(char const *str)
{
    int a = -1;

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (a >= 0) {
        }
        else if (str[i] >= 48 && str[i] <= 57)
            a = i;
    }
    return (a);
}

static int sign(char const *str)
{
    int sign = 0;

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] == '-')
            sign = sign + 1;
    }
    return (sign % 2);
}

static int transfo(char *c, int a, int s)
{
    long res = 0;
    int resultat = 0;

    if (a > 11)
        res = 0;
    else {
        for (int i = 0; i < a; i = i + 1)
            res = res * 10 + c[i] - '0';
    }
    if (s == 1)
        res = res * -1;
    if (res > 2147483647 || res < -2147483648)
        res = 0;
    resultat = res;
    return (resultat);
}

int my_getnbr(char const *str)
{
    int result = 0;
    int a = analyse(str);
    int b = where_to_start(str);
    int neg = sign(str);
    char c[a];

    for (int i = 0; i < a; i = i + 1) {
        c[i] = str[b];
        b = b + 1;
    }
    result = transfo(c, a, neg);
    return (result);
}
