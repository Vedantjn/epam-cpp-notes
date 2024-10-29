/*
 * Multibyte strings are sequences of characters that may use more than one byte 
 * to represent a single character. This is common for:
 *
 * 1. Unicode/UTF-8 encoded text where characters can use 1-4 bytes
 * 2. Extended ASCII character sets
 * 3. Asian character sets like Shift-JIS, Big5, etc.
 *
 * Unicode String Examples:
 * - ASCII: "Hello" (1 byte per char)
 * - UTF-8: "Hello 世界" (mix of 1 and 3 bytes per char)
 * - UTF-16: L"Hello 世界" (wide string literal)
 *
 * Wide Character Functions:
 * - wchar_t: Wide character type for Unicode
 * - wstring: Wide string class in C++
 * - wcout: Wide character output stream
 * - wprintf: Wide character printf
 * - setlocale: Set locale for proper encoding
 *
 * String Copy Functions:
 * strcpy -> wcscpy (for wide chars)
 * strncpy -> wcsncpy
 * strcat -> wcscat
 * strlen -> wcslen
 */

/*
 * Wide Characters (wchar_t):
 * - Fixed-width characters typically 16 or 32 bits wide
 * - Designed to handle Unicode and international character sets
 * - Prefixed with 'L' in string literals: L"Hello"
 * - Uses special functions with 'wcs' prefix (wide char string)
 * - Platform dependent size (Windows: 16-bit, Unix: 32-bit)
 * - Can represent any Unicode code point directly
 * - More memory efficient for processing than multibyte strings
 * - No need for complex parsing of character boundaries
 * - Supported by C/C++ standard libraries via <wchar.h>
 * - Common in Windows API (UTF-16) programming
 */


#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
// #include <iostream>

int main() {
    // Set locale for Unicode support
    // Set the program's locale to the system default locale
    // This enables proper handling of Unicode characters in input/output
    // The setlocale(LC_ALL, "") function is used to configure the program 
    // to support Unicode. Without setting the locale, some functions may 
    // not process Unicode characters correctly, leading to unexpected characters (like ?? in the output).

    // setlocale(LC_ALL, "");
    setlocale(LC_ALL, "en_US.UTF-8");

    // Regular multibyte string
    const char *mb_str = "Hello 世界";
    
    // Wide character string
    const wchar_t *wide_str = L"Hello 世界";
    
    // Wide character array
    wchar_t dest[50];
    
    // Copy wide string (wcscpy equivalent of strcpy)
    wcscpy(dest, wide_str);
    
    // Print using different methods
    printf("Multibyte string: %s\n", mb_str);
    // cout << mb_str << endl;
    // %ls is used for printing wide character strings (wchar_t*)
    wprintf(L"Wide string: %ls\n", wide_str);
    wprintf(L"Copied string: %ls\n", dest);
    
    // Get lengths
    // %zu is used for printing size_t values (unsigned sizes and lengths)
    printf("Multibyte length in bytes: %zu\n", strlen(mb_str));
    printf("Wide string length in characters: %zu\n", wcslen(wide_str));
    
    return 0;
}

// Multibyte string: Hello ä,-çO
// Wide string: Hello ??
// Copied string: Hello ??
// Multibyte length in bytes: 12
// Wide string length in characters: 8