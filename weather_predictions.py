import requests
import time

API_KEY = "1d39a0abd7841b32fb2d5d2069dfe7f3"
BASE_URL = "http://api.openweathermap.org/data/2.5/weather"

# In-memory storage for favourite cities and cache
favourite_cities = []
weather_cache = {}  # Cache structure: {city_name: {"timestamp": <timestamp>, "data": <weather_data>}}
CACHE_EXPIRATION = 300  # Cache expiry time in seconds (5 minutes)


def get_weather(city_name):
    """Fetches weather details for a given city, using cache if available and valid."""
    current_time = time.time()

    # Check if city is in cache and not expired
    if city_name in weather_cache:
        cached_data = weather_cache[city_name]
        if current_time - cached_data["timestamp"] < CACHE_EXPIRATION:
            print(f"Using cached data for {city_name.capitalize()}:")
            display_weather(cached_data["data"])
            return

    # Fetch fresh data from API
    try:
        response = requests.get(BASE_URL, params={"q": city_name, "appid": API_KEY, "units": "metric"})
        data = response.json()

        if response.status_code == 200:
            # Cache the data
            weather_cache[city_name] = {"timestamp": current_time, "data": data}
            print(f"Weather in {city_name.capitalize()}:")
            display_weather(data)
        else:
            print(f"Error: {data['message']}")
    except Exception as e:
        print(f"An error occurred: {e}")


def display_weather(data):
    """Displays weather details."""
    print(f"Temperature: {data['main']['temp']}°C")
    print(f"Condition: {data['weather'][0]['description'].capitalize()}")


def update_favourites():
    """Prompts the user to replace an old city with a new one in the favourites list."""
    while True:
        old_city = input("Enter the city to remove from favourites: ").strip()
        if old_city in favourite_cities:
            break  # Exit the loop if the old city is in the list
        else:
            print(f"Error: {old_city.capitalize()} is not in your favourites list. Please try again.")
    
    new_city = input("Enter the new city to add to favourites: ").strip()
    favourite_cities.remove(old_city)
    favourite_cities.append(new_city)
    print(f"Replaced {old_city.capitalize()} with {new_city.capitalize()} in favourites!")


def add_to_favourites(city_name):
    """Adds a city to favourites if within the limit."""
    if len(favourite_cities) < 3:
        favourite_cities.append(city_name)
        print(f"{city_name.capitalize()} added to favourites!")
    else:
        print("Favourites list is full! Please update to add more cities.")


def list_favourites():
    """Lists favourite cities with their current weather details."""
    if not favourite_cities:
        print("No favourite cities added yet!")
        return

    print("Favourite Cities:")
    for city in favourite_cities:
        get_weather(city)


def main():
    """Main function to interact with the user."""
    while True:
        print("\nOptions:")
        print("1. Search for Weather Details")
        print("2. Add a City to Favourites")
        print("3. List Favourite Cities")
        print("4. Update Favourite Cities")
        print("5. Exit")
        
        choice = input("Enter your choice: ").strip()

        if choice == "1":
            city = input("Enter the city name: ").strip()
            get_weather(city)
        elif choice == "2":
            city = input("Enter the city name to add to favourites: ").strip()
            add_to_favourites(city)
        elif choice == "3":
            list_favourites()
        elif choice == "4":
            update_favourites()
        elif choice == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid choice! Please try again.")


if __name__ == "__main__":
    main()
