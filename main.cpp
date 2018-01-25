#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <UIBindings/WorkoutLogViewModel.h>
#include <uitesthelper.h>

#include <JsonDbParser.h>


#include <QDebug>


int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    WorkoutLogViewModel logViewModel;
    logViewModel.AddWorkout(Workout(1, QDateTime::currentDateTime(), "note A", QList<Excercise>()));
    logViewModel.AddWorkout(Workout(1, QDateTime::currentDateTime(), "note b", QList<Excercise>()));
    logViewModel.AddWorkout(Workout(1, QDateTime::currentDateTime(), "note c", QList<Excercise>()));

    UiTestHelper uihelper(&logViewModel);

    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", &logViewModel);
    ctxt->setContextProperty("_uihelper", &uihelper);


    engine.load(QUrl(QStringLiteral("qrc:/UserInterface/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    /*
    QList<QObject*> dataList;
    dataList.append(new DataObject("Item 1", "red"));
    dataList.append(new DataObject("Item 2", "green"));
    dataList.append(new DataObject("Item 3", "blue"));
    dataList.append(new DataObject("Item 4", "yellow"));
    dataList.append(new DataObject("newShid", "übsilon"));

    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    */

#if 1
    QString workouts;
    QFile file;
    file.setFileName(":/db/workouts.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    workouts = file.readAll();
    file.close();

    QJsonDocument jdoc = QJsonDocument::fromJson(workouts.toUtf8());

    QVector<Workout> lstWorkouts;
    if (JsonDbParser::parseFrom(jdoc, lstWorkouts))
    {

    }


#endif


    return app.exec();
}
