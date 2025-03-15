include ../desktop-shared/Makefile.sources
include ../desktop-shared/Makefile.source7z

SDLPATH ?= /opt/local/x86_64-w64-mingw32

SOURCES_CXX += $(DESKTOP_SRC_DIR)/nfd/nfd_win.cpp
LDFLAGS += -mconsole `$(SDLPATH)/bin/sdl2-config --libs` -loleaut32 -luuid -lopengl32 -static-libgcc -static-libstdc++ -lole32
CPPFLAGS += `$(SDLPATH)/bin/sdl2-config --cflags`

CPPFLAGS += -I thirdparty/glew-2.2.0/include -DGLEW_STATIC
SOURCES_C += thirdparty/glew-2.2.0/src/glew.c

UNAME_S=MinGW

include ../desktop-shared/Makefile.common
include ../desktop-shared/Makefile.install

CC=x86_64-w64-mingw32-gcc
CXX=x86_64-w64-mingw32-g++
