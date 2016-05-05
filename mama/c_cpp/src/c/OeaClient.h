/** \file OeaClient.h
 * The declaration of the OEA client
 * and associated methods/functions.
 */

#ifndef OEA_CLIENT_H__
#define OEA_CLIENT_H__

/**
 *
 * INCLUDE DIRECTIVES
 *
 */
#include <OeaStatus.h>
#include <OeaSubscription.h>

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * Reasons for arrival of disconnection request.
 */
typedef enum
{
    OEA_DISCONNECT_REASON_ADMIN,
    OEA_DISCONNECT_REASON_NEW_CONNECTION,
    OEA_DISCONNECT_REASON_ENTITLEMENTS_UPDATE,
    OEA_DISCONNECT_REASON_INVALID = 101
} OEA_DISCONNECT_REASON;

/**
 * \var OEA_DISCONNECT_REASON_ADMIN
 * Disconnection request sent by an administrator
 * via Site Server GUI.
 */

/**
 * \var OEA_DISCONNECT_REASON_NEW_CONNECTION
 * Disconnection request sent due to user reaching
 * concurrent access limit.
 */

/**
 * \var OEA_DISCONNECT_REASON_ENTITLEMENTS_UPDATE
 * Disconnection request sent due to an entitlements
 * modification resulting in user currently
 * exceeding concurrent access limit.
 */

/**
 * The Open Entitlements client type.
 */
typedef struct _oeaClient oeaClient;

/**
 * Disconnection callback.
 *
 * \c aOeaClient points to the \c oeaClient that is
 * being requested to disconnect.
 *
 * \c aReason holds reason disconnection request
 * was sent.
 *
 * \c aUserId, \c aHost and \c aApplicationName
 * will hold the following when \c aReason is:
 *
 * <ul>
 * <li>
 *   OEA_DISCONNECT_REASON_NEW_CONNECTION
 *   <ul>
 *     <li>
 *       \c aUserId points to id of user that
 *       is attempting to connect.
 *     </li>
 *     <li>
 *       \c aHost points to hostname/ip address
 *       where \c aUserId is attempting to
 *       connect from.
 *     </li>
 *     <li>
 *       \c aApplicationName points to name of
 *       application that \c aUserId is using
 *       to connect (possibly empty).
 *     </li>
 *   </ul>
 * </li>
 * <li>
 *   OEA_DISCONNECT_REASON_ADMIN
 *   <ul>
 *     <li>
 *       \c aUserId points to id of admin user
 *       disconnecting the client, e.g.
 *       using the Site Server GUI.
 *     </li>
 *     <li>
 *       \c aHost points to hostname/ip address
 *       of the Site Server.
 *     </li>
 *     <li>
 *       \c aApplicationName equals "site server".
 *     </li>
 *   </ul>
 * </li>
 * <li>
 *   OEA_DISCONNECT_REASON_ENTITLEMENTS_UPDATE
 *   <ul>
 *     <li>
 *       \c aUserId points to id of user that
 *       Site Server is running under.
 *     </li>
 *     <li>
 *       \c aHost points to hostname/ip address
 *       of the Site Server.
 *     </li>
 *     <li>
 *       \c aApplicationName equals "site server".
 *     </li>
 *   </ul>
 * </li>
 * </ul>
 *
 * The callback function should not attempt to
 * free \c aUserId, \c aHost or
 * \c aApplicationName.
 *
 * It is safe to call
 * oeaClient_destroy() on \c aOeaClient
 * from within the callback function.
 */
#ifndef WIN32
typedef void (*oeaDisconnectCallback)(
                    oeaClient*            aOeaClient,
              const OEA_DISCONNECT_REASON aReason,
              const char* const           aUserId,
              const char* const           aHost,
              const char* const           aApplicationName);
#else
typedef void (__stdcall *oeaDisconnectCallback)(
                    oeaClient*            aOeaClient,
              const OEA_DISCONNECT_REASON aReason,
              const char* const           aUserId,
              const char* const           aHost,
              const char* const           aApplicationName);
#endif

/**
 * Entitlements Updated callback.
 *
 * \c aOeaClient points to the \c oeaClient
 * for which entitlements have been updated.
 *
 * \c aIsOpenSubscriptionForbidden holds 1
 * if there is at least one open subscription that is
 * no longer allowed following the entitlements update,
 * otherwise holds 0.
 */
