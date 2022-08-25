#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#define max_len 250

int add_last(void **arr, int *len, data_structure *data)
{

}

int add_at(void **arr, int *len, data_structure *data, int index)
{

}

void find(void *data_block, int len, int index) 
{

}

int delete_at(void **arr, int *len, int index)
{

}

void run_insert(char *buffer) {
	char *token = strtok(NULL, " ");
	printf("%s\n", token);
	

} 

int main() {
	// the vector of bytes u have to work with
	// good luck :)
	void *arr = NULL;
	int len = 0;
	char *buffer = (char*) malloc(max_len);

	fgets(buffer, max_len, stdin);

	while (strcmp(buffer, "exit") != 0) {
		char *command = strtok(buffer, " ");

		if (strcmp(command, "insert") == 0) {
			run_insert(buffer);
		} else if (strcmp(command, "insert_at") == 0) {

		} else if (strcmp(command, "delete_at") == 0) {
			
		} else if (strcmp(command, "find") == 0) {

		} else if (strcmp(command, "print") == 0) {

		}

		fgets(buffer, max_len, stdin);
	}

	return 0;
}
