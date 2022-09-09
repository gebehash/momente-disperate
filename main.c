#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#define max_len 250
#define sizeof_header 5

void* get_last_pos(void *arr, int len) {
	printf("get_last_pos: arr:%p\n", arr);
	while(len > 0) {
		int p = 0;
		
		memcpy(&p, arr+4, 1);
		memcpy(&p + 1, arr+3, 1);
		memcpy(&p + 2, arr+2, 1);
		memcpy(&p + 3, arr+1, 1);

		// for (int i = 0; i < 4; i++)
		// 	memcpy(&p + i, arr+4-i, 1);

		printf("p: %d\n", p);
		arr += p;
		printf("get_last_pos: arr:%p\n", arr);
		len--;
	}
	printf("get_last_pos: return arr:%p\n", arr);
	return arr;
}

int add_last(void **arr, int *len, data_structure *data)
{
	// printf("%p\n", arr);
	// printf("%p\n", *arr);
	int sizeof_data = data->header->len - sizeof_header;
	*arr = realloc(*arr, sizeof(*arr) + sizeof_data + sizeof_header);
	// printf("%p\n", *arr);
	// char *s = (char *)malloc(200);
	// memcpy(s, data->data, sizeof_data);
	// for (int i = 0; i < sizeof_data; i++)
	// 	printf("%d ", s[i]);
	
	// printf("\n");
	// memcpy(s, data->header, sizeof_header + 5);
	// for (int i = 0; i < sizeof_header + 5; i++)
	// 	printf("%d ", s[i]);
	printf("%p\n", *arr);
	printf("%p\n",get_last_pos(*arr, *len));
	memcpy(*arr, data->header, sizeof_header);
	memcpy(*arr + sizeof_header, data->data, sizeof_data);
	*len = *len + 1;
	//printf("date: %s\n", *arr);
	// for (int i = 0; i <= sizeof(*arr); i++) {
	// 	printf("%d ", (*arr + i));
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
	char *typestr = strtok(NULL, " ");
	char *dedicant = strtok(NULL, " ");
	char *bancnota1 = strtok(NULL, " ");
	char *bancnota2 = strtok(NULL, " ");
	char *dedicat = strtok(NULL, " \n");
	int sizeof_data = 0;
	int b1 = atoi(bancnota1);
	int b2 = atoi(bancnota2);

	int type = atoi(typestr);

	if (type == 1) {
		sizeof_data = strlen(dedicant) + sizeof(int8_t) + sizeof(int8_t) + strlen(dedicat);
	} else if (type == 2) {
		sizeof_data = strlen(dedicant) + sizeof(int16_t) + sizeof(int32_t) + strlen(dedicat);
	} else if (type == 3) {
		sizeof_data = strlen(dedicant) + sizeof(int32_t) + sizeof(int32_t) + strlen(dedicat);
	}

	sizeof_data += 2;
	// printf("sizeof_data: %d\n", sizeof_data);
	data_structure *data = (data_structure *) malloc(sizeof(data_structure));
	data->data = malloc(sizeof_data);
	head *h = (head *) malloc(sizeof_header);
	h->type = type;
	h->len = sizeof_header + sizeof_data;
	data->header = h;

	memcpy(data->data, dedicant, strlen(dedicant) + 1);
	memcpy(data->data + strlen(dedicant) + 1, &b1, 4);
	memcpy(data->data + strlen(dedicant) + 5, &b2, 4);
	memcpy(data->data + strlen(dedicant) + 9, dedicat, strlen(dedicat) + 1);
	return data;
} 

int main() {
	// the vector of bytes u have to work with
	// good luck :)
	void *arr = malloc(0);
	// printf("%p\n", &arr);
	// printf("%p\n", arr);
	int len = 0;
	char *buffer = (char*) malloc(max_len);
	fgets(buffer, max_len, stdin);
	while (strcmp(buffer, "exit") != 0) {
		char *command = strtok(buffer, " ");
		//printf("comanda: %s\n", command);
		if (strcmp(command, "insert") == 0) {
			add_last(&arr, &len, run_insert());
			char *s = (char *)malloc(200);
			memcpy(s, arr, 70);
			for (int i = 0; i < 70; i++)
				printf("%d ", s[i]);
			printf("\n%d\n", len);
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
