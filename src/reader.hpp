/*
    Copyright (C) 2017 José Rodrigo
    rodrigojose690@gmail.com

    Tiger is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Tiger is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef READER_HPP
#define READER_HPP

#include <QObject>
#include <QMetaProperty>
#include <QList>
#include <QJsonArray>
#include <QJsonObject>

namespace Tiger {

    /*!
     * \class Reader<Entity>
     * \abstract Converts a JSON array in a list of Entity objects
     */
    template<typename Entity>
    class Reader
    {
        // Entity need to be a Object child, otherwise the magic doesn't work
        static_assert(std::is_base_of<QObject, Entity>::value, "Entity need to be a QOject child.");
    public:

        /*!
            Reader is a singleton class.
            For every Entity class, a Reader will exist.
        */
        static Reader &instance()
        {
            static Reader reader;

            return reader;
        }

        /*!
            Converts QJsonObject in Entity*, allocating objects in head.
        */
        Entity * createEntity(const QJsonObject &jsobj)
        {
            const int size = Entity::staticMetaObject.propertyCount();

            QList<QMetaProperty> properties;
            auto entity = new Entity();

            for (int i = 0; i < size; ++i)
                properties.append(Entity::staticMetaObject.property(i));


            for (int j = 0; j < size; ++j)
                entity->setProperty(properties[j].name(), jsobj[properties[j].name()].toVariant());


            return entity;
        }

        /*!
            Converts QJsonArray in QList<Entity *>, allocating objects in head.
        */
        QList<Entity *> createEntityList(const QJsonArray &jsarray)
        {
            const int size = Entity::staticMetaObject.propertyCount();
            const int arraysize = jsarray.count();

            if(arraysize < 1)
                return QList<Entity *>();

            QList<QMetaProperty> properties;
            QList<Entity *> entities;            

            for (int i = 0; i < size; ++i)
                properties.append(Entity::staticMetaObject.property(i));

            for (int i = 0; i < arraysize; ++i) {
                auto e = new Entity();
                QJsonObject jso = jsarray[i].toObject();

                for (int j = 0; j < size; ++j)
                    e->setProperty(properties[j].name(), jso[properties[j].name()].toVariant());

                entities.append(e);

            }

            return entities;
        }

    private:
        Reader() {
#ifdef TIGER_SUPER_VERBOSE
            qDebug("Tiger::Reader<%s> created", Entity::staticMetaObject.className());
#endif
        }
    };
}

#endif // READER_HPP
