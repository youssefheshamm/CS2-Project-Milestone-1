#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
//Please make sure to run the app at least once and then
// move all the assets to the project build file for the
// program to work correctly
class bullet : public QGraphicsPixmapItem
{
private:

public:
    bullet();
    bool exist;
    void setbullet(int r, int c);
};
#endif // BULLET_H
