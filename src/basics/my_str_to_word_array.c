/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

static int check_if_inc(char c, char *notinc)
{
    for (int i = 0; notinc[i] != '\0'; i++)
        if (c == notinc[i])
            return (0);
    return (1);
}

static int nb_words(char *str, char *notinc)
{
    int nb_words = 0;

    while (*str != '\0') {
        if (check_if_inc(*str, notinc) == 0)
            str += 1;
        if (*str != '\0' && check_if_inc(*str, notinc) == 1)
            nb_words++;
        for (; *str != '\0'  && check_if_inc(*str, notinc) == 1; str += 1);
    }
    return (nb_words);
}

static int word_len(char *str, char *notinc)
{
    int i = 0;

    for (; str[i] != '\0' && check_if_inc(str[i], notinc) == 1; i++);
    return (i);
}

static char *sub_str_to_word_array(char *str, char *notinc, char **word)
{
    int j = 0;

    if (word[0] == NULL)
        return (NULL);
    for (j = 0; *str && check_if_inc(*str, notinc) == 1; j++) {
        word[0][j] = *str;
        str += 1;
    }
    word[0][j] = '\0';
    return (str);
}

char **my_str_to_word_array(char *str, char *notinc)
{
    int nb_word = nb_words(str, notinc);
    int i = -1;
    char **words = malloc(sizeof(char*) * (nb_word+1));

    if (words == NULL)
        return (NULL);
    while (*str != '\0' && nb_word > 0) {
        if (check_if_inc(*str, notinc) == 0)
            str += 1;
        if (*str != '\0' && check_if_inc(*str, notinc) == 1) {
            words[i+=1] = malloc(sizeof(char) * word_len(str, notinc)+1);
            str = sub_str_to_word_array(str, notinc, &words[i]);
        }
        if (str == NULL)
            return (NULL);
    }
    words[nb_word] = NULL;
    return (words);
}
