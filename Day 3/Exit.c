#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Before calling exit()\n");
    exit(0);
    printf("This line will not be executed.\n");

    return 0;
}
