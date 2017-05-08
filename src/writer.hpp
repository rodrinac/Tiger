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

#ifndef WRITER_HPP
#define WRITER_HPP

#include <QObject>
#include <QMetaProperty>
#include <QJsonArray>
#include <QJsonObject>
#include <QList>

namespace Tiger {

    /*!
     * \class Writer<Entity>
     * \abstract Converts a list of Entity objects in a JSON array
     */
    template<typename Entity>
    class Writer
    {
        // Entity need to be a Object child, otherwise the magic doesn't work
        static_assert(std::is_base_of<QObject, Entity>::value, "Entity need to be a QOject child.");
    public:

        /*!
            Writer is a singleton class.
            For every Entity class, a Writer will exist.
        */
        static Writer &instance()
        {
            static Writer writer;

            return writer;
        }

        /*!
            Converts Entity* in QJsonObject.
            QObject property 'objectName' may be excluded from parsing.
        */
        QJsonObject getJsonObject(Entity *entity, bool excludeObjectName = false)
        {
            const int size = Entity::staticMetaObject.propertyCount();

            QList<QMetaProperty> properties;
            QJsonObject jso;

            for (int i = 0; i < size; ++i)
                properties.append(Entity::staticMetaObject.property(i));

            for (int j = excludeObjectName? 1 : 0; j < size; ++j)
                jso.insert(properties[j].name(), QJsonValue::fromVariant(entity->property(properties[j].name())));

            return jso;
        }

        /*!
            Converts QList<Entity *> in QJsonArray.
            QObject property 'objectName' may be excluded from parsing.
        */
        QJsonArray getJsonArray(const QList<Entity *> &entities, bool excludeObjectName = false)
        {
            const int size = Entity::staticMetaObject.propertyCount();
            const int arraysize = entities.count();

            if(arraysize < 1)
                return QJsonArray();

            QList<QMetaProperty> properties;
            QJsonArray jsarray;

            for (int i = 0; i < size; ++i)
                properties.append(Entity::staticMetaObject.property(i));     

            for (auto e : entities) {
                QJsonObject jso;

                for (int j = excludeObjectName? 1 : 0; j < size; ++j)
                    jso.insert(properties[j].name(), QJsonValue::fromVariant(e->property(properties[j].name())));

                jsarray.append(jso);
            }

            return jsarray;
        }

    private:
        Writer() {
#ifdef TIGER_SUPER_VERBOSE
            qDebug("Tiger::Writer<%s> created", Entity::staticMetaObject.className());
#endif
        }
    };
}


#endif // WRITER_HPP
