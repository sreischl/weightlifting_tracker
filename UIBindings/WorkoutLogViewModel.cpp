#include "WorkoutLogViewModel.h"

WorkoutLogViewModel::WorkoutLogViewModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

void WorkoutLogViewModel::AddWorkout(const Workout& w)
{
  beginInsertRows(QModelIndex(), rowCount(), rowCount());

  m_workouts << w;

  endInsertRows();
}

// Override functions of QAbstractListModel
int WorkoutLogViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_workouts.count();
}

QVariant WorkoutLogViewModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_workouts.count())
        return QVariant();

    const Workout& selectedWorkout = m_workouts.at(index.row());

    switch (role) {
    case WORKOUTROLES_DATE:
      return selectedWorkout.dateString();

    case WORKOUTROLES_NOTE:
      return selectedWorkout.note();

    default:
      return QVariant();
    }
}

QHash<int, QByteArray> WorkoutLogViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[WORKOUTROLES_DATE] = "workoutDate";
    roles[WORKOUTROLES_NOTE] = "workoutNote";

    return roles;
}
