#ifndef __POLAPARSER_H__
#define __POLAPARSER_H__

#include <stdio.h>
#include <stdlib.h>

char **split_cmd_line(char *cmd_line, int size_line, char separator);
/*
S�pare la chaine de caract�re "cmd_line" de taille "size_line" en n sous-chaines d�limit�es par "separator".
*/
int nb_separators(char *cmd_line, int size_line, char separator);
/*
Compte le nombre d'occurrences du caract�re "separator" dans la chaine de caract�re "cmd_line" de longueur "size_line"
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
