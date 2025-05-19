#include <iostream>
#include <string>

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0/9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0/5.0 + 32;
}

void printError(const std::string &msg) {
    std::cout << "Error: " << msg << "\n";
}

bool isValidUnit(char c) {
    return (c == 'F' || c == 'C' || c == 'K');
}

int tempConverter() {
    std::string s;
    char target;
    char unit;
    double temperature;
    double result = 0.0;

    std::cout << "The temperature value: ";
    if (!(std::cin >> temperature)) {
        printError("Invalid numeric input");
        return 1;
    }
    std::cout << "The current unit (C, F, or K): ";
    std::cin >> s;
    if (s.length() != 1) {
        printError("There must be exactly one character for the unit");
        return 1;
    }
    unit = s[0];

    std::cout << "The target unit (C, F, or K): ";
    std::cin >> s;
    if (s.length() != 1) {
        printError("There must be exactly one character for the target");
        return 1;
    }
    target = s[0];
    if (!isValidUnit(unit) || !isValidUnit(target)) {
        printError("Only C, F, or K are accepted");
        return 1;
    }
    if (unit == target) {
        result = temperature;
    } else if (unit == 'C' && target == 'F') {
        result = celsiusToFahrenheit(temperature);
    } else if (unit == 'C' && target == 'K') {
        result = celsiusToKelvin(temperature);
    } else if (unit == 'F' && target == 'C') {
        result = fahrenheitToCelsius(temperature);
    } else if (unit == 'F' && target == 'K') {
        result = fahrenheitToKelvin(temperature);
    } else if (unit == 'K' && target == 'C') {
        result = kelvinToCelsius(temperature);
    } else if (unit == 'K' && target == 'F') {
        result = kelvinToFahrenheit(temperature);
    } else {
        printError("Unsupported conversion");
        return 1;
    }
    std::cout << "The result: " << result << "\n";
    return 0;
}

int main() {
	std::string response;
    while (true) {
        if (std::cin.eof()){
            std::cin.clear();
        }
        if (tempConverter() != 0) {
            std::cout << "Conversion failed. Please try again.\n";
        }
        std::cout << "Do you want to convert another temperature? (y/n): ";
        std::cin >> response;
        if (response != "y" && response != "Y") {
            break;
        }
    }
    return 0;
}