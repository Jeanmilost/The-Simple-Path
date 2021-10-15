import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as T

/**
* Connector, used to connect two symbols with a message
*@author Jean-Milost Reymond
*/
T.Control
{
    // aliases
    property alias connectorRect: rcConnector

    // advanced properties
    property var m_Source: null
    property var m_Target: null

    // common properties
    id: ctConnector
    width: 14
    height: 14

    /**
    * Connector rectangle
    */
    Rectangle
    {
        // common properties
        id: rcConnector
        anchors.fill: parent
        color: "transparent"
        border.color: "#c0c0c0"
        border.width: 3
        radius: 7
    }

    /**
    * Connector mouse area
    */
    MouseArea
    {
        // common properties
        id: maConnector
        anchors.fill: parent
        cursorShape: Qt.CrossCursor
        acceptedButtons: Qt.LeftButton
        hoverEnabled: true
    }
}