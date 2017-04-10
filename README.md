# Waypoint

Total rewrite of the barely functional "kernel" I wrote around a year ago. (and rewrote 2 years ago and so on)
ie, making it do something beyond put a letter on the screen.

Waypoint is a hobby project of mine, something to work on and add code to when I don't have anything else to really do.
It's created also for the following reasons:
  - I **really** like the MIT license. I'd like to force derivatives to also be open source, but drivers would be nice...
  - Because the old one was __really__ bad. *__Very__* bad.
  - Something that's trivial to port some existing programs over to.
  - Have some fun with IPC and lower level stuff and all. Systems and graphics and everything is fun.
  - Get something besides Android on my phone if I do make an ARM port, because it's fun.
  - "I made that".
  
I'd like to also implement some specific features for Waypoint:
  - UEFI-compatible bootloader. Something short, simple, GUIless, and easy to maintain.
  - BTRFS file system support, or a custom filesystem specifically built for Waypoint.
  - Some programming magic to get some Linux programs running on Waypoint ala WINE or LXSS.
  - A modular kernel that's still quite monolithic, with an emphasis on making IPC **fast**. (Because it's easy to understand).
  - A custom windowing system/compositior/thing, with Wayland support integrated.
  - Ideally, a custom compiler and linker and assembler would be nice, but that's too much. So just clang + nasm.
  - A custom shell, built from scratch, making sure it's *very* obvious Waypoint is it's own thing.
  - A C standard library implementation specifically for Waypoint. 
  - Have a working, stable release before Half-Life 3.
  - Because Linus did it.
  - Be more serious in readmes in the next update.

Some notes and stuff:
  - Files are files. They're not everything. Everything is an _object_, which is *usually* a file, but not **always**.
  - What actually *are* files are run based on their extension. For example, 'waydll.dyn' is always a dynamic library, even if the file contents say otherwise, we disregard that. 'waypro.txt' is a text file, even if it has the PE/ELF/whatever I decide executable header.
  - Locations are mounted based on drives. Not as folders in root and whatever. In this sense, we're **very** DOS-like.
  '''
    A:/Waypoint/System/Kernel/ is a valid directory.
  '''
  - A:/ is "root". We mount partitions like A:1/, A:2/, A:3/, etc. Separate SATA stuff is on B:/, C:/, etc. the :0 for the root is implied.
  - Shell will probably look like this:
```
 Brian@A:/Users/Brian/Desktop\>!: chdir A:/System/Waypoint/ && run "taskmgr.pro"
```

