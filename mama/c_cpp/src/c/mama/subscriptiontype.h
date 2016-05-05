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

#ifndef MAMA_SUBSC_TYPE_H__
#define MAMA_SUBSC_TYPE_H__

#include "wombat/port.h"
/*
 * This file provides subscription type information.
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
* Enumeration to describe the type of subscription made
*/
typedef enum mamaSubscriptionType
{
    MAMA_SUBSC_TYPE_NORMAL                   = 0, /**< Normal Subscription */
    MAMA_SUBSC_TYPE_GROUP                    = 1, /**< Group Subscription */
    MAMA_SUBSC_TYPE_BOOK                     = 2, /**< Book Subscription */
    MAMA_SUBSC_TYPE_BASIC                    = 3, /* No Market data */
    MAMA_SUBSC_TYPE_DICTIONARY               = 4, /**< Dictionary Subscription */
    MAMA_SUBSC_TYPE_SYMBOL_LIST              = 5, /**< Symbol List Subscription */
    MAMA_SUBSC_TYPE_SYMBOL_LIST_NORMAL       = 6, /**< Symbol List Subscription */
    MAMA_SUBSC_TYPE_SYMBOL_LIST_GROUP        = 7, /**< Symbol List Subscription */
    MAMA_SUBSC_TYPE_SYMBOL_LIST_BOOK         = 8 /**< Symbol List Subscription */
} mamaSubscriptionType;

MAMAExpDLL extern const char* MamaSubscTypeStr (mamaSubscriptionType subtype);

#if defined(__cplusplus)
}
#endif

#endif /* MAMA_SUBSC_TYPE_H__ */

