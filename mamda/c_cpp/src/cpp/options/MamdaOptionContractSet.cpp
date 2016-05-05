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

#include <mamda/MamdaOptionContractSet.h>

namespace Wombat
{

    MamdaOptionContractSet::MamdaOptionContractSet ()
        : mBboContract       (NULL)
        , mWombatBboContract (NULL)
    {
    }

    MamdaOptionContractSet::~MamdaOptionContractSet ()
    {
    }

    void MamdaOptionContractSet::setBboContract (
        MamdaOptionContract*  contract)
    {
        mBboContract  = contract;
    }

    void MamdaOptionContractSet::setWombatBboContract (
        MamdaOptionContract*  contract)
    {
        mWombatBboContract  = contract;
    }

    void MamdaOptionContractSet::setExchangeContract (
        const char*           exchange,
        MamdaOptionContract*  contract)
    {
        operator[](exchange) = contract;
    }

    MamdaOptionContract* MamdaOptionContractSet::getBboContract () const
    {
        return mBboContract;
    }

    MamdaOptionContract* MamdaOptionContractSet::getWombatBboContract () const
    {
        return mWombatBboContract;
    }

    MamdaOptionContract* MamdaOptionContractSet::getExchangeContract (
        const char*  exchange) const
    {
        const_iterator found = find (exchange);
        if (found == end())
            return NULL;
        else
            return found->second;
    }

} // namespace
