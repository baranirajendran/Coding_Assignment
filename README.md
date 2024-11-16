README: Weather Management and Median Calculation Applications

Overview
This project consists of two Python-based command-line applications:
1. Weather Management Application**: Interacts with the OpenWeather API to manage weather details for cities and perform operations like searching, favoriting, and updating cities.
2. Median Calculation Application**: Implements a sorting algorithm to compute the median of an array of numbers.

Files Included
1. `weather_predictions.py`: 
   - Manages weather details of cities using the OpenWeather API.
   - Implements functionalities such as:
     - Search weather for a city.
     - Add cities to favorites (max 3).
     - List favorite cities and their weather.
     - Update favorite cities.

2. `median_generation.py`:
   - Implements a sorting algorithm to sort an array and calculate its median.
   - Offers a simple interface to input an array of numbers or use predefined test cases.

Setup and Usage

1. Prerequisites:
   - Python 3.x installed on your machine.
   - Install dependencies using the command:
     ```bash
     pip install requests
     ```

2. Running the Applications:

   - Weather Management Application:
     1. Navigate to the directory containing the files.
     2. Run the application with:
        ```bash
        python3 weather_predictions.py
        ```
     3. Follow the on-screen prompts to:
        - Search for city weather.
        - Add, view, and update favorite cities.

   - Median Calculation Application:
     1. Navigate to the directory containing the files.
     2. Run the application with:
        ```bash
        python3 median_generation.py
        ```
     3. Input an array of numbers as prompted, or use the predefined test cases.
     4. The application will display the sorted array and its median.

Assignment Objective

Weather Management Application:
- Objective: Develop a CLI tool to interact with the OpenWeather API for managing city weather details.
- Features:
  - Search and retrieve current weather for a city.
  - Add cities to a favorite list (max 3).
  - List and display weather details for favorite cities.
  - Update the favorite list by removing and adding cities while maintaining the maximum limit.
- Evaluation Criteria:
  1. Effective API integration.
  2. Code readability and maintainability.
  3. Efficient problem-solving for managing the favorite list and handling API responses.

Median Calculation Application:
- Objective: Implement the pseudocode provided to calculate the median of an array.
- Features:
  - Sort an array of numbers using a chosen sorting algorithm.
  - Calculate and return the median.
  - Provide a user-friendly interface for input.
- Evaluation Criteria:
  1. Accuracy of pseudocode implementation.
  2. Code efficiency and clarity.
  3. Effective handling of inputs and output of results.

Notes
- Ensure to replace placeholder API keys (if any) with your actual OpenWeather API key in `weather_predictions.py`.
- Both programs are standalone and independent. You can test and use them separately.