#ifndef WIN32
typedef void (*oeaEntitlementsUpdatedCallback)(
                                    oeaClient* aOeaClient,
                                    const int  aIsOpenSubscriptionForbidden);
#else
typedef void (__stdcall *oeaEntitlementsUpdatedCallback)(
                                    oeaClient* aOeaClient,
                                    const int  aIsOpenSubscriptionForbidden);
#endif

/**
 * Switch Entitlements Checking callback.
 *
 * \c aOeaClient points to the \c oeaClient
 * for which entitlements checking has been switched,
 * for example, from enabled to disabled.
 *
 * \c aIsEntitlementsCheckingDisabled holds 1
 * if entitlements checking has been switched to disabled,
 * otherwise holds 0.
 */
#ifndef WIN32
typedef void (*oeaSwitchEntitlementsCheckingCallback)(
                                    oeaClient* aOeaClient,
                                    const int  aIsEntitlementsCheckingDisabled);
#else
typedef void (__stdcall *oeaSwitchEntitlementsCheckingCallback)(
                                    oeaClient* aOeaClient,
                                    const int  aIsEntitlementsCheckingDisabled);
#endif

/**
 * Holds callback functions to be invoked upon arrival of \n
 * disconnection request and after entitlements update.
 */
typedef struct
{
   /**
    * Points to callback function to be invoked upon disconnection
    * request.
    */
    oeaDisconnectCallback onDisconnect;

   /**
    * Points to callback function to be invoked after dynamic
    * entitlements update has occurred.
    */
    oeaEntitlementsUpdatedCallback onEntitlementsUpdated;

   /**
    * Points to callback function to be invoked after
    * entitlements checking has been switched,
    * for example, from enabled to disabled.
    */
    oeaSwitchEntitlementsCheckingCallback onSwitchEntitlementsChecking;

} oeaCallbacks;

/**
 * Version.
 *
 * @pre  None.
 *
 * @post A pointer to a string containing
 *       the version number has been returned.
 *       The caller should not attempt to
 *       modify the returned pointer.
 */
extern OEAExpDLL const char* oea_version(void);

/**
 * All versions.
 *
 * @pre  None.
 *
 * @post A pointer to a string containing
 *       the version number of OEA and all
 *       the packages that is uses has been
 *       returned.
 *       The version numbers are separated
 *       by newline characters.
 *       The caller should not attempt to
 *       modify the returned pointer.
 */
extern OEAExpDLL const char* oea_allVersions(void);

