#ifndef OEA_STATUS_H__
#define OEA_STATUS_H__
/**
 * OEA status codes.
 *
 * @author  Martin Downey
 * @version $Revision: #6 $
 *          $DateTime: 2013/05/10 12:11:10 $
 */

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

/**
 *  Allow use from C++.
 */
#if defined(__cplusplus)
extern "C" {
#endif

/**
 *  Values indicating state of OEA.
 */
typedef enum
{
   /**
    * No error.
    */
    OEA_STATUS_OK = 0,

   /**
    * Out of memory.
    */
    OEA_STATUS_NOMEM = 1,

   /**
    * Invalid parameter.
    */
    OEA_STATUS_BAD_PARAM = 2,

   /**
    * The XML returned from Site Server was invalid.
    */
    OEA_STATUS_BAD_DATA = 3,

   /**
    * Invalid URL.
    */
    OEA_STATUS_HTTP_URL_ERROR = 4,

   /**
    * Unable to determine OS ID of account process is running under.
    */
    OEA_STATUS_OS_LOGIN_ID_UNAVAILABLE = 5,

   /**
    * When an attempt to get entitlements after
    * a successful attempt has already been made.
    */
    OEA_STATUS_ALREADY_ENTITLED = 6,

   /**
    * A user has exceeded concurrent access limit.
    */
    OEA_STATUS_CAC_LIMIT_EXCEEDED = 7,

   /**
    * Failed to create OEP listener that processes
    * inbound messages from site server.
    * Required for concurrent access control and/or
    * dynamic entitlements update.
    */
    OEA_STATUS_OEP_LISTENER_CREATION_FAILURE = 8,

   /**
    * No such host
    */
    OEA_HTTP_ERRHOST = 10,

   /**
    * Can't create socket
    */
    OEA_HTTP_ERRSOCK = 11,

   /**
    * Can't connect to host
    */
    OEA_HTTP_ERRCONN = 12,

   /**
    * Write error on socket while writing header
    */
    OEA_HTTP_ERRWRHD = 13,

   /**
    * Write error on socket while writing data
    */
    OEA_HTTP_ERRWRDT = 14,

   /**
    * Read error on socket while reading result
    */
    OEA_HTTP_ERRRDHD = 15,

   /**
    * Invalid answer from data server
    */
    OEA_HTTP_ERRPAHD = 16,

   /**
    * Null data pointer
    */
    OEA_HTTP_ERRNULL = 17,

   /**
    * No/Bad length in header
    */
    OEA_HTTP_ERRNOLG = 18,

   /**
    * Can't allocate memory
    */
    OEA_HTTP_ERRMEM = 19,

   /**
    * Read error while reading data
    */
    OEA_HTTP_ERRRDDT = 20,

   /**
    * Invalid url - must start with 'http://'
    */
    OEA_HTTP_ERRURLH = 21,

   /**
    * Invalid port in url
    */
    OEA_HTTP_ERRURLP = 22,

   /**
    * Invalid QUERY HTTP RESULT 400
    */
    OEA_HTTP_BAD_QUERY = 23,

   /**
    * FORBIDDEN HTTP RESULT 403
    */
    OEA_HTTP_FORBIDDEN = 24,

   /**
    * Request Timeout HTTP RESULT 408
    */
    OEA_HTTP_TIMEOUT = 25,

   /**
    * Server Error HTTP RESULT 500
    */
    OEA_HTTP_SERVER_ERR = 26,

   /**
    * Not Implemented HTTP RESULT 501
    */
    OEA_HTTP_NO_IMPL = 27,

   /**
    * Overloaded HTTP RESULT 503
    */
    OEA_HTTP_OVERLOAD = 28,

   /**
    * NOT FOUND HTTP RESULT 404.
    */
    OEA_HTTP_NOT_FOUND = 29,

   /**
    * A user subscription is not allowed for a subject.
    */
    OEA_SUBJECT_NOT_ALLOWED = 30,

   /**
    * A user subscription is not allowed for an entitlement code.
    */
    OEA_ENTITLEMENT_CODE_NOT_ALLOWED = 31,

   /**
    * Site name passed to Site Server
    * was not found.
    */
    OEA_STATUS_SITE_NOT_FOUND = 32,

   /**
    * Failed to initialise entitlements on demand mechanism.
    */
    OEA_STATUS_ENTITLEMENTS_ON_DEMAND_INIT_FAILURE = 33,

   /**
    * The configuration XML returned from Site Server
    * was greater than 'INT_MAX' in length.
    */
    OEA_STATUS_CONFIGURATION_XML_TOO_LARGE = 34,

   /**
    * The entitlements XML returned from Site Server was
    * greater than 'INT_MAX' in length.
    */
    OEA_STATUS_ENTITLEMENTS_XML_TOO_LARGE = 35,

   /**
    * Invalid status code.
    */
    OEA_STATUS_INVALID = 101

} oeaStatus;

/**
 * OEA status message that corresponds to the
 * supplied OEA status code.
 *
 * @pre  None.
 *
 * @post A pointer to a string (literal)
 *       that is a description of
 *       the status code \c aCode
 *       has been returned.
 *       The caller must not attempt to free the returned pointer.
 */
extern OEAExpDLL const char* oeaStatus_text(const oeaStatus aCode);

#if defined(__cplusplus)
}
#endif

#endif /* OEA_STATUS_H__*/

/**
 * $File: //commsof_depot/dart/wentitlements-api/trunk/c/OeaStatus.h $
 * $Revision: #6 $
 * $DateTime: 2013/05/10 12:11:10 $
 * $Author: mdowney $
 *
 * Copyright (c) 2013 NYSE Euronext.
 * All rights reserved.
 */

