#include "polash.h"

void polash()
{
	char *buff = malloc(SIZE*sizeof(char));
	int real_size=0;
	
	while ((real_size=read(0,buff, SIZE))>0 && strcmp(buff,"quit")!=0)
	{
		if(strstr(buff, "pola-i")!=NULL)
		{
			//on décale le buffer de 6 caractère afin de ne garder dans buff que la ligne de commande
			buff=buff+6;
			polai(buff, real_size-6);
		}
		else
		{
			
			char *cmd_name = split_cmd_line(buff, real_size, ' ');
			char *cmd_path = get_cmd_path(cmd_name);
			if(cmd_path != NULL)
			{
				exec_cmd(cmd_path,buff);
			}
			else
			{
				printf("la commande %s n'existe pas\n",cmd_name);
			}
			polapars(buff, real_size);
		}
	}
	
	return ;
}

char* get_cmd_path(char *cmd_name)
{
	int i, cmd_size = strlen(cmd_name)+1;
	int nb_paths, found=0;
	
	char *path = getenv("PATH"), *cmd_path;
	nb_paths = nb_separators(path, strlen(path),':')+1;

	char **all_paths = malloc(nb_paths*sizeof(char*));
    all_paths = split_cmd_line(path,strlen(path),':');
	
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

int is_cmd(char* path)
{
	struct stat s;

	if(stat(path, &s) != -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void exec_cmd(char* cmd_path, char* args)
{
	pid_t pid = fork();

	if(pid == -1)
	{
		perror("fork");
		exit(-1);
	}
	else 
	{
		if(pid == 0)
		{
			execvp(cmd_path, args);
		}
		else
		{
			wait(NULL);
		}
	}
}
