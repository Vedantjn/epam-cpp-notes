#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Date {
private:
    int year, month, day;

    // Helper function to check if a year is leap
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Helper function to get days in a month
    int daysInMonth(int m, int y) const {
        switch(m) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
            case 4: case 6: case 9: case 11: return 30;
            case 2: return isLeapYear(y) ? 29 : 28;
            default: cout << "Month must be between 1 and 123" << endl;
            return 0;
        }
    }

    // Helper function to validate date
    void validateDate() {
        if (month < 1 || month > 12) {
            cout << "Month must be between 1 and 12" << endl;
            exit(1);
        }
        if (day < 1 || day > daysInMonth(month, year)) {
            cout << "Invalid day for the given month and year" << endl;
            exit(1);
        }
    }

public:
    // Constructor
    Date(int y, int m, int d) : year(y), month(m), day(d) {
        validateDate();
    }

    // Increment date by one day
    void incrementDay() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    // Operator += to add days to date
    Date& operator+=(int days) {
        for (int i = 0; i < days; ++i) {
            incrementDay();
        }
        return *this;
    }

    // Prefix increment (++dt)
    Date& operator++() {
        incrementDay();
        return *this;
    }

    // Postfix increment (dt++)
    Date operator++(int) {
        Date temp = *this;
        incrementDay();
        return temp;
    }

    // Difference in days between two dates
    int operator-(const Date& other) const {
        Date temp = other;
        int days = 0;
        while (temp < *this) {
            temp.incrementDay();
            ++days;
        }
        while (*this < temp) {
            Date tempThis = *this;
            tempThis.incrementDay();
            ++days;
        }
        return days;
    }

    // Comparison operators
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator>(const Date& other) const { return other < *this; }
    bool operator==(const Date& other) const { return year == other.year && month == other.month && day == other.day; }
    bool operator!=(const Date& other) const { return !(*this == other); }

    // Calculate the weekday (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    string Weekday() const {
        static const string weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        int d = day, m = month, y = year;
        
        // For Zeller's formula, January and February are considered as months 13 and 14
        // of the previous year. This is because the formula works better this way.
        // January 2024 becomes month 13 of 2023
        // February 2024 becomes month 14 of 2023
        if (m < 3) {
            m += 12;  // Convert January (1) to 13, February (2) to 14
            y -= 1;   // Move back one year since we're treating it as part of previous year
        }
        
        // Zeller's Congruence formula to calculate day of week
        // Returns 0 for Sunday, 1 for Monday, etc.
        int weekday = (d + 2 * m + (3 * (m + 1) / 5) + y + y / 4 - y / 100 + y / 400) % 7;
        
        // Return the weekday name using the calculated index
        return weekdays[weekday];
    }
    // Display function
    void display() const {
        cout << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day << endl;
    }
};

int main() {
    Date dt(2024, 11, 6);
    dt.display();

    // += operator
    dt += 20;
    dt.display();

    // prefix increment
    ++dt;
    dt.display();

    // postfix increment
    dt++;
    dt.display();

    // difference in days
    Date dt1(2024, 11, 6);
    Date dt2(2024, 12, 1);
    int days = dt2 - dt1;
    cout << "Days between dt1 and dt2: " << days << endl;

    // comparison
    if (dt2 > dt1) {
        cout << "dt2 is after dt1" << endl;
    }

    // weekday calculation
    cout << "The day of the week for dt2 is: " << dt2.Weekday() << endl;

    return 0;
}

// 2024-11-06
// 2024-11-26
// 2024-11-27
// 2024-11-28
// Days between dt1 and dt2: 25
// dt2 is after dt1
// The day of the week for dt2 is: Saturday