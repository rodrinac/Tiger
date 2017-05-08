#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QObject>

class Player : public QObject
{
    Q_OBJECT // Neccessary to Qt's MetaObject System
    Q_PROPERTY(int id READ id WRITE setId) // Create property 'id'
    Q_PROPERTY(QString name READ name WRITE setName) // Create property 'name'
public:
    // Tiger need's entity classes to have a constructor to be called as Class a;
    explicit Player(QObject *parent = nullptr);

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    QString toString() const;

private:
    int m_id;
    QString m_name;
};

#endif // PLAYER_HPP
