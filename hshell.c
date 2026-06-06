#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cmd_help(void);
void cmd_pwd(void);
void cmd_clear(void);
void show_banner(void);

int main(void)
{
	char input[100];

	cmd_clear();
	show_banner();

	while(1){
		printf("HShell> ");
		if(fgets(input, sizeof(input), stdin) == NULL){
			printf("\nSee you later!!\n");
			break;
		}

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

		else if(strcmp(input, "clear") == 0){
			cmd_clear();
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
	printf("clear - Clear screen\n");
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

void cmd_clear(void){
	system("clear");
}

void show_banner(void)
{
	printf("=================================\n");
	printf("          HShell v1.0\n");
	printf("          Made by Hoke\n");
	printf("=================================\n");
	printf("\n");
	printf("Type 'help' for available commands.\n");
	printf("\n");
}
