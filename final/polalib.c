#include "polalib.h"

int parser(char *cmd, int flags)
{
	int cmd_lenght;
    int inf=0, sup=0, plus=0;
	int correct=0
    char mess_log[1024];

    // s'il n'y a pas de nom :
    if(cmd==NULL)
    {
        perror("pas de nom de fichier");
        exit(1);
    }

    // sinon teste le parsing du nom
    cmd_lenght=strlen(cmd);

    if(cmd[0]=='<') 
	{
		inf=1;
	}
    if(cmd[cmd_lenght-1]=='>') 
	{
		sup=1;
	}
    if(cmd[0]=='+') 
	{
		plus=1;
	}
    if((plus)||(sup))
    {
        if(cmd[1]=='<') 
        {
            inf=1;
        }
    }
	if(inf && sup) 
	{
		correct=1;
	}

	// Si le parsing n'est pas correct
    if(!correct||!plus)
    {
        printf("il manque des elements du parsing\n");
		exit(2);
    }

    // Write access
    if( (flags==O_WRONLY||flags==O_RDWR)&&(correct==1||plus==1))
    {
        openlog("polalib", 0, LOG_USER);
        strcpy(mess_log, "Pola erreur : ");
        strcpy(mess_log, cmd);
        strcpy(mess_log, " n'a pas ete ouvert correctement.\n");
        syslog(LOG_ERR, mess_log, cmd);
        closelog();

        perror("Vous n'avez pas les droits\n");
        exit(5);
    }

    else
    {
        if(unpars_name(pathname, inf, sup, plus) != 0)
        {
            printf("Erreur sur clear_name");
            exit(6);
        }

        return 0;
    }

}

int unpars_name(char *name, int inf, int sup, int plus)
{
    int name_lenght=strlen(name);
    int i=0, decalage=1;

    if(inf&&plus)
    {
        name[0]=name[2];
		name[1]=name[3];
        i=2;
		decalage++;
    }
	else
	{
		if(inf||plus)
		{
			name[0]=name[1];
			i=1;
		}
    }

    if(sup)
    {
		name_lenght--;
        name[name_lenght]='\0';
    }

    for (i;i<name_lenght;i++)
    {
        name[i]=name[i+decalage];
    }
	
	if(!sup)
    {
		name[i] = '\0';
	}
    return 0;
}