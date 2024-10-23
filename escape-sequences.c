Newline (\n)
Inserts a new line in the output.

#include <stdio.h>

int main() {
    printf("Hello\nWorld\n");
    return 0;
}

Output:
Hello
World

--------------------------------------------------------------------------------

Tab (\t)
Inserts a horizontal tab.

#include <stdio.h>

int main() {
    printf("Column1\tColumn2\tColumn3\n");
    return 0;
}

Output:
Column1   Column2   Column3

--------------------------------------------------------------------------------

Backslash (\\)
Prints a backslash character.

#include <stdio.h>

int main() {
    printf("This is a backslash: \\\n");
    return 0;
}

Output:
This is a backslash: \

--------------------------------------------------------------------------------

Single Quote (\')
Prints a single quote character.

#include <stdio.h>

int main() {
    printf("This is a single quote: \'\n");
    return 0;
}
Output:
This is a single quote: '
Topic: Special Characters Handling

--------------------------------------------------------------------------------

Double Quote (\")
Prints a double quote character.

#include <stdio.h>

int main() {
    printf("He said, \"Hello!\"\n");
    return 0;
}

Output:
He said, "Hello!"

--------------------------------------------------------------------------------

Carriage Return (\r)
Moves the cursor to the beginning of the current line (without advancing to the next line). It can overwrite part of the output.

#include <stdio.h>

int main() {
    printf("12345\rABCDE\n");
    return 0;
}
Output:
ABCDE

--------------------------------------------------------------------------------

Alert/Bell (\a)
Triggers an alert sound (in environments that support this feature).

#include <stdio.h>

int main() {
    printf("Alert! \a\n");
    return 0;
}

(May produce a beep sound depending on the system)

--------------------------------------------------------------------------------

Backspace (\b)
Moves the cursor one position backward.

#include <stdio.h>

int main() {
    printf("12345\b\b\n");
    return 0;
}
Output:
123

--------------------------------------------------------------------------------

Form Feed (\f)
Advances the output to the next page in a printer or text file (this is mostly obsolete).

#include <stdio.h>

int main() {
    printf("Hello\fWorld\n");
    return 0;
}
Output:
Depending on the system, it may not visibly show anything different.

--------------------------------------------------------------------------------

Null Character (\0)
Terminates a string in C.

#include <stdio.h>

int main() {
    char str[] = "Hello\0World";
    printf("%s\n", str);
    return 0;
}
Output:
Hello