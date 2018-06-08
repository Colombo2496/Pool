#include <QApplication>

#include "dialog.h"
#include "initializer.h"
#include "poolgame.h"
#include <QDebug>
#include "statistics.h"


int main(int argc, char *argv[])
{
//    player = new QMediaPlayer;
//    // ...
//    player->setMedia(QUrl::fromLocalFile("/Users/me/Music/coolsong.mp3"));
//    player->setVolume(50);
//    player->play();
    QApplication a(argc, argv);
    Dialog w;
    PoolGame* game = Initializer().createPoolgame("/Users/Juan/Documents/2018/Semester 1/INFO3220/Assignment/#3/PoolTable/config.json",&w);
    //if the returned game is a nullptr the json file couldn't be found or was invalid
    if(!game) return a.exec();
    Statistics stat(&w);
    stat.setUpPointers(game);
    w.show();
    w.start(game);
    return a.exec();
}
