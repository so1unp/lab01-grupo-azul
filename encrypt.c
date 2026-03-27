#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Agregar código aquí.
    if(argc <= 1) {
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    size_t totalChar = 0;
    for(int i = 1; i < argc; i++) {
        totalChar += strlen(argv[i]);
    }

    char input[totalChar + 1];
    char output[totalChar*8 + 1];

    input[0] = '\0';
    output[0] = '\0';

    for(int i = 1; i < argc; i++) {
        strcat(input, argv[i]);
    }

    int index = 0;
    for(int i = 0; i < (int)strlen(input); i++) {
        for(int j = 0; j < 7; j++) {
            output[index++] = (char)(rand() % 256);
        }
        output[index++] = input[i];
    }

    printf("OUTPUT:\n%s", output);
    
    // Guardado en file output.txt
    FILE *txt = fopen("output.txt", "w+"); 

    if(txt == NULL) {
        perror("Error opening file");
        return 1;
    }

    fwrite(output, 1, strlen(output), txt);

    fclose(txt);

    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}
