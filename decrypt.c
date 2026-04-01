#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BLOCK_SIZE 8

int main()
{
    unsigned char buffer[BLOCK_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(STDIN_FILENO, buffer, BLOCK_SIZE)) > 0) {
        // Validar que el bloque tenga el tamaño esperado
        if (bytes_read != BLOCK_SIZE) {
            fprintf(stderr, "Error: bloque incompleto recibido\n");
            exit(EXIT_FAILURE);
        }

        // El byte real es el último (posición 7)
        if (write(STDOUT_FILENO, &buffer[7], 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}