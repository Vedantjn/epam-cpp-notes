1. strlen() - Get String Length
Returns the length of a C-style string (excluding the null terminator).

Syntax:
size_t strlen(const char *str);

#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, World!";
    printf("Length of the string: %zu\n", strlen(str));
    return 0;
}

// ---------------------------------------------------------------------------------------------

2. strcpy() - Copy String
Copies a C-string to another location, including the null terminator.

Syntax:
char *strcpy(char *dest, const char *src);

#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello";
    char dest[10];
    strcpy(dest, src);
    printf("Copied string: %s\n", dest);
    return 0;
}


// ---------------------------------------------------------------------------------------------

3. strncpy() - Copy String with Limit
Copies up to n characters of a C-string, padding with null bytes if necessary.

Syntax:
char *strncpy(char *dest, const char *src, size_t n);

#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello";
    char dest[10];
    strncpy(dest, src, 3);
    dest[3] = '\0';
    printf("Copied string: %s\n", dest);
    return 0;
}

// ---------------------------------------------------------------------------------------------

4. strcmp() - Compare Strings
Compares two strings lexicographically (returns 0 if they are equal).

Syntax:
int strcmp(const char *str1, const char *str2);

#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    if (strcmp(str1, str2) == 0) {
        printf("Strings are equal\n");
    }
    return 0;
}

// ---------------------------------------------------------------------------------------------

5. strncmp() - Compare Strings with Limit
Compares up to n characters of two strings.

Syntax:
int strncmp(const char *str1, const char *str2, size_t n);

#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "HelloWorld";
    if (strncmp(str1, str2, 5) == 0) {
        printf("First 5 characters are equal\n");
    }
    return 0;
}

// ---------------------------------------------------------------------------------------------

6. strcat() - Concatenate Strings
Appends one string to the end of another.

Syntax:
char *strcat(char *dest, const char *src);

#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello, ";
    char str2[] = "World!";
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    return 0;
}

// ---------------------------------------------------------------------------------------------

7. strncat() - Concatenate Strings with Limit
Appends up to n characters of one string to another.

Syntax:
char *strncat(char *dest, const char *src, size_t n);

#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello, ";
    char str2[] = "World!";
    strncat(str1, str2, 3);
    printf("Concatenated string: %s\n", str1);
    return 0;
}

// ---------------------------------------------------------------------------------------------

8. strchr() - Locate Character in String
Finds the first occurrence of a character in a string.

Syntax:
char *strchr(const char *str, int c);

#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, World!";
    char *ptr = strchr(str, 'W');
    if (ptr != NULL) {
        printf("Character found: %c\n", *ptr);
    }
    return 0;
}

// ---------------------------------------------------------------------------------------------

9. strrchr() - Locate Last Occurrence of Character
Finds the last occurrence of a character in a string.

Syntax:
char *strrchr(const char *str, int c);

#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, World!";
    char *ptr = strrchr(str, 'o');
    if (ptr != NULL) {
        printf("Last occurrence: %c\n", *ptr);
    }
    return 0;
}

// ---------------------------------------------------------------------------------------------

10. strstr() - Locate Substring
Finds the first occurrence of a substring in a string.

Syntax:
char *strstr(const char *haystack, const char *needle);

#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, World!";
    const char *substr = "World";
    char *ptr = strstr(str, substr);
    if (ptr != NULL) {
        printf("Substring found: %s\n", ptr);
    }
    return 0;
}

// ---------------------------------------------------------------------------------------------

11. strtok() - Tokenize String
Splits a string into tokens based on a delimiter.

Syntax:
char *strtok(char *str, const char *delim);

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World, How, Are, You";
    char *token = strtok(str, ", ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ", ");
    }
    return 0;
}
// ---------------------------------------------------------------------------------------------