//
// Created by Latandu on 26/04/2023.
//

#ifndef JAKDOJADE_POINT_H
#define JAKDOJADE_POINT_H


class Point {
private:
    int row, column;
public:
    int getRow() const;

    void setRow(int row);

    int getColumn() const;

    void setColumn(int column);
};


#endif //JAKDOJADE_POINT_H
