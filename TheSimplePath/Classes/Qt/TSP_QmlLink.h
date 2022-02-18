/****************************************************************************
 * ==> TSP_QmlLink ---------------------------------------------------------*
 ****************************************************************************
 * Description:  Qt link component                                          *
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

// core classes
#include "Core\TSP_Link.h"
#include "Core\TSP_Page.h"

// qt classes
#include "TSP_QmlLinkProxy.h"

/**
* Qt link component
*@author Jean-Milost Reymond
*/
class TSP_QmlLink : public TSP_Link
{
    public:
        /**
        * Constructor
        *@param pOwner - the page owner
        */
        TSP_QmlLink(TSP_Page* pOwner);

        /**
        * Constructor
        *@param title - component title
        *@param description - component description
        *@param comments - component comments
        *@param pOwner - component owner
        */
        TSP_QmlLink(const std::wstring& title,
                    const std::wstring& description,
                    const std::wstring& comments,
                          TSP_Page*     pOwner);

        virtual ~TSP_QmlLink();

        /**
        * Gets the link proxy
        *@return the link proxy, nullptr if no proxy
        */
        TSP_QmlLinkProxy* GetProxy() const;

        /**
        * Sets the link proxy
        *@param pProxy - the link proxy
        */
        void SetProxy(TSP_QmlLinkProxy* pProxy);

    private:
        TSP_QmlLinkProxy* m_pProxy = nullptr;
};
