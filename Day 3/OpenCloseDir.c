#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

struct dirent *dptr;

int main (int argc, char *argv[]) {
    char buff[100];
    DIR *dirp;
   
    printf ("Enter the directory name: ");
    scanf ("%s", buff);
   
    if ((dirp=opendir(buff)) == NULL) {
        printf ("The directory doesn't exist\n");
        exit (1);
    }
    while (dirp = readdir(dirp)) {
        printf ("%s", dptr->d_name);
    }
   
    closedir (dirp);
}
