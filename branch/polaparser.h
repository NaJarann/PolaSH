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
Renvoie la position du premier s�parateur "separator" dans la chaine de caract�re "cmd_line" de longueur "size_line"
*/
int polapars(char *cmd_line, int size_line);
/*
Fonction de parsing 
prend en argument la ligne de commande entr�e par l'utilisateur et sa taille r�elle.
todo : v�rification de la pr�sence des chevrons, du +
*/
void polai(char *cmd_line, int size_line);
/*
Fonction d'appel interactif pola-i
Non commenc�e
*/

#endif
