#include <stdio.h>
#include <string.h>

#include <dirent.h> 
#include <stdio.h>  /* defines FILENAME_MAX */
//#define WINDOWS  /* uncomment this line to use it for windows.*/
#include <unistd.h>
#define GetCurrentDir getcwd


void start_comp(int silent, int verbose, int jobs, char *compiler, char *fn)
{

    char path[FILENAME_MAX];
    GetCurrentDir( path, FILENAME_MAX );

    //printf("%s\n", path);

    sprintf(path, "%s/%s.interstellar", path, fn);

    DIR *d = opendir(path); // open the path
    if (d == NULL)
        return;         // if was not able, return
    struct dirent *dir; // for the directory entries

    char full_path[FILENAME_MAX];

    char compiler_command[FILENAME_MAX];
    sprintf(compiler_command, "%s ", compiler);

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            //Condition to check regular file.
            if(dir->d_type==DT_REG){
                full_path[0]='\0';
                strcat(full_path,path);
                strcat(full_path,"/");
                strcat(full_path,dir->d_name);
                strcat(full_path," ");
                //printf("%s\n",full_path);
            
                strcat(compiler_command, full_path);
                
            }
        }
        closedir(d);
    }

    strcat(compiler_command, "-o ./cbuild  -linterstellar ");

    system(compiler_command);

    system("./cbuild");

    //printf("%s\n", compiler_command);

    //ccmain();
}