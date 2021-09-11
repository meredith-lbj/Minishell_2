/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** No file there, just an epitech header example
*/

#ifndef MYSH_H_
#define MYSH_H_
#include "my.h"
typedef struct my_env_s
{
    char *name;
    char *value;
    struct my_env_s *next;
}my_env_t;
typedef struct parse_s
{
    char **com;
    char *fixed_com;
    char *ope;
    int empty;
    struct parse_s *next;
}parse_t;
typedef struct redirect_s
{
    char *ope;
    char *filepath;
    int fdfile;
    int stdout;
    int stdin;
}redirect_t;
int reset_fd(redirect_t *redirect);
char *find_redirections(parse_t *parse);
int check_double_operator(char *commands, int i);
redirect_t *redirections(parse_t *parse, redirect_t *redirect);
redirect_t *init_redirect(parse_t *parse, redirect_t *redirect, char *ope);
void command_not_found(char *command);
int move(char *command, int i);
int space_count(char const *command);
int count_chr(char *chaine, char chr);
int find_my_chr(char const *str, char c);
int parse_commands(char *commands, parse_t **parse);
parse_t *create_parse(parse_t *parse, char *commands, char *fixed, int pos);
int find_operator(char *commands);
char *fix_operator(char *command);
int find_letter(char *commands, int i);
int semicolon_error(char *command, char **fixed, int i, int *j);
int double_quotes_error(char *command, char **fixed, int i, int *j);
int quotes_error(char *command, char **fixed, int i, int *j);
int pipe_error(char *command, char **fixed, int i, int *j);
int check_ope(char *commands, int pos);
int calcul_operator(char *commands);
int count_pipe(parse_t *parse);
parse_t *my_pipe(parse_t *parse,  my_env_t *my_env);
parse_t *check_exit(my_env_t *my_env, parse_t *parse);
char *fix_space(char *command);
char **swap_way(char **path, int pos, char *command);
char **get_binary(char **path, char *command);
char **get_commands(char const *str);
char *get_name(char const *chaine);
char *get_value(char const *chaine);
char *get_way(my_env_t *my_env, char *find);
char **get_2d_env(my_env_t *my_env);
int check_var(my_env_t *my_env, char *name);
int check_access(my_env_t *my_env, char *find);
int check_start(char const *str1, char *str2);
char **get_path(my_env_t *my_env);
my_env_t *print_helper(my_env_t *my_env);
my_env_t *create_env(my_env_t *my_env, char **env);
my_env_t *builtin_list(my_env_t *my_env, char *command);
my_env_t *exec_cd(my_env_t *my_env, char **exe, int space);
my_env_t *exec_setenv(my_env_t *my_env, char **exe, int space);
my_env_t *exec_unsetenv(my_env_t *my_env, char **exe, int space);
my_env_t *exec_command(my_env_t *my_env, char **exe, char *fixed);
my_env_t *exec_operator(my_env_t *my_env, parse_t *parse);
parse_t *exec_semicolon(my_env_t *my_env, parse_t *parse);
parse_t *exec_pipe(my_env_t *my_env, parse_t *parse);
my_env_t *exec_exit(my_env_t *my_env, char *command, char *fixed);
my_env_t *cd_builtin(my_env_t *my_env, char *commands);
my_env_t *prev_directory(my_env_t *my_env, char *commands);
my_env_t *check_dir_perms(my_env_t *my_env, char *commands);
my_env_t *change_dir(my_env_t *my_env, char *commands);
my_env_t *change_dir2(my_env_t *my_env, char *commands);
my_env_t *setenv_builtin(my_env_t *my_env, char *name, const char *value);
int exit_builtin(char *fixed, my_env_t *my_env);
my_env_t *unsetenv_builtin(my_env_t *my_env, char *name);
int execut(my_env_t *my_env, char **exe);
my_env_t *print_env(my_env_t *my_env);
parse_t *delete_node(parse_t *parse);
void not_directory(char *commands);
void perm_denied(char *commands);
void free_list(my_env_t *my_env);
void free_parse(parse_t *parse);
#endif
