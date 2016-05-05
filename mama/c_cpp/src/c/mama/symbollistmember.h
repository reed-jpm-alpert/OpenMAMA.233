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

#ifndef  MAMA_SYMBOL_LIST_MEMBER_H__
#define  MAMA_SYMBOL_LIST_MEMBER_H__

/* *************************************************** */
/* Includes. */
/* *************************************************** */
#include "mama/mama.h"
#include "mama/symbollisttypes.h"

#if defined(__cplusplus)
extern "C" {
#endif
    
/* *************************************************** */
/* Public Function Prototypes. */
/* *************************************************** */

/**
 * @brief This function will allocate a new symbol list member.
 * The returned member should be freed using mamaSymbolListMember_deallocate.
 *
 * @param[in] symbolList The parent symbol list that the member will
 *                       become part of.
 * @param[out] member To return the new member.
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */
MAMAExpDLL
extern mama_status
mamaSymbolListMember_allocate(
    mamaSymbolList symbolList,
    mamaSymbolListMember *member);

/**
 * @brief Frees a symbol list member previously created by a called to 
 * mamaSymbolListMember_allocate.
 *
 * @param[in] member The member to free. 
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */
MAMAExpDLL
extern mama_status
mamaSymbolListMember_deallocate(
    mamaSymbolListMember member);

/**
 * @brief This function returns the closure assocated with the symbol list member.
 *
 * @param[in] member The member to free. 
 * @param[out] closure The closure to return.
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */
MAMAExpDLL
extern mama_status
mamaSymbolListMember_getClosure(
    const mamaSymbolListMember member,
    void **closure);

int mamaSymbolListMember_getSize (void);

/**
 * @brief This function returns the source assocated with the symbol list member.
 *
 * @param[in] member The member to free. 
 * @param[out] source The source to return.
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */
MAMAExpDLL
extern mama_status
mamaSymbolListMember_getSource(
    const mamaSymbolListMember member, 
    const char **source);

/**
 * @brief This function returns the symbol assocated with the symbol list member.
 *
 * @param[in] member The member to free. 
 * @param[out] symbol The symbol to return.
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */
MAMAExpDLL
extern mama_status
mamaSymbolListMember_getSymbol(
    const mamaSymbolListMember member,
    const char **symbol);

/**
 * @brief This function returns the symbol list assocated with the symbol list member.
 *
 * @param[in] member The member to free. 
 * @param[out] symbolList The symbol list to return
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */
MAMAExpDLL
extern mama_status
mamaSymbolListMember_getSymbolList(
    const mamaSymbolListMember member,
    mamaSymbolList *symbolList);

/**
 * @brief This function returns the transport assocated with the symbol list member.
 *
 * @param[in] member The member to free. 
 * @param[out] transport To return the transport.
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */
MAMAExpDLL
extern mama_status
mamaSymbolListMember_getTransport(
    const mamaSymbolListMember member,
    mamaTransport *transport);

/**
 * @brief Set the closure assocated with the symbol list member.
 *
 * @param[in] member The symbollist member.
 * @param[in] closure The closure
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */

MAMAExpDLL
extern mama_status
mamaSymbolListMember_setClosure (mamaSymbolListMember  member,
                                 void*                 closure);

/**
 * @brief Set the source assocated with the symbol list member.
 *
 * @param[in] member The symbollist member.
 * @param[in] The source
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */

MAMAExpDLL
extern mama_status
mamaSymbolListMember_setSource (mamaSymbolListMember    member,
                                const char*             source);

/**
 * @brief Set the symbol assocated with the symbol list member.
 *
 * @param[in] member The symbollist member.
 * @param[in] The symbol
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */

MAMAExpDLL
extern mama_status
mamaSymbolListMember_setSymbol (mamaSymbolListMember    member,
                                const char*             symbol);

/**
 * @brief Set the symbol list assocated with the symbol list member.
 *
 * @param[in] member The symbollist member.
 * @param[in] The symbollist
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */

MAMAExpDLL
extern mama_status
mamaSymbolListMember_setSymbolList (mamaSymbolListMember  member,
                                    mamaSymbolList        symbolList);

/**
 * @brief This function sets the transport assocated with the symbol list member.
 *
 * @param[in] member The symbollist member.
 * @param[out] transport The transport
 *
 * @return mama_status value can be one of
 *          MAMA_STATUS_NULL_ARG
 *          MAMA_STATUS_OK
 */

MAMAExpDLL
extern mama_status
mamaSymbolListMember_setTransport (mamaSymbolListMember member,
                                   mamaTransport        transport);

#if defined(__cplusplus)
}
#endif


#endif

