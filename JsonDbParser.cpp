#include "JsonDbParser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QRegularExpression>

#include "Types/Workout.h"

//
// JSON DB Identifiers
//

// Workout depended identifiers
#define JSONDB_ID_DATE "date"
#define JSONDB_ID_NOTES "notes"
#define JSONDB_ID_EXCERCISES "excercises"

// Excercise depended identifiers
#define JSONDB_ID_EX_ID "id"
#define JSONDB_ID_EX_SETS "sets"

//
// Private helper functions
//
inline bool ValidateWorkout(const QJsonObject& jsonWorkout)
{
  if (jsonWorkout.contains(JSONDB_ID_DATE) && jsonWorkout[JSONDB_ID_DATE].isString()
          && jsonWorkout.contains(JSONDB_ID_NOTES) && jsonWorkout[JSONDB_ID_NOTES].isString()
          && jsonWorkout.contains(JSONDB_ID_EXCERCISES) && jsonWorkout[JSONDB_ID_EXCERCISES].isArray())
  {
      return true;
  }

  return false;
}


//
// Implementation
//

bool JsonDbParser::parseFrom(
        const QJsonDocument& jdoc,
        QVector<Workout>& parsedWorkouts)
{
  const QJsonObject& json = jdoc.object();

  if (json.contains("workouts") && json["workouts"].isArray())
  {
    const QJsonArray& jsonWorkouts = json["workouts"].toArray();

    foreach(const QJsonValue& jsonWorkoutVal, jsonWorkouts)
    {
      const QJsonObject& jsonWorkout = jsonWorkoutVal.toObject();

      // After this check was successful it is assumed that everything will be avilable
      // (excercises not validated within here)
      if (! ValidateWorkout(jsonWorkout))
      {
        // Skip invalid workout
        qWarning() << "Skipping invalid workout (Workout information invalid)";
        return false;
      }

      QList<Excercise> parsedExcercises;
      foreach (const QJsonValue& v, jsonWorkout[JSONDB_ID_EXCERCISES].toArray())
      {
        const QJsonObject& jsonEx = v.toObject();
        Excercise currEx;

        if (jsonEx.contains(JSONDB_ID_EX_ID)
            && jsonEx[JSONDB_ID_EX_ID].isDouble()
            && jsonEx.contains(JSONDB_ID_EX_SETS)
            && jsonEx[JSONDB_ID_EX_SETS].isArray())
        {
          // Excercise seems valid

          currEx.id = jsonEx[JSONDB_ID_EX_ID].toDouble();

          static const QRegularExpression regexSetComplete("^(\\d+)\\/(\\d+)\\/(\\d+)$");
//          static const QRegularExpression regexSetSingles("^(\\d+)\\/(\\d+)$");

          foreach (const QJsonValue& s, jsonEx[JSONDB_ID_EX_SETS].toArray())
          {
            const QRegularExpressionMatch& completeMatch = regexSetComplete.match(s.toString());

            if (completeMatch.hasMatch())
            {
              Set s;
              s.weight = completeMatch.capturedRef(1).toInt();
              s.sets = completeMatch.capturedRef(2).toInt();
              s.reps = completeMatch.capturedRef(3).toInt();

              currEx.sets.append(s);
            }
            else
            {
              qWarning() << "Skipping invalid set";
              return false;
            }
          }

          parsedExcercises.append(currEx);
        }
        else
        {
          qWarning() << "Skipping invalid workout (Excercise invalid)";
          return false;
        }
      }

      QDateTime dt; // parse fromjsonWorkout[JSONDB_ID_DATE])
      Workout currWorkout(1, dt, jsonWorkout[JSONDB_ID_NOTES].toString(), parsedExcercises);

      parsedWorkouts.append(currWorkout);
    }
  }

  return true;
}