/**
 * Create OEA Client.
 *
 * This function creates the OEA client object
 * and attempts to download the API configuration
 * from a Site Server.
 *
 * The API configuration indicates if
 * concurrent access control,
 * dynamic entitlements update and
 * entitlements checking switching
 * are enabled or disabled.
 * If any of these are enabled, the
 * configuration contains the
 * heartbeat interval and the UDP port
 * to which heartbeats will be sent.
 *
 * Concurrent access control,
 * dynamic entitlements update and
 * entitlements checking switching are disabled
 * for an OEA client if the Site Server that is
 * being contacted does not support these features.
 *
 * Before the OEA client object can be used for
 * entitlement checking,
 * oeaClient_downloadEntitlements() must be called.
 *
 * The TCP/IP port range defined by \c aPortLow and \c aPortHigh,
 * will only be used if concurrent access control,
 * dynamic entitlements update or
 * entitlements checking switching are enabled.
 * The port range used by OEA is obtained from
 * the first valid port range provided to this
 * function.
 *
 * @param  aStatus             Is populated with entitlement
 *                             status after attempt to create
 *                             client.
 * @param  aSite               Points to a string that is
 *                             the name of a site defined
 *                             in the DART Entitlements
 *                             database.
 *                             Optional.
 * @param  aPortLow            Holds lowest TCP/IP port number
 *                             on which OEA can listen for
 *                             requests from Site Server.
 * @param  aPortHigh           Holds highest TCP/IP port number
 *                             on which OEA can listen for
 *                             requests from Site Server.
 * @param  aServers            Points to a collection of site
 *                             server URLs.
 * @param  aNumberOfServers    Holds the number of servers in
 *                             \c aServers.
 *
 * @pre    0 != aStatus
 * @pre    0 == aSite || 0 != *aSite
 * @pre    0 != aServers
 * @pre    aNumberOfServers > 0
 * @pre    aPortHigh >= aPortLow
 *         (if concurrent access control,
 *          dynamic entitlements update or
 *          entitlements checking switching
 *          are enabled)
 * @pre    aPortLow > 0
 *         (if concurrent access control,
 *          dynamic entitlements update or
 *          entitlements checking switching
 *          are enabled)
 *
 * @post   If the IP address of the primary
 *         Site Server (i.e. first entry in \c aServers)
 *         could not be determined,
 *         then 0 has been returned
 *         and \c aStatus points to #OEA_HTTP_ERRHOST.
 * @post   Otherwise,
 *         if none of the \c aNumberOfServers
 *         Site Servers within \c aServers could be contacted,
 *         then 0 has been returned
 *         and \c aStatus points to an \c oeaStatus
 *         indicating why the last Site Server
 *         could not be contacted.
 * @post   Otherwise,
 *         if aSite was not NULL and a Site Server has been
 *         successfully contacted whose site did not equal
 *         \c aSite then 0 has been returned and \c aStatus
 *         points to #OEA_STATUS_SITE_NOT_FOUND.
 * @post   Otherwise,
 *         if a Site Server has been successfully contacted
 *         which did not support
 *         concurrent access control,
 *         dynamic entitlements update and
 *         entitlements checking switching,
 *         then these features have been disabled for
 *         the returned OEA client,
 *         \c aStatus points to #OEA_STATUS_OK
 *         and a pointer to an \c oeaClient
 *         has been returned.
 * @post   Otherwise,
 *         if a Site Server was successfully contacted
 *         which supports concurrent access control,
 *         dynamic entitlements update,
 *         or entitlements checking switching
 *         and the downloaded API configuration was invalid,
 *         \c aStatus points to #OEA_STATUS_BAD_DATA
 *         and 0 has been returned.
 * @post   Otherwise,
 *         if a Site Server was successfully contacted
 *         which supports concurrent access control,
 *         dynamic entitlements update,
 *         or entitlements checking switching
 *         and the downloaded API configuration was valid,
 *         concurrent access control,
 *         dynamic entitlements update and
 *         entitlements checking switching
 *         have been configured accordingly for the
 *         returned OEA client,
 *         \c aStatus points to #OEA_STATUS_OK
 *         and a pointer to an \c oeaClient
 *         has been returned.
 *
 * @note   If preconditions were not satisfied,
 *         then \c aStatus points to #OEA_STATUS_BAD_PARAM,
 *         and 0 has been returned.
 * @note   If memory allocation was unsuccessful,
 *         then \c aStatus points to #OEA_STATUS_NOMEM,
 *         and 0 has been returned.
 * @note   If \c aSite is NULL the \c oeaClient returned
 *         is associated with the site that the contacted
 *         Site Server supports.
 */
extern OEAExpDLL oeaClient* oeaClient_create(
                           oeaStatus* const aStatus,
                     const char*      const aSite,
                     const int              aPortLow,
                     const int              aPortHigh,
                     const char**           aServers,
                     const int              aNumberOfServers
                                            );

