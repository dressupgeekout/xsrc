.\" $TOG: X.cpp /main/72 1997/10/13 14:20:40 kaleb $
.\" Copyright (c) 1994  X Consortium
.\" Copyright \(co 2000  The XFree86 Project, Inc.
.\" 
.\" Permission is hereby granted, free of charge, to any person obtaining a
.\" copy of this software and associated documentation files (the "Software"), 
.\" to deal in the Software without restriction, including without limitation 
.\" the rights to use, copy, modify, merge, publish, distribute, sublicense, 
.\" and/or sell copies of the Software, and to permit persons to whom the 
.\" Software furnished to do so, subject to the following conditions:
.\" 
.\" The above copyright notice and this permission notice shall be included in
.\" all copies or substantial portions of the Software.
.\" 
.\" THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
.\" IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
.\" FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL 
.\" THE X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
.\" WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF 
.\" OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
.\" SOFTWARE.
.\" 
.\" Except as contained in this notice, the name of the X Consortium shall not 
.\" be used in advertising or otherwise to promote the sale, use or other 
.\" dealing in this Software without prior written authorization from the 
.\" X Consortium.
.\"
.\" $XFree86$
.\"
.TH X __miscmansuffix__ "XFree86 4.0.2" "X Version 11"
.SH NAME
X \- a portable, network-transparent window system
.SH SYNOPSIS
.PP
The X Window System is a network transparent window system which runs
on a wide range of computing and graphics machines.  It should be
relatively straightforward to build the X Consortium software
distribution on most ANSI C and POSIX compliant systems.  Commercial
implementations are also available for a wide range of platforms.
.PP
The X Consortium requests that the following names be used when
referring to this software:
.sp
.ce 5
X
.br
X Window System
.br
X Version 11
.br
X Window System, Version 11
.br
X11
.PP
.I "X Window System"
is a trademark of X Consortium, Inc.
.SH DESCRIPTION
X Window System servers run on computers with bitmap displays.
The server distributes user input to and accepts output requests from various
client programs through a variety of different interprocess
communication channels.  Although the most common case is for the client
programs to be
running on the same machine as the server, clients can be run transparently
from other machines (including machines with different architectures and
operating systems) as well.
.PP
X supports overlapping hierarchical subwindows and text and
graphics operations, on both monochrome and color
displays.
For a full explanation of the functions that are available, see
the \fIXlib - C Language X Interface\fP manual, 
the \fIX Window System Protocol\fP specification,
the \fIX Toolkit Intrinsics - C Language Interface\fP manual,
and various toolkit documents.
.PP
The number of programs that use \fIX\fP is quite large.
Programs provided in the core X Consortium distribution include:
a terminal emulator, \fIxterm\fP;
a window manager, \fItwm\fP; 
a display manager, \fIxdm\fP;
a console redirect program, \fIxconsole\fP;
a mail interface, \fIxmh\fP;
a bitmap editor, \fIbitmap\fP;
resource listing/manipulation tools, \fIappres\fP, \fIeditres\fP;
access control programs, \fIxauth\fP, \fIxhost\fP, and \fIiceauth\fP;
user preference setting programs, \fIxrdb\fP, \fIxcmsdb\fP,
\fIxset\fP, \fIxsetroot\fP, \fIxstdcmap\fP, and \fIxmodmap\fP;
clocks, \fIxclock\fP and \fIoclock\fP;
a font displayer, (\fIxfd\fP;
utilities for listing information about fonts, windows, and displays,
\fIxlsfonts\fP, \fIxwininfo\fP, \fIxlsclients\fP,
\fIxdpyinfo\fP, \fIxlsatoms\fP, and \fIxprop\fP;
screen image manipulation utilities, \fIxwd\fP, \fIxwud\fP, and \fIxmag\fP;
a performance measurement utility, \fIx11perf\fP;
a font compiler, \fIbdftopcf\fP;
a font server and related utilities, \fIxfs\fP, \fIfsinfo\fP, \fIfslsfonts\fP, \fIfstobdf\fP;
an X Image Extension exerciser, \fIxieperf\fP;
a display server and related utilities, \fIXserver\fP, \fIrgb\fP, \fImkfontdir\fP;
remote execution utilities, \fIrstart\fP and \fIxon\fP;
a clipboard manager, \fIxclipboard\fP;
keyboard description compiler and related utilities, \fIxkbcomp\fP, 
\fIxkbprint\fP, \fIxkbbell\fP, \fIxkbevd\fP, \fIxkbvleds\fP, and \fIxkbwatch\fP;
a utility to terminate clients, \fIxkill\fP; 
an optimized X protocol proxy, \fIlbxproxy\fP;
a firewall security proxy, \fIxfwp\fP;
a proxy manager to control them, \fIproxymngr\fP;
a utility to find proxies, \fIxfindproxy\fP;
Netscape Navigator Plug-ins, \fIlibxrx.so\fP and \fIlibxrxnest.so\fP;
an RX MIME-type helper program, \fIxrx\fP;
and a utility to cause part or all of the screen to be redrawn, \fIxrefresh\fP. 
.PP
Many other utilities, window managers, games, toolkits, etc. are included
as user-contributed software in the X Consortium distribution, or are
available using anonymous ftp on the Internet.
See your site administrator for details.
.SH "STARTING UP"
.PP 
There are two main ways of getting the X server and an initial set of
client applications started.  The particular method used depends on what
operating system you are running and whether or not you use other window
systems in addition to X.
.TP 8
.B "\fIxdm\fP (the X Display Manager)"
If you want to always have X running on your display, your site administrator
can set your machine up to use the X Display Manager \fIxdm\fP.  This program
is typically started by the system at boot time and takes care of keeping the
server running and getting users logged in.  If you are running
\fIxdm\fP, you will see a window on the screen welcoming you to the system and
asking for your username and password.  Simply type them in as you would at
a normal terminal, pressing the Return key after each.  If you make a mistake,
\fIxdm\fP will display an error message and ask you to try again.  After you
have successfully logged in, \fIxdm\fP will start up your X environment.  By
default, if you have an executable file named \fI.xsession\fP in your
home directory,
\fIxdm\fP will treat it as a program (or shell script) to run to start up 
your initial clients (such as terminal emulators, clocks, a window manager,
user settings for things like the background, the speed of the pointer, etc.).
Your site administrator can provide details.
.TP 8
.B "\fIxinit\fP (run manually from the shell)"
Sites that support more than one window system might choose to use the
\fIxinit\fP program for starting X manually.  If this is true for your 
machine, your site administrator will probably have provided a program 
named "x11", "startx", or "xstart" that will do site-specific initialization
(such as loading convenient default resources, running a window manager, 
displaying a clock, and starting several terminal emulators) in a nice
way.  If not, you can build such a script using the \fIxinit\fP program.
This utility simply runs one user-specified program to start the server,
runs another to start up any desired clients, and then waits for either to
finish.  Since either or both of the user-specified programs may be a shell 
script, this gives substantial flexibility at the expense of a
nice interface.  For this reason, \fIxinit\fP is not intended for end users.
.SH "DISPLAY NAMES"
.PP
From the user's perspective, every X server has a \fIdisplay name\fP of the
form:
.sp
.ce 1
\fIhostname:displaynumber.screennumber\fP
.sp
This information is used by the application to determine how it should
connect to the server and which screen it should use by default
(on displays with multiple monitors):
.TP 8
.I hostname
The \fIhostname\fP specifies the name of the machine to which the display is
physically connected.  If the hostname is not given, the most efficient way of 
communicating to a server on the same machine will be used.
.TP 8
.I displaynumber
The phrase "display" is usually used to refer to collection of monitors that
share a common keyboard and pointer (mouse, tablet, etc.).  Most workstations
tend to only have one keyboard, and therefore, only one display.  Larger, 
multi-user
systems, however, frequently have several displays so that more than
one person can be doing graphics work at once.  To avoid confusion, each
display on a machine is assigned a \fIdisplay number\fP (beginning at 0)
when the X server for that display is started.  The display number must always
be given in a display name.
.TP 8
.I screennumber
Some displays share a single keyboard and pointer among two or more monitors.
Since each monitor has its own set of windows, each screen is assigned a
\fIscreen number\fP (beginning at 0) when the X server for that display is
started.  If the screen number is not given, screen 0 will be used.
.PP
On POSIX systems, the default display name is stored 
in your DISPLAY environment variable.  This variable is set automatically
by the \fIxterm\fP terminal emulator.  However, when you log into another
machine on a network, you will need to set DISPLAY by hand to point to your
display.  For example,
.sp
.nf
    % setenv DISPLAY myws:0
    $ DISPLAY=myws:0; export DISPLAY
.fi
The \fIxon\fP script can be used to start an X program on a remote machine;
it automatically sets the DISPLAY variable correctly.
.PP
Finally, most X programs accept a command line option of 
\fB-display \fIdisplayname\fR to temporarily override the contents of
DISPLAY.  This is most commonly used to pop windows on another person's
screen or as part of a "remote shell" command to start an xterm pointing back 
to your display.  For example,
.sp
.nf
    % xeyes -display joesws:0 -geometry 1000x1000+0+0
    % rsh big xterm -display myws:0 -ls </dev/null &
.fi
.PP
X servers listen for connections on a variety of different 
communications channels (network byte streams, shared memory, etc.).
Since there can be more than one way of contacting a given server,
The \fIhostname\fP part of the display name is used to determine the
type of channel 
(also called a transport layer) to be used.  X servers generally
support the following types of connections:
.TP 8
.I "local"
.br
The hostname part of the display name should be the empty string.
For example:  \fI:0\fP, \fI:1\fP, and \fI:0.1\fP.  The most efficient
local transport will be chosen.
.TP 8
.I TCP\/IP
.br
The hostname part of the display name should be the server machine's
IP address name.  Full Internet names, abbreviated names, and IP addresses
are all allowed.  For example:  \fIx.org:0\fP, \fIexpo:0\fP,
\fI198.112.45.11:0\fP, \fIbigmachine:1\fP, and \fIhydra:0.1\fP.
.TP 8
.I DECnet
.br
The hostname part of the display name should be the server machine's 
nodename, followed by two colons instead of one.
For example:  \fImyws::0\fP, \fIbig::1\fP, and \fIhydra::0.1\fP.
.PP
.SH "ACCESS CONTROL"
An X server can use several types of access control.  Mechanisms provided
in Release 6 are:
.nf
.br
.ta 3.4i
    Host Access	Simple host-based access control.
    MIT-MAGIC-COOKIE-1	Shared plain-text "cookies".
    XDM-AUTHORIZATION-1	Secure DES based private-keys.
    SUN-DES-1	Based on Sun's secure rpc system.
    MIT-KERBEROS-5	Kerberos Version 5 user-to-user.
.fi
.PP
\fIXdm\fP initializes access control for the server and also places
authorization information in a file accessible to the user.
Normally, the list of hosts from
which connections are always accepted should be empty, so that only clients
with are explicitly authorized can connect to the display.  When you add
entries to the host list (with \fIxhost\fP), the server no longer performs any
authorization on connections from those machines.  Be careful with this.
.PP
The file from which \fIXlib\fP extracts authorization data can be
specified with the environment variable \fBXAUTHORITY\fP, and defaults to
the file \fB.Xauthority\fP in the home directory.  \fIXdm\fP uses
\fB$HOME/.Xauthority\fP and will create it or merge in authorization records
if it already exists when a user logs in.
.PP
If you use several machines and share a common home directory
across all of the machines by means of a network file system,
you never really have to worry about authorization files,
the system should work correctly by default.
Otherwise, as the authorization files are machine-independent,
you can simply copy the files to share them.
To manage authorization files, use \fIxauth\fP.
This program allows you to extract
records and insert them into other files.  Using this, you can send
authorization to remote machines when you login,
if the remote machine does not share a common home directory with
your local machine.
Note that authorization information transmitted
``in the clear'' through a network file system or
using \fIftp\fP or \fIrcp\fP can be ``stolen''
by a network eavesdropper, and as such may enable unauthorized access.
In many environments, this level of security is not a concern, but if it is,
you need to know the exact semantics of the particular authorization
data to know if this is actually a problem.
.PP
For more information on access control, see the \fIXsecurity\fP manual page.
.SH "GEOMETRY SPECIFICATIONS"
One of the advantages of using window systems instead of
hardwired terminals is that 
applications don't have to be restricted to a particular size or location
on the screen.
Although the layout of windows on a display is controlled
by the window manager that the user is running (described below), 
most X programs accept
a command line argument of the form \fB-geometry \fIWIDTHxHEIGHT+XOFF+YOFF\fR
(where \fIWIDTH\fP, \fIHEIGHT\fP, \fIXOFF\fP, and \fIYOFF\fP are numbers)
for specifying a preferred size and location for this application's main
window.
.PP
The \fIWIDTH\fP and \fIHEIGHT\fP parts of the geometry specification are
usually measured in either pixels or characters, depending on the application.
The \fIXOFF\fP and \fIYOFF\fP parts are measured in pixels and are used to
specify the distance of the window from the left or right and top and bottom
edges of the screen, respectively.  Both types of offsets are measured from the
indicated edge of the screen to the corresponding edge of the window.  The X
offset may be specified in the following ways:
.TP 8
.I +XOFF
The left edge of the window is to be placed \fIXOFF\fP pixels in from the
left edge of the screen (i.e., the X coordinate of the window's origin will be 
\fIXOFF\fP).  \fIXOFF\fP may be negative, in which case the window's left edge 
will be off the screen.
.TP 8
.I -XOFF
The right edge of the window is to be placed \fIXOFF\fP pixels in from the
right edge of the screen.  \fIXOFF\fP may be negative, in which case the 
window's right edge will be off the screen.
.PP
The Y offset has similar meanings:
.TP 8
.I +YOFF
The top edge of the window is to be \fIYOFF\fP pixels below the
top edge of the screen (i.e., the Y coordinate of the window's origin will be
\fIYOFF\fP).  \fIYOFF\fP may be negative, in which case the window's top edge 
will be off the screen.
.TP 8
.I -YOFF
The bottom edge of the window is to be \fIYOFF\fP pixels above the
bottom edge of the screen.  \fIYOFF\fP may be negative, in which case 
the window's bottom edge will be off the screen.
.PP
Offsets must be given as pairs; in other words, in order to specify either
\fIXOFF\fP or \fIYOFF\fP both must be present.  Windows can be placed in the
four corners of the screen using the following specifications:
.TP 8
.I +0+0
upper left hand corner.
.TP 8
.I -0+0
upper right hand corner.
.TP 8
.I -0-0
lower right hand corner.
.TP 8
.I +0-0
lower left hand corner.
.PP
In the following examples, a terminal emulator is placed in roughly
the center of the screen and
a load average monitor, mailbox, and clock are placed in the upper right 
hand corner:
.sp
.nf
    xterm -fn 6x10 -geometry 80x24+30+200 &
    xclock -geometry 48x48-0+0 &
    xload -geometry 48x48-96+0 &
    xbiff -geometry 48x48-48+0 &
.fi
.PP
.SH "WINDOW MANAGERS"
The layout of windows on the screen is controlled by special programs called
\fIwindow managers\fP.  Although many window managers will honor geometry
specifications as given, others may choose to ignore them (requiring the user
to explicitly draw the window's region on the screen with the pointer, for 
example).
.PP
Since window managers are regular (albeit complex) client programs,
a variety of different user interfaces can be built.  The X Consortium distribution
comes with a window manager named \fItwm\fP which supports overlapping windows,
popup menus, point-and-click or click-to-type input models, title bars, nice
icons (and an icon manager for those who don't like separate icon windows).
.PP
See the user-contributed software in the X Consortium distribution for other
popular window managers.
.SH "FONT NAMES"
Collections of characters for displaying text and symbols in X are known as
\fIfonts\fP.  A font typically contains images that share a common appearance
and look nice together (for example, a single size, boldness, slant, and
character set).  Similarly, collections of fonts that are based on a common
type face (the variations are usually called roman, bold, italic, bold italic, 
oblique, and bold oblique) are called \fIfamilies\fP.  
.PP
Fonts come in various sizes.  The X server supports \fIscalable\fP fonts,
meaning it is possible to create a font of arbitrary size from a single
source for the font.  The server supports scaling from \fIoutline\fP
fonts and \fIbitmap\fP fonts.  Scaling from outline fonts usually produces
significantly better results than scaling from bitmap fonts.
.PP
An X server can obtain fonts from individual files stored in directories
in the file system, or from one or more font servers,
or from a mixtures of directories and font servers.
The list of places the server looks when trying to find
a font is controlled by its \fIfont path\fP.  Although most installations
will choose to have the server start up with all of the commonly used font
directories in the font path, the font path can be changed at any time
with the \fIxset\fP program.
However, it is important to remember that the directory names are
on the \fBserver\fP's machine, not on the application's.
.PP
Bitmap font files are usually created by compiling a textual font description
into binary form, using \fIbdftopcf\fP.
Font databases are created by running the \fImkfontdir\fP program in the
directory containing the source or compiled versions of the fonts.
Whenever fonts are added to a directory, \fImkfontdir\fP should be rerun
so that the server can find the new fonts.  To make the server reread the
font database, reset the font path with the \fIxset\fP program.  For example,
to add a font to a private directory, the following commands could be used:
.sp
.nf
    % cp newfont.pcf ~/myfonts
    % mkfontdir ~/myfonts
    % xset fp rehash 
.fi
.PP
The \fIxfontsel\fP and \fIxlsfonts\fP programs can be used to browse
through the fonts available on a server.
Font names tend to be fairly long as they contain all of the information
needed to uniquely identify individual fonts.  However, the X server
supports wildcarding of font names, so the full specification
.sp
.nf
    \fI-adobe-courier-medium-r-normal--10-100-75-75-m-60-iso8859-1\fP
.fi
.sp
might be abbreviated as:
.sp
.nf
    \fI-*-courier-medium-r-normal--*-100-*-*-*-*-iso8859-1\fP
.fi
.PP
Because the shell also has special meanings for \fI*\fP and \fI?\fP,
wildcarded font names should be quoted:
.sp
.nf
    % xlsfonts -fn '-*-courier-medium-r-normal--*-100-*-*-*-*-*-*'
.fi
.PP
The \fIxlsfonts\fP program can be used to list all of the fonts that
match a given pattern.  With no arguments, it lists all available fonts.
This will usually list the same font at many different sizes.  To see
just the base scalable font names, try using one of the following patterns:
.sp
.nf
    \fI-*-*-*-*-*-*-0-0-0-0-*-0-*-*\fP
    \fI-*-*-*-*-*-*-0-0-75-75-*-0-*-*\fP
    \fI-*-*-*-*-*-*-0-0-100-100-*-0-*-*\fP
.fi
.PP
To convert one of the resulting names into a font at a specific size,
replace one of the first two zeros with a nonzero value.
The field containing the first zero is for the pixel size; replace it
with a specific height in pixels to name a font at that size.
Alternatively, the field containing the second zero is for the point size;
replace it with a specific size in decipoints (there are 722.7 decipoints to
the inch) to name a font at that size.
The last zero is an average width field, measured in tenths of pixels;
some servers will anamorphically scale if this value is specified.
.SH "FONT SERVER NAMES"
One of the following forms can be used to name a font server that
accepts TCP connections:
.sp
.nf
    tcp/\fIhostname\fP:\fIport\fP
    tcp/\fIhostname\fP:\fIport\fP/\fIcataloguelist\fP
.fi
.PP
The \fIhostname\fP specifies the name (or decimal numeric address)
of the machine on which the font server is running.  The \fIport\fP
is the decimal TCP port on which the font server is listening for connections.
The \fIcataloguelist\fP specifies a list of catalogue names,
with '+' as a separator.
.PP
Examples: \fItcp/x.org:7100\fP, \fItcp/198.112.45.11:7100/all\fP.
.PP
One of the following forms can be used to name a font server that
accepts DECnet connections:
.sp
.nf
    decnet/\fInodename\fP::font$\fIobjname\fP
    decnet/\fInodename\fP::font$\fIobjname\fP/\fIcataloguelist\fP
.fi
.PP
The \fInodename\fP specifies the name (or decimal numeric address)
of the machine on which the font server is running.
The \fIobjname\fP is a normal, case-insensitive DECnet object name.
The \fIcataloguelist\fP specifies a list of catalogue names,
with '+' as a separator.
.PP
Examples: \fIDECnet/SRVNOD::FONT$DEFAULT\fP, \fIdecnet/44.70::font$special/symbols\fP.
.SH "COLOR NAMES"
Most applications provide ways of tailoring (usually through resources or
command line arguments) the colors of various elements
in the text and graphics they display.
A color can be specified either by an abstract color name,
or by a numerical color specification.
The numerical specification can identify a color in either
device-dependent (RGB) or device-independent terms.
Color strings are case-insensitive.
.PP
X supports the use of abstract color names, for example, "red", "blue".
A value for this abstract name is obtained by searching one or more color
name databases.
\fIXlib\fP first searches zero or more client-side databases;
the number, location, and content of these databases is
implementation dependent.
If the name is not found, the color is looked up in the
X server's database.
The text form of this database is commonly stored in the file
\fI<XRoot>/lib/X11/rgb.txt\fP, where <XRoot> is replaced by the 
root of the X11 install tree.
.PP
A numerical color specification
consists of a color space name and a set of values in the following syntax:
.sp
.nf
    \fI<color_space_name>\fP:\fI<value>/.../<value>\fP
.fi
.PP
An RGB Device specification is identified by
the prefix "rgb:" and has the following syntax:
.sp
.nf
    rgb:\fI<red>/<green>/<blue>\fP

        \fI<red>\fP, \fI<green>\fP, \fI<blue>\fP := \fIh\fP | \fIhh\fP | \fIhhh\fP | \fIhhhh\fP
        \fIh\fP := single hexadecimal digits
.fi
Note that \fIh\fP indicates the value scaled in 4 bits, 
\fIhh\fP the value scaled in 8 bits,
\fIhhh\fP the value scaled in 12 bits,
and \fIhhhh\fP the value scaled in 16 bits, respectively.
These values are passed directly to the X server,
and are assumed to be gamma corrected.
.PP
The eight primary colors can be represented as:
.sp
.ta 2.5i
.nf
    black	rgb:0/0/0
    red	rgb:ffff/0/0
    green	rgb:0/ffff/0
    blue	rgb:0/0/ffff
    yellow	rgb:ffff/ffff/0
    magenta	rgb:ffff/0/ffff
    cyan	rgb:0/ffff/ffff
    white	rgb:ffff/ffff/ffff
.fi
.PP
For backward compatibility, an older syntax for RGB Device is
supported, but its continued use is not encouraged.
The syntax is an initial sharp sign character followed by
a numeric specification, in one of the following formats:
.sp
.ta 3i
.nf
    #RGB	(4 bits each)
    #RRGGBB	(8 bits each)
    #RRRGGGBBB	(12 bits each)
    #RRRRGGGGBBBB	(16 bits each)
.fi
.PP
The R, G, and B represent single hexadecimal digits.
When fewer than 16 bits each are specified, 
they represent the most-significant bits of the value
(unlike the "rgb:" syntax, in which values are scaled).
For example, #3a7 is the same as #3000a0007000.
.PP
An RGB intensity specification is identified
by the prefix "rgbi:" and has the following syntax:
.sp
.nf
    rgbi:\fI<red>/<green>/<blue>\fP
.fi
.PP
The red, green, and blue are floating point values
between 0.0 and 1.0, inclusive.
They represent linear intensity values, with
1.0 indicating full intensity, 0.5 half intensity, and so on.
These values will be gamma corrected by \fIXlib\fP
before being sent to the X server.
The input format for these values is an optional sign,
a string of numbers possibly containing a decimal point,
and an optional exponent field containing an E or e 
followed by a possibly signed integer string.
.PP
The standard device-independent string specifications have
the following syntax:
.sp
.ta 3.5i
.nf
    CIEXYZ:\fI<X>/<Y>/<Z>\fP	(\fInone\fP, 1, \fInone\fP)
    CIEuvY:\fI<u>/<v>/<Y>\fP	(~.6, ~.6, 1)
    CIExyY:\fI<x>/<y>/<Y>\fP	(~.75, ~.85, 1)
    CIELab:\fI<L>/<a>/<b>\fP	(100, \fInone\fP, \fInone\fP)
    CIELuv:\fI<L>/<u>/<v>\fP	(100, \fInone\fP, \fInone\fP)
    TekHVC:\fI<H>/<V>/<C>\fP	(360, 100, 100)
.fi
.PP
All of the values (C, H, V, X, Y, Z, a, b, u, v, y, x) are
floating point values.  Some of the values are constrained to
be between zero and some upper bound; the upper bounds are
given in parentheses above.
The syntax for these values is an optional '+' or '-' sign,
a string of digits possibly containing a decimal point,
and an optional exponent field consisting of an 'E' or 'e'
followed by an optional '+' or '-' followed by a string of digits.
.PP
For more information on device independent color,
see the \fIXlib\fP reference manual.
.SH KEYBOARDS
.PP
The X keyboard model is broken into two layers:  server-specific codes
(called \fIkeycodes\fP) which represent the physical keys, and 
server-independent symbols (called \fIkeysyms\fP) which
represent the letters or words that appear on the keys.  
Two tables are kept in the server for converting keycodes to keysyms:
.TP 8
.I "modifier list"
Some keys (such as Shift, Control, and Caps Lock) are known as \fImodifier\fP
and are used to select different symbols that are attached to a single key
(such as Shift-a generates a capital A, and Control-l generates a control
character ^L).  The server keeps a list of keycodes corresponding to the
various modifier keys.  Whenever a key is pressed or released, the server 
generates an \fIevent\fP that contains the keycode of the indicated key as 
well as a mask that specifies which of the modifier keys are currently pressed.
Most servers set up this list to initially contain
the various shift, control, and shift lock keys on the keyboard.  
.TP 8
.I "keymap table"
Applications translate event keycodes and modifier masks into keysyms
using a \fIkeysym table\fP which contains one row for each keycode and one
column for various modifier states.  This table is initialized by the server
to correspond to normal typewriter conventions.  The exact semantics of
how the table is interpreted to produce keysyms depends on the particular
program, libraries, and language input method used, but the following
conventions for the first four keysyms in each row are generally adhered to:
.PP
The first four elements of the list are split into two groups of keysyms.
Group 1 contains the first and second keysyms;
Group 2 contains the third and fourth keysyms.
Within each group,
if the first element is alphabetic and the
the second element is the special keysym \fINoSymbol\fP,
then the group is treated as equivalent to a group in which
the first element is the lowercase letter and the second element
is the uppercase letter.
.PP
Switching between groups is controlled by the keysym named MODE SWITCH,
by attaching that keysym to some key and attaching
that key to any one of the modifiers Mod1 through Mod5.
This modifier is called the ``group modifier.''
Group 1 is used when the group modifier is off,
and Group 2 is used when the group modifier is on.
.PP
Within a group,
the modifier state determines which keysym to use.
The first keysym is used when the Shift and Lock modifiers are off.
The second keysym is used when the Shift modifier is on,
when the Lock modifier is on and the second keysym is uppercase alphabetic,
or when the Lock modifier is on and is interpreted as ShiftLock.
Otherwise, when the Lock modifier is on and is interpreted as CapsLock,
the state of the Shift modifier is applied first to select a keysym;
but if that keysym is lowercase alphabetic,
then the corresponding uppercase keysym is used instead.
.SH OPTIONS
Most X programs attempt to use the same names for command line options and
arguments.  All applications written with the X Toolkit Intrinsics
automatically accept the following options:
.TP 8
.B \-display \fIdisplay\fP
This option specifies the name of the X server to use.
.TP 8
.B \-geometry \fIgeometry\fP
This option specifies the initial size and location of the window.
.TP 8
.B \-bg \fIcolor\fP, \fB\-background \fIcolor\fP
Either option specifies the color to use for the window background.
.TP 8
.B \-bd \fIcolor\fP, \fB\-bordercolor \fIcolor\fP
Either option specifies the color to use for the window border.
.TP 8
.B \-bw \fInumber\fP, \fB\-borderwidth \fInumber\fP
Either option specifies the width in pixels of the window border.
.TP 8
.B \-fg \fIcolor\fP, \fB\-foreground \fIcolor\fP
Either option specifies the color to use for text or graphics.
.TP 8
.B \-fn \fIfont\fP, \fB-font \fIfont\fP
Either option specifies the font to use for displaying text.
.TP 8
.B \-iconic
.br
This option indicates that the user would prefer that the application's
windows initially not be visible as if the windows had be immediately 
iconified by the user.  Window managers may choose not to honor the
application's request.  
.TP 8
.B \-name
.br
This option specifies the name under which resources for the
application should be found.  This option is useful in shell
aliases to distinguish between invocations of an application,
without resorting to creating links to alter the executable file name.
.TP 8
.B \-rv\fP, \fB\-reverse\fP
Either option indicates that the program should simulate reverse video if 
possible, often by swapping the foreground and background colors.  Not all
programs honor this or implement it correctly.  It is usually only used on
monochrome displays.
.TP 8
.B \+rv
.br
This option indicates that the program should not simulate reverse video.  
This is used to
override any defaults since reverse video doesn't always work properly.
.TP 8
.B \-selectionTimeout
This option specifies the timeout in milliseconds within which two
communicating applications must respond to one another for a selection
request.
.TP 8
.B \-synchronous
This option indicates that requests to the X server should be sent 
synchronously, instead of asynchronously.  Since 
.I Xlib
normally buffers requests to the server, errors do not necessarily get reported
immediately after they occur.  This option turns off the buffering so that
the application can be debugged.  It should never be used with a working 
program.
.TP 8
.B \-title \fIstring\fP
This option specifies the title to be used for this window.  This information 
is sometimes
used by a window manager to provide some sort of header identifying the window.
.TP 8
.B \-xnllanguage \fIlanguage[_territory][.codeset]\fP
This option specifies the language, territory, and codeset for use in
resolving resource and other filenames.
.TP 8
.B \-xrm \fIresourcestring\fP
This option specifies a resource name and value to override any defaults.  It 
is also very useful for setting resources that don't have explicit command 
line arguments.
.SH RESOURCES
To make the tailoring of applications to personal preferences easier, X 
provides a mechanism for storing default values for program resources
(e.g. background color, window title, etc.)
Resources are specified as strings
that are read in from various places when an application is run.
Program components are named in a hierarchical fashion,
with each node in the hierarchy identified by a class and an instance name.
At the top level is the class and instance name of the application itself.
By convention, the class name of the application is the same as the program
name, but with  the first letter capitalized (e.g. \fIBitmap\fP or \fIEmacs\fP)
although some programs that begin with the letter ``x'' also capitalize the
second letter for historical reasons.
.PP
The precise syntax for resources is:
.PP
.nf
.ta 1.8i 2.0i
ResourceLine	=	Comment | IncludeFile | ResourceSpec | <empty line>
Comment	=	"!" {<any character except null or newline>}
IncludeFile	=	"#" WhiteSpace "include" WhiteSpace FileName WhiteSpace
FileName	=	<valid filename for operating system>
ResourceSpec	=	WhiteSpace ResourceName WhiteSpace ":" WhiteSpace Value
ResourceName	=	[Binding] {Component Binding} ComponentName
Binding	=	"\&." | "*"
WhiteSpace	=	{<space> | <horizontal tab>}
Component	=	"?" | ComponentName
ComponentName	=	NameChar {NameChar}
NameChar	=	"a"\-"z" | "A"\-"Z" | "0"\-"9" | "_" | "-"
Value	=	{<any character except null or unescaped newline>}
.fi
.PP
Elements separated by vertical bar (|) are alternatives.
Curly braces ({\&.\&.\&.}) indicate zero or more repetitions
of the enclosed elements.
Square brackets ([\&.\&.\&.]) indicate that the enclosed element is optional.
Quotes ("\&.\&.\&.") are used around literal characters.
.PP
IncludeFile lines are interpreted by replacing the line with the
contents of the specified file.  The word "include" must be in lowercase.
The filename is interpreted relative to the directory of the file in
which the line occurs (for example, if the filename contains no
directory or contains a relative directory specification).
.PP
If a ResourceName contains a contiguous sequence of two or more Binding
characters, the sequence will be replaced with single "\&." character
if the sequence contains only "\&." characters,
otherwise the sequence will be replaced with a single "*" character.
.PP
A resource database never contains more than one entry for a given
ResourceName.  If a resource file contains multiple lines with the
same ResourceName, the last line in the file is used.
.PP
Any whitespace character before or after the name or colon in a ResourceSpec
are ignored.
To allow a Value to begin with whitespace,
the two-character sequence ``\\\^\fIspace\fP'' (backslash followed by space)
is recognized and replaced by a space character,
and the two-character sequence ``\\\^\fItab\fP''
(backslash followed by horizontal tab)
is recognized and replaced by a horizontal tab character.
To allow a Value to contain embedded newline characters,
the two-character sequence ``\\\^n'' is recognized and replaced by a
newline character.
To allow a Value to be broken across multiple lines in a text file,
the two-character sequence ``\\\^\fInewline\fP''
(backslash followed by newline) is
recognized and removed from the value.
To allow a Value to contain arbitrary character codes,
the four-character sequence ``\\\^\fInnn\fP'',
where each \fIn\fP is a digit character in the range of ``0''\-``7'',
is recognized and replaced with a single byte that contains
the octal value specified by the sequence.
Finally, the two-character sequence ``\\\\'' is recognized
and replaced with a single backslash.
.PP
When an application looks for the value of a resource, it specifies
a complete path in the hierarchy, with both class and instance names.
However, resource values are usually given with only partially specified
names and classes, using pattern matching constructs.
An asterisk (*) is a loose binding and is used to represent any number
of intervening components, including none.
A period (.) is a tight binding and is used to separate immediately
adjacent components.
A question mark (?) is used to match any single component name or class.
A database entry cannot end in a loose binding;
the final component (which cannot be "?") must be specified.
The lookup algorithm searches the resource database for the entry that most
closely matches (is most specific for) the full name and class being queried.
When more than one database entry matches the full name and class,
precedence rules are used to select just one.
.LP
The full name and class are scanned from left to right (from highest
level in the hierarchy to lowest), one component at a time.
At each level, the corresponding component and/or binding of each
matching entry is determined, and these matching components and
bindings are compared according to precedence rules.
Each of the rules is applied at each level,
before moving to the next level,
until a rule selects a single entry over all others.
The rules (in order of precedence) are:
.IP 1. 5
An entry that contains a matching component (whether name, class, or "?")
takes precedence over entries that elide the level (that is, entries
that match the level in a loose binding).
.IP 2. 5
An entry with a matching name takes precedence over both
entries with a matching class and entries that match using "?".
An entry with a matching class takes precedence over
entries that match using "?".
.IP 3. 5
An entry preceded by a tight binding takes precedence over entries
preceded by a loose binding.
.PP
Programs based on the X Tookit Intrinsics
obtain resources from the following sources
(other programs usually support some subset of these sources):
.TP 8
.B "RESOURCE_MANAGER root window property"
Any global resources that should be available to clients on all machines 
should be stored in the RESOURCE_MANAGER property on the
root window of the first screen using the \fIxrdb\fP program.
This is frequently taken care
of when the user starts up X through the display manager or \fIxinit\fP.
.TP 8
.B "SCREEN_RESOURCES root window property"
Any resources specific to a given screen (e.g. colors)
that should be available to clients on all machines 
should be stored in the SCREEN_RESOURCES property on the
root window of that screen.
The \fIxrdb\fP program will sort resources automatically and place them
in RESOURCE_MANAGER or SCREEN_RESOURCES, as appropriate.
.TP 8
.B "application-specific files"
Directories named by the environment variable XUSERFILESEARCHPATH
or the environment variable XAPPLRESDIR (which names a single
directory and should end with a '/' on POSIX systems), plus directories in a
standard place (usually under <XRoot>/lib/X11/,
but this can be overridden with the XFILESEARCHPATH environment variable)
are searched for for application-specific resources.
For example, application default resources are usually kept in
<XRoot>/lib/X11/app-defaults/.
See the \fIX Toolkit Intrinsics - C Language Interface\fP manual for
details.
.TP 8
.B XENVIRONMENT
Any user- and machine-specific resources may be specified by setting
the XENVIRONMENT environment variable to the name of a resource file
to be loaded by all applications.  If this variable is not defined,
a file named \fI$HOME\fP/.Xdefaults-\fIhostname\fP is looked for instead,
where \fIhostname\fP is the name of the host where the application
is executing.
.TP 8
.B \-xrm \fIresourcestring\fP
Resources can also be specified from the 
command line.  The \fIresourcestring\fP is a single resource name and value as
shown above.  Note that if the string contains characters interpreted by
the shell (e.g., asterisk), they must be quoted.
Any number of \fB\-xrm\fP arguments may be given on the
command line.
.PP
Program resources are organized into groups called \fIclasses\fP, so that 
collections of individual resources (each of which are 
called \fIinstances\fP)
can be set all at once.  By convention, the instance name of a resource
begins with a lowercase letter and class name with an upper case letter.
Multiple word resources are concatenated with the first letter of the 
succeeding words capitalized.  Applications written with the X Toolkit
Intrinsics will have at least the following resources:
.PP
.TP 8
.B background (\fPclass\fB Background)
This resource specifies the color to use for the window background.
.PP
.TP 8
.B borderWidth (\fPclass\fB BorderWidth)
This resource specifies the width in pixels of the window border.
.PP
.TP 8
.B borderColor (\fPclass\fB BorderColor)
This resource specifies the color to use for the window border.
.PP
Most applications using the X Toolkit Intrinsics also have the resource
\fBforeground\fP
(class \fBForeground\fP), specifying the color to use for text
and graphics within the window.
.PP
By combining class and instance specifications, application preferences 
can be set quickly and easily.  Users of color displays will frequently
want to set Background and Foreground classes to particular defaults.
Specific color instances such as text cursors can then be overridden
without having to define all of the related resources.  For example,
.sp
.nf
    bitmap*Dashed:  off
    XTerm*cursorColor:  gold
    XTerm*multiScroll:  on
    XTerm*jumpScroll:  on
    XTerm*reverseWrap:  on
    XTerm*curses:  on
    XTerm*Font:  6x10
    XTerm*scrollBar: on
    XTerm*scrollbar*thickness: 5
    XTerm*multiClickTime: 500
    XTerm*charClass:  33:48,37:48,45-47:48,64:48
    XTerm*cutNewline: off
    XTerm*cutToBeginningOfLine: off
    XTerm*titeInhibit:  on
    XTerm*ttyModes:  intr ^c erase ^? kill ^u
    XLoad*Background: gold
    XLoad*Foreground: red
    XLoad*highlight: black
    XLoad*borderWidth: 0
    emacs*Geometry:  80x65-0-0
    emacs*Background:  rgb:5b/76/86
    emacs*Foreground:  white
    emacs*Cursor:  white
    emacs*BorderColor:  white
    emacs*Font:  6x10
    xmag*geometry: -0-0
    xmag*borderColor:  white
.fi
.PP
If these resources were stored in a file called \fI.Xresources\fP in your home
directory, they could be added to any existing resources in the server with
the following command:
.sp
.nf
    % xrdb -merge $HOME/.Xresources
.fi
.sp
This is frequently how user-friendly startup scripts merge user-specific 
defaults
into any site-wide defaults.  All sites are encouraged to set up convenient
ways of automatically loading resources. See the \fIXlib\fP 
manual section \fIResource Manager Functions\fP for more information.
.SH ENVIRONMENT
.TP
.SM
.B DISPLAY
This is the only mandatory environment variable. It must point to an
X server. See section "Display Names" above.
.TP
.SM
.B XAUTHORITY
This must point to a file that contains authorization data. The default
is \fI$HOME/.Xauthority\fP. See
.BR Xsecurity (__miscmansuffix__),
.BR xauth (1),
.BR xdm (1),
.BR Xau (3).
.TP
.SM
.B ICEAUTHORITY
This must point to a file that contains authorization data. The default
is \fI$HOME/.ICEauthority\fP.
.TP
.SM
.BR LC_ALL ", " LC_CTYPE ", " LANG
The first non-empty value among these three determines the current
locale's facet for character handling, and in particular the default
text encoding. See
.BR locale (__miscmansuffix__),
.BR setlocale (3),
.BR locale (1).
.TP
.SM
.B XMODIFIERS
This variable can be set to contain additional information important
for the current locale setting. Typically set to \fI@im=<input-method>\fP
to enable a particular input method. See
.BR XSetLocaleModifiers (3).
.TP
.SM
.B XLOCALEDIR
This must point to a directory containing the locale.alias file and
Compose and XLC_LOCALE file hierarchies for all locales. The default value
is \fI<XRoot>/lib/X11/locale\fP, i.e. normally /usr/X11R6/lib/X11/locale.
.TP
.SM
.B XENVIRONMENT
This must point to a file containing X resources. The default is
\fI$HOME/.Xdefaults-<hostname>\fP. Unlike \fI<XRoot>/lib/X11/Xresources\fP,
it is consulted each time an X application starts.
.TP
.SM
.B XFILESEARCHPATH
This must contain a colon separated list of path templates, where libXt
will search for resource files. The default value consists of
.sp
.nf
    <XRoot>/lib/X11/%L/%T/%N%C%S:\\
    <XRoot>/lib/X11/%l/%T/%N%C%S:\\
    <XRoot>/lib/X11/%T/%N%C%S:\\
    <XRoot>/lib/X11/%L/%T/%N%S:\\
    <XRoot>/lib/X11/%l/%T/%N%S:\\
    <XRoot>/lib/X11/%T/%N%S
.fi
.sp
i.e. normally
.sp
.nf
    /usr/X11R6/lib/X11/%L/%T/%N%C%S:\\
    /usr/X11R6/lib/X11/%l/%T/%N%C%S:\\
    /usr/X11R6/lib/X11/%T/%N%C%S:\\
    /usr/X11R6/lib/X11/%L/%T/%N%S:\\
    /usr/X11R6/lib/X11/%l/%T/%N%S:\\
    /usr/X11R6/lib/X11/%T/%N%S
.fi
.sp
A path template is transformed to a pathname by substituting:
.sp
.nf
    %N => name (basename) being searched for
    %T => type (dirname) being searched for
    %S => suffix being searched for
    %C => value of the resource "customization"
          (class "Customization")
    %L => the locale name
    %l => the locale's language (part before '_')
    %t => the locale's territory (part after '_` but before '.')
    %c => the locale's encoding (part after '.')
.fi
.TP
.SM
.B XUSERFILESEARCHPATH
This must contain a colon separated list of path templates,
where libXt will search for user dependent resource files. The default
value is:
.sp
.nf
    $XAPPLRESDIR/%L/%N%C:\\
    $XAPPLRESDIR/%l/%N%C:\\
    $XAPPLRESDIR/%N%C:\\
    $HOME/%N%C:\\
    $XAPPLRESDIR/%L/%N:\\
    $XAPPLRESDIR/%l/%N:\\
    $XAPPLRESDIR/%N:\\
    $HOME/%N
.fi
.sp
$XAPPLRESDIR defaults to \fI$HOME\fP, see below.
.sp
A path template is transformed to a pathname by substituting:
.sp
.nf
    %N => name (basename) being searched for
    %T => type (dirname) being searched for
    %S => suffix being searched for
    %C => value of the resource "customization"
          (class "Customization")
    %L => the locale name
    %l => the locale's language (part before '_')
    %t => the locale's territory (part after '_` but before '.')
    %c => the locale's encoding (part after '.')
.fi
.TP
.SM
.B XAPPLRESDIR
This must point to a base directory where the user stores his application
dependent resource files. The default value is \fI$HOME\fP. Only used if
XUSERFILESEARCHPATH is not set.
.TP
.SM
.B XKEYSYMDB
This must point to a file containing nonstandard keysym definitions.
The default value is \fI<XRoot>/lib/X11/XKeysymDB\fP, i.e. normally
/usr/X11R6/lib/X11/XKeysymDB.
.TP
.SM
.B XCMSDB
This must point to a color name database file. The default value is
\fI<XRoot>/lib/X11/Xcms.txt\fP, i.e. normally /usr/X11R6/lib/X11/Xcms.txt.
.TP
.SM
.B XFT_CONFIG
This must point to a configuration file for the Xft library. The default
value is \fI<XRoot>/lib/X11/XftConfig\fP, i.e. normally
/usr/X11R6/lib/X11/XftConfig.
.TP
.SM
.B RESOURCE_NAME
This serves as main identifier for resources belonging to the program
being executed. It defaults to the basename of pathname of the program.
.TP
.SM
.B SESSION_MANAGER
Denotes the session manager the application should connect. See
.BR xsm (1),
.BR rstart (1).
.TP
.SM
.B XF86BIGFONT_DISABLE
Setting this variable to a non-empty value disables the XFree86-Bigfont
extension. This extension is a mechanism to reduce the memory consumption
of big fonts by use of shared memory.
.LP
.B XKB_FORCE
.br
.B XKB_DISABLE
.br
.B XKB_DEBUG
.br
.B _XKB_CHARSET
.br
.B _XKB_LOCALE_CHARSETS
.br
.B _XKB_OPTIONS_ENABLE
.br
.B _XKB_LATIN1_LOOKUP
.br
.B _XKB_CONSUME_LOOKUP_MODS
.br
.B _XKB_CONSUME_SHIFT_AND_LOCK
.br
.B _XKB_IGNORE_NEW_KEYBOARDS
.br
.B _XKB_CONTROL_FALLBACK
.br
.B _XKB_COMP_LED
.B _XKB_COMP_FAIL_BEEP
.TP
.SM
.I ""
These variables influence the X Keyboard Extension.
.SH EXAMPLES
The following is a collection of sample command lines for some of the 
more frequently used commands.  For more information on a particular command,
please refer to that command's manual page.
.sp
.nf
    %  xrdb $HOME/.Xresources
    %  xmodmap -e "keysym BackSpace = Delete"
    %  mkfontdir /usr/local/lib/X11/otherfonts
    %  xset fp+ /usr/local/lib/X11/otherfonts
    %  xmodmap $HOME/.keymap.km
    %  xsetroot -solid 'rgbi:.8/.8/.8' 
    %  xset b 100 400 c 50 s 1800 r on
    %  xset q
    %  twm
    %  xmag
    %  xclock -geometry 48x48-0+0 -bg blue -fg white
    %  xeyes -geometry 48x48-48+0
    %  xbiff -update 20 
    %  xlsfonts '*helvetica*'
    %  xwininfo -root
    %  xdpyinfo -display joesworkstation:0
    %  xhost -joesworkstation
    %  xrefresh
    %  xwd | xwud
    %  bitmap companylogo.bm 32x32
    %  xcalc -bg blue -fg magenta
    %  xterm -geometry 80x66-0-0 -name myxterm $*
    %  xon filesysmachine xload
.fi
.SH DIAGNOSTICS
A wide variety of error messages are generated from various programs.
The default error handler in \fIXlib\fP (also used by many toolkits) uses
standard resources to construct diagnostic messages when errors occur.  The
defaults for these messages are usually stored in \fI<XRoot>/lib/X11/XErrorDB\fP.
If this file is not present, error messages will be rather terse and cryptic.
.PP
When the X Toolkit Intrinsics encounter errors converting resource strings to
the
appropriate internal format, no error messages are usually printed.  This is
convenient when it is desirable to have one set of resources across a variety
of displays (e.g. color vs. monochrome, lots of fonts vs. very few, etc.),
although it can pose problems for trying to determine why an application might
be failing.  This behavior can be overridden by the setting the
\fIStringConversionsWarning\fP resource.
.PP
To force the X Toolkit Intrinsics to always print string conversion error
messages,
the following resource should be placed in the file that gets
loaded onto the RESOURCE_MANAGER property
using the \fIxrdb\fP program (frequently called \fI.Xresources\fP
or \fI.Xres\fP in the user's home directory):
.sp
.nf
    *StringConversionWarnings: on
.fi
.sp
To have conversion messages printed for just a particular application,
the appropriate instance name can be placed before the asterisk:
.sp
.nf
    xterm*StringConversionWarnings: on
.fi
.SH "SEE ALSO"
.PP
.\" introductions
.BR XProjectTeam (__miscmansuffix__),
.BR XStandards (__miscmansuffix__),
.BR Xsecurity (__miscmansuffix__),
.\" clients, utilities, and demos
.BR appres (1),
.BR bdftopcf (1),
.BR bitmap (1),
.BR editres (1),
.BR fsinfo (1),
.BR fslsfonts (1),
.BR fstobdf (1),
.BR iceauth (1),
.BR imake (1),
.BR lbxproxy (1),
.BR makedepend (1),
.BR mkfontdir (1),
.BR oclock (1),
.BR proxymngr (1),
.BR rgb (1), 
.BR resize (1),
.BR rstart (1),
.BR smproxy (1),
.BR twm (1),
.BR x11perf (1),
.BR x11perfcomp (1), 
.BR xauth (1),
.BR xclipboard (1),
.BR xclock (1),
.BR xcmsdb (1),
.BR xconsole (1),
.BR xdm (1),
.BR xdpyinfo (1),
.BR xfd (1),
.BR xfindproxy (1),
.BR xfs (1),
.BR xfwp (1),
.BR xhost (1),
.BR xieperf (1),
.BR xinit (1),
.BR xkbbell (1),
.BR xkbcomp (1),
.BR xbkevd (1),
.BR xkbprint (1),
.BR xkbvleds (1),
.BR xkbwatch (1),
.BR xkill (1),
.BR xlogo (1),
.BR xlsatoms (1),
.BR xlsclients (1),
.BR xlsfonts (1),
.BR xmag (1),
.BR xmh (1),
.BR xmodmap (1),
.BR xon (1),
.BR xprop (1),
.BR xrdb (1),
.BR xrefresh (1),
.BR xrx (1),
.BR xset (1),
.BR xsetroot (1),
.BR xsm (1),
.BR xstdcmap (1),
.BR xterm (1),
.BR xwd (1),
.BR xwininfo (1),
.BR xwud (1).
.\" servers
.BR Xserver (1),
.BR Xdec (1),
.BR XmacII (1),
.BR Xsun (1),
.BR Xnest (1),
.BR Xvfb (1),
.BR XFree86 (1),
.BR Xdarwin (1),
.BR kbd_mode (1),
.\" specifications
.I "Xlib \- C Language X Interface\fR,\fP"
and
.I "X Toolkit Intrinsics \- C Language Interface"
.SH TRADEMARKS
.PP
X Window System is a trademark of X Consortium, Inc.
.SH AUTHORS
.PP
A cast of thousands, literally.  The Release 6.3 distribution is 
brought to you by X Consortium, Inc.  The names of all people who 
made it a reality will be found in the individual documents and 
source files.  The staff members at the X Consortium responsible
for this release are: Donna Converse (emeritus), Stephen Gildea 
(emeritus), Kaleb Keithley, Matt Landau (emeritus), Ralph Mor 
(emeritus), Janet O'Halloran, Bob Scheifler, Ralph Swick, Dave 
Wiggins (emeritus), and Reed Augliere.
.PP
The X Window System standard was originally developed at the
Laboratory for Computer Science at the Massachusetts Institute 
of Technology, and all rights thereto were assigned to the X Consortium 
on January 1, 1994.
X Consortium, Inc. closed its doors on December 31, 1996.  All rights to the
X Window System have been assigned to the Open Software Foundation.
