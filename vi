#include "LK_prompt.h"

void execute_command(char *args[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        wait(NULL);
    }
}

int main(void) {
    char input[256];  // Adjust the input buffer size as needed
    char *args[MAX_ARGS];
    char *token;
    int i;

    while (1) {
        printf("$ ");
        fgets(input, sizeof(input), stdin);

        // Tokenize the input
        i = 0;
        token = strtok(input, " \n");
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i] = strdup(token); // Allocate memory for each argument
            token = strtok(NULL, " \n");
            i++;
        }
        args[i] = NULL; // Set the last argument to NULL for execvp

        if (args[0] != NULL) {
            // Execute the command
            execute_command(args);
        }

        // Free allocated memory for arguments
        for (int j = 0; j < i; j++) {
            free(args[j]);
        }
    }

    return 0;
}

