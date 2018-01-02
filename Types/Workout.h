#ifndef WORKOUT_H
#define WORKOUT_H

#include <QObject>
#include <QDateTime>

class Excercise
{
public:
    explicit Excercise()
    {}

    Excercise(const Excercise& other)
    {}

    virtual ~Excercise()
    {}
};

class Workout
{
//    Q_OBJECT

//    Q_PROPERTY(QString dateString READ dateString /*WRITE setDateString NOTIFY dateStringChanged*/)
//    Q_PROPERTY(QString note READ note /*WRITE setNote NOTIFY noteChanged*/)

public:
  explicit Workout(
      const uint32_t m_id,
      const QDateTime& m_date,
      const QString& m_note,
      const QList<Excercise>& m_excercises);

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
