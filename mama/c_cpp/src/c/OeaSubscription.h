/** \file OeaSubscription.h
 * The declaration of the OEA user subscription
 * and associated methods/functions.
 *
 * @author  Martin Downey
 * @version $Revision: #6 $
 *          $DateTime: 2013/05/15 06:58:01 $
 */
#ifndef OEA_SUBSCRIPTION_H__
#define OEA_SUBSCRIPTION_H__

/**
 *
 * INCLUDE DIRECTIVES
 *
 */
#ifdef WIN32
#include "OeaWin.h"
#else
#define OEAExpDLL
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * market data delivery mode timeliness types.
 */
typedef enum
{
    /** Data is delivered in delayed mode. */
    OEA_DELAYED  = 1,

    /** Data is delivered in real-time mode. */
    OEA_REALTIME = 2
} OEA_TIMELINESS_TYPE;

/**
 * Represents a user subscription to market data.
 */
typedef struct _oeaSubscription oeaSubscription;

/**
 * Set the delivery mode timeliness value of the subscription.
 *
 * @pre  0 != aOeaSubscription
 * @pre  !oeaSubscription_hasBeenOpened(aOeaSubscription)
 *
 * @post The delivery mode timeliness value for
 *       \c aOeaSubscription equals \c aTimeliness.
 */
extern OEAExpDLL void oeaSubscription_setTimeliness(
    oeaSubscription* const aOeaSubscription,
    const OEA_TIMELINESS_TYPE aTimeliness);

/**
 * Set the 'is snapshot' indicator of the subscription.
 *
 * @pre  0 != aOeaSubscription
 * @pre  !oeaSubscription_hasBeenOpened(aOeaSubscription)
 *
 * @post <ul>
 *       <li>
 *       If \c aIsSnapshot holds the value 0 then
 *       the 'is snapshot' indicator for
 *       \c aOeaSubscription equals 0
 *       (to indicate streaming delivery mode),
 *       </li>
 *       <li>
 *       If \c aIsSnapshot holds any value other than 0 then
 *       the 'is snapshot' indicator for
 *       \c aOeaSubscription equals 1
 *       (to indicate snapshot delivery mode),
 *       </li>
 *       </ul>
 */
extern OEAExpDLL void oeaSubscription_setIsSnapshot(
    oeaSubscription* const aOeaSubscription,
    const int aIsSnapshot);

/**
 * Set the subject of the subscription.
 *
 * @pre  0 != aOeaSubscription
 * @pre  !oeaSubscription_hasBeenOpened(aOeaSubscription)
 * @pre  0 == aSubject || 0 != *aSubject
 *
 * @post If \c aSubject was NULL then \c aOeaSubscription
 *       does not contain a subject.
 * @post Otherwise, the subject for \c aOeaSubscription
 *       equals (is a copy of) \c aSubject.
 */
extern OEAExpDLL void oeaSubscription_setSubject(
    oeaSubscription* const aOeaSubscription,
    const char* const aSubject);

/**
 * Add an entitlement code to the subscription.
 *
 * @pre  0 != aOeaSubscription
 * @pre  !oeaSubscription_hasBeenOpened(aOeaSubscription)
 * @pre  aEntitlementCode > 0
 *
 * @post The entitlement code \c aEntitlementCode has been added
 *       to the list of entitlement codes in \c aOeaSubscription.
 */
extern OEAExpDLL void oeaSubscription_addEntitlementCode(
    oeaSubscription* const aOeaSubscription,
    const int aEntitlementCode);

