#include <sys/stat.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct stat sfile;
	stat("example.txt", &sfile);
	printf("File Size = %ld\n", sfile.st_size);
	printf ("User ID = %d\n", sfile.st_uid);
	printf ("Last Access = %ld\n", sfile.st_atime);
}
