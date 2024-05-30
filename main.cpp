#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption open_file(QStringList() << "o" << "open", "open file", "image file");
    parser.addOption(open_file);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/image2ct/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    // if (parser.isSet(write_md_file)) {
    //     QString wfile = parser.value("w");
    //     app.activateWindow();
    //     app.mainWindow()->openFile(wfile);
    //     return app.exec();
    // }

    return app.exec();
}
