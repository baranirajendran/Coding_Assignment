README: Running the Weather Application and Median Calculation Program

Overview

This repository contains two applications:

1. Weather Application: A command-line tool that interacts with the OpenWeather API to fetch, manage, and display weather information.
2. Median Calculation Program: A utility to sort a list of numbers and find their median.

 Prerequisites

- Compiler: A C++ compiler supporting C++17 (e.g., `g++`).
- Dependencies:
  - `libcurl`: Required for the Weather Application to make HTTP requests.
  - `nlohmann/json` header file for JSON parsing (included in the repository).

 Setup Instructions

 Step 1: Install Required Tools and Libraries

1. Install `libcurl`:
   - On macOS:
     ```bash
     brew install curl
     ```
   - On Linux:
     ```bash
     sudo apt-get install libcurl4-openssl-dev
     ```
   - On Windows:
     Use a package manager like `vcpkg` to install `libcurl`.

2. Include `json.hpp`:
   - Ensure the `json.hpp` file (from nlohmann JSON library) is in the same directory as the `weather_app.cpp`.

 Step 2: Set Environment Variables for `libcurl`

   ```bash
   export LDFLAGS="-L/usr/local/opt/curl/lib"
   export CPPFLAGS="-I/usr/local/opt/curl/include"
   ```

 Compilation and Execution

 1. Weather Application

1. Compile the Weather Application:
   ```bash
   g++ -std=c++17 weather_app.cpp -o weather_app -lcurl
   ```

2. Run the Weather Application:
   ```bash
   ./weather_app
   ```

 2. Median Calculation Program

1. Compile the Median Calculation Program:
   ```bash
   g++ -std=c++17 median_generation.cpp -o median_generation
   ```

2. Run the Median Calculation Program:
   ```bash
   ./median_generation
   ```

 Features

 Weather Application
- Search Weather: Fetch current weather for any city using the OpenWeather API.
- Manage Favourites:
  - Add cities to favourites (maximum of 3).
  - List all favourite cities with their weather details.
  - Update favourites by replacing an existing city.
- Caching: Weather data is cached for 5 minutes to minimize API requests.

 Median Calculation Program
- Sorting: Implements a sorting algorithm to arrange numbers in ascending order.
- Median Calculation:
  - Returns the median for a list of numbers.
  - Supports both odd and even-sized lists.

Notes
-Weather Application:
  - Replace the `API_KEY` placeholder in `weather_app.cpp` with your OpenWeather API key.
  - The program uses `nlohmann/json.hpp` for JSON parsing.

Median Calculation Program:
  - Input numbers are predefined or can be modified in the code.

Troubleshooting
- Ensure `libcurl` is correctly installed and its paths are set using `LDFLAGS` and `CPPFLAGS`.
- Ensure `json.hpp` is in the correct directory for the Weather Application.
- Use `g++ --version` to confirm your compiler supports C++17. Update if necessary.