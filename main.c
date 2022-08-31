#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#define max_len 250
#define sizeof_header 5

int add_last(void **arr, int *len, data_structure *data)
{
	printf("%p\n", *arr);
	int sizeof_data = data->header->len;
	*arr = realloc(*arr, sizeof(*arr) + sizeof_data + sizeof_header);
	memcpy(*arr, data, sizeof_data + sizeof_header);
	*len = *len + 1;
	// for (int i = 0; i <= sizeof(*arr); i++) {
	// 	printf("%c ", **arr + i);
	// }
	return 0;
}

int add_at(void **arr, int *len, data_structure *data, int index)
{

	return 0;
}

void find(void *data_block, int len, int index) 
{

}

int delete_at(void **arr, int *len, int index)
{

	return 0;
}

data_structure *run_insert() {
	printf("inceput");
	char *typestr = strtok(NULL, " ");
	char *dedicant = strtok(NULL, " ");
	char *bancnota1 = strtok(NULL, " ");
	char *bancnota2 = strtok(NULL, " ");
	char *dedicat = strtok(NULL, " ");
	int sizeof_data = 0;

	int type = atoi(typestr);

	if (type == 1) {
		sizeof_data = strlen(dedicant) + sizeof(int8_t) + sizeof(int8_t) + strlen(dedicat);
	} else if (type == 2) {
		sizeof_data = strlen(dedicant) + sizeof(int16_t) + sizeof(int32_t) + strlen(dedicat);
	} else if (type == 3) {
		sizeof_data = strlen(dedicant) + sizeof(int32_t) + sizeof(int32_t) + strlen(dedicat);
	}

	data_structure *data = (data_structure *) malloc(sizeof_header);
	head *h = (head *) malloc(sizeof_header);
	h->type = type;
	h->len = sizeof_header + sizeof_data;

	data->header = h;

	memcpy(data->data, dedicant, strlen(dedicant));
	memcpy(data->data + strlen(dedicant), bancnota1 -'0', 1);
	memcpy(data->data + strlen(dedicant) + 1, bancnota2 -'0', 1);
	memcpy(data->data + strlen(dedicant) + 2, dedicat, strlen(dedicat));
	printf("final");
	return data;
} 

int main() {
	// the vector of bytes u have to work with
	// good luck :)
	void *arr = malloc(0);
	printf("%p\n", arr);
	int len = 0;
	char *buffer = (char*) malloc(max_len);
	printf("%p\n", buffer);
	printf("aici2\n");
	fgets(buffer, max_len, stdin);
	// fscanf(stdin, "%s", buffer);
	printf("%s", buffer);
	while (strcmp(buffer, "exit") != 0) {
		char *command = strtok(buffer, " ");
		printf("%s\n", command);
		if (strcmp(command, "insert") == 0) {
			add_last(arr, &len, run_insert());
		} else if (strcmp(command, "insert_at") == 0) {

		} else if (strcmp(command, "delete_at") == 0) {
			
		} else if (strcmp(command, "find") == 0) {

		} else if (strcmp(command, "print") == 0) {

		}

		// fgets(buffer, max_len, stdin);
		fscanf(stdin, "%s", buffer);
	}

	free(arr);

	return 0;
}
