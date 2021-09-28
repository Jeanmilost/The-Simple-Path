import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as T

/**
* Embedded edit text area, used to edit a text in a contol
*@author Jean-Milost Reymond
*/
T.Control
{
    // aliases, allow access to children components
    property alias edit: edEdit

    // advanced properties
    property string m_Text:    ""
    property bool   m_Hovered: false
    property bool   m_Active:  false

    id: ctEdit

    /**
    * Text edit area
    */
    TextEdit
    {
        // common properties
        id: edEdit
        anchors.fill: parent
        anchors.margins: 2
        color: "#202020"
        font.family: "Arial"
        font.pointSize: 10
        wrapMode: TextEdit.WordWrap
        selectByMouse: true
        mouseSelectionMode: TextEdit.SelectCharacters
        activeFocusOnPress: true
        clip: true

        /**
        * Called when the text changed
        */
        onTextChanged:
        {
            // update the matching text
            m_Text = edEdit.text;

            // call the parent callback
            ctEdit.textChanged(edEdit.text);
        }

        /**
        * Called when the focus changed
        */
        onActiveFocusChanged:
        {
            // call the parent callback
            ctEdit.activeFocusChanged(edEdit.activeFocus);
        }

        /**
        * Called when the edition finished
        */
        onEditingFinished:
        {
            // call the parent callback
            ctEdit.editingFinished();
        }

        /**
        * The mouse area which will apply the correct state in relation to the current mouse status
        */
        MouseArea
        {
            // common properties
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
            propagateComposedEvents: true

            // mouse interaction callbacks
            onEntered:         {ctEdit.m_Hovered = true;}
            onExited:          {ctEdit.m_Hovered = false;}
            onPressed:         {ctEdit.m_Active  = true;  mouse.accepted = false;}
            onReleased:        {ctEdit.m_Active  = false; mouse.accepted = false;}
            onDoubleClicked:   {mouse.accepted   = false;}
            onPositionChanged: {mouse.accepted   = false;}
            onPressAndHold:    {mouse.accepted   = false;}
        }
    }

    /**
    * onTextChanged callback function to override
    *@param text - new text
    */
    function textChanged(text)
    {}

    /**
    * onActiveFocusChanged callback function to override
    *@param hasFocus - if true, the edit has the focus
    */
    function activeFocusChanged(hasFocus)
    {}

    /**
    * onEditingFinished callback function to override
    */
    function editingFinished()
    {}
}
