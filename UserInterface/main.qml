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
          ListView {
            width: 200; height: 250

//            model: myModel
            delegate: Text { text: "Animal: " + type + ", " + size }
          }

//          ListView {
//            id: view
//            anchors.fill: parent
//            model: 20

//            highlightFollowsCurrentItem: false    // force discarding default animation

//            delegate: Rectangle {
//              border.color: "steelblue"
//              color: Qt.lighter(border.color)
//              width: ListView.view.width
//              height: 20

//              Text { anchors.centerIn: parent; z: 2; text: index + 1 }

//              MouseArea {
//                anchors.fill: parent
//                onClicked: view.currentIndex = index
//              }
//            }

//            highlight: Rectangle {
//              border.color: "yellow"
//              border.width: 3
//              color: "transparent"
//              height: 20
//              width: ListView.view.width
//              y:  view.currentItem.y      // highlighting direct binding to selected item!
//              z: Infinity
//            }
//          }
//          Rectangle {

//            width: 300
//            height: 100
//            color: "green"
//          }
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
