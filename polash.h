#ifndef __POLASH_H__
#define __POLASH_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <sys/wait.h>
#include <unistd.h>
#include "polaparser.h"

#define SIZE 1024

void polash();
/*
Fonction d'appel au shell, lancée par le main.
Execture temporairement le programme, en attente du parsing.
*/
char* get_cmd_path(char *cmd_name);
/*
Fonction d'obtention du chemin absolu de la commande "cmd_name"
Renvoie cmd_path.
*/
int is_cmd(char* path);
/*
Fonction de test de l'existence du fichier "path"
*/
void exec_cmd(char* cmd_name, char* args);
/*
Fonction d'execution de la commande "cm_name" avec les arguments contenu dans "args".
Crée un processus fils qui executera la commande a l'aide d'un execvp
*/

#endif