/**
 * Download entitlements.
 *
 * Attempts to gain platform access and
 * download entitlements from a Site Server
 * for specified \c oeaClient.
 *
 * @param  aOeaClient    Points to an \c oeaClient for
 *                       which the entitlements profile
 *                       is to be downloaded.
 *
 * @pre    0 != aOeaClient
 *
 * @post   If entitlements for \c aOeaClient
 *         have already been downloaded,
 *         then #OEA_STATUS_ALREADY_ENTITLED
 *         has been returned.
 * @post   Otherwise,
 *         if concurrent access control,
 *         dynamic entitlements update
 *         or entitlements checking switching are enabled
 *         for \c aOeaClient:
 *         <ul>
 *           <li>
 *             If concurrent access control is enabled
 *             and this download attempt results in the
 *             concurrent access control count
 *             of the user associated with \c aOeaClient being exceeded,
 *             #OEA_STATUS_CAC_LIMIT_EXCEEDED has been returned.
 *           </li>
 *           <li>
 *             Otherwise, if entitlements download was unsuccessful,
 *             an \c oeaStatus value
 *             has been returned indicating why
 *             entitlements failed to be downloaded
 *             from the last Site Server.
 *           </li>
 *           <li>
 *             Otherwise,
 *             entitlements have been successfully downloaded,
 *             #OEA_STATUS_OK has been returned,
 *             \c aOeaClient is ready for entitlements checking,
 *             the primary Site Server of \c aOeaClient has been
 *             registered to receive UDP heartbeats from OEA,
 *             and if concurrent access control is enabled
 *             the concurrent access count of the user associated
 *             with \c aOeaClient has been increased by one.
 *           </li>
 *         </ul>
 * @post   Otherwise,
 *         if concurrent access control,
 *         dynamic entitlements update and
 *         entitlements checking switching
 *         are disabled for \c aOeaClient:
 *         <ul>
 *           <li>
 *             If entitlements download was successful,
 *             #OEA_STATUS_OK has been returned
 *             and \c aOeaClient is ready
 *             for entitlements checking.
 *           </li>
 *           <li>
 *             Otherwise, an \c oeaStatus
 *             has been returned indicating why
 *             entitlements failed to be downloaded
 *             from the last Site Server.
 *           </li>
 *         </ul>
 * @post   If usage logging is enabled for the user
 *         associated with \c aOeaClient and the
 *         attempt to download entitlements was
 *         successful a connection OK usage event
 *         has been logged.
 * @post   If usage logging is enabled for the site
 *         associated with \c aOeaClient and the
 *         attempt to download entitlements was
 *         unsuccessful a connection failure usage
 *         event has been logged.
 *
 * @note   If preconditions were not satisfied,
 *         then #OEA_STATUS_BAD_PARAM
 *         has been returned.
 * @note   If memory allocation was unsuccessful,
 *         then #OEA_STATUS_NOMEM
 *         has been returned.
 * @note   If concurrent access control,
 *         dynamic entitlements update
 *         or entitlements checking switching are enabled
 *         for \c aOeaClient,
 *         and this is the first successful call to
 *         download entitlements,
 *         a thread has been started that listens for
 *         requests to disconnect,
 *         update entitlements,
 *         and/or switch entitlements checking
 *         from a Site Server on a TCP/IP port
 *         from the range provided by the call to
 *         oeaClient_create(),
 *         and the thread will also send
 *         'alive' heartbeats (UDP unicast)
 *         to the registered Site Servers at a
 *         configured interval.
 * @note   If a request to disconnect,
 *         to update entitlements,
 *         or to switch entitlements checking
 *         has been received from a Site Server,
 *         then the corresponding callback function
 *         (if specified by a call to oeaClient_setCallbacks())
 *         will be invoked.
 * @note   The downloaded entitlements may have specified
 *         that entitlements checking is disabled
 *         for the user associated with \c aOeaClient
 *         as part of an emergency entitlements procedure.
 *         See oeaSubscription_isAllowed().
 */
extern OEAExpDLL oeaStatus oeaClient_downloadEntitlements(
                                       oeaClient* const aOeaClient
                                                         );

/**
 *  Set callback functions.
 *
 *  @param  aOeaClient    Points to \c oeaClient whose
 *                        callback functions will be set.
 *  @param  aCallbacks    Points to \c oeaCallbacks structure
 *                        holding the set of callback
 *                        functions to be invoked,
 *                        or is 0.
 *
 *  @pre    0 != aOeaClient
 *  @pre    \c aCallbacks points to a valid \c oeaCallbacks structure,
 *          or is 0.
 *
 *  @post   If \c aOeaClient is already entitled,
 *          then #OEA_STATUS_ALREADY_ENTITLED
 *          has been returned.
 *  @post   Otherwise #OEA_STATUS_OK has been returned,
 *          and if \c aCallbacks is not 0,
 *          then the callback functions specified by \c aCallbacks
 *          have been associated with \c aOeaClient,
 *          otherwise \c aOeaClient
 *          has been associated with no callback functions.
 *
 *  @note   If preconditions were not satisfied,
 *          then #OEA_STATUS_BAD_PARAM
 *          has been returned.
 */
