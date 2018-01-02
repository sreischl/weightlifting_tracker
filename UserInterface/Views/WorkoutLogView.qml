import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
  ///
  /// PROPERTIES
  ///
  // Setter for list model
  property variant prop_workoutLogListModel: defaultWorkoutLogListModel

  ///
  /// SETTINGS
  ///
  anchors.fill: parent

//  // (Only for UI debugging purposes)
//  Rectangle {
//    anchors.fill: parent
//    color: "red"
//    border.color: "black"
//  }

  ///
  /// DEFAULTS
  ///
  ListModel {
    id: defaultWorkoutLogListModel

    ListElement {
      workoutDate: "01.01.2017"
      description: "Workout A"
      workoutNote: "note on workout A"
    }
    ListElement {
      workoutDate: "02.02.2017"
      description: "Workout B"
      workoutNote: "note on workout B"
    }
    ListElement {
      workoutDate: "03.03.2017"
      description: "Workout C"
      workoutNote: "note on workout C"
    }
  }

  ///
  /// DELEGATES
  ///
  Component {
      id: workoutLogListViewModel
    Item{
      width: workoutLogListView.width
      height: childrenRect.height

      Column {
        id: workoutInfo
        anchors.left: parent.left

        Text {text: "<b>Date:</b> " + workoutDate }
        Text {text: "<b>Note:</b> " + workoutNote }
      }

      // Change selected item on click
      MouseArea {
        anchors.fill: parent
        onClicked: {
          workoutLogListView.currentIndex = index
        }
      }

      Rectangle {
          id: workoutDetails
          color: "green"
          width: parent.width
          height: 0
          visible: false
          anchors.top: workoutInfo.bottom

          Text {
              text: "... here will be details..."
              anchors.centerIn: parent
          }
      }

      RoundButton {
        anchors.right: parent.right
        anchors.margins: 3
        height: 20
        width: 20
        text: "+"
        enabled: true

        onClicked: {
            if (text == "+")
            {
                text = "-"
                parent.height += 200
                workoutDetails.height += 200
                workoutDetails.visible = true
            }
            else
            {
                text = "+"
                parent.height -= 200
                workoutDetails.height -= 200
                workoutDetails.visible = false
            }
        }
      }
    }
  }

  ///
  /// MAIN VIEW
  ///
  ListView {
    id: workoutLogListView
    anchors.fill: parent
    spacing: 3
    model: prop_workoutLogListModel
    delegate: workoutLogListViewModel
//    delegate: Text { text: "Animal: " + type + ", " + size }

    focus: true
    highlightResizeDuration: 0    // Disable slow animation when resizing the delegate
    highlight: Rectangle {
        color: "lightsteelblue"
        radius: 2
        width: workoutLogListView.width
    }
  }
}