/**
 * Is the subscription allowed to be opened?
 *
 * @pre  0 != aOeaSubscription
 * @pre  Either a subject or at least one entitlement code
 *       has been set for \c aOeaSubscription.
 *
 * @post If \c aOeaSubscription is allowed then 1
 *       has been returned, otherwise 0 has been returned.
 * @post If usage logging for the associated OEA client
 *       instance of \c aOeaSubscription is enabled and
 *       the subscription is not allowed a subscription
 *       denied usage event has been logged.
 * @post If 1 has been returned due to entitlements on
 *       demand, and this is the first time that the
 *       entitlement codes contained in this subscription
 *       have been granted via entitlements on demand,
 *       then an entitlement code activation record for
 *       each entitlement code in this subscription has
 *       been logged.
 *
 * @note 1 has been returned if
 *       the entitlements downloaded for the OEA client instance
 *       associated with subscription \c aOeaSubscription
 *       specifies that entitlements checking is disabled -
 *       see oeaClient_downloadEntitlements().
 * @note 1 has been returned if
 *       entitlements checking for the OEA client instance
 *       associated with subscription \c aOeaSubscription
 *       has been switched from enabled to disabled -
 *       see oeaSwitchEntitlementsCheckingCallback().
 */
extern OEAExpDLL int oeaSubscription_isAllowed(
    oeaSubscription* aOeaSubscription);

/**
 * Open the subscription.
 *
 * @pre  0 != aOeaSubscription
 * @pre  !oeaSubscription_isOpen(aOeaSubscription)
 *
 * @post If \c aOeaSubscription is allowed then
 *       it has been successfully opened, otherwise
 *       no action has been taken. The open status of
 *       \c aOeaSubscription can be tested by calling
 *       oeaSubscription_isOpen() after this method has exited.
 * @post If usage logging for the associated OEA client
 *       instance of \c aOeaSubscription is enabled and
 *       the subscription was opened a subscription open
 *       usage event has been logged.
 * @post If the subscription was opened due to entitlements on
 *       demand, and this is the first time that the
 *       entitlement codes contained in this subscription
 *       have been granted via entitlements on demand,
 *       then an entitlement code activation record for
 *       each entitlement code in this subscription has
 *       been logged.
 */
extern OEAExpDLL void oeaSubscription_open(oeaSubscription* aOeaSubscription);

/**
 * Close the subscription.
 *
 * @pre  0 != aOeaSubscription
 * @pre  oeaSubscription_isOpen(aOeaSubscription)
 *
 * @post \c aOeaSubscription has been successfully closed.
 * @post If usage logging for the associated OEA client
 *       instance of \c aOeaSubscription is enabled 
 *       a subscription closed usage event has been logged.
 */
extern OEAExpDLL void oeaSubscription_close(oeaSubscription* aOeaSubscription);

/**
 * Is the subscription open ?
 *
 * @pre  0 != aOeaSubscription
 *
 * @post If \c aOeaSubscription is open then 1
 *       has been returned, otherwise 0 has been returned.
 */
extern OEAExpDLL int oeaSubscription_isOpen(
    const oeaSubscription* const aOeaSubscription);

/**
 * Has the subscription ever been opened?
 *
 * @pre  0 != aOeaSubscription
 *
 * @post If \c aOeaSubscription has been opened at least once then 1
 *        has been returned, otherwise 0 has been returned.
 */
extern OEAExpDLL int oeaSubscription_hasBeenOpened(
    const oeaSubscription* const aOeaSubscription);

/**
 * Destroy the subscription.
 *
 * @pre  None.
 *
 * @post If \c aOeaSubscription was NULL
 *       this function did nothing.
 *       Otherwise, ...
 * @post If \c aOeaSubscription was open then it has been closed.
 * @post All resources associated with
 *       \c aOeaSubscription have been freed.
 */
extern OEAExpDLL void oeaSubscription_destroy(
    oeaSubscription* aOeaSubscription);

#if defined(__cplusplus)
}
#endif

#endif /* OEA_SUBSCRIPTION_H__ */

/**
 * $File: //commsof_depot/dart/wentitlements-api/trunk/c/OeaSubscription.h $
 * $Revision: #6 $
 * $DateTime: 2013/05/15 06:58:01 $
 * $Author: mdowney $
 *
 * Copyright (c) 2013 NYSE Euronext.
 * All rights reserved.
 */
