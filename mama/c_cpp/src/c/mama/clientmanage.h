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

#ifndef MAMA_CLIENT_MANAGE_H__
#define MAMA_CLIENT_MANAGE_H__

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * FIDS and Command IDs for client management commands
 */

/** FIDS */

/** Client Management Request Get Sent HERE */
#define MAMA_CM_TOPIC       "__MAMA_CM"
#define MAMA_CM_PUB_TOPIC   "__MAMA_PUB_CM"

/** The SyncResponder puts the topics in a string array with this ID */
#define MAMA_SYNC_TOPICS_ID                 101

/** Future: We may add other (possibly wadmin style) commands  U16*/
#define MAMA_CM_COMMAND_ID                  102

/** Client only sends topics for this SOURCE */
#define MAMA_SYNC_SOURCE_ID                 103

/** Client responds with max TOPICS_PER_MSG  U16 */
#define MAMA_SYNC_TOPICS_PER_MSG_ID         104

/** Clients waits random interval \> 0 \< RESPONSE_DELAY before initiating
 * response.
 */
#define MAMA_SYNC_RESPONSE_DELAY_ID         105

/** Clients send response over this duration */
#define MAMA_SYNC_RESPONSE_DURATION_ID      106

/**The SyncResponder puts the subscription types in a string array with this ID*/
#define MAMA_SYNC_TYPES_ID                 107

/** Commands */

/**
 *@brief The enumeration of supported commands
 */    

typedef enum 
{
    MAMA_COMMAND_SYNC = 1 /** Sync Request */
} mamaCmCommand;

/**
 * @brief The function prototype for command
 */

typedef void (*cmCommandDtor)(void* handle);

/**
 * @brief This structure allows for generic commands to be destroyed by the
 * clientmanageresponder.
 *
 * @param[in] mHandle Command handler
 * @param[in] mDtor   Callback destructor
 *
 * @details It is not correct for the commands to destroy themselves on completion
 * since the responder creates them. Furthermore, there would be problems at
 * shutdown.
 *
 * Every command needs to populate this structure accordingly.
 *
 */

typedef struct
{
    void*         mHandle;
    cmCommandDtor mDtor; 
} mamaCommand;

/**
 * @brief Commands invoke this callback when they complete so the responder can
 * destroy them.
 * 
 * @param[in] command The sync command
 * @param[in] closure User supplied data
 */
typedef void (*mamaCommandEndCB)(mamaCommand* command, void *closure);

#if defined(__cplusplus)
}
#endif

#endif /* MAMA_CLIENT_MANAGE_H__ */
