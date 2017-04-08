#ifndef EXPOSEMODEL_H
#define EXPOSEMODEL_H

// Here we create a class based on QStandardItemModel
// And give it our data roles

#include <QStandardItemModel>

class ExposeModel : public QStandardItemModel
{
	Q_OBJECT

public:
	// Our data enum containing our roles
	enum DataRoles {
		NameRole = Qt::UserRole+1,
	};

	ExposeModel(QObject *parent = 0)
		: QStandardItemModel(parent)
	{
	}

protected:
	// We Override this function to return our roles to QML
	QHash<int, QByteArray> roleNames() const
	{
		QHash<int, QByteArray> m_roles;

		// We do this for every data role
		m_roles[NameRole] = "nameRole";

		return m_roles;
	}

};

#endif // EXPOSEMODEL_H
