
#include <iostream>
#include <vector>
using namespace std;

// Q1: Faulty function provided in the assignment.
// The fault is that the loop starts at index 1 instead of index 0,
// causing the first lecture's attendance to be skipped.
bool failLecture(const vector<int>& attendance_records) {
    int absent_count = 0;

    // FAULT: Starts at index 1 instead of index 0
    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += attendance_records[i] == 0;
    }

    return absent_count >= 3;
}

// Calculates the expected absence count correctly
int expectedAbsences(const vector<int>& attendance) {
    int count = 0;

    for (int i = 0; i < attendance.size(); ++i) {
        if (attendance[i] == 0) {
            count++;
        }
    }

    return count;
}

// Calculates the actual absence count using the faulty loop
int actualAbsences(const vector<int>& attendance) {
    int count = 0;

    for (int i = 1; i < attendance.size(); ++i) {
        if (attendance[i] == 0) {
            count++;
        }
    }

    return count;
}

// Displays and verifies each test case
void runTest(int testNumber, const vector<int>& attendance) {

    int expected = expectedAbsences(attendance);
    int actual = actualAbsences(attendance);

    bool expectedOutput = expected >= 3;
    bool actualOutput = failLecture(attendance);

    cout << "\nTest Case " << testNumber << endl;

    cout << "Attendance Record: ";

    for (int value : attendance) {
        cout << value << " ";
    }

    cout << "\nExpected Absence Count: " << expected;
    cout << "\nActual Absence Count: " << actual;

    cout << "\nExpected Output: "
         << (expectedOutput ? "Fail" : "Pass");

    cout << "\nActual Output: "
         << (actualOutput ? "Fail" : "Pass");

    cout << "\n";
}

int main() {

    // Q3: The fault executes, but no error state occurs.
    // The first attendance value is 1 (present), so skipping it
    // does not change the absence count.
    vector<int> test3 = {
        1, 1, 1, 1, 1, 1, 1, 0, 0, 0
    };

    // Q4: An error state occurs, but no failure occurs.
    // The first attendance value is 0 (absent), so the actual
    // absence count is incorrect (1 instead of 2).
    // However, both counts are below 3, so the output is correct.
    vector<int> test4 = {
        0, 0, 1, 1, 1, 1, 1, 1, 1, 1
    };

    // Q5: An error state causes a failure.
    // The actual absence count is 2 instead of 3.
    // The program incorrectly reports Pass instead of Fail.
    vector<int> test5 = {
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1
    };

    runTest(3, test3);
    runTest(4, test4);
    runTest(5, test5);

    return 0;
}
