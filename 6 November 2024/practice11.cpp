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
            default: throw invalid_argument("Invalid month");
        }
    }

    // Helper function to validate date
    void validateDate() {
        if (month < 1 || month > 12)
            throw invalid_argument("Month must be between 1 and 12");
        if (day < 1 || day > daysInMonth(month, year))
            throw invalid_argument("Invalid day for the given month and year");
    }

    // Increment date by one day
    void incrementDay() const {
        Date temp = *this;
        temp.day++;
        if (temp.day > temp.daysInMonth(temp.month, temp.year)) {
            temp.day = 1;
            temp.month++;
            if (temp.month > 12) {
                temp.month = 1;
                temp.year++;
            }
        }
        *const_cast<Date*>(this) = temp;
    }

public:
    // Constructor
    Date(int y, int m, int d) : year(y), month(m), day(d) {
        validateDate();
    }

    // Operator += to add days to date
    Date& operator+=(int days) {
        for (int i = 0; i < days; ++i) {
            incrementDay();
        }
        return *this;
    }

    // Prefix increment (e.g., ++dt)
    Date& operator++() {
        incrementDay();
        return *this;
    }

    // Postfix increment (e.g., dt++)
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
            incrementDay();
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
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        int weekday = (d + 2 * m + (3 * (m + 1) / 5) + y + y / 4 - y / 100 + y / 400) % 7;
        return weekdays[weekday];
    }

    // Display function
    void display() const {
        cout << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day << endl;
    }
};

// Main function to test the Date class
int main() {
    try {
        Date dt(2024, 11, 6);
        dt.display();

        // Test += operator
        dt += 20;
        dt.display();

        // Test prefix increment
        ++dt;
        dt.display();

        // Test postfix increment
        dt++;
        dt.display();

        // Test difference in days
        Date dt1(2024, 11, 6);
        Date dt2(2024, 12, 1);
        int days = dt2 - dt1;
        cout << "Days between dt1 and dt2: " << days << endl;

        // Test comparison
        if (dt2 > dt1) {
            cout << "dt2 is after dt1" << endl;
        }

        // Test weekday calculation
        cout << "The day of the week for dt2 is: " << dt2.Weekday() << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}