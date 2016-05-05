/**
 * Window headers and macros.
 *
 * @author  Martin Downey
 * @version $Revision: #5 $
 *          $DateTime: 2013/05/10 12:11:10 $
 */

#ifndef OEA_H_
#define OEA_H_

/**
 * Required for data exported from DLL's.
 */
#if defined( WIN32 ) && defined( OEA_DLL )
#define OEAExpDLL __declspec(dllexport)
#else
#define OEAExpDLL
#endif

#ifdef WIN32
#define WIN32_EXTRA_LEAN
#define WIN32_LEAN_AND_MEAN

#ifndef _WINSOCKAPI_
#ifndef _WINSOCK2API_
#include <winsock2.h>
#endif
#endif

#include <windows.h>

#endif

#endif /* OEA_H_ */

/**
 * $File: //commsof_depot/dart/wentitlements-api/trunk/c/OeaWin.h $
 * $Revision: #5 $
 * $DateTime: 2013/05/10 12:11:10 $
 * $Author: mdowney $
 *
 * Copyright (c) 2013 NYSE Euronext.
 * All rights reserved.
 */
