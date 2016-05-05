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

#ifndef MAMA_SYMBOL_SOURCE_CPP_H__
#define MAMA_SYMBOL_SOURCE_CPP_H__

#include "mama/mamacpp.h"

namespace Wombat 
{
    class MamaSymbolSourceCallback;  

    /**
     * MamaSymbolSource defines an interface which all SymbolSources should
     * implement in order to provide a mechanism by which objects implementing
     * the "MamaSymbolSourceCallback::onSymbol" can be registered with the source
     * such that they can be notified of new symbols as they arrive.
     */
    class MAMACPPExpDLL MamaSymbolSource
    {
    public:
        virtual ~MamaSymbolSource () {};

        virtual void addHandler (MamaSymbolSourceCallback* callback) = 0;
    };

} // namespace Wombat
#endif // MAMA_SYMBOL_SOURCE_CPP_H__
