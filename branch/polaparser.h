#ifndef __POLAPARSER_H__
#define __POLAPARSER_H__

#include <stdio.h>
#include <stdlib.h>

char *cmd_name(char *cmd_line, int size_line, char separator);
/*
Renvoie le nom de la commande "cmd_line" de taille "size_line".
*/
int first_sep(char *cmd_line, int size_line, char separator);
/*
Renvoie la position du premier séparateur "separator" dans la chaine de caractère "cmd_line" de longueur "size_line"
*/
int polapars(char *cmd_line, int size_line);
/*
Fonction de parsing 
prend en argument la ligne de commande entrée par l'utilisateur et sa taille réelle.
todo : vérification de la présence des chevrons, du +
*/
void polai(char *cmd_line, int size_line);
/*
Fonction d'appel interactif pola-i
Non commencée
*/
char **split_cmd_line(char *cmd_line, int size_line, char separator);
/*
 * Sépare la chaine de caractère "cmd_line" de taille "size_line" en n
 * sous-chaines délimitées par "separator".
*/
int nb_separators(char *cmd_line, int size_line, char separator);
/*
 * Compte le nombre d'occurrences du caractère "separator" dans la chaine de
 * caractère "cmd_line" de longueur "size_line"
*/
#endif
