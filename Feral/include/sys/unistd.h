/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

//For POSIX compatibility, we blindly follow POSIX, throwing logic for things like block sizes out the Glass Pane.
//If you want 512-byte blocks and other GNUy stuff, set the environment variable "LOGICALLY_CORRECT" to 1.
//Most POSIX commands and whatnot are ported from FreeBSD. If it's under the GPL, we write a replacement for it. etc. etc.
//Since we borrow a lot from the BSDs for POSIX conformance, we also need to imitate the FreeBSD kernel a lot. TODO on that.

//We'd really like to be fully POSIX-conformant, even though we shove the "POSIXness" into A:/System/Posix/root/
//Which then has the familiar /usr, /bin, /sys, /dev, /proc, /home, etc.
//(We look in A:/System/Posix/root/usr/bin and others after going into A:/Applications/, A:/Program Files/, etc. Thus, we look like a NIX system.)
//The kernel silently symlinks (A:)/usr to A:/System/Posix/root/usr, and so on. We extend filesystems which don't support this with our own software libre extensions to them.

//Something we should consider is extending that functionality to declare a drive as a 'POSIX drive' and let it act like you expect a Linux or BSD system to.
//We try to speak 'POSIXified Linux' for our POSIX personality. Thus, we say '/dev/sdXX', not '/dev/disk0s1' or '/dev/hd0s1' or whatever.
//We'll have to figure out how to do something like /dev/random, /dev/urandom, etc. later, since Waypoint does that functionality with a program (we don't do "special files").
//For programs asking for the kernel for some reason, we create a symlink: (A:)/mach_kernel. We'll also symlink 'pacman', 'apt', 'brew', 'emerge', 'zypper' and 'rpm' to pkgmgr.

#ifndef _SYS_UNISTD_H_
#define _SYS_UNISTD_H_

#include <feral/feralobjs.h>

//We're going to aim to implement POSIX.1-2008.
#define _POSIX_VERSION  200809L

//As specified by POSIX...
#define _POSIX2_VERSION 200809L

//Pathfinder (will) ha(ve/s) a X server personality. Thus, we can be X11R6 compliant. Essentially the inverse of how Wayland solves this problem.
//The framing system imitates Xorg, not Xorg implementing the new specification. Where patches to existing projects can be avoided, we do it.
//Pathfinder will have some sort of system that lets us have remote desktops and all probably. I don't know.
#define _XOPEN_VERSION 700

//(We're going to need to have a way to have 'blessed' applications pose as different applications, ie, Xorg. Maybe we can do this by having a program run as 'Xorg' which just passes it's IPC messages to 
//Pathfinder?, and not create a glaring security risk?) I'm not that greatly familiar on how X11 actually works. Maybe we can do something else instead.

//(In an ideal world, we'd have wrappers to support Quartz and Explorer personalities, but I'm not talented enough to do all that work myself, nooo waaayy. Cramming a Mach-O loader is enough.)
//If you REALLY want to run ReactOS or Darwin GUI programs, let WINE and Darling get ports to Waypoint. I'm not doing that.

//Actual binary compatibility with Linux would be nice, but seems like too much work to possibly ever get done, especially since we're not really NIXoid in nature. We're just trying to be flexible.

typedef UINT16 size_t;
typedef INT16 ssize_t;

#define  STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#ifndef NULL
#define NULL 0
#endif


#define F_OK 0
#define X_OK 1
#define W_OK 2
#define R_OK 4

//POSIX 'access()' call...
int access(const char* path, int amode);

//POSIX alarm() call...
unsigned int alarm(unsigned int);

//POSIX chdir() call...
int chdir(const char*); 

//

//External variables.
extern char* optarg;
extern int   optind;
extern int   opterr; 
extern int   optopt;



#endif
