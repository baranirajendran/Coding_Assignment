#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <curl/curl.h>
#include "json.hpp" // Include nlohmann JSON library

using json = nlohmann::json;
using namespace std;

const string API_KEY = "1d39a0abd7841b32fb2d5d2069dfe7f3";
const string BASE_URL = "http://api.openweathermap.org/data/2.5/weather";
const int CACHE_EXPIRATION = 300; // Cache expiry time in seconds (5 minutes)

// Global variables for favorite cities and cache
vector<string> favourite_cities;
unordered_map<string, pair<time_t, json>> weather_cache;

// Function to write data from curl to a string
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

// Function to make HTTP requests
string make_request(const string& url) {
    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return response;
}

// Function to display weather data
void display_weather(const json& data) {
    cout << "Temperature: " << data["main"]["temp"] << "°C" << endl;
    cout << "Condition: " << data["weather"][0]["description"].get<string>() << endl;
}

// Function to fetch weather details
void get_weather(const string& city_name) {
    time_t current_time = time(nullptr);

    // Check if city is in cache and not expired
    if (weather_cache.find(city_name) != weather_cache.end()) {
        auto cached_data = weather_cache[city_name];
        if (current_time - cached_data.first < CACHE_EXPIRATION) {
            cout << "Using cached data for " << city_name << ":" << endl;
            display_weather(cached_data.second);
            return;
        }
    }

    // Fetch fresh data from API
    try {
        string url = BASE_URL + "?q=" + city_name + "&appid=" + API_KEY + "&units=metric";
        string response = make_request(url);
        json data = json::parse(response);

        if (data.contains("main")) {
            // Cache the data
            weather_cache[city_name] = {current_time, data};
            cout << "Weather in " << city_name << ":" << endl;
            display_weather(data);
        } else {
            cout << "Error: " << data["message"].get<string>() << endl;
        }
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
}

// Function to update favorites
void update_favourites() {
    string old_city, new_city;

    while (true) {
        cout << "Enter the city to remove from favourites: ";
        getline(cin, old_city);

        auto it = find(favourite_cities.begin(), favourite_cities.end(), old_city);
        if (it != favourite_cities.end()) {
            favourite_cities.erase(it);
            break;
        } else {
            cout << "Error: " << old_city << " is not in your favourites list. Please try again." << endl;
        }
    }

    cout << "Enter the new city to add to favourites: ";
    getline(cin, new_city);
    favourite_cities.push_back(new_city);
    cout << "Replaced " << old_city << " with " << new_city << " in favourites!" << endl;
}

// Function to add a city to favourites
void add_to_favourites(const string& city_name) {
    if (favourite_cities.size() < 3) {
        favourite_cities.push_back(city_name);
        cout << city_name << " added to favourites!" << endl;
    } else {
        cout << "Favourites list is full! Please update to add more cities." << endl;
    }
}

// Function to list favourite cities
void list_favourites() {
    if (favourite_cities.empty()) {
        cout << "No favourite cities added yet!" << endl;
        return;
    }

    cout << "Favourite Cities:" << endl;
    for (const auto& city : favourite_cities) {
        get_weather(city);
    }
}

// Main function
void main_menu() {
    string choice;

    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Search for Weather Details" << endl;
        cout << "2. Add a City to Favourites" << endl;
        cout << "3. List Favourite Cities" << endl;
        cout << "4. Update Favourite Cities" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        getline(cin, choice);

        if (choice == "1") {
            string city;
            cout << "Enter the city name: ";
            getline(cin, city);
            get_weather(city);
        } else if (choice == "2") {
            string city;
            cout << "Enter the city name to add to favourites: ";
            getline(cin, city);
            add_to_favourites(city);
        } else if (choice == "3") {
            list_favourites();
        } else if (choice == "4") {
            update_favourites();
        } else if (choice == "5") {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}

int main() {
    main_menu();
    return 0;
}
