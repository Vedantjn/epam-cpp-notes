1. %d or %i - Integer (signed decimal)
Prints a
#include <stdio.h>

int main() {
    int num = 25;
    printf("Integer: %d\n", num);
    return 0;
}
Output:
Integer: 25

// -----------------------------------------------------------------------

2. %u - Unsigned Integer
Prints an unsigned integer.

#include <stdio.h>

int main() {
    unsigned int num = 300;
    printf("Unsigned Integer: %u\n", num);
    return 0;
}
Output:
Unsigned Integer: 300

// -----------------------------------------------------------------------

3. %f - Floating-point
Prints a floating-point number.

#include <stdio.h>

int main() {
    float num = 3.14159;
    printf("Floating-point: %f\n", num);
    return 0;
}
Output:
Floating-point: 3.141590

// -----------------------------------------------------------------------

4. %lf - Double
Prints a double-precision floating-point number.

#include <stdio.h>

int main() {
    double num = 3.14159;
    printf("Double: %lf\n", num);
    return 0;
}
Output:
Double: 3.141590

// -----------------------------------------------------------------------

5. %c - Character
Prints a single character.

#include <stdio.h>

int main() {
    char ch = 'A';
    printf("Character: %c\n", ch);
    return 0;
}
Output:
Character: A

// -----------------------------------------------------------------------

6. %s - String
Prints a string (array of characters).

#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    printf("String: %s\n", str);
    return 0;
}
Output:
String: Hello, World!

// -----------------------------------------------------------------------

7. %x or %X - Hexadecimal (lowercase/uppercase)
Prints an unsigned integer in hexadecimal format. %x prints it in lowercase, while %X prints it in uppercase.

#include <stdio.h>

int main() {
    int num = 255;
    printf("Hexadecimal: %x\n", num);  // lowercase
    printf("Hexadecimal: %X\n", num);  // uppercase
    return 0;
}
Output:
Hexadecimal: ff
Hexadecimal: FF

// -----------------------------------------------------------------------

8. %o - Octal
Prints an unsigned integer in octal (base-8) format.

#include <stdio.h>

int main() {
    int num = 10;
    printf("Octal: %o\n", num);
    return 0;
}
Output:
Octal: 12

// -----------------------------------------------------------------------

9. %p - Pointer
Prints the memory address of a variable (pointer).

#include <stdio.h>

int main() {
    int num = 10;
    printf("Pointer: %p\n", (void*)&num);
    return 0;
}
Output:
Pointer: 0x7ffee47b3c7c

// -----------------------------------------------------------------------

10. %e or %E - Scientific Notation
Prints a floating-point number in scientific notation (lowercase or uppercase E).

#include <stdio.h>

int main() {
    float num = 1234.56789;
    printf("Scientific Notation: %e\n", num);
    return 0;
}
Output:
Scientific Notation: 1.234568e+03

// -----------------------------------------------------------------------

11. %g or %G - Shorter of %f or %e
Automatically selects the shorter form between %f and %e based on the value.

#include <stdio.h>

int main() {
    float num = 1234.56789;
    printf("Shorter Form: %g\n", num);
    return 0;
}
Output:
Shorter Form: 1234.57

// -----------------------------------------------------------------------

12. %lu - Unsigned Long
Prints an unsigned long integer.

#include <stdio.h>

int main() {
    unsigned long num = 4294967295;
    printf("Unsigned Long: %lu\n", num);
    return 0;
}
Output:
Unsigned Long: 4294967295

// -----------------------------------------------------------------------

13. %lld - Long Long (signed)
Prints a signed long long integer.

#include <stdio.h>

int main() {
    long long num = 9223372036854775807;
    printf("Long Long: %lld\n", num);
    return 0;
}
Output:
Long Long: 9223372036854775807

// -----------------------------------------------------------------------

14. %% - Prints a Percent Symbol
Prints the % symbol itself.

#include <stdio.h>

int main() {
    printf("Percentage: 100%%\n");
    return 0;
}
Output:
Percentage: 100%

// -----------------------------------------------------------------------

15. %ld - Long Integer (signed)
Prints a signed long integer.

#include <stdio.h>

