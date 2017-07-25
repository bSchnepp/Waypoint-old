/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */
 
 
 
 //Let's try our best to avoid the legacy mess of trying to metaphorically be a VT100 in a box.
 //Terminals should play nice with the framing system, talk using the standard interfaces of the OS, etc. etc.
 //ie, control + v better do exactly what you think it does.
 
 struct FeralTerminal
 {
	CHAR8* ShellName;
	CHAR8* RunningProgram;
	CHAR8* ShellOwner;
	UINT8  ShellNumber;
 }FeralTerminal;