#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Agregar código aquí.
    srand(time(NULL));

    // Posible cambio
    char input[1024];
    input[0] = '\0';

    size_t totalChar = 0;
    if(argc > 1) {
        for(int i = 1; i < argc; i++) {
            for (int j = 0; argv[i][j] != '\0'; j++) {
                input[totalChar++] = argv[i][j];
            }
        }
    } else {
        int c;
        while((c = getchar()) != EOF) {
            input[totalChar++] = (char)c;
        }
    }

    char output[totalChar * 8 + 1];
    output[0] = '\0';

    int index = 0;
    for(int i = 0; i < (int)totalChar; i++) {
        for(int j = 0; j < 7; j++) {
            output[index++] = (char)(rand() % 256);
        }
        output[index++] = input[i];
    }

    fwrite(output, 1, totalChar*8, stdout);

    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}
