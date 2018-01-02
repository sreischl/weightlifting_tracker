#ifndef WORKOUTLOGVIEWMODEL_H
#define WORKOUTLOGVIEWMODEL_H

#include <QAbstractListModel>

#include <Types/Workout.h>

class WorkoutLogViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum WorkoutRoles
    {
        WORKOUTROLES_DATE = Qt::UserRole + 1,
        WORKOUTROLES_NOTE
    };

    explicit WorkoutLogViewModel(QObject *parent = nullptr);

    void AddWorkout(const Workout& w);

    // Override functions of QAbstractItemModel

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

protected:
    QHash<int, QByteArray> roleNames() const;

signals:

public slots:

private:
    QList<Workout> m_workouts;
};

#endif // WORKOUTLOGVIEWMODEL_H
