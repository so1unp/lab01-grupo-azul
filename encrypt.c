#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("%d argumentos\n", (argc-1));
    
    printf("Debug argv\n");
    for(int i = 0; i < argc; i++) {
        printf("%s\n", argv[i+1]);
    }

    // Agregar código aquí.
    printf("%s argv\n", argv[2]);

    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}
