#ifndef ROOMCARPET_H
#define ROOMCARPET_H

#include "RoomDimension.h"

class RoomCarpet
{
private:
    // Non-owning reference. The room must outlive this object.
    const RoomDimension& dimensions;
    double costPerSquareFoot;

public:
    RoomCarpet(const RoomDimension& room, double price);
    double getTotalCost() const;
};

#endif