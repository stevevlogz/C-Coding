#include <iostream>
#include <iomanip> // for setw and setprecision

using namespace std;

// Template function to calibrate a sensor value
template <typename T>
T calibrateValue(const T &value, char factor) {
    return value * factor;
}

// Function to adjust a reading
void adjustReading(double *reading, double offset = 1.25) {
    *reading = *reading + offset;
}

// Function to clamp a reading between 0 and 100
void clampReading(double &reading) {
    if (reading < 0) reading = 0;
    if (reading > 100) reading = 100;
}

// Function to compute difference between int and double
double computeDifference(int intValue, double doubleValue) {
    return intValue - doubleValue;
}

int main() {
    cout << "***** Sensor Calibration Program *****" << endl;

    // Input readings
    int intSensor;
    double doubleSensor;

    cout << "Enter an integer sensor reading: ";
    cin >> intSensor;

    cout << "Enter a double sensor reading: ";
    cin >> doubleSensor;

    // Calibrate readings by factor 2
    char factor = 2; // using char as requested
    int calibratedInt = calibrateValue(intSensor, factor);
    double calibratedDouble = calibrateValue(doubleSensor, factor);

    cout << fixed << setprecision(4);
    cout << "Calibrated readings:" << endl;
    cout << setw(10) << calibratedInt << setw(10) << calibratedDouble << endl;

    // Convert integer to double for adjustments
    double intAsDouble = static_cast<double>(calibratedInt);

    // Adjust readings
    adjustReading(&intAsDouble);           // default offset 1.25
    adjustReading(&calibratedDouble, 3.4); // offset 3.4

    cout << "Adjusted readings:" << endl;
    cout << setw(10) << intAsDouble << setw(10) << calibratedDouble << endl;

    // Clamp readings
    clampReading(intAsDouble);
    clampReading(calibratedDouble);

    cout << "Clamped readings:" << endl;
    cout << setw(10) << intAsDouble << setw(10) << calibratedDouble << endl;

    // Convert back to integer
    int finalInt = static_cast<int>(intAsDouble);
    cout << "Final integer reading:" << setw(10) << finalInt << endl;

    // Compute difference
    double difference = computeDifference(finalInt, calibratedDouble);
    cout << "Difference between readings:" << setw(10) << difference << endl;

    return 0;
}
