#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H

#include "FeetInches.h"

class RoomDimension
{
private:
    FeetInches length;
    FeetInches width;

public:
    RoomDimension(const FeetInches& roomLength, const FeetInches& roomWidth);
    double getArea() const;
};

#endif