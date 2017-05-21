/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 */

/*
 *	Contributors:
 *		Brian Schnepp
 */


#ifdef __x86_64
//---
#define uint8_t unsigned char
#define uint16_t unsigned short int
#define uint32_t unsigned int
#define uint64_t unsigned long long int

#define int8_t  char
#define int16_t short int
#define int32_t int
#define int64_t long long int

#define mem_sz unsigned int 
#define task_count unsigned long long int
//---
#endif

//TODO: Move this into hardabs.dyn [hardware abstraction layer], or into klibc's stdint.
