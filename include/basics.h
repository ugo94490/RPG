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
char **copy_words(char **words, int arg);
char **add_str_to_array(char **arr, char *str);
char **remove_string_array(char **words, int poswords);
char **replace_string_array(char **arr, char *str, int pos);
void free_word_array(char **words);

#endif
