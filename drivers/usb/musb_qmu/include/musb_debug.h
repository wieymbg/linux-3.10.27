/*
 * MUSB OTG driver debug defines
 *
 * Copyright 2005 Mentor Graphics Corporation
 * Copyright (C) 2005-2006 by Texas Instruments
 * Copyright (C) 2006-2007 Nokia Corporation
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 * NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *   Porting to suit mediatek
 *   Copyright (C) 2011-2012
 *   Wei.Wen, Mediatek Inc <wei.wen@mediatek.com>
 */

#ifndef __MUSB_LINUX_DEBUG_H__
#define __MUSB_LINUX_DEBUG_H__

#include <linux/version.h>

#define yprintk(facility, format, args...) \
	do { printk(facility "%s %d: " format , \
	__func__, __LINE__ , ## args); } while (0)
#define WARNING(fmt, args...) yprintk(KERN_WARNING, fmt, ## args)
#define INFO(fmt, args...) yprintk(KERN_INFO, fmt, ## args)
#define ERR(fmt, args...) yprintk(KERN_ERR, fmt, ## args)

#define xprintk(level, facility, format, args...) do { \
	if (_dbg_level(level)) { \
		printk(facility "%s %d: " format , \
				__func__, __LINE__ , ## args); \
	} } while (0)

extern unsigned musb_debug;

static inline int _dbg_level(unsigned l)
{
	return musb_debug >= l;
}
#if 1
#define DBG(level, fmt, args...) xprintk(level, KERN_INFO, fmt, ## args)
#else
#define DBG(level, fmt, args...) do{\
	if(level < 1)\
	printk("%s " fmt,"[musb]", ## args);\
	}while(0)
#endif
#define MUSB_ASSERT(x)   if (!(x)) BUG();

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 0, 0))
extern const char *otg_state_string(struct musb *);
#endif

#endif				/*  __MUSB_LINUX_DEBUG_H__ */
