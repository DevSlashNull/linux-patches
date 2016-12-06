/*
 * Compatibility interface for userspace libc header coordination:
 *
 * Define compatibility macros that are used to control the inclusion or
 * exclusion of UAPI structures and definitions in coordination with another
 * userspace C library.
 *
 * This header is intended to solve the problem of UAPI definitions that
 * conflict with userspace definitions. If a UAPI header has such conflicting
 * definitions then the solution is as follows:
 *
 * * Synchronize the UAPI header and the libc headers so either one can be
 *   used and such that the ABI is preserved. If this is not possible then
 *   no simple compatibility interface exists (you need to write translating
 *   wrappers and rename things) and you can't use this interface.
 *
 * Then follow this process:
 *
 * (a) Include libc-compat.h in the UAPI header.
 *      e.g. #include <linux/libc-compat.h>
 *     This include must be as early as possible.
 *
 * (b) In libc-compat.h add enough code to detect that the comflicting
 *     userspace libc header has been included first.
 *
 * (c) If the userspace libc header has been included first define a set of
 *     guard macros of the form __UAPI_DEF_FOO and set their values to 1, else
 *     set their values to 0.
 *
 * (d) Back in the UAPI header with the conflicting definitions, guard the
 *     definitions with:
 *     #if __UAPI_DEF_FOO
 *       ...
 *     #endif
 *
 * This fixes the situation where the linux headers are included *after* the
 * libc headers. To fix the problem with the inclusion in the other order the
 * userspace libc headers must be fixed like this:
 *
 * * For all definitions that conflict with kernel definitions wrap those
 *   defines in the following:
 *   #if !__UAPI_DEF_FOO
 *     ...
 *   #endif
 *
 * This prevents the redefinition of a construct already defined by the kernel.
 */
#ifndef _UAPI_LIBC_COMPAT_H
#define _UAPI_LIBC_COMPAT_H

#ifndef __KERNEL__ /* we're used from userspace */

/* Coordinate with libc netinet/in.h header. */
#if defined(_NETINET_IN_H)

/* LIBC headers included first so don't define anything
 * that would already be defined. */
#define __UAPI_DEF_IN_ADDR		0
#define __UAPI_DEF_IN_IPPROTO		0
#define __UAPI_DEF_IN_PKTINFO		0
#define __UAPI_DEF_IP_MREQ		0
#define __UAPI_DEF_SOCKADDR_IN		0
#define __UAPI_DEF_IN_CLASS		0

#define __UAPI_DEF_IN6_ADDR		0
#define __UAPI_DEF_IN6_ADDR_ALT		0
#define __UAPI_DEF_SOCKADDR_IN6		0
#define __UAPI_DEF_IPV6_MREQ		0
#define __UAPI_DEF_IPPROTO_V6		0
#define __UAPI_DEF_IPV6_OPTIONS		0
#define __UAPI_DEF_IN6_PKTINFO		0
#define __UAPI_DEF_IP6_MTUINFO		0

#else /* defined(_NETINET_IN_H) */

/* Linux headers included first, and we must define everything
 * we need. The expectation is that libc will check the
 * __UAPI_DEF_* defines and adjust appropriately. */
#define __UAPI_DEF_IN_ADDR		1
#define __UAPI_DEF_IN_IPPROTO		1
#define __UAPI_DEF_IN_PKTINFO		1
#define __UAPI_DEF_IP_MREQ		1
#define __UAPI_DEF_SOCKADDR_IN		1
#define __UAPI_DEF_IN_CLASS		1

#define __UAPI_DEF_IN6_ADDR		1
/* We unconditionally define the in6_addr macros and libc must
 * coordinate. */
#define __UAPI_DEF_IN6_ADDR_ALT		1
#define __UAPI_DEF_SOCKADDR_IN6		1
#define __UAPI_DEF_IPV6_MREQ		1
#define __UAPI_DEF_IPPROTO_V6		1
#define __UAPI_DEF_IPV6_OPTIONS		1
#define __UAPI_DEF_IN6_PKTINFO		1
#define __UAPI_DEF_IP6_MTUINFO		1

#endif /* _NETINET_IN_H */

/* Definitions for xattr.h */
#if defined(_SYS_XATTR_H)
#define __UAPI_DEF_XATTR		0
#else
#define __UAPI_DEF_XATTR		1
#endif

/* If we did not see any headers from any supported C libraries,
 * or we are being included in the kernel, then define everything
 * that we need. */
#else /* __KERNEL__ */

/* Definitions for in.h */
#define __UAPI_DEF_IN_ADDR		1
#define __UAPI_DEF_IN_IPPROTO		1
#define __UAPI_DEF_IN_PKTINFO		1
#define __UAPI_DEF_IP_MREQ		1
#define __UAPI_DEF_SOCKADDR_IN		1
#define __UAPI_DEF_IN_CLASS		1

/* Definitions for in6.h */
#define __UAPI_DEF_IN6_ADDR		1
#define __UAPI_DEF_IN6_ADDR_ALT		1
#define __UAPI_DEF_SOCKADDR_IN6		1
#define __UAPI_DEF_IPV6_MREQ		1
#define __UAPI_DEF_IPPROTO_V6		1
#define __UAPI_DEF_IPV6_OPTIONS		1
#define __UAPI_DEF_IN6_PKTINFO		1
#define __UAPI_DEF_IP6_MTUINFO		1

/* Definitions for xattr.h */
#define __UAPI_DEF_XATTR		1

#endif /* __KERNEL__ */

#endif /* _UAPI_LIBC_COMPAT_H */
