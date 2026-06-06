#include <stdio.h>
#include <string.h>

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
		
		printf("You typed: %s\n", input);
	}
	
	return 0;
}
