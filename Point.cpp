//
// Created by Latandu on 26/04/2023.
//

#include "Point.h"

int Point::getRow() const {
    return row;
}

void Point::setRow(int row) {
    Point::row = row;
}

int Point::getColumn() const {
    return column;
}

void Point::setColumn(int column) {
    Point::column = column;
}
