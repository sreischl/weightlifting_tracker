#ifndef UITESTHELPER_H
#define UITESTHELPER_H

#include <UIBindings/WorkoutLogViewModel.h>

class UiTestHelper : public QObject
{
    Q_OBJECT
public:
    UiTestHelper(WorkoutLogViewModel* m)
        : QObject(nullptr),
          model(m)
    {}

public slots:
    inline void btnAddItem()
    {
        model->AddWorkout(Workout(2, QDateTime::currentDateTime(), "my new note", QList<Excercise>()));
    }

private:
    WorkoutLogViewModel* model;
};

#endif // UITESTHELPER_H
