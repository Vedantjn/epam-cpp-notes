
#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

union Data {
    int i;
    float f;
    char str[20];
};

enum Days {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

typedef struct {
    int x;
    int y;
} Point;

int main() {
    struct Student student1;
    student1.rollNo = 1;
    strcpy(student1.name, "John");
    student1.marks = 85.5;
    
    printf("Student Details:\n");
    printf("Roll No: %d\n", student1.rollNo);
    printf("Name: %s\n", student1.name);
    printf("Marks: %.2f\n\n", student1.marks);

    // Using union
    union Data data;
    data.i = 10;
    printf("Union Data (integer): %d\n", data.i);
    data.f = 220.5;
    printf("Union Data (float): %.2f\n", data.f);
    strcpy(data.str, "Hello");
    printf("Union Data (string): %s\n\n", data.str);

    // Using enum
    enum Days today = WEDNESDAY;
    printf("Day number: %d\n\n", today);

    // Using typedef
    Point p1;
    p1.x = 10;
    p1.y = 20;
    printf("Point coordinates: (%d, %d)\n", p1.x, p1.y);

    return 0;
}
