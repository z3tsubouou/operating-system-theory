#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>


void create(char argv[]){

	int counter;
	FILE *fptr;

	fptr = freopen(argv, "w", stdout);
	fclose(fptr);

}

void input(char argv[], char argv1[]){

	char c;
	FILE *fptr;

	fptr = fopen(argv1,"w");

	int size = (unsigned)strlen(argv);
	
	fputs(argv, fptr);

	fclose(fptr);
}

void delete(char argv[]){

	remove(argv);

}

void re_name(char argv[], char argv1[]){

	rename(argv, argv1);

}

void dir(){
	
	DIR *folder;
	folder = opendir(".");
	struct dirent *entry;

	if(folder == NULL){
	
		perror("Error");
	}

	while((entry = readdir(folder))){
	
		printf("%s\n", entry->d_name);
	
	}
	
	closedir(folder);

}

int main(){

	char hello[100], hello1[100];
	int t;
	while(1){
	
		printf("1. Shine text file uusgeh\n2. Text filed utga oruulah\n3.File ustgah\n4. Fileiin neriig solih\n5. dir\n6. Garah\n");
		scanf("%d", &t);
	
		switch(t){
		
			case(1):
				printf("Neeh text fileiin neriig oruulna uu\n");
				scanf("%s", hello);
				create(hello);
				break;
			case(2):
				printf("Utga oruulah text fileiin neriig oruulna uu\n");
				// scanf("%[^\n]%*c", hello);
				scanf("%s", hello);
				printf("Oruulah utgaa oruulna uu\n");
				scanf("%s", hello1);
				// scanf("%[^\n]%*c", hello1);
				input(hello1,hello);
				break;
			case(3):
				printf("Ustgah text fileiin neriig oruulna uu\n");
				// scanf("%[^\n]%*c", hello);
				scanf("%s", hello);
				delete(hello);
				break;
			case(4):
				printf("Shinechleh text fileiin neriig oruulna uu\n");
				// scanf("%[^\n]%*c", hello);
				scanf("%s", hello);
				printf("Shine neriig oruulna uu\n");
				// scanf("%[^\n]%*c", hello1);
				scanf("%s", hello1);
				re_name(hello, hello1);
				break;
			case(5):
				dir();
				break;
			default:
				exit(0);
		
		}
	
	}	

}
