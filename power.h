#ifndef POWER_H
#define POWER_H
#include <QGraphicsPixmapItem>
//Please make sure to run the app at least once and then
// move all the assets to the project build file for the
// program to work correctly

class power : public QGraphicsPixmapItem
{
private:

public:
    power();

    void setpower(int r, int c);
};
#endif // POWER_H
