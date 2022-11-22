#include "franklin.h"

//Please make sure to run the app at least once and then
// move all the assets to the project build file for the
// program to work correctly

Player::Player(int boardData[17][23],QGraphicsScene &scene)
{
    // Set Image
    QPixmap image("player.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    health =3;
     enemies = 2;
    // Set Position
    row = 8;
    column = 11;
    invincible = false;
    stt= new QTimer(this);
    sttb= new QTimer(this);
    setPos(50 + column * 50, 50 + row * 50);
    // setting the health and the state text:
     ph = new QGraphicsTextItem("Health: " + QString::number(health));
    ph->setPos(50+2*50,50+0*50);
     QColor brush(Qt::white);
    ph->setDefaultTextColor(brush);
    QFont f("comic sans",25);
    ph->setFont(f);
    scene.addItem(ph);
    state = new QGraphicsTextItem("State: Normal");
   state->setPos(50+9*50,50+0*50);
    QColor stbrush(Qt::white);
   state->setDefaultTextColor(stbrush);
   QFont stf("comic sans",25);
   state->setFont(stf);
     scene.addItem(state);
    // Set data Array
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 23; j++)
            data[i][j] = boardData[i][j];

    t1.setthug(boardData,15,10);
    t2.setthug(boardData,15,12);

    scene.addItem(&t1);
    scene.addItem(&t2);

    b1.setbullet(1,1);
    b2.setbullet(1,21);
    b3.setbullet(15,1);
    b4.setbullet(15,21);
    scene.addItem(&b1);
    scene.addItem(&b2);
    scene.addItem(&b3);
    scene.addItem(&b4);

    p1.setpower(3,3);
    p2.setpower(9,18);
    scene.addItem(&p1);
    scene.addItem(&p2);

    displayt = new QTimer(this);
    connect(displayt,SIGNAL(timeout()),this,SLOT(display()));
    displayt->start(850);
    timetext = new QGraphicsTextItem("   ");
    timetext->setPos(50+17*50,50+0*50);
     QColor ttbrush(Qt::white);
    timetext->setDefaultTextColor(ttbrush);
    QFont ttf("comic sans",25);
    timetext->setFont(ttf);
    scene.addItem(timetext);
    n=5;

}
void Player:: display(){

    if(invincible==false){
        timetext->setPlainText(" ");
    }else {

        timetext->setPlainText("Timer: "+ QString::number(n));
        n--;
    }
}

