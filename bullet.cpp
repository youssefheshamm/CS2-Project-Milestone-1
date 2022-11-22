#include "bullet.h"
//Please make sure to run the app at least once and then
// move all the assets to the project build file for the
// program to work correctly
bullet::bullet(){exist=true;}
void bullet::setbullet(int r, int c)
{
    // Set Image
    QPixmap image("bullet.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    // Set Position
      setPos(50 + c * 50, 50 + r * 50);
}