int main() {
    long num = 9223372036854775807L;
    printf("Signed Long: %ld\n", num);
    return 0;
}
Output:
Signed Long: 9223372036854775807

// -----------------------------------------------------------------------

16. %llu - Unsigned Long Long
Prints an unsigned long long integer.

#include <stdio.h>

int main() {
    unsigned long long num = 18446744073709551615ULL;
    printf("Unsigned Long Long: %llu\n", num);
    return 0;
}
Output:
Unsigned Long Long: 18446744073709551615

// -----------------------------------------------------------------------

17. %h - Short Integer
You can use %hd for signed short integer and %hu for unsigned short integer.

#include <stdio.h>

int main() {
    short num = 32767;
    printf("Signed Short: %hd\n", num);
    return 0;
}
Output:
Signed Short: 32767

// -----------------------------------------------------------------------

18. %lf with scanf() for Double
In the scanf() function, %lf is used to read double values. While printf() can use %f for both float and double, scanf() needs %lf to distinguish a double from a float.

#include <stdio.h>

int main() {
    double num;
    printf("Enter a double: ");
    scanf("%lf", &num);
    printf("You entered: %lf\n", num);
    return 0;
}

// -----------------------------------------------------------------------

19. %n - Number of Characters Printed So Far
Writes the number of characters printed so far to the corresponding argument.

#include <stdio.h>

int main() {
    int count;
    printf("Hello, world!%n", &count);
    printf(" (Length: %d characters)\n", count);
    return 0;
}
Output:
Hello, world! (Length: 13 characters)

// -----------------------------------------------------------------------

20. %a or %A - Hexadecimal Floating-point
Prints a floating-point number in hexadecimal format (scientific notation using powers of 2). %a uses lowercase p, and %A uses uppercase P.

#include <stdio.h>

int main() {
    float num = 3.14;
    printf("Hexadecimal Floating-point: %a\n", num);
    return 0;
}
Output:
Hexadecimal Floating-point: 0x1.91eb86p+1

// -----------------------------------------------------------------------

21. Field Width and Precision Modifiers
You can specify the minimum field width and precision for formatting numbers and strings.

Syntax:

%m.nX where m is the minimum field width, n is the precision, and X is the format specifier.
For numbers, precision controls the number of digits after the decimal point.
For strings, precision limits the number of characters to print

#include <stdio.h>

int main() {
    float num = 3.14159;
    printf("Width 10, Precision 2: %10.2f\n", num);
    printf("String with Precision: %.5s\n", "Hello, World!");
    return 0;
}
Output:
     3.14
Hello

// -----------------------------------------------------------------------

22. Flags with Format Specifiers
Flags can be used with format specifiers to modify the behavior of printf():

-: Left-justify the result within the field width.
+: Print a plus sign for positive numbers.
0: Pad with leading zeros (instead of spaces).
(space): Leave a space before positive numbers.
#: Adds a prefix to certain specifiers (0x for hex, 0 for octal)

#include <stdio.h>

int main() {
    int num = 42;
    printf("Left-justify: %-10d|\n", num); // left-justified
    printf("Leading zeros: %010d\n", num); // padded with zeros
    printf("Sign for positive: %+d\n", num); // adds +
    return 0;
}
Output:
Left-justify: 42        |
Leading zeros: 0000000042
Sign for positive: +42

// -----------------------------------------------------------------------

23. %g or %G - Shortest Representation of %f or %e
%g automatically chooses between the fixed-point notation (%f) and the scientific notation (%e), based on the value and precision, whichever is shorter.

#include <stdio.h>

int main() {
    double num = 1234.5678;
    printf("Shortest Representation: %g\n", num);
    return 0;
}
Output:
Shortest Representation: 1234.57

// -----------------------------------------------------------------------

24. %I64d or %lld - 64-bit Integer (for Windows)
Prints a signed 64-bit integer on Windows systems. %lld is used cross-platform, but %I64d is specific to Windows(Windows-specific):

#include <stdio.h>

int main() {
    __int64 num = 9223372036854775807;
    printf("64-bit Integer: %I64d\n", num);
    return 0;
}
Output (Windows):
64-bit Integer: 9223372036854775807