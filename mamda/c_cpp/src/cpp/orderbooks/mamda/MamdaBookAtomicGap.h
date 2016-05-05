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

#ifndef MamdaBookAtomicGapH
#define MamdaBookAtomicGapH

#include <mamda/MamdaOptionalConfig.h>
#include <mamda/MamdaBasicEvent.h>

namespace Wombat
{

    /**
     * MamdaBookAtomicGap is an interface that provides access to order book 
     * atomic update gap related fields.
     */
    class MAMDAOPTExpDLL MamdaBookAtomicGap : public MamdaBasicEvent
    {
    public:

        /**
         * The starting number of a detected sequence number gap in order book
         * updates from the feedhandler.
         *
         * @return Starting sequence number of a sequence number gap.
         */
        virtual mama_seqnum_t  getBeginGapSeqNum() const = 0;

        /**
         * The ending number of a detected sequence number gap in order book
         * updates from the feedhandler.
         *
         * @return Ending sequence number of a sequence number gap.
         */
        virtual mama_seqnum_t  getEndGapSeqNum()   const = 0;
        
        virtual ~MamdaBookAtomicGap() {};
    };

} // namespace

#endif // MamdaBookAtomicGapH
