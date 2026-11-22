#include <iostream>
#include "FeetInches.h"
#include "RoomDimension.h"
#include "RoomCarpet.h"
#include <iomanip>

int main()
{
    FeetInches length(5, 6);
    FeetInches width(4, 3);

    FeetInches copy(length);
    std::cout << "Copied feet and inches: "
        << copy.getFeet() << ", " << copy.getInches() << '\n';

    copy.setFeet(9);
    std::cout << "Original feet: " << length.getFeet()
        << ", copied feet: " << copy.getFeet() << '\n';

    std::cout << "Area: " << length * width << " sq ft\n";
    RoomDimension room(length, width);
    length.setFeet(9);
    std::cout << "Room area: " << room.getArea() << " sq ft\n";
    RoomCarpet carpetAtFour(room, 4.0);
    RoomCarpet carpetAtEight(room, 8.0);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total at $4.00 per sq ft: $"
        << carpetAtFour.getTotalCost() << '\n';
    std::cout << "Total at $8.00 per sq ft: $"
        << carpetAtEight.getTotalCost() << '\n';
}