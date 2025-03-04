# Alpha Decay Simulation in C++

This project simulates the alpha decay process using a simple numerical approach in C++. The program calculates the remaining amount of alpha particles over time, given an initial amount, time step, and total duration. It also computes the error between the numerical solution and the analytical solution for comparison.

---

## Table of Contents
1. [Introduction](#introduction)
2. [How It Works](#how-it-works)
3. [Code Structure](#code-structure)
4. [Usage](#usage)
5. [Results](#results)
6. [Dependencies](#dependencies)

---

## Introduction

Alpha decay is a type of radioactive decay where an unstable atomic nucleus emits an alpha particle (consisting of 2 protons and 2 neutrons). This process reduces the mass number of the nucleus by 4 and the atomic number by 2. The decay follows an exponential law, which can be modeled using differential equations.

This C++ program simulates the alpha decay process numerically, allowing users to input the initial amount of alpha particles, the time step, and the total duration of the simulation. The program outputs the remaining amount of alpha particles at each time step and calculates the error compared to the analytical solution.

---

## How It Works

The simulation is based on the differential equation for alpha decay:

\[
\frac{dN}{dt} = -N
\]

Where:
- \( N \) is the amount of alpha particles.
- \( t \) is time.

The program uses a simple numerical approach to approximate the solution:
1. The user inputs the initial amount of alpha particles (\( N_0 \)), the time step (\( dt \)), and the total duration (\( t \)).
2. The program iteratively calculates the remaining amount of alpha particles at each time step using the formula:
   \[
   N(t + \Delta t) = N(t) - N(t) \cdot \Delta t
   \]
3. The program also calculates the error between the numerical solution and the analytical solution:
   \[
   N_{\text{analytical}}(t) = N_0 \cdot e^{-t}
   \]
4. The results are saved in two output files: one for the decay data and one for the error data.

---

## Code Structure

The project consists of a single C++ file with the following structure:
- **`alpha_decay()`**: The main function that performs the simulation. It takes user input, performs the calculations, and writes the results to output files.
- **`int_to_str(double u)`**: A utility function that converts a double to a string. This is used to generate output file names based on the time step.
- **`main()`**: Calls the `alpha_decay()` function to run the simulation.

---

## Usage

1. Clone the repository or download the `alpha_decay.cpp` file.
2. Compile the code using a C++ compiler:
   ```bash
   g++ alpha_decay.cpp -o alpha_decay
3. Run:
   ./alpha_decay
---

## Results

The program outputs the decay data and error data, which can be plotted to visualize the alpha decay process. The results show that smaller time steps produce more accurate numerical solutions, as expected.

Example output for initial alpha = 100, duration = 5, and time step = 0.1:
- **Decay Data**: `alpha_decay_0.1.dat`
- **Error Data**: `error_0.1.dat`

---

## Dependencies

- **C++ Compiler**: The code requires a C++ compiler (e.g., `g++`).
- **Standard Libraries**: The program uses the following C++ standard libraries:
  - `<iostream>` for input/output.
  - `<fstream>` for file handling.
  - `<string>` and `<sstream>` for string manipulation.
  - `<cmath>` for mathematical functions.
