#include "polash.h"

char **polapars(char *buff, int size_line)
{
	int nb_sep=nb_separators(buff,size_line,' '), i, nb_args=nb_sep+3;
	char **s_buff = split_string(buff,size_line,' ');
	char **cmd = malloc(nb_args*sizeof(char*));
	//cmd[0] contient le path de la commande, afin que l'execvp fonctionne correctement
	cmd[0] = get_cmd_path(buff);
	//de la seconde a l'avant-derniere cases, cmd[i] contient l'un des arguments entres par l'utilisateur
	for(i=1;i<nb_arg-1;i++)
	{
		for(j=0;j<strlen(s_buff[i-1]);j++)
		{
			cmd[i][j]=s_buff[i-1][j];
		}
	}
	//la derniere case du tableau est fixee a NULL pour l'execvp
	cmd[nb_args-1]=NULL;
	
	return cmd;
}

char* get_cmd_path(char *cmd_line, size_line)
{
	char *cmd_name;
	get_cmd_name(cmd_line,size_line,cmd_name);
	int i, cmd_size = strlen(cmd_name)+1;
	int nb_paths, found=0;

	char *path = getenv("PATH"), *cmd_path;
	nb_paths = nb_separators(path, strlen(path),':')+1;

	char **all_paths = malloc(nb_paths*sizeof(char*));
    all_paths = split_string(path,strlen(path),':');

    for(i = 0; i<nb_paths&&found==0; i++)
	{
		int path_lenght = strlen(all_paths[i])+cmd_size;
		cmd_path = malloc(path_lenght*sizeof(char));

		sprintf(cmd_path, "%s/%s", all_paths[i], cmd_name);

		if(is_cmd(cmd_path) == 1)
		{
			found=1;
		}
	}

	if (found==1)
	{
		return cmd_path;
	}
	else
	{
		return NULL;
	}
}
void get_cmd_name(char *cmd_line, int size_line, char *cmd_name)
{
	int i, nb_char = first_sep(cmd_line,size_line,' ');

    for(i=0;i<nb_char;i++)
    {
        cmd_name[i]=cmd_line[i];
    }
	
	return ;
}
int nb_separators(char *cmd, int size, char separator)
{
	int i,
    count=0;
    for(i=0;i<size;i++)
    {
        if(cmd_line[i]==separator)
        {
            count++;
        }
    }

    return count;
}
char **split_string(char *cmd, int size, char separator)
{
	int i, j=0, nb_args=nb_separators(cmd,size,separator);
	char **splited_string = malloc((nb_args+1)*sizeof(char*));
	
	for(i=0;i<nb_args;i++)
	{
		for(j;j<size&&cmd[j]!=separator;j++)
		{
			splited_string[i]=cmd[j]
		}
		j++;
	}
}
int first_sep(cmd_line,size_line,separator)
{
	int i, count=-1;
    for(i=0;i<size_line&&count==-1;i++)
    {
        if(cmd_line[i]==separator)
        {
            count=i;
        }
    }

    if(count==-1)
    {
        count=size_line;
    }
    return count;
}