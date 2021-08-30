/****************************************************************************
 * ==> RPM_Application -----------------------------------------------------*
 ****************************************************************************
 * Description:  The main application class                                 *
 * Contained in: Core                                                       *
 * Developer:    Jean-Milost Reymond                                        *
 ****************************************************************************
 * MIT License - todo FIXME -cFeature -oJean: Set the project name here     *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, sub-license, and/or sell copies of the Software, and to      *
 * permit persons to whom the Software is furnished to do so, subject to    *
 * the following conditions:                                                *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY     *
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,     *
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE        *
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                   *
 ****************************************************************************/

#pragma once

// qt
#include <QGuiApplication>
#include <QQmlApplicationEngine>

// core classes
#include "Core\RPM_Document.h"

/**
* Main application
*@author Jean-Milost Reymond
*/
class RPM_Application
{
    public:
        /**
        * Constructor
        *@param argc - argument count contained in argv
        *@param argv - argument vector passed by the user
        */
        RPM_Application(int argc, char* argv[]);

        virtual ~RPM_Application();

        /**
        * Gets the Qt application
        *@return the Qt application, nullptr if not found or on error
        */
        virtual QGuiApplication* GetQtApp() const;

        /**
        * Gets the Qt application engine
        *@return the Qt application engine, nullptr if not found or on error
        */
        virtual QQmlApplicationEngine* GetQtEngine() const;

        /**
        * Gets the main document
        *@return the main document, nullptr if not found or on error
        */
        virtual RPM_Document* GetDocument() const;

        /**
        * Executes the main application
        *@return success or error code
        */
        virtual int Execute();

    private:
        QGuiApplication*       m_pApp      = nullptr;
        QQmlApplicationEngine* m_pEngine   = nullptr;
        RPM_Document*          m_pDocument = nullptr;
};