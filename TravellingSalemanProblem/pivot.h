#ifndef PIVOT_H
#define PIVOT_H

#include <QString>
#include <QBrush>
#include <QPen>

class pivot
{
public:
    pivot();
    QVector<QVector<int>> adj_matrix =
    {
        { 0, 14, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 42, 23 },
        { 19, 0, 0, 9, 0, 0 },
        { 0, 0, 0, 0, 0, 31 },
        { 0, 0, 18, 0, 0, 0 },
        { 28, 23, 0, 0, 0, 0 }
    };
};

#endif // PIVOT_H
