1. perror() - Print Error Message
The perror() function is used to print a description of the error that occurred during the execution of a program. It uses the errno variable, which stores the error code, and prints a custom message followed by the description of the error related to the last system call.

Syntax:
void perror(const char *s);

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main() {
    int fd = open("non_existent_file.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
    }
    return 0;
}

// --------------------------------------------------------------------------------

2. strerror() - Get String Representation of Error
The strerror() function returns a pointer to the textual description of the error code passed to it.

Syntax:
char *strerror(int errnum);

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    int errnum = EACCES;
    printf("Error: %s\n", strerror(errnum));
    return 0;
}

// --------------------------------------------------------------------------------

3. errno - Error Code Variable
errno is a global variable that stores the last error code set by a system call or library function.

#include <stdio.h>
#include <errno.h>

int main() {
    FILE *file = fopen("non_existent_file.txt", "r");

    if (file == NULL) {
        printf("Error opening file: %d\n", errno);
    }
    return 0;
}

// --------------------------------------------------------------------------------

4. clearerr() - Clear Error Indicator
clearerr() clears the error and EOF indicators for a file stream.

Syntax:
void clearerr(FILE *stream);

#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fgetc(file);
    clearerr(file);

    if (ferror(file)) {
        printf("An error still exists\n");
    } else {
        printf("Error cleared successfully\n");
    }

    fclose(file);
    return 0;
}

// --------------------------------------------------------------------------------

5. feof() - End of File Indicator
feof() checks whether the end-of-file (EOF) indicator is set for a file stream.

Syntax:
int feof(FILE *stream);

#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (!feof(file)) {
        char c = fgetc(file);
        if (c != EOF) {
            putchar(c);
        }
    }

    fclose(file);
    return 0;
}

// --------------------------------------------------------------------------------

6. ferror() - Check for Errors on a Stream
ferror() checks whether an error has occurred on a file stream.

Syntax:
int ferror(FILE *stream);

#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fgetc(file);
    if (ferror(file)) {
        printf("Error reading file\n");
    } else {
        printf("No error reading file\n");
    }

    fclose(file);
    return 0;
}

// --------------------------------------------------------------------------------

7. exit() - Terminate Program
The exit() function terminates a program and can return a status code to the operating system.

Syntax:
void exit(int status);

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fclose(file);
    exit(EXIT_SUCCESS);
}

// --------------------------------------------------------------------------------

8. abort() - Abnormal Termination
The abort() function forces the program to terminate immediately and generates a core dump if possible.

Syntax:
void abort(void);

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Something went wrong, aborting...\n");
    abort();
}

// --------------------------------------------------------------------------------

9. setjmp() and longjmp() - Non-Local Jumps
These functions allow you to jump back to a specific point in the code.

Syntax:
int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);

#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;

void error_occurred() {
    printf("An error occurred, jumping back...\n");
    longjmp(buffer, 1);
}

int main() {
    if (setjmp(buffer) == 0) {
        printf("Calling a function that will fail...\n");
        error_occurred();
    } else {
        printf("Recovered from error\n");
    }
    return 0;
}

// --------------------------------------------------------------------------------

10. atexit() - Register Exit Handlers
The atexit() function registers a function to be called when the program terminates normally.

Syntax:
int atexit(void (*func)(void));

#include <stdio.h>
#include <stdlib.h>

void cleanup(void) {
    printf("Cleanup done!\n");
}

int main() {
    atexit(cleanup);
    printf("Exiting the program...\n");
    return 0;
}
// --------------------------------------------------------------------------------