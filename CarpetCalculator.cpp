#include <iostream>
#include "FeetInches.h"
#include "RoomDimension.h"

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
}