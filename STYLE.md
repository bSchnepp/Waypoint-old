Code submitted to Waypoint should fit the following guidelines:

We use tabs instead of spaces.
Generally, functions should avoid as much as possible being over 4 tabs in.

System call names should be in the format
<PREFIX> <ACTION> <OBJECT>
We would thus have system calls named like:

```
FERALSTATUS UsCreateProcess(...);
FERALSTATUS KeAllocateMemory(...);
FERALSTATUS KeLoadDriver(...);
FERALSTATUS PpFindDriver(...);
FERALSTATUS UsStartThread(...);
FERALSTATUS UsChangeMode(...);
FERALSTATUS KeForkProcess(..);
```

Prefixes MUST be 2 letters, and fit into the following definitions:
|  Prefix  | Stands for... |
|  :-----: |    :-----:    |
| Ke       | Kernel function |
| Us       | Userspace manipulation |
| Dd       | Device Discovery   |
| Ip       | Inter-process communication |
| Fs       | Filesystem manipulation |
| Vt       | Kernel-based virtualization |
| Io       | Non-filesystem I/O (ie, files)|
| Mm       | Memory management |
| Ob       | Object management |
| Pm       | Power management |
| Rt       | System runtime things |
| Se       | Security features |
| Tm       | System transaction management |
| Um       | User manipulation |
| Ne       | Networking and internet-related stuff. |

Most things in Ke** have direct userspace equivalents. For example, KeForkProcess() in OWaysys is just 'ForkProcess()', and in POSIX is 'fork()'.

Function prototypes should have all of it's arguments on one line. If this is impossible, do something that looks consistent. There's no 80 character limit or anything like that, just make sure it stays consistent with everything else in the same file and files in the same directory.
(A formal standard might be made later.)


We do System V ABI calling convention.
(Stack grows down, parameters passed in registers (if overflow, pass the rest on stack), return value stored in RAX. etc. etc.) You should avoid assembly in the kernel as much as possible (and if you HAVE to put it in, put it under Feral's hardware abstraction layer so it's easier to port between architectures)


## DO NOT EVER PUT MULTIPLE DECLARATIONS ON A SINGLE LINE.

Global functions that aren't system calls should have reasonable names. Don't just name it 'foobar()'.
Functions should be camelase (until I break the rule and do snakecase again, fix that later.)

Local variables shouldn't go too far with naming. "LoopCounter" is too much. Just call it 'i' or 'k'.

Typedefs should have a reason behind why they're typedeffed.
Generally, this is for platform abstraction, naming things, or complying with standards out of our control, or for core function of the kernel (hence, typedef enum FERALSTATUS).
If a typedef can be avoided, avoid it.



**DO NOT EVER DO SOMETHING LIKE
typedef FERALSTATUS*** **pFERALSTATUS;**

NO. We don't do Hungarian notation. Just refer to 'FERALSTATUS*' as 'FERALSTATUS*'.
Compiler knows what type it is. Completely redundant to do that.



Waypoint should have most of it's functionality defined through drivers. These must define a DriverEntry, DriverDispatcher, DriverUnload, etc. function to be loaded.


All braces ALWAYS should be put on their own lines.
Examples:

void function(void)
{
	//code...
}

if (statement)
{
	//code...
}

while (statement)
{
	//code...
}

int array[] =
{
	//Numbers...
}

switch (code)
{
case 1:
	//code...
	break;
default:
	break;
}

etc. etc. Braces should NEVER be omitted. 
