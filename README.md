# Waypoint

Waypoint is a hobby project of mine, something to work on and add code to when I don't have anything else to really do.
It's nothing big or professional like Linux, and for now, it's only going to run on amd64 (probably off USB 3.0 sticks, that's all I got spare right now).
Just something to passively work on when I don't have other things to do. Filesystem might just end up being a reimplementation of ext4 too, or something. 
Worst case scenario is only FAT32 support.

Total rewrite of the barely functional system I wrote around 3 years ago now.
Since then, some ideas have changed:

	- Waypoint is less UNIX-like than earlier versions that never got to anywhere acceptable.

	- Waypoint is more "self-reliant": it will use it's own make system and it's own libc implementation, etc.

	- Waypoint is more monolithic, rather than being a hybrid kernel. 

	- Waypoint's kernel actually has a name: "Canine", a play on "k9", as this is the 9th rewrite. (That number is a (overestimated?) guess, I don't actually know how many rewrites I've done now.)

___

Waypoint has the following _absolute_ requirements:

	- Provide a multitasking, preemtive environment with support for (flat) virtual memory. Rely on and assume a MMU is present.

	- Portable to many different processor architectures, with amd64 support as an absolute priority. (Small layer to do all the cpu-specific stuff)

	- Easilly adaptable for pretty much anyone to use by (FORCING?/utilizing) Unicode, at the very least internally.

	- Scale well with symmetric multiprocessing systems: tasks should be allocated intelligently. (utilize multiple cores if present)

	- Reasonable POSIX compliance, in an effort to port programs from my host system (Arch Linux) to Waypoint and be self-hosting.

	- Be fairly secure. "Linux level" secure is an impossibility, but something reasonably close is the idea.

	- Implement a bootloader which supports UEFI.

	- Implement graphics as a 'core function' of the operating system. Graqphics must _always_ be present.



And some general design guidelines:

	- Extensibility:
		Don't write code that's not easilly adaptable, extendable, or portable. Just don't. This is an obvious thing. It should be fairly simple to modify a module to add functionality.

	- Reliability:
		The user should never _ever_ see a Stop Error (or "Kernel Panic", same thing.) Do **absolutely everything** in your power to prevent a stop error from happening.
		Never, ever, *ever*, should we **ever** allow a user-space program to tamper with the kernel or device drivers.
		They should always communicate through system calls or some other mechanisms, but NEVER act on them themselves.

	- Performance:
		Absolutely sacrifice **everything** (within reason) to get things like multimedia players or video games to run as fast as possible. Any unnecessary tasks in the way being done by the system should be suspended or stopped in favor of making things like games to run *faster*. 


___
Waypoint isn't UNIX-like with it's filesystem structure.
Instead, Waypoint organizes drives into "modules": totally separate trees where folders can be mounted as drives, but not vice-versa.
As such, rather than '/dev/sda1/, we have "A:0/" (or A:/, as the :0 is implied).
These letter-based drives however, are not 'special files' like in UNIX. They just... work.

Switching between drives from the shell follows the DOS-style/EFI syntax.
```
	B:
```

However, Waypoint isn't too similar to say, ReactOS, either. On Waypoint, "C:\" is _not_ the system drive, but rather, __*A:/*__ *always* is.
Waypoint also mounts partitions (by default) as other "chunks" of the same module -- we can have A:/, A:1/, A:2/, B:/, B:1/, C:/, D:/, E:/, etc.
These "modules", however, *never* "bleed" into each other. They are all separate, just 'exposed' as part of the same drive.

The shell is still being thought up and designed and all, (all just scribble-notes, no code), and will probably look something like this:
```
 BRIAN-PC#Brian@A:/Users/Brian/Desktop/>+: chdir A:/System/Waypoint/ && run "taskmgr.pro"
```
A (barely) working "prototype" for MS-WINDOWS is in another repository, called JvShell.



Waypoint should install with a couple users after installation:
SYSTEM (equivalent to UNIX 'root')
Administrator (Users and Groups are the same thing in Waypoint: a User inherits another User or multiple Users. This is essentially 'sudo' group.)
(USERNAME) (Whatever username you pick at install time.)
