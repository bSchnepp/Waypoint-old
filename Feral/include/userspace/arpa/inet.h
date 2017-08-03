/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */

#ifndef _NIXOID_INET_ARPA_H_
#define _NIXOID_INET_ARPA_H_

/* TODO: create netinet/in.h  */

/* 
	This file is for the headers for the implementation of Berkeley sockets (which are used for internet magics).
	As such, it's one of the more important interfaces into the Feral kernel's custom TCP/IP stack.

	The file is defined by the POSIX standard.
 */

uint16_t 	htons(uint16_t val);
uint16_t 	ntohs(uint16_t val);

uint32_t 	htonl(uint32_t val);
uint32_t 	ntohl(uint32_t val);

char*     	inet_ntoa(struct in_addr in);

struct in_addr	inet_makeaddr(in_addr_t net, in_addr_t lna);

in_addr_t 	inet_addr(const char* cp);
in_addr_t 	inet_lnaof(struct in_addr in);
in_addr_t	inet_netof(struct in_addr in);
in_addr_t 	inet_network(const char* cp);


#endif
