#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>



void red();
void green();
void reset ();

int main(int numArgu, char *param[]){
	struct dirent *files; // This is a structure type used to return information about directory entrie
   	DIR* directore;
   if (*param[1] != 47) {
   		red();
   		printf("Path start in / slash\n");
   		reset();
   }
   
   if (numArgu != 2) {
   	red();
	printf("Can not found the path of directory\n");
	reset();
   }

   if (numArgu == 2) {
        directore = opendir(param[1]); // Open directore
        if(directore) { // Founded Dir
		    files = readdir(directore); // Read File in Dir
		    while (files) {
				printf("I-Node: ");
				green();
				printf("%ld", files->d_ino);
				reset();
				printf("  file-Name: ");
				green();
				printf("%s\n", files->d_name);
				reset();
			 	files = readdir(directore);
		 		}
		    closedir(directore);
		    }
    }
    return 0;
}


void red() { 
	printf("\033[0;31m");
}
void green(){
  printf("\033[0;32m");
}
void reset (){
  printf("\033[0m");
}