/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** basics header
*/

#ifndef BASICS_H
#define BASICS_H

int my_strlen(char const *str);
char *my_strdup(char const *str);
int my_strcmp(char const *str1, char const *str2);
char **copy_words(char **words, int arg);
char **add_str_to_array(char **arr, char *str);
char **remove_string_array(char **words, int poswords);
char **replace_string_array(char **arr, char *str, int pos);
void free_word_array(char **words);
char **my_str_to_word_array(char *str, char *notinc);
int my_getnbr(char const *str);
int get_nb_words(char **words);
char *my_strcat(char *str1, char *str2);

#endif
