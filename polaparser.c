#include "polaparser.h"

char **split_cmd_line(char *cmd_line, int size_line, char separator)
{
	char **splited_line;
	int n_args=nb_separators(cmd_line, size_line, separator)+2;
	//la derniere valeur sera mise à NULL pour l'utilisation de execvp
	int i,j,pos=0;
	
	splited_line=malloc(n_args*sizeof(char*));
	
	for(i=0;i<nb_args-1;i++)
	{
		j=0;
		while(j<size_line&&cmd_line[j]!=separator)
		{
			splited_line[i][j]=cmd_line[pos];
			pos++;
			j++;
		}
	}
	
	splited_line[nb_args-1]=NULL;
	
	return splited_line;
}

int nb_separators(char *cmd_line, int size_line, char separator)
{
	int i, count=0;
	for(i=0;i<size_line;i++)
	{
		if(cmd_line[i]==separator)
		{
			count++;
		}
	}
	
	return count;
}

int polapars(char *cmd_line, int size_line)
{
	//char **s_cmd_line = split_cmd_line(cmd_line, size_line, ' ');
	
	return 0;
}

void polai(char *cmd_line, int size_line)
{
	return;
}