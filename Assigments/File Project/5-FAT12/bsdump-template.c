#include <stdio.h> 
#include<string.h>
#include<errno.h>
#include<dirent.h>
int main(int argc, char *argv[]) {
// argv[1] include path of Directore
// argv[0] include file.exe (feras.out)
	
	DIR *directore;
	printf("%p", &directore);
	printf("in feras %s\n", argv[1]); 
	struct dirent *file;
	if (argc == 2){
		directore = opendir(argv[1]);
		if(directore){
			while(file = readdir(directore))
				printf("%s\n", file->d_name);
			closedir(directore);
		}
	}

	return 0;
}