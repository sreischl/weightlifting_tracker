import QtQuick 2.0

Item {
  ///
  /// PROPERTIES
  ///
  // Setter for list model
  property ListModel prop_workoutListModel: defaultWorkoutListModel

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
    id: defaultWorkoutListModel

    ListElement {
      date: "01.01.2017"
      description: "Workout A"
    }
    ListElement {
      date: "02.02.2017"
      description: "Workout B"
    }
    ListElement {
      date: "03.03.2017"
      description: "Workout C"
    }
  }

  ///
  /// DELEGATES
  ///
  Component {
    id: myListDelegate

    Row{
      width: workoutListView.width

      Column {
        Text {text: "<b>Date:</b> " + date }
        Text {text: "<b>Description:</b> " + description }
      }

      Column {
        Text {text: "<b>Note:</b> Sonstirgendwas" }
      }
    }
  }

  ///
  /// MAIN VIEW
  ///
  ListView {
    id: workoutListView
    anchors.fill: parent
    spacing: 3
    model: prop_workoutListModel
    delegate: myListDelegate

    focus: true
    highlight: Rectangle {color: "lightsteelblue"}
  }
}
