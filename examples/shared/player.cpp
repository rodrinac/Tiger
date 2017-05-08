#include "player.hpp"

Player::Player(QObject *parent) : QObject(parent)
{

}

int Player::id() const
{
    return m_id;
}

void Player::setId(int id)
{
    m_id = id;
}

QString Player::name() const
{
    return m_name;
}

void Player::setName(const QString &name)
{
    m_name = name;
}

QString Player::toString() const
{
    return "Player { id = " + QString::number(m_id) + ", name = " + m_name + "}";
}
