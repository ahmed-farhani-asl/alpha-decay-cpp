#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

// Function declarations
void alpha_decay();  // Function to simulate alpha decay
string int_to_str(double);  // Function to convert double to string

int main() {
    // Main function that calls the alpha_decay function
    alpha_decay();
    return 0;
}

void alpha_decay() {
    // Function to simulate the alpha decay process
    fstream print, p2;  // File streams for output and error data
    string output_file_name, gap = "\t";  // Output file name and gap for formatting
    double N0, N, dt, t, error;  // Variables for initial amount, current amount, time step, duration, and error
    int end_loop;  // Number of time steps

    // User input for initial conditions
    cout << "Insert the quantities below" << endl << endl;
    cout << "Initial amount of alpha: ";
    cin >> N;

    N0 = N;  // Store the initial amount of alpha

    cout << "Time step: ";
    cin >> dt;

    cout << "Duration time: ";
    cin >> t;

    cout << endl << "Note: The units of the result will be the same units you've inserted above..." << endl;

    // Generate output file names based on the time step
    output_file_name = "alpha_decay_" + int_to_str(dt) + ".dat";
    print.open(output_file_name.c_str(), ios::out);  // Open file for writing alpha decay data
    p2.open(("error_" + int_to_str(dt) + ".dat").c_str(), ios::out);  // Open file for writing error data

    // Write initial data to the output file
    print << 0 << gap << N << endl;

    end_loop = t / dt;  // Calculate the number of time steps

    // Loop to simulate the decay process
    for (int i = 1; i <= end_loop; i++) {
        N -= N * dt;  // Update the amount of alpha after each time step

        // Write the current time and amount of alpha to the output file
        print << i * dt << gap << N << endl;

        // Calculate and write the error (difference between numerical and analytical solution)
        p2 << i * dt << gap << fabs(N - N0 * (exp(-dt * i))) << endl;
    }

    // Output the results to the console
    cout << endl << "Steps: " << end_loop << endl;
    cout << "Remaining alpha: " << N << endl;
    cout << "Decayed alpha: " << N0 - N << endl;

    // Close the output files
    print.close();
    p2.close();
}

string int_to_str(double u) {
    // Function to convert a double to a string
    string name;
    stringstream convert;

    convert << u;  // Convert the double to a string
    name = convert.str();

    return name;  // Return the string
}