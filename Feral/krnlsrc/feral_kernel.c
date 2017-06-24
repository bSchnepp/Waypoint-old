#include <feral.h>
#include <feral/feralobjs.h>
#include <feral_syscalls.h>

//Things hasn't even been defined yet...
#define KERNEL_DEBUG_MODE
#include <feral/feralstdout.h>
#include <feral/debug_kfunc.h>


#define Build_Date "June 24, 2017\n"
#define Code_Name "Alpha Aligator\n"
//Now's a good time to think about theming. They can be essentially anything, but I'd like a consistent theme.
//The first idea I got was for <ADJECTIVE> + <ANIMAL> where the adjective would have something to do with the OS release, and be the same two letters when possible.
//So we'd get Alpha Aligator, Beta Baboon, Courageous Canine, Dangerous Dog, Expanding Elephant, Furious Fox, ..., Strong Snake, ..., Vengeful Vulpine, ...
//Terribly generic, eh.

//TODO: Bacronym for 'FERAL', Free preEmptive Really Awesome kerneL. That is so awful it's in a creativity league of it's own.
//(Still better than "Freedom pErformance Rallying Amazing kerneL... actually they're both equally awful. Hm.)
//How about combining them? "Free pErformance oRiented Awesome kerneL..?" That's actually not too bad... even if the performance part is exxagerated a bit.

//Expect wchar_t to be 16-bit. Change this into a "CHAR16" later.)
//EFISTUB from kernel will load drivers (and link accordingly) for us before jumping here. Hopefully. TODO on that.
UINTN Kernel_Main(UINTN argc, wchar_t* argv)
{
	printk("Feral kernel loading...\n");
	printk("RELEASE: ");
	printk(Code_Name);
	printk("Build date: ");
	printk(Build_Date);
	printk("Welcome to Feral Waypoint!");
	KThrowStopError(0x100);	//Temporary debug-only function which throws a stop error (essentially a kernel panic) for a specified reason.
	return 0;
}
