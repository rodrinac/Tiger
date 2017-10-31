#include <QtDebug>
#include <tiger>

#include "../shared/player.h"

int main(int argc, char *argv[])
{
    qDebug() << "Using Tiger version " << Tiger::libVersion << endl;

    QJsonArray jsarray {
        QJsonObject { {"id", 1}, {"name", "Phoenix"} },
        QJsonObject { {"id", 2}, {"name", "Jorethe"} }
    };

    QList<Player *> ps = Tiger::Reader<Player>::instance().createEntityList(jsarray);
    jsarray = Tiger::Writer<Player>::instance().getJsonArray(ps, true);

    for(auto p : ps)
        qDebug() << p->toString();

    qDebug() << endl << jsarray;
}
