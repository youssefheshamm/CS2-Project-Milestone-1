#include "thug.h"
//Please make sure to run the app at least once and then
// move all the assets to the project build file for the
// program to work correctly
thug::thug(){health =2; die = false;}
void thug::setthug(int mapData[17][23], int r, int c)
{
    // Set Image
    QPixmap npc("thug.png");
    npc = npc.scaledToWidth(50);
    npc = npc.scaledToHeight(50);
    setPixmap(npc);

    // Set Position
    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 23; j++)
            map[i][j] = mapData[i][j];


}

void thug:: resetpos(int r, int c){
row = r;
column = c;
setPos(50 + column * 50, 50 + row * 50);
}

void thug::move()
{
    bool x = false;
    int y;
    while(x==false){
        y=rand()%4;
        if(y==0){if(map[row-1][column]==1){row--; x=true;}}
        else if(y==1){if(map[row+1][column]==1){row++;; x=true;}}
        else if(y==2){if(map[row][column+1]==1){column++; x=true;}}
        else if(y==3){if(map[row][column-1]==1){column--; x=true;}}
    setPos(50 + column * 50, 50 + row * 50);}

}
