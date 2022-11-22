#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include "franklin.h"
#include <QDir>
#include <QDebug>
//Please make sure to run the app at least once and then
// move all the assets to the project build file for the
// program to work correctly

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;

    view.setFixedSize(1200, 900);
    view.setWindowTitle("GTA 1");
    QBrush brush(Qt::darkBlue);
    view.setBackgroundBrush(brush);

    QFile file("map.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int boardData[17][23];
    QString temp;
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 23; j++)
        {
            stream >> temp;
            boardData[i][j] = temp.toInt();
        }

    QPixmap buildingImage1("building1.png");
    buildingImage1 = buildingImage1.scaledToWidth(50);
    buildingImage1 = buildingImage1.scaledToHeight(50);
    QPixmap buildingImage2("building2.png");
    buildingImage2 = buildingImage2.scaledToWidth(50);
    buildingImage2 = buildingImage2.scaledToHeight(50);

    QPixmap buildingImage3("building3.png");
    buildingImage3 = buildingImage3.scaledToWidth(50);
    buildingImage3 = buildingImage3.scaledToHeight(50);

    QPixmap buildingImage4("building4.png");
    buildingImage4 = buildingImage4.scaledToWidth(50);
    buildingImage4 = buildingImage4.scaledToHeight(50);


    QPixmap bricksImage("brick.png");
    bricksImage = bricksImage.scaledToWidth(50);
    bricksImage = bricksImage.scaledToHeight(50);

    QPixmap floorimage("road.png");
    floorimage = floorimage.scaledToWidth(50);
    floorimage = floorimage.scaledToHeight(50);


    QGraphicsPixmapItem boardItems[17][23];
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 23; j++)
        {
            // Set Image
            if (boardData[i][j] == 1001)
                boardItems[i][j].setPixmap(bricksImage);
            else if(boardData[i][j] == 1000){
                //RANDOMIZING MAP ASSESTS
                int x = rand()%4;
                if(x==0){boardItems[i][j].setPixmap(buildingImage1);}
                if(x==1){boardItems[i][j].setPixmap(buildingImage2);}
                if(x==2)boardItems[i][j].setPixmap(buildingImage3);
                if(x==3){boardItems[i][j].setPixmap(buildingImage4);}

            }
            else{
                boardItems[i][j].setPixmap(floorimage);}

            // Set Position
            boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

            // Add to the Scene
            scene.addItem(&boardItems[i][j]);
        }

    Player player(boardData, scene);
    scene.addItem(&player);



    player.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player.setFocus();




    view.setScene(&scene);
    view.show();
    return a.exec();
}
