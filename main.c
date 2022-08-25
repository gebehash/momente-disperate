#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#define max_len 250
#define sizeof_header 5

int add_last(void **arr, int *len, data_structure *data)
{
	int sizeof_data = data->header->len;
	*arr = realloc(*arr, sizeof_data + sizeof_header);
	memcpy(*arr+len, data, data->header->len + sizeof_header);
	len += data->header->len;
	return 0;
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

data_structure *run_insert(char *buffer) {
	char *type = strtok(NULL, " ");
	char *dedicant = strtok(NULL, " ");
	char *bancnota1 = strtok(NULL, " ");
	char *bancnota2 = strtok(NULL, " ");
	char *dedicat = strtok(NULL, " ");
	int sizeof_data = 0;

	if (*type == '1') {
		sizeof_data = strlen(dedicant) + sizeof(int8_t) + sizeof(int8_t) + strlen(dedicat);
	} else if (*type == '2') {
		sizeof_data = strlen(dedicant) + sizeof(int16_t) + sizeof(int32_t) + strlen(dedicat);
	} else if (*type == '3') {
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

	return data;
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
			add_last(arr, len, run_insert(buffer));
		} else if (strcmp(command, "insert_at") == 0) {

		} else if (strcmp(command, "delete_at") == 0) {
			
		} else if (strcmp(command, "find") == 0) {

		} else if (strcmp(command, "print") == 0) {

		}

		fgets(buffer, max_len, stdin);
	}

	free(arr);

	return 0;
}
