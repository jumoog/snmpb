SnmpB is a desktop SNMP browser and MIB editor written with Qt.

Supported features:
 + custom MIB loading & editing
 + trap reception
 + agent discovery
 + SNMPv3 USM (authentication & encryption)
 + IPv6


### Compiling ###

# make (linux, macosx, unix)
# gmake (*BSD)
> make (Windows/MSYS2)

Make variables to tune:
 - QTBIN sets the Qt bin path (used to locate qmake)
 - INSTALL_PREFIX sets the installation directory (/usr/local by default)
 - BIN_PREFIX is "bin" by default, sets binary install path suffix
 - NO_ROOT enables non-root install (off by default)

Tested & compiles on MSYS2/Windows, Linux, MacOS Leonard & Sierra, and NetBSD


### Dependencies ###

SnmpB uses the following libraries:
 - Qt5 for cross-platform UI widgets
 - QWT for extended graphing widgets
 - libsmi for parsing MIB files
 - snmp++ to speak the SNMP protocol
 - libtomcrypt or OpenSSL for SNMPv3 crypto


#### Dev dependencies ####

Additional tools are needed to compile and/or update SnmpB.

 - C++ compiler -- at least C++11 is required.
 - CMake and one of builders it supports (GNU Make, Ninja-build, any other).
 - GNU patch or compatible.
 - Library headers of main dependencies (-dev or -devel packages).


#### Bundled dependencies ####

These libraries are vendored within SnmpB tree:
 - libsmi -- v0.5.0 + a dozen patches
 - libtomcrypt -- 1.17 + a few patches
 - snmp++ -- 3.4.1 + a dozen patches

The libs were patched in-tree by the original author.

Since SnmpB 1.2, all the patches are explicitly tracked under patches/.


### Windows build ###

See separate guide in installer/win32/building-on-windows.md


--------------------------------

Original author: Martin Jolicoeur <martsjoli@gmail.com>

Current maintainer: Max Ulidtko <ulidtko@gmail.com>
