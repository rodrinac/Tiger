#include <QtDebug>
#include <tiger>

#include "../shared/player.h"

int main()
{
    qDebug() << "Using Tiger version " << Tiger::libVersion << endl;

    auto p = Tiger::Reader<Player>::instance().createEntity({ {"id", 1}, {"name", "Phoenix"} });

    p->setObjectName("mainPlayer");

    QJsonObject jsobj = Tiger::Writer<Player>::instance().getJsonObject(p);

    qDebug() << p->toString();

    qDebug() << endl << jsobj;
}
