#include "Workout.h"

Workout::Workout(
    const uint32_t id,
    const QDateTime& date,
    const QString& note,
    const QList<Excercise>& excercises)
  : m_id(id),
    m_date(date),
    m_note(note),
    m_excercises(excercises)
{
}

Workout::Workout(const Workout& other)
    : Workout(other.m_id, other.m_date, other.m_note, other.m_excercises)
{
}

Workout& Workout::operator =(const Workout& other)
{
    return *this;
}

Workout::~Workout()
{
}

QString Workout::dateString() const
{
    return m_date.toString();
}

QString Workout::note() const
{
    return m_note;
}
