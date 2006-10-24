#
# snmpb project top-level makefile. Supports Linux & Windows(mingwin)
#
os:=$(shell uname -o)

ifeq (${os}, Cygwin)
snmpb: libtomcrypt/libtomcrypt.a \
       libsmi/win/libsmi.a \
       qwt/lib/libqwt.a \
       app/snmpb
else
snmpb: libtomcrypt/libtomcrypt.a \
       libsmi/lib/.libs/libsmi.a \
       qwt/lib/libqwt.a \
       app/snmpb
endif

libtomcrypt/libtomcrypt.a:
ifeq (${os}, Cygwin)
	export CFLAGS="-mno-cygwin"; make -C libtomcrypt
else
	make -C libtomcrypt
endif

ifeq (${os}, Cygwin)
libsmi/win/libsmi.a:
	make -C libsmi/win -f Makefile.mingw
else
libsmi/lib/.libs/libsmi.a: libsmi/Makefile
	make -C libsmi
endif

libsmi/Makefile:
	# Linux FC5
	cd libsmi; automake-1.4; ./configure --disable-shared --with-pathseparator=';' --with-dirseparator='/'

qwt/lib/libqwt.a: qwt/Makefile
	make -C qwt

qwt/Makefile:
ifeq (${os}, Cygwin)
	cd qwt; export MINGW_IN_SHELL=1; qmake qwt.pro
else
	# Linux FC5
	cd qwt; qmake-qt4 qwt.pro
endif

app/snmpb:
	make -C app

clean:
	-make -C libtomcrypt clean
ifeq (${os}, Cygwin)
	-make -C libsmi/win -f Makefile.mingw clean
else
	-make -C libsmi clean
endif
	-make -C qwt clean
	-make -C app clean