extern OEAExpDLL oeaStatus oeaClient_setCallbacks(
                                       oeaClient* const aOeaClient,
                              const oeaCallbacks* const aCallbacks
                                                );

/**
 * Set alternative user id.
 *
 * This provides an alternative user id to
 * the OS user id to use when attempting to connect to Site Server
 * (dependent on Site Server being configured
 *  to allow use of alternative user id).
 *
 * @param  aOeaClient          Points to \c oeaClient whose
 *                             alternative user id will be set.
 * @param  aAlternativeUserId  Points to the alternative user id being set,
 *                             or is 0.
 *
 * @pre    0 != aOeaClient
 * @pre    0 == aAlternativeUserId || 0 != *aAlternativeUserId
 *
 * @post   If \c aOeaClient is already entitled,
 *         then #OEA_STATUS_ALREADY_ENTITLED
 *         has been returned.
 * @post   Otherwise #OEA_STATUS_OK has been returned,
 *         and the alternative user id for
 *         \c aOeaClient equals
 *         \c aAlternativeUserId (which may be 0).
 *
 * @note   If preconditions were not satisfied,
 *         then #OEA_STATUS_BAD_PARAM
 *         has been returned.
 * @note   Passing 0 for \c aAlternativeUserId has the effect of
 *         no alternative user id being specified for \c aOeaClient.
 */
extern OEAExpDLL oeaStatus oeaClient_setAlternativeUserId(
                                       oeaClient* const aOeaClient,
                                 const char*      const aAlternativeUserId
                                                );

/**
 * Set application id.
 *
 * The application id is currently ignored.
 *
 * @param  aOeaClient        Points to \c oeaClient whose
 *                           application id will be set.
 * @param  aApplicationId    Points to the application id being set,
 *                           or is 0.
 *
 * @pre    0 != aOeaClient
 * @pre    0 == aApplicationId || 0 != *aApplicationId
 *
 * @post   If \c aOeaClient is already entitled,
 *         then #OEA_STATUS_ALREADY_ENTITLED
 *         has been returned.
 * @post   Otherwise #OEA_STATUS_OK has been returned,
 *         and the application id for
 *         \c aOeaClient equals
 *         \c aApplicationId (which may be 0).
 *
 * @note   If preconditions were not satisfied,
 *         then #OEA_STATUS_BAD_PARAM
 *         has been returned.
 * @note   Passing 0 for \c aApplicationId has the effect of no
 *         application id being specified for \c aOeaClient.
 */
extern OEAExpDLL oeaStatus oeaClient_setApplicationId(
                                       oeaClient* const aOeaClient,
                                 const char*      const aApplicationId
                                                );
/**
 * Set client data.
 *
 * @param  aOeaClient        Points to \c oeaClient
 *                           whose client data will be set.
 * @param  aClientData       Points to the client data being set,
 *                           or is 0.
 *
 * @pre    0 != aOeaClient
 *
 * @post   #OEA_STATUS_OK has been returned,
 *         and the client data for
 *         \c aOeaClient equals
 *         \c aClientData (which may be 0).
 *
 * @note   If preconditions were not satisfied,
 *         then #OEA_STATUS_BAD_PARAM
 *         has been returned.
 * @note   Passing 0 for \c aClientData has the effect of
 *         no client data being specified for \c aOeaClient.
 */
extern OEAExpDLL oeaStatus oeaClient_setClientData(
                                       oeaClient*  const aOeaClient,
                                       void* const aClientData);

/**
 * Set effective IP address.
 *
 * The effective IP address is used for counting concurrent
 * connections and is recorded as the IP address in usage
 * logging records.
 *
 * If an effective IP address is not specified the actual
 * address of the current machine is used.
 *
 * @pre    0 != aOeaClient
 * @pre    0 == aEffectiveIpAddress || 0 != *aEffectiveIpAddress
 * @pre    If \c aEffectiveIpAddress is not null it
 *         must be a valid IP address expressed in the
 *         Internet standard dotted notation.
 *
 * @post   If \c aOeaClient is already entitled,
 *         then #OEA_STATUS_ALREADY_ENTITLED
 *         has been returned.
 * @post   Otherwise #OEA_STATUS_OK has been returned,
 *         and the effective IP address for
 *         \c aOeaClient equals \c aEffectiveIpAddress
 *         (which may be 0).
 *
 * @note   If preconditions were not satisfied,
 *         #OEA_STATUS_BAD_PARAM has been returned.
 * @note   If the user identified by \c aOeaClient has
 *         IP restrictions then both the IP address
 *         of the current machine and the effective IP
 *         address must satisfy the user's IP
 *         restrictions.
 * @note   Passing 0 for \c aEffectiveIpAddress has the
 *         effect of no effective IP address being 
 *         specified for \c aOeaClient.
 */
extern OEAExpDLL oeaStatus oeaClient_setEffectiveIpAddress(
                                       oeaClient* const aOeaClient,
                                 const char*      const aEffectiveIpAddress);

/**
 * The client data for \c aOeaClient.
 *
 * @param  aStatus           Is populated with entitlement status
 *                           after attempt to get client data for
 *                           \c aOeaClient.
 * @param  aOeaClient        Points to \c oeaClient
 *                           whose client data will be returned.
 *
 * @pre    0 != aStatus
 * @pre    0 != aOeaClient
 *
 * @post   A pointer to the client data for \c aOeaClient
 *         (which may be 0) has been returned.
 *
 * @note   If \c aOeaClient is 0 then
 *         \c aStatus points to #OEA_STATUS_BAD_PARAM,
 *         and 0 has been returned.
 */
extern OEAExpDLL void* oeaClient_clientData(oeaStatus* const aStatus,
                                            oeaClient* const aOeaClient);

/**
 * Destroy OEA client.
 *
 * @param  aOeaClient  Points to \c oeaClient to be destroyed,
 *                     or is 0.
 *
 * @pre    None.
 *
 * @post   If 0 has been passed for \c aOeaClient,
 *         then nothing has been done.
 * @post   Otherwise,
 *         if concurrent access control is enabled,
 *         then the concurrent access control count
 *         of the user associated with \c aOeaClient
 *         has been reduced by one.
 * @post   If concurrent access control,
 *         dynamic entitlements update,
 *         or entitlements checking switching are enabled,
 *         and \c aOeaClient is the last OEA client instance,
 *         then the thread started by the first successful call to
 *         oeaClient_downloadEntitlements() has been stopped,
 *         and the listening TCP/IP port has been closed,
 *         and the sending of heartbeats has been stopped.
 * @post   If usage logging is enabled for the user
 *         associated with \c aOeaClient a disconnection
 *         usage event has been logged.
 * @post   All resources associated with
 *         \c aOeaClient have been freed.
 *
 * @note   After a call to oeaClient_destroy(),
 *         each OEA subscription that has been created for
 *         \c aOeaClient (by a call to oeaClient_newSubscription())
 *         has been destroyed and should no longer be accessed
 *         from within the calling code.
 */
extern OEAExpDLL void oeaClient_destroy(oeaClient* aOeaClient);

/**
 * Creates new OEA subscription.
 *
 * Creates a subscription to market data for
 * the user associated with the specified \c oeaClient.
 *
 * @param  aStatus     Points to an \c oeaStatus
 *                     populated after attempt to create subscription.
 * @param aOeaClient   Points to the entitlements client for which
 *                     the OEA user subscription is to created.
 *
 * @pre    0 != aOeaClient
 * @pre    A call to \c oeaClient_downloadEntitlements()
 *         has been made.
 *
 * @post   \c aStatus points to #OEA_STATUS_OK,
 *         and a pointer to the new \c oeaSubscription
 *         has been returned,
 *         with market data delivery mode
 *         defaulted to real-time streamed.
 *
 * @note   If memory allocation was unsuccessful then,
 *         \c aStatus points to #OEA_STATUS_NOMEM,
 *         and 0 has been returned.
 */
extern OEAExpDLL oeaSubscription* oeaClient_newSubscription(
                                       oeaStatus* const aStatus,
                                       oeaClient* const aOeaClient);
#if defined(__cplusplus)
}
#endif

#endif /* OEA_CLIENT_H__ */

/*
 * $File: //commsof_depot/dart/wentitlements-api/trunk/c/OeaClient.h $
 * $Revision: #8 $
 * $DateTime: 2013/05/20 11:13:05 $
 * $Author: mdowney $
 *
 * Copyright (c) 2013 NYSE Euronext.
 * All rights reserved.
 */

