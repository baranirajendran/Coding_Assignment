def sort_and_find_median(numbers):
    """Sorts a list of numbers and finds the median."""
    # Sort the numbers
    numbers = sort(numbers)
    
    # Find the median
    n = len(numbers)
    if n % 2 == 0:
        # Even length: Average the two middle values
        return (numbers[n // 2 - 1] + numbers[n // 2]) / 2
    else:
        # Odd length: Return the middle value
        return numbers[n // 2]

def sort(numbers):
    """Sorts a list of numbers in ascending order using bubble sort."""
    n = len(numbers)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if numbers[j] > numbers[j + 1]:
                # Swap the elements
                numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
    return numbers

def run_predefined_test_cases():
    """Runs predefined test cases."""
    test_cases = {
        "Empty List": [],
        "Single Element": [42],
        "Two Elements": [7, 3],
        "Odd Number of Elements": [7, 1, 3, 9, 5],
        "Even Number of Elements": [10, 3, 5, 7],
        "Negative Numbers": [-3, -1, -7, -5],
        "Mixed Positive and Negative": [7, -3, 5, -1],
        "Already Sorted": [1, 2, 3, 4, 5],
        "Reverse Sorted": [9, 8, 7, 6, 5],
        "Large Dataset": list(range(1000, 0, -1)),  # Reverse ordered large dataset
    }

    print("Running Predefined Test Cases:\n")
    for case, numbers in test_cases.items():
        try:
            print(f"Case: {case}")
            print(f"Input: {numbers}")
            result = sort_and_find_median(numbers.copy())  # Use copy to avoid modifying the original list
            print(f"Median: {result}\n")
        except Exception as e:
            print(f"Error: {e}\n")

def run_custom_input():
    """Accepts custom input from the user and calculates the median."""
    print("Custom Input:\n")
    try:
        user_input = input("Enter a list of numbers separated by spaces: ")
        numbers = list(map(float, user_input.split()))
        result = sort_and_find_median(numbers)
        print(f"Median: {result}")
    except ValueError as ve:
        print(f"Error: {ve}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

def main():
    """Main function to prompt user for choice and execute accordingly."""
    print("Choose an option:")
    print("1. Run Predefined Test Cases")
    print("2. Provide Custom Input")

    try:
        choice = int(input("Enter your choice (1 or 2): ").strip())
        if choice == 1:
            run_predefined_test_cases()
        elif choice == 2:
            run_custom_input()
        else:
            print("Invalid choice! Please enter 1 or 2.")
    except ValueError:
        print("Invalid input! Please enter a numeric choice (1 or 2).")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

# Entry point of the program
if __name__ == "__main__":
    main()
