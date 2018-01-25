import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import "Views/" as Views

Window {
  id: mainWindow
  visible: true
  width: 640
  height: 480
  title: qsTr("Hello World")

  Rectangle{
    anchors.fill: parent
    anchors.margins: 0
    color: "yellow"
  }

  GridLayout {
    anchors.fill: parent
    anchors.margins: 0
    columns: 2
    rows:3


    ///
    /// Buttons to switch views
    ///
    Button {
      text: "Show WorkoutListView"
      onClicked: {
        itemStackView.pop()
        itemStackView.focus = true
      }
    }
    Button {
      text: "Show Add workout"
      onClicked: {
        itemStackView.push(addWorkoutViewComp)
      }
    }

    Item {
      width: mainWindow.width
      height: 400
      Layout.columnSpan: 2

      StackView{
        id: itemStackView
        anchors.fill: parent
        focus: true
        initialItem: workoutListViewComp

        ///
        /// Components to be loaded
        ///
        Component{
          id: addWorkoutViewComp

          Views.AddWorkoutView{
              width: 300
              height: 300
          }
        }
        Component{
          id: workoutListViewComp

          Views.WorkoutLogView{
            id: workoutListView
            prop_workoutLogListModel: myModel
            anchors.margins: 5
          }
        }
      } // StackView
    }

    Button {
        text: "test"
        onClicked: _uihelper.btnAddItem()
    }
  }
}
