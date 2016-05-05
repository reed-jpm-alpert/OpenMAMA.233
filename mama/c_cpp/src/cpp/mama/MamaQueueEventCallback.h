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

#ifndef MAMA_QUEUE_EVENT_CB_H__
#define MAMA_QUEUE_EVENT_CB_H__

namespace Wombat 
{

    class MamaQueue;

    /**
     * Definition of the callback method for when a user added event fires.
     * Concrete instances of this interface are registered with an
     * event queue using the <code>MamaQueue.enqueueEvent()</code>. Currently
     * only support by Wombat Middleware.
     */
    class MAMACPPExpDLL MamaQueueEventCallback
    {
    public:
        virtual ~MamaQueueEventCallback () {};

       /** Invoked when a user event, added by <code>MamaQueue.enqueueEvent()</code>
        *  fires.
        *
        * @param queue The MamaQueue on which the event was enqueued.
        * @param closure The user specified data associated with this event.
        */
        virtual void onEvent (
            MamaQueue&  queue, 
            void*       closure) = 0;
    };

} // namespace Wombat
#endif //MAMA_QUEUE_EVENT_CB_H__ 