void Player::imagereset(){
    QPixmap image("player.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
}
void Player::imagereset1(){
    QPixmap image("player.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
}

void Player::imagereset2(){
    QPixmap image("player.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
}

void Player::imagereset3(){
    QPixmap image("player.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
}


void Player::updatehealth(){
    health--;
    QString h="Health: "+ QString::number(health);
ph->setPlainText(h);
row=8;
column=11;
setPos(50 + column * 50, 50 + row * 50);
t1.resetpos(15,10);
t2.resetpos(15,12);
if(b1.exist==false){
   b1.setbullet(1,1);
   scene()->addItem(&b1);
}
if(b2.exist==false){
   b2.setbullet(1,21);
   scene()->addItem(&b2);
}
if(b3.exist==false){
   b3.setbullet(15,1);
   scene()->addItem(&b3);
}
if(b4.exist==false){
   b4.setbullet(15,21);
   scene()->addItem(&b4);
}

}
void Player::statereset(){
    n=5;
    state->setPlainText("State: Normal");
    invincible=false;
}
void Player::statereset1(){
    n=5;
    state->setPlainText("State: Normal");
    invincible=false;
}
void Player::endgame(){
       escape.setdoor(8, 11);
       escape.added=true;
   scene()->addItem(&escape);
}
void Player::keyPressEvent(QKeyEvent* event)
{
    if(health<=0){
        //scene()->removeItem(this);
        QGraphicsTextItem *d;
        d = new QGraphicsTextItem("DEFEAT :(");
       d->setPos(50+9*50,50+8*50);
        QColor brush(Qt::red);
       d->setDefaultTextColor(brush);
       QFont f("comic sans",50);
       d->setFont(f);
       scene()->addItem(d);
       scene()->removeItem(this);

    }
    if (event->key() == Qt::Key_Up && data[row - 1][column] == 1)
    {
        row--;
        t1.move();
        t2.move();
    }
    else if (event->key() == Qt::Key_Down && data[row + 1][column] == 1)
    {
        row++;
         t1.move();
         t2.move();
    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] == 1)
    {
        column++;
        t1.move();
        t2.move();
    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] == 1)
    {
        column--;
        t1.move();
        t2.move();
    }
    setPos(50 + column * 50, 50 + row * 50);

    QList<QGraphicsItem*> items = collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        if (typeid(*items[i]) == typeid(b1)&&row==1&&column==1){
            QPixmap image("shoot.png");
            image = image.scaledToWidth(50);
            image = image.scaledToHeight(50);
            setPixmap(image);

            connect(sttb, SIGNAL(timeout()),this,SLOT(imagereset()),Qt::UniqueConnection);
            sttb->start(1000);
            b1.exist=false;
            scene()->removeItem(&b1);
            if(t1.health>0){t1.health--;}
            else if(t2.health>0){t2.health--;}
        }
         if (typeid(*items[i]) == typeid(b2)&&row==1&&column==21){
             QPixmap image("shoot.png");
             image = image.scaledToWidth(50);
             image = image.scaledToHeight(50);
             setPixmap(image);
             connect(sttb, SIGNAL(timeout()),this,SLOT(imagereset1()),Qt::UniqueConnection);
             sttb->start(1000);
            b2.exist=false;
            scene()->removeItem(&b2);
            if(t1.health>0){t1.health--;}
            else if(t2.health>0){t2.health--;}
        }
         if (typeid(*items[i]) == typeid(b3)&&row==15&&column==1){
             QPixmap image("shoot.png");
             image = image.scaledToWidth(50);
             image = image.scaledToHeight(50);
             setPixmap(image);
             connect(sttb, SIGNAL(timeout()),this,SLOT(imagereset2()),Qt::UniqueConnection);
             sttb->start(1000);
            b3.exist=false;
            scene()->removeItem(&b3);
            if(t1.health>0){t1.health--;}
            else if(t2.health>0){t2.health--;}
        }
         if (typeid(*items[i]) == typeid(b4)&&row==15&&column==21){
             QPixmap image("shoot.png");
             image = image.scaledToWidth(50);
             image = image.scaledToHeight(50);
             setPixmap(image);
             connect(sttb, SIGNAL(timeout()),this,SLOT(imagereset3()),Qt::UniqueConnection);
             sttb->start(1000);
            b4.exist=false;
            scene()->removeItem(&b4);
            if(t1.health>0){t1.health--;}
            else if(t2.health>0){t2.health--;}
        }

        else if(typeid(*items[i]) == typeid(thug)&&this->invincible==false){

updatehealth();
        }else if(typeid(*items[i]) == typeid(power)){
         invincible=true;
         state->setPlainText("State: Invincible");
         bool timerready=true;
         if(timerready){

         connect(stt, SIGNAL(timeout()),this,SLOT(statereset()),Qt::UniqueConnection);
         stt->start(5000);
         scene()->removeItem(items[i]);
         timerready=false;}
         else{
             connect(stt, SIGNAL(timeout()),this,SLOT(statereset1()),Qt::UniqueConnection);
             stt->start(5000);
             scene()->removeItem(items[i]);
         }
         }
         else if(typeid(*items[i]) == typeid(door)){
             QGraphicsTextItem *vic;
             vic = new QGraphicsTextItem("VICTORY!");
            vic->setPos(50+9*50,50+8*50);
             QColor brush(Qt::cyan);
            vic->setDefaultTextColor(brush);
            QFont v("comic sans",50);
            vic->setFont(v);
            scene()->addItem(vic);
            scene()->removeItem(this);

         }

    }
    if(t1.health<=0&&t1.die==false){
         enemies--;
         t1.die=true;
      scene()->removeItem(&t1);

    }


    if(t2.health<=0&&t2.die==false){
         enemies--;
         t2.die=true;
      scene()->removeItem(&t2);

    }
    if(health<=0){
        //
        QGraphicsTextItem *d;
        d = new QGraphicsTextItem("DEFEAT :(");
       d->setPos(50+9*50,50+8*50);
        QColor brush(Qt::red);
       d->setDefaultTextColor(brush);
       QFont f("comic sans",50);
       d->setFont(f);
       scene()->addItem(d);
       scene()->removeItem(this);
    }
    if(enemies<=0&&escape.added==false){
        escape.added=true;
        endgame();
    }


}
