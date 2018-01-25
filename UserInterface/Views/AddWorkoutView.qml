import QtQuick 2.0
import QtQuick.Controls 1.4


Item {
  anchors.fill: parent

  Text {
    id: name
    text: qsTr("add workout view")
  }

  ListModel {
    id: testListModel

    ListElement {
      TU: "3"
      Sets: [
        ListElement {setvalue: "20/1/5"},
        ListElement {setvalue: "30/1/5"},
        ListElement {setvalue: "50/1/5"}
      ]
    }
    ListElement {
      TU: "6"
      Sets: [
        ListElement {setvalue: "20/1/5"},
        ListElement {setvalue: "30/1/5"},
        ListElement {setvalue: "40/2/3"},
        ListElement {setvalue: "50/1/5"}
      ]
    }
    ListElement {
      TU: "27"
      Sets: [
        ListElement {setvalue: "20/1/5"},
        ListElement {setvalue: "30/1/5"},
        ListElement {setvalue: "50/1/5"},
        ListElement {setvalue: "150/1/5"}
      ]
    }
  }

  Component
  {
    id: columnComponent
    TableViewColumn{
      width: 100
      title: "test"
    }
  }

  TableView {
    id: view
    anchors.fill: parent
    model: testListModel

    Component.onCompleted: resizeColumnsToContents()

    // Here we build views colums (in fact TableViewColumn's).
    // The "role" property gets ignored as the data filling is done within the
    // delegate.
    resources: {
      var temp = []
      for(var i = 0; i < 10; i++) // TODO: Add calculation of correct column count
      {
        if (i === 0)
          temp.push(columnComponent.createObject(view, { "title": "Turnübung" }))
        else
          temp.push(columnComponent.createObject(view, { "title": "Set " + i }))
      }
      return temp
    }

    itemDelegate: TextField {
      enabled: styleData.column === 0 ? false : true // first column: read-only
      text: {
        // Unitialization gives -1 as values
        if (styleData.row < 0 || styleData.column < 0)
          return "";

        // Direct data access via the model (json like)
        var data = testListModel.get(styleData.row);

        // First item is TU (see model)
        if (styleData.column === 0)
          return data.TU;

        // Take data directly from model
        // Column access requires -1 because first iteration will be TU.
        // So in order to not forget the first array entry in sets this is necessary.
        var element = data.Sets.get(styleData.column - 1)
        if (element)
          return element.setvalue; // Avoid errors when one excercise has less sets than another
      }
    }
  }
}
