#include "RoomDimension.h"

RoomDimension::RoomDimension(const FeetInches& roomLength,
    const FeetInches& roomWidth)
    : length(roomLength), width(roomWidth)
{
}

double RoomDimension::getArea() const
{
    return length * width;
}