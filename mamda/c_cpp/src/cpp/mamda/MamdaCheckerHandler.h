/* $Id$
 *
 * OpenMAMA: The open middleware agnostic messaging API
 * Copyright (C) 2011 NYSE Technologies, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef MamdaCheckerHandlerH
#define MamdaCheckerHandlerH

#include <mamda/MamdaCheckerType.h>

namespace Wombat
{

    /**
     * MamdaCheckerHandler is an interface for applications that
     * want to handle the results of the MamdaQuoteChecker and 
     * MamdaTradeChecker. Callback interfaces are provided for correct
     * and erroneous checks.
     */
     
    class MamdaCheckerHandler
    {
    public:
        /**
         * Method invoked when a successful check is completed.
         */
        virtual void onSuccess (MamdaCheckerType  checkType) = 0;

        /**
         * Method invoked when check is completed inconclusively.  An
         * attempt to check the order book may be inconclusive if the
         * order book sequence numbers do not match up.
         */
        virtual void onInconclusive (MamdaCheckerType checkType,
                                     const char*      reason) = 0;

        /**
         * Method invoked when a failed check is completed.  The message
         * provided, if non-NULL, is the one received for the snapshot or
         * delta, depending upon the value of checkType.
         */
        virtual void onFailure (MamdaCheckerType  checkType,
                                const char*       reason,
                                const MamaMsg&    msg) = 0;
        
    };

} // namespace

#endif // MamdaCheckerHandlerH
