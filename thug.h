#ifndef THUG_H
#define THUG_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
//Please make sure to run the app at least once and then
// move all the assets to the project build file for the
// program to work correctly

class thug : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row, column;
    int map[17][23];

public:
    thug();
    void setthug(int mapData[17][23], int r, int c);
    int health;
    bool die;
void resetpos(int r, int c);
public slots:
      void move();

};
#endif // THUG_H
