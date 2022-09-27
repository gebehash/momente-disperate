#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "structs.h"
#define MAX_LEN 250
#define SIZEOF_HEADER 5
 
void printArr(void *arr, int len) {
	printf("Arr addr: %p\n", arr);
	for (int k = 0; k < len; k++) {
			char c;
			memcpy(&c, arr + k, 1);
			printf("%d ", c);
		}
	printf("\n");
	//for dev testing
}

int get_dim(int nr, int type) {
	int v[3][4] = {
		{0, 0, 0, 0},
		{0, 1, 2, 4}, //nr = 1
		{0, 1, 4, 4}  //nr = 2
	};
	return v[nr][type];
}

void swap(char *a, char *b) {
	char aux = *(a);
	*(a) = *(b);
	*(b) = aux;
}
 
int get_len_from_header(void *arr, int i) {
	unsigned int len = 0;
	memcpy(&len, arr + i + 1, sizeof(int));
	return len + SIZEOF_HEADER;
}
 
int get_position_by_index(void *arr, int index) {
	if (index == 0)
		return 0;
	unsigned int i = 0;
	while (index != 0) {
		i += get_len_from_header(arr, i);
		index--;
	}
	//printf("return i: %d\n", i);
	return i;
}

void print_by_format_specifier(unsigned char type, int b1, int b2) {
	if (type == 1) {
		printf("%"PRId8"\n", b1);
		printf("%"PRId8"\n\n", b2);
	} else if (type == 2) {
		printf("%"PRId16"\n", b1);
		printf("%"PRId32"\n\n", b2);
	} else if (type == 3) {
		printf("%"PRId32"\n", b1);
		printf("%"PRId32"\n\n", b2);
	}
}

void print_single(void *arr) {
	unsigned char type = 0;
	memcpy(&type, arr, 1);


	printf("\nTipul %d\n", type);
	
	unsigned char aux = -1;
	int i = 5;
	
	while (aux != 0) {
		memcpy(&aux, arr + i, 1);
		printf("%c", (char) aux);
		i++;
	}

	int b1 = 0;
	memcpy(&b1, arr + i, get_dim(1, type));
	i += get_dim(1, type);

	int b2 = 0;
	memcpy(&b2, arr + i, get_dim(1, type));
	i += get_dim(2, type);

	aux = -1;
	
	printf(" pentru ");

	while (aux != 0) {
		memcpy(&aux, arr + i, 1);
		printf("%c", (char) aux);
		i++;
	}

	printf("\n");

	print_by_format_specifier(type, b1, b2);
}

int add_last(void **arr, int *len, data_structure *data)
{
	int sizeof_data = data->header->len;
	int last_index = get_position_by_index(*arr, *len);
	*arr = realloc(*arr, last_index + sizeof_data);
 
	memcpy(*arr + last_index, &data->header->type, 1);
	memcpy(*arr + last_index + 1, &data->header->len, sizeof(int));
	memcpy(*arr + last_index + SIZEOF_HEADER, data->data, sizeof_data);
	*len = *len + 1;
 
	// printArr(*arr, 100);
	free(data->header);
	free(data->data);
	free(data);
	return 0;
}
 
int add_at(void **arr, int *len, data_structure *data, int index)
{

	return 0;
}
 
int parse_idx() {
	char *index_str = strtok(NULL, " ");
	int index_int = atoi(index_str);

	return index_int;
}

void find(void *data_block, int len, int index) 
{
	print_single(data_block + get_position_by_index(data_block, index));
}
 
int delete_at(void **arr, int *len, int index)
{
 
	return 0;
}



void print(void *arr, int len) {

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
 
	sizeof_data = strlen(dedicant) + get_dim(1,type) + get_dim(2, type) + strlen(dedicat);
 
	sizeof_data += 2;
	data_structure *data = (data_structure *) malloc(sizeof(data_structure));
	data->data = malloc(sizeof_data);
 
	head *h = (head *) malloc(sizeof(head));
	h->type = type;
	h->len = sizeof_data;
	data->header = h;
 
	int i = strlen(dedicant) + 1;
	memcpy(data->data, dedicant, i);
	memcpy(data->data + i, &b1, get_dim(1, type));
	i += get_dim(1, type);
	memcpy(data->data + i, &b2, get_dim(2, type));
	i += get_dim(2, type);
	memcpy(data->data + i, dedicat, strlen(dedicat) + 1);
	return data;
}

 
int main() {
	// the vector of bytes u have to work with
	// good luck :)
	void *arr = malloc(0);
	char *buffer = (char*) malloc(MAX_LEN);
 
	int len = 0;
 
	fgets(buffer, MAX_LEN, stdin);
	char *command = strtok(buffer, " ");
 
	while (strstr(command, "exit") == 0) {
		if (strcmp(command, "insert") == 0) {
			add_last(&arr, &len, run_insert());
			// print_single(arr);
		} else if (strcmp(command, "insert_at") == 0) {
			
		} else if (strcmp(command, "delete_at") == 0) {
 
		} else if (strcmp(command, "find") == 0) {
			find(arr, len, parse_idx());
		} else if (strcmp(command, "print") == 0) {
			
		}
		fgets(buffer, MAX_LEN, stdin);
		command = strtok(buffer, " ");
	}
 
	free(arr);
	free(buffer);
	return 0;
}