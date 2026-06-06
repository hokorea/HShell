#include <stdio.h>
#include <string.h>
#include <unistd.h>

void cmd_help(void);
void cmd_pwd(void);

int main(void)
{
	char input[100];
	printf("Welcome to HShell!\n");

	while(1){
		printf("HShell> ");
		fgets(input, sizeof(input), stdin);

		for(int i = 0; input[i] != '\0'; i++){
			if(input[i] == '\n'){
				input[i] = '\0';
				break;
			}
		}
		if(strcmp(input, "exit") == 0){
			printf("See you later!!\n");
			return 0;
		}

		else if(strcmp(input, "help") == 0){
			cmd_help();
			continue;
		}

		else if(strcmp(input, "pwd") == 0){
			cmd_pwd();
			continue;
		}
		
		printf("You typed: %s\n", input);
	}
	
	return 0;
}

void cmd_help(void){
	printf("Available Commands:\n");
	printf("\nhelp - Show help\n");
	printf("pwd - Show current directory\n");
	printf("exit - Exit HShell\n");
}

void cmd_pwd(void){
	char path[1024];
	
	if(getcwd(path, sizeof(path)) == NULL){
		perror("getcwd");
	}
	else{
		printf("%s\n", path);
	}
}
