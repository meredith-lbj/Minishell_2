/*
** EPITECH PROJECT, 2021
** print_helper
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"

my_env_t *print_helper(my_env_t *my_env)
{
    my_putstr("Minishell commands:\n");
    my_putstr("env : Print the environement\n\n");
    my_putstr("setenv [const char *NAME] [const char *value] : ");
    my_putstr("Add the variable NAME to the ennment ");
    my_putstr("with the value, if NAME does not already exist. ");
    my_putstr("If NAME does exist in the environment,  ");
    my_putstr("then its value is changed to value\n\n");
    my_putstr("unsetenv [const char *NAME] : ");
    my_putstr("Delete the variable name from the environment. ");
    my_putstr("If NAME does not exist in the environment, ");
    my_putstr("the environment is unchanged\n\n");
    my_putstr("cd : Change the directory\n");
    my_putstr("Availaible commands:\n");
    my_putstr("cd => Navigate to home directory\n");
    my_putstr("cd - => Navigate to the previous directory\n");
    my_putstr("cd .. => Navigate to the parent directory\n");
    my_putstr("cd [directory] => Navigate to the directory\n\n");
    my_putstr("exit : Leave the minishell\n");
    return (my_env);
}
