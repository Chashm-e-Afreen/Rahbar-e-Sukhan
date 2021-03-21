#include "dummy_class.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QInputMethod>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlContext>
#include "fetch_dict.hpp"
#include "input.hpp"
#include "meters.hpp"
#include "Satoor.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/icon.svg"));
//    QScopedPointer<dummy_class> dummy(new dummy_class);
    QQmlApplicationEngine engine;

    dummy_class* dummy = new dummy_class();
    engine.rootContext()->setContextProperty("Dummy", dummy);
//    qmlRegisterSingletonInstance("Dummy", 1, 0, "Dummy", dummy.get());
    const QUrl url(QStringLiteral("qrc:/main.qml"));


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}


