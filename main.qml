import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
	visible: true
	width: 400
	height: 600
	title: qsTr("Hello World")

	ListView {
		anchors.fill: parent
		model: ExposeModel // Our C++ model

		delegate: ItemDelegate {
			text: nameRole // Defined in exposemodel.h
			width: parent.width
		}
	}

	footer: Row {
		id: row

		TextField {
			id: nameField
			placeholderText: "Enter Name"
			width: row.width-addButton.width-clearButton.width
		}

		Button {
			id: addButton
			text: "Add"

			onClicked: {
				// Here we add the nameField's text to our model
				// Via the C++ function addNameToModel
				// If the nameField's text is empty it won't add it to model

				if (nameField.text != "")
					ExposeClass.addNameToModel(nameField.text)

				// Here we clear the nameField's text
				nameField.clear()

				// Here we give the focus back to nameField
				nameField.focus = true
			}
		}

		Button {
			id: clearButton
			text: "Clear"

			onClicked: {
				// Here we clear our model
				ExposeClass.clearModel()

				// Here we give the focus back to nameField
				nameField.focus = true
			}
		}
	}
}
