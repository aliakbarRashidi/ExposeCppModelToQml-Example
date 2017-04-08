#include <QGuiApplication>
#include <QQmlApplicationEngine>

// You must include this to use
#include <QQmlContext>

// Include your class
#include <exposeclass.h>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	// Here we create an instance of our class
	ExposeClass expose;

	QQmlApplicationEngine engine;

	//Here we expose both the class and the model to QML
	engine.rootContext()->setContextProperty("ExposeClass", &expose); /// The refrence infront of expose is because the "setContextProperty" function accept's a pointer to the object
	engine.rootContext()->setContextProperty("ExposeModel", expose.model());

	engine.load(QUrl(QLatin1String("qrc:/main.qml")));

	return app.exec();
}
