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

package com.wombat.mama;

/**
 *
 * Class to define payload types
 */
public class MamaPayloadType
{
    /** Solace Message */
    public static final char MAMA_PAYLOAD_SOLACE        =   '1';
    /** V5 Message */
    public static final char MAMA_PAYLOAD_V5            =   '5';
    /** AVIS Message */
    public static final char MAMA_PAYLOAD_AVIS          =   'A';
    /** Tick42 BLP Message */
    public static final char MAMA_PAYLOAD_TICK42BLP     =   'B';
    /** FAST Message */
    public static final char MAMA_PAYLOAD_FAST          =   'F';
    /** RAI Message */
    public static final char MAMA_PAYLOAD_RAI           =   'I';
    /** KWANTUM Message */
    public static final char MAMA_PAYLOAD_KWANTUM       =   'K';
    /** UMS Message */
    public static final char MAMA_PAYLOAD_UMS           =   'L';
    /** Inrush Message */
    public static final char MAMA_PAYLOAD_INRUSH        =   'N';
    /** Tick42 RMDS Message */
    public static final char MAMA_PAYLOAD_TICK42RMDS    =   'P';
    /** QPID Message */
    public static final char MAMA_PAYLOAD_QPID          =   'Q';
    /** TIBRV Message */
    public static final char MAMA_PAYLOAD_TIBRV         =   'R';
    /** IBMWFO Message */
    public static final char MAMA_PAYLOAD_IBMWFO        =   'S';
    /** ACTIV Message */
    public static final char MAMA_PAYLOAD_ACTIV         =   'T';
    /** Vulcan Message */
    public static final char MAMA_PAYLOAD_VULCAN        =   'V';
    /** Wombat Message */
    public static final char MAMA_PAYLOAD_WOMBAT_MSG    =   'W';
    /** Wombat Message */
    public static final char MAMA_PAYLOAD_EXEGY         =   'X';
    /** Unknown type */
    public static final char MAMA_PAYLOAD_UNKNOWN       =   'U';
}
