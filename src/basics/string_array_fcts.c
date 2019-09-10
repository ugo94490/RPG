/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** string_array_fcts
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strdup(char const *src);

void free_word_array(char **words)
{
    if (words != NULL) {
        for (int i = 0; words[i]; i++)
            free(words[i]);
        free(words);
    }
}

char **copy_words(char **words, int arg)
{
    int i = 0;
    int j = 0;
    char **copy;

    for (; words[i] != NULL; i++);
    copy = malloc(sizeof(char*) * (i+1+arg));
    if (copy == NULL)
        exit(84);
    copy[i] = NULL;
    for (i = 0; words[i] != NULL; i++) {
        copy[i] = malloc(sizeof(char)* (my_strlen(words[i])+1));
        if (copy[i] == NULL)
            exit(84);
    }
    for (i = 0; words[i] != NULL; i++) {
        for (j = 0; words[i][j] != '\0'; j++)
            copy[i][j] = words[i][j];
        copy[i][j] = '\0';
    }
    return (copy);
}

char **add_str_to_array(char **arr, char *str)
{
    int i = 0;
    char **cpy = copy_words(arr, 1);

    for (; cpy[i] != NULL; i++);
    cpy[i] = str;
    cpy[i+1] = NULL;
    free_word_array(arr);
    return (cpy);
}

char **remove_string_array(char **words, int poswords)
{
    int i = 0;
    int j = 0;
    char **copy;

    for (; words[i] != NULL; i++);
    copy = malloc(sizeof(char*) * (i));
    if (copy == NULL)
        exit(84);
    i = 0;
    while (words[i] != NULL) {
        if (i != poswords) {
            copy[j] = my_strdup(words[i]);
            j++;
        }
        i++;
    }
    copy[j] = NULL;
    free_word_array(words);
    return (copy);
}

char **replace_string_array(char **arr, char *str, int pos)
{
    char **cpy = copy_words(arr, 0);

    free(cpy[pos]);
    cpy[pos] = str;
    free_word_array(arr);
    return (cpy);
}
