/*
File naming rules for C:

1. File names should end with .c for source files and .h for header files
   Example: my_program.c, utilities.h
2. Use lowercase letters for file names (convention)
   Example: my_script.c, my_header.h
3. Avoid spaces - use underscores instead
   Example: user_data.c, file_operations.h
4. File names should be descriptive of the code's purpose
   Example: string_utilities.c, math_operations.h
5. Keep names concise but meaningful
   Example: sort.c, search.h
6. Valid characters include:
   - Letters (a-z)
   - Numbers (0-9) 
   - Underscores (_)
7. Don't start file names with numbers
   Invalid: 1st_file.c, 2024_data.h
   Valid: first_file.c, data_2024.h
8. Avoid special characters and spaces
   Invalid: my file!.c, data@2024.h
9. Common naming patterns:
   - main.c
   - utils.c
   - string_functions.c
   - data_structures.h
   - constants.h

Note: While C itself doesn't enforce naming rules, these are common conventions
that make code more maintainable and portable across systems.
*/

#include <stdio.h>

struct Person {
    char name[20];
    int age;
    float height;
};

int main() {
    FILE *file;
    char text[100];
    char ch;

    //===========================================
    // Standard Streams 
    //===========================================
    
    // stdin  - reading from standard input
    char input[100];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    fprintf(stdout, "You entered: %s", input);
    
    // stdout  - writing to standard output
    fprintf(stdout, "This is written to stdout\n");
    
    // stderr  - writing error messages
    fprintf(stderr, "This is an error message written to stderr\n");
    
    // Using stdin with fscanf
    int num;
    printf("Enter a number: ");
    fscanf(stdin, "%d", &num);
    fprintf(stdout, "You entered the number: %d\n", num);

    //===========================================
    // Basic File Operations
    //===========================================

    // Writing to a file
    file = fopen("a.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }
    fprintf(file, "Hello! This is a simple file a.\n");
    fclose(file);

    //===========================================
    // File Reading Methods
    //===========================================

    // Method 1: Reading using fgetc and feof
    file = fopen("a.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    printf("Content read from file character by character:\n");
    while (!feof(file)) {
        ch = fgetc(file);
        if (ch != EOF) {
            printf("%c", ch);
        }
    }
    fclose(file);

    // Method 2: Alternative reading using fgetc
    file = fopen("a.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }
    printf("\nAlternative reading method:\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);

    //===========================================
    // fscanf Example
    //===========================================

    // Create a file with formatted data
    file = fopen("data.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }
    fprintf(file, "42 3.14 Hello");
    fclose(file);

    // Read formatted data using fscanf
    int number;
    float decimal;
    char word[20];
    
    file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }
    fscanf(file, "%d %f %s", &number, &decimal, word);
    printf("\nRead using fscanf:\n");
    printf("Number: %d\n", number);
    printf("Decimal: %.2f\n", decimal);
    printf("Word: %s\n", word);
    fclose(file);

    //===========================================
    // Character Writing  (fputc)
    //===========================================

    file = fopen("fputc_example.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    fputc('A', file);                        // Single character
    for(char c = 'B'; c <= 'E'; c++) {       // Multiple characters
        fputc(c, file);
    }
    fputc('1', file);                        // Number as character
    fputc('\n', file);                       // Special character
    fputc('z', file);                        // Lowercase letter
    fclose(file);

    //===========================================
    // File Positioning (fseek and ftell)
    //===========================================

    // fseek examples
    file = fopen("fputc_example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    ch = fgetc(file);
    printf("\nFirst character: %c\n", ch);

    fseek(file, 2, SEEK_CUR);
    ch = fgetc(file);
    printf("Character after moving 2 positions forward: %c\n", ch);

    fseek(file, -1, SEEK_CUR);
    ch = fgetc(file);
    printf("Character after moving 1 position backward: %c\n", ch);
    fclose(file);

    // ftell examples
    file = fopen("fputc_example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    long pos = ftell(file);
    printf("\nInitial position: %ld\n", pos);

    fgetc(file); fgetc(file);
    pos = ftell(file);
    printf("Position after reading 2 characters: %ld\n", pos);

    fseek(file, 0, SEEK_END);
    pos = ftell(file);
    printf("Position at end of file: %ld\n", pos);
    fclose(file);

    //===========================================
    // Buffer Management (fflush)
    //===========================================

    file = fopen("flush_example.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    fprintf(file, "Writing this to file");
    fflush(file);
    fprintf(file, " and this too");
    fflush(file);
    fclose(file);

    //===========================================
    // File Access Modes
    //===========================================

    // Append mode
    file = fopen("a.txt", "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }
    fprintf(file, "This text is appended.\n");
    fclose(file);

    // Read and Write mode (r+)
    file = fopen("a.txt", "r+");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }
    fprintf(file, "Overwriting at current position\n");
    fclose(file);

    // Write and Read mode (w+)
    file = fopen("a.txt", "w+");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }
    fprintf(file, "New content with w+\n");
    rewind(file);
    fgets(text, 100, file);
    printf("Content read: %s", text);
    fclose(file);

    // Append and Read mode (a+)
    file = fopen("a.txt", "a+");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }
    fprintf(file, "Appending with a+\n");
    rewind(file);
    while (fgets(text, 100, file) != NULL) {
        printf("%s", text);
    }
    fclose(file);

    //===========================================
    // Binary File Operations
    //===========================================

    // Writing binary data
    file = fopen("data.bin", "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening binary file!\n");
        return 1;
    }

    int numbers[] = {1, 2, 3, 4, 5};
    char chars[] = {'A', 'B', 'C'};
    float floats[] = {1.1f, 2.2f, 3.3f};
    
    struct Person person = {"John", 25, 175.5};
    struct Person people[] = {
        {"Alice", 22, 165.0},
        {"Bob", 30, 180.0}
    };

    // Write different data types
    fwrite(numbers, sizeof(int), 5, file);
    fwrite(chars, sizeof(char), 3, file);
    fwrite(floats, sizeof(float), 3, file);
    fwrite(&person, sizeof(struct Person), 1, file);
    fwrite(people, sizeof(struct Person), 2, file);
    fclose(file);

    // Reading binary data
    file = fopen("data.bin", "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening binary file!\n");
        return 1;
    }

    // Read back the data
    int read_numbers[5];
    char read_chars[3];
    float read_floats[3];
    struct Person read_person;
    struct Person read_people[2];

    fread(read_numbers, sizeof(int), 5, file);
    fread(read_chars, sizeof(char), 3, file);
    fread(read_floats, sizeof(float), 3, file);
    fread(&read_person, sizeof(struct Person), 1, file);
    fread(read_people, sizeof(struct Person), 2, file);
    fclose(file);

    // Output the read data
    printf("\nRead from binary file:\n");
    printf("Numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", read_numbers[i]);
    }
    printf("\nCharacters: ");
    for (int i = 0; i < 3; i++) {
        printf("%c ", read_chars[i]);
    }
    printf("\nFloats: ");
    for (int i = 0; i < 3; i++) {
        printf("%.2f ", read_floats[i]);
    }
    printf("\nPerson: %s, %d, %.2f\n", read_person.name, read_person.age, read_person.height);
    printf("People:\n");
    for (int i = 0; i < 2; i++) {
        printf("%s, %d, %.2f\n", read_people[i].name, read_people[i].age, read_people[i].height);
    }

    return 0;
}
