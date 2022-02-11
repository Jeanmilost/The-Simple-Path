/****************************************************************************
 * ==> TSP_QtGlobalMacros --------------------------------------------------*
 * **************************************************************************
 * Description : Macros collection depending on Qt which may be used        *
 *               globally                                                   *
 * Contained in: Qt                                                         *
 * Developer:    Jean-Milost Reymond                                        *
 ****************************************************************************
 * MIT License - The Simple Path                                            *
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

// common classes
#include "Common/TSP_Exception.h"

// qt
#include <QString>

/**
* Global translated messages related to Qt/Qml
*/
class TSP_QtGlobalMsg
{
    public:
        static const QString m_UnknownTitle;
        static const QString m_UnknownMsg;
};

/**
* Closing catch block, error message is sent to log
*/
#define M_CATCH_QT_MSG\
    catch (std::exception& e)\
    {\
        M_LogException("STD", e.what());\
        m_pApp->GetMainFormModel()->showError(TSP_QtGlobalMsg::m_UnknownTitle,\
                                              TSP_QtGlobalMsg::m_UnknownMsg,\
                                              e.what());\
    }\
    catch (...)\
    {\
        M_LogException(TSP_ExceptionFormatter::m_GenericTypeName, "Unknown exception");\
        m_pApp->GetMainFormModel()->showError(TSP_QtGlobalMsg::m_UnknownTitle,\
                                              TSP_QtGlobalMsg::m_UnknownMsg,\
                                              "Unknown exception");\
    }
