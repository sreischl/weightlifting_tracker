#ifndef JSONDBPARSER_H
#define JSONDBPARSER_H

#include "Types/Workout.h"
#include <QVector>

class JsonDbParser
{
public:
    static bool parseFrom(const QJsonDocument& jdoc, QVector<Workout> &parsedWorkouts);

private:
    JsonDbParser();
};

#endif // JSONDBPARSER_H
