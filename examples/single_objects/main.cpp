#include <QtDebug>

#include "../../src/tiger.hpp"
#include "../../src/reader.hpp"
#include "../../src/writer.hpp"

#include "../shared/player.hpp"

int main(int argc, char *argv[])
{
    qDebug() << "Using Tiger version " << Tiger::libVersion << endl;

    QJsonObject jsobj {
        {"id", 1},
        {"name", "Matheux"}
    };

    Player * p = Tiger::Reader<Player>::instance().createEntity(jsobj);

    p->setObjectName("MyPlayer");

    QJsonObject jsObj = Tiger::Writer<Player>::instance().getJsonObject(p);

    qDebug() << p->toString();

    qDebug() << endl << jsObj;
}
