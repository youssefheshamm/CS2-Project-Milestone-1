#ifndef DOOR_H
#define DOOR_H
#include <QGraphicsPixmapItem>
//Please make sure to run the app at least once and then
// move all the assets to the project build file for the
// program to work correctly
class door : public QGraphicsPixmapItem
{
private:

public:
    door();
    void setdoor(int r, int c);
    bool added;
};
#endif // DOOR_H
