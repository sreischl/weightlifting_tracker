#ifndef WORKOUT_H
#define WORKOUT_H

#include <QObject>
#include <QDateTime>


/**
 * @brief The Set struct
 *
 * "50/2/3" -> weight/sets/reps
 */
struct Set
{
public:
    uint32_t weight;
    uint32_t sets;
    uint32_t reps;
};

struct Excercise
{
public:
    uint32_t id; // Turnübung
    QList<Set> sets;
};

class Workout
{
public:
  explicit Workout(
      const uint32_t m_id,
      const QDateTime& m_date,
      const QString& m_note,
      const QList<Excercise>& m_excercises);
    Workout();

    Workout(const Workout& other);
    Workout& operator =(const Workout& other);

    virtual ~Workout();

    // Getter / Setter
    QString dateString() const;
    QString note() const;

signals:

public slots:

private:
    uint32_t m_id;
    QDateTime m_date;
    QString m_note;
    QList<Excercise> m_excercises;
};

#endif // WORKOUT_H
