#include "door.h"
//Please make sure to run the app at least once and then
// move all the assets to the project build file for the
// program to work correctly
door::door(){}
void door::setdoor(int r, int c)
{
    // Set Image
    QPixmap image("door.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    // Set Position
      setPos(50 + c * 50, 50 + r * 50);

      added=false;
}
