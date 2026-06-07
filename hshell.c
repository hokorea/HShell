#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cmd_help(void);
void cmd_pwd(void);
void cmd_clear(void);
void cmd_cd(char *arg);
void show_banner(void);
void show_prompt(void);

const char *home = "/data/data/com.termux/files/home";

int main(void)
{
	char input[100];

	cmd_clear();
	show_banner();

	while(1){
		show_prompt();
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

		char temp[100];
		strcpy(temp, input);
		
		char *cmd = strtok(temp, " ");
		char *arg = strtok(NULL, " ");

		if(cmd == NULL){
			continue;
		}
		
		if(strcmp(cmd, "exit") == 0){
			printf("See you later!!\n");
			return 0;
		}

		else if(strcmp(cmd, "help") == 0){
			cmd_help();
			continue;
		}

		else if(strcmp(cmd, "pwd") == 0){
			cmd_pwd();
			continue;
		}

		else if(strcmp(cmd, "clear") == 0){
			cmd_clear();
			continue;
		}

		else if(strcmp(cmd, "cd") == 0){
			cmd_cd(arg);
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
	printf("cd - Change directory\n");
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

void cmd_cd(char *arg){
	if (arg == NULL){
		chdir(home);
	}
	else if(chdir(arg) != 0){
		perror("cd");
	}
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

void show_prompt(void){
	char path[1024];

	if(getcwd(path, sizeof(path)) == NULL){
		printf("HShell:?> ");
		return;
	}

	if(strncmp(home, path, strlen(home)) == 0){
		printf("HShell:~%s > ", path + strlen(home));
	}
	else{
		printf("HShell:%s > ", path);
	}
}
