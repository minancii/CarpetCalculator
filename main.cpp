#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "FeetInches.h"
#include "RoomDimension.h"
#include "RoomCarpet.h"

bool readMeasurement(const char* prompt, FeetInches& measurement)
{
    std::cout << prompt;

    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);

    int feet = 0;
    int inches = 0;
    if (!(input >> feet >> inches) || !(input >> std::ws).eof()
        || feet < 0 || inches < 0
        || feet > std::numeric_limits<int>::max() - inches / 12)
    {
        return false;
    }

    measurement.setFeet(feet);
    measurement.setInches(inches);
    return true;
}

void demonstrateFeetInches()
{
    FeetInches original(5, 6);
    FeetInches other(4, 3);
    FeetInches copy(original);

    std::cout << "\nOriginal: " << original << '\n';
    std::cout << "Copy: " << copy << '\n';

    copy.setFeet(9);
    std::cout << "After changing the copy: original = " << original
        << ", copy = " << copy << '\n';

    std::cout << "Multiplication demo: " << original * other << " sq ft\n";
}

int main()
{
    FeetInches length;
    FeetInches width;

    if (!readMeasurement("Enter room length (feet inches): ", length)
        || !readMeasurement("Enter room width (feet inches): ", width))
    {
        std::cerr << "Invalid measurement. Enter two nonnegative whole numbers.\n";
        return 1;
    }

    std::cout << "Enter carpet price per square foot: ";

    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    double price = 0.0;

    if (!(input >> price) || !(input >> std::ws).eof()
        || !std::isfinite(price) || price <= 0.0)
    {
        std::cerr << "Invalid price. Enter a number greater than zero.\n";
        return 1;
    }

    demonstrateFeetInches();

    RoomDimension room(length, width);
    RoomCarpet carpet(room, price);
    const double total = carpet.getTotalCost();

    if (!std::isfinite(total))
    {
        std::cerr << "The total cost is too large to display.\n";
        return 1;
    }

    std::cout << "\nRoom length: " << length << '\n';
    std::cout << "Room width: " << width << '\n';
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Room area: " << room.getArea() << " sq ft\n";
    std::cout << std::setprecision(2);
    std::cout << "Carpet price per square foot: $" << price << '\n';
    std::cout << "Total carpet cost: $" << total << '\n';

    return 0;
}