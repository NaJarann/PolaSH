#include "polash.h"

int main()
{
	char *buff = malloc(SIZE*sizeof(char));
	char **cmd;
	int real_size=0;
	pid_t pid;
	fflush(stdout);

	while ((real_size=read(0,buff, SIZE))>0 && strcmp(buff,"quit")!=0)
	{
		cmd = polapars(buff,real_size);
		
		if(cmd!=NULL)
		{
			pid=fork();
			if(pid < 0)
			{
				perror("Erreur sur le fork -> ");
				exit(2);
			}

			if(pid == 0)
			{
				if(execvp(cmd[0], cmd) == -1)
				{
					perror("execvp");
					exit(3);
				}
			}
			else
			{
				wait(NULL);
			}
		}
		else
		{
			printf("Erreur de parsing\n");
		}
	}

	return 0;
}