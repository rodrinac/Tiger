#include <QtDebug>

#include "../../src/tiger.hpp"
#include "../../src/reader.hpp"
#include "../../src/writer.hpp"

#include "../shared/player.hpp"

int main(int argc, char *argv[])
{
    qDebug() << "Using Tiger version " << Tiger::libVersion << endl;

    QJsonArray array {
        QJsonObject {{"id", 1}, {"name", "Matheux"}},
        QJsonObject {{"id", 2}, {"name", "Jorethe"}}
    };

    QList<Player *> ps = Tiger::Reader<Player>::instance().createEntityList(array);
    QJsonArray jsArray = Tiger::Writer<Player>::instance().getJsonArray(ps, true);

    for(auto &p : ps)
        qDebug() << p->toString();

    qDebug() << endl << jsArray;    
}
