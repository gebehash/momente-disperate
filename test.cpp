#include <iostream>
using namespace std;
int main() {
    char *buffer = (char*) malloc(100);
    fgets(buffer, 100, stdin);

    

    return 0;
}