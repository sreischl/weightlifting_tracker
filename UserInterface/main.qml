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
    rows:2

    ///
    /// Buttons to switch views
    ///
    Button {
      text: "Show WorkoutListView"
      onClicked: {
//        itemStackView.clear()
//        itemStackView.push(workoutListViewComp)
        itemStackView.pop()
        itemStackView.focus = true
      }
    }
    Button {
      text: "Show Box"
      onClicked: {
        itemStackView.push(boxComp)
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
          id: boxComp
          Rectangle {

            width: 300
            height: 100
            color: "green"
          }
        }
        Component{
          id: workoutListViewComp
          Views.WorkoutListView{
            id: workoutListView
            anchors.margins: 5
          }
        }
      } // StackView

    }
  }
}
