1. time() - Get Current Calendar Time
Retrieves the current calendar time (in seconds since the Unix Epoch: January 1, 1970, 00:00:00 UTC).

Syntax:
time_t time(time_t *timer);

Example:
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    time(¤t_time);
    printf("Current time: %ld seconds since the Epoch\n", current_time);
    return 0;
}

// -----------------------------------------------------------------------------------

2. clock() - Get Processor Time Used by Program
Returns the processor time consumed by the program since it started (in clock ticks).

Syntax:
clock_t clock(void);

Example:
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();
    // Simulate some work
    for (long i = 0; i < 100000000; ++i);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}

// -----------------------------------------------------------------------------------

3. difftime() - Difference Between Two Times
Computes the difference in seconds between two time_t values.

Syntax:
double difftime(time_t end, time_t start);

Example:
#include <stdio.h>
#include <time.h>

int main() {
    time_t start = time(NULL);
    // Simulate some delay
    for (long i = 0; i < 1000000000; ++i);
    time_t end = time(NULL);
    double difference = difftime(end, start);
    printf("Time difference: %.2f seconds\n", difference);
    return 0;
}

// -----------------------------------------------------------------------------------

4. ctime() - Convert Time to String
Converts a time_t value to a human-readable string in the format: Day Month Date HH:MM:SS YYYY.

Syntax:
char *ctime(const time_t *timer);

Example:
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    time(¤t_time);
    printf("Current time: %s", ctime(¤t_time));
    return 0;
}

// -----------------------------------------------------------------------------------

5. asctime() - Convert tm Structure to String
Converts a struct tm to a human-readable string. Similar to ctime() but takes a tm structure as input.

Syntax:
char *asctime(const struct tm *timeptr);

Example:
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;

    time(¤t_time);
    time_info = localtime(¤t_time);

    printf("Formatted time: %s", asctime(time_info));
    return 0;
}

// -----------------------------------------------------------------------------------

6. strftime() - Custom Time String Formatting
Converts the tm structure to a string, with user-defined formatting options.

Syntax:
size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr);

Common Format Specifiers:
%Y - Year
%m - Month
%d - Day of the month
%H - Hour (24-hour clock)
%M - Minutes
%S - Seconds
%A - Full weekday name

Example:
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    char buffer[80];

    time(¤t_time);
    time_info = localtime(¤t_time);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
    printf("Custom formatted time: %s\n", buffer);
    return 0;
}

// -----------------------------------------------------------------------------------

7. localtime() - Convert time_t to Local Time (tm Structure)
Converts a time_t value to a tm structure that represents the local time.

Syntax:
struct tm *localtime(const time_t *timer);

Example:
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;

    time(¤t_time);
    time_info = localtime(¤t_time);
    printf("Year: %d\n", time_info->tm_year + 1900);
    return 0;
}

// -----------------------------------------------------------------------------------

8. gmtime() - Convert time_t to UTC (GMT) Time
Similar to localtime(), but converts the time_t value to Coordinated Universal Time (UTC) instead of local time.

Syntax:
struct tm *gmtime(const time_t *timer);

Example:
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *utc_time;

    time(¤t_time);
    utc_time = gmtime(¤t_time);

    printf("UTC Year: %d\n", utc_time->tm_year + 1900);
    return 0;
}

// -----------------------------------------------------------------------------------

9. mktime() - Convert tm Structure to time_t
Converts a tm structure representing local time to a time_t value.

Syntax:
time_t mktime(struct tm *timeptr);

Example:
#include <stdio.h>
#include <time.h>

int main() {
    struct tm time_info = {0};
    time_info.tm_year = 2024 - 1900;  // Year since 1900
    time_info.tm_mon = 9;             // October
    time_info.tm_mday = 23;

    time_t time_val = mktime(&time_info);
    printf("Unix Timestamp: %ld\n", time_val);
    return 0;
}

// -----------------------------------------------------------------------------------

10. nanosleep() - High Precision Sleep (POSIX)
Suspends the program execution for the specified time (nanoseconds precision). Available in POSIX-compliant systems like Linux.

Syntax:
int nanosleep(const struct timespec *req, struct timespec *rem);

Example:
#include <stdio.h>
#include <time.h>

int main() {
    struct timespec ts;
    ts.tv_sec = 1;          // 1 second
    ts.tv_nsec = 500000000; // 500 million nanoseconds (0.5 second)

    printf("Sleeping for 1.5 seconds...\n");
    nanosleep(&ts, NULL);
    printf("Awake now!\n");
    return 0;
}