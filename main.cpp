#include <QApplication>

#include "dialog.h"
#include "initializer.h"
#include "poolgame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    PoolGame* game = Initializer().createPoolgame("../PoolTable/config.json",&w);

    //if the returned game is a nullptr the json file couldn't be found or was invalid
    if(!game) return a.exec();
    w.show();
    w.start(game);

    return a.exec();

}
