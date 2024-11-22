#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[25];  
    int lineNumber = 1;
    file = fopen("Saad.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;  
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d: %s", lineNumber++, line);  
    }
    fclose(file);

    return 0;
}
