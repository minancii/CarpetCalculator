#include "RoomCarpet.h"

RoomCarpet::RoomCarpet(const RoomDimension& room, double price)
    : dimensions(room), costPerSquareFoot(price)
{
}

double RoomCarpet::getTotalCost() const
{
    return dimensions.getArea() * costPerSquareFoot;
}