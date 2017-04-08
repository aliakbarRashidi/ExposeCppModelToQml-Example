#ifndef EXPOSECLASS_H
#define EXPOSECLASS_H

// We include our model here
#include <exposemodel.h>

#include <QObject>
#include <QStandardItemModel>

class ExposeClass : public QObject
{
	Q_OBJECT

	// This is the model that we want to expose to QML
	QStandardItemModel *m_model;

public:
	// Our data enum containing our roles
	enum DataRoles {
		NameRole = Qt::UserRole+1,
	};

	explicit ExposeClass(QObject *parent = 0);

	// The getter for our model
	QStandardItemModel *model() const;

public slots:
	// The names explain themselves
	void addNameToModel(const QString &name);
	void clearModel();
};

#endif // EXPOSECLASS_H
