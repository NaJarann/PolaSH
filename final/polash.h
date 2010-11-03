#ifndef __POLASH_H__
#define __POLASH_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 1024

char **polapars(char *buff, int size_line);
/*
 *Renvoie la commande parsee de façon a etre utilisable pour execvp.
 */

char* get_cmd_path(char *cmd_line, int size_line);
/*
 *  Fonction d'obtention du chemin absolu de la commande "cmd_name"
 *  Renvoie cmd_path.
*/

void get_cmd_name(char *cmd_line, int size_line, char *cmd_name);
/*
 *Donne le nom de la commande "cmd_line" de taille "size_line" dans l'argument "cmd_name"
*/

int nb_separators(char *cmd, int size, char separator);
/*
 * Compte le nombre d'occurrences du caractere "separator" dans la chaine de
 * caractere "cmd_line" de longueur "size_line"
*/

char **split_string(char *cmd, int size, char separator);
/*
 * Separe la chaine de caractere "cmd_line" de taille "size_line" en n
 * sous-chaines delimitees par "separator".
*/

int first_sep(char *cmd_line, int size_line,char separator);
/*
 *  Renvoie la position du premier separateur "separator" dans la chaine de caractere "cmd_line" de longueur "size_line"
*/

int is_cmd(char* path);
/*
 * Fonction de test de l'existence du fichier "path"
*/

#endif
