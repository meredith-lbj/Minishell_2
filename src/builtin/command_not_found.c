/*
** EPITECH PROJECT, 2021
** command_not_found
** File description:
** No file there, just an epitech header example
*/

#include "mysh.h"
#include <unistd.h>

void command_not_found(char *command)
{
    write(2, command, my_strlen(command));
    write(2, ": Command not found.\n", 21);
}
