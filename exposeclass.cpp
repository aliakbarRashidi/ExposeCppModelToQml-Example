#include "exposeclass.h"

ExposeClass::ExposeClass(QObject *parent) : QObject(parent)
{
	// We assign our model to the model that we created in exposemodel.h
	m_model = new ExposeModel(this);

	// Here we add a few example data to model
	for (int i=0; i<5; ++i)
	{
		// Here we create the item we want to have the data
		QStandardItem *item = new QStandardItem;
		// Here we give the data to the item
		item->setData("Example "+QString::number(i+1), NameRole);
		//here we add the item to the model
		m_model->appendRow(item);
	}
}

QStandardItemModel *ExposeClass::model() const
{
	return m_model;
}

void ExposeClass::addNameToModel(const QString &name)
{
	// Here we create the item we want to have the data
	QStandardItem *item = new QStandardItem;
	// Here we give the data to the item
	item->setData(name, NameRole);
	//here we add the item to the model
	m_model->appendRow(item);
}

void ExposeClass::clearModel()
{
	m_model->clear();
}
