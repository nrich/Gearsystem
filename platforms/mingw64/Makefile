include ../desktop-shared/Makefile.sources
include ../desktop-shared/Makefile.source7z

REAL_UNAME_S := $(shell uname -s)

ifeq ($(REAL_UNAME_S), Linux)
    SDL2PATH ?= /opt/local/x86_64-w64-mingw32
else
    SDL2PATH ?= /mingw64
endif

SOURCES_CXX += $(DESKTOP_SRC_DIR)/nfd/nfd_win.cpp

ifdef DEBUG
    LDFLAGS += -mconsole
endif

LDFLAGS += `$(SDL2PATH)/bin/sdl2-config --static-libs` -lopengl32 -static-libgcc -static-libstdc++
CPPFLAGS += `$(SDL2PATH)/bin/sdl2-config --cflags`

CPPFLAGS += -I thirdparty/glew-2.2.0/include -DGLEW_STATIC
SOURCES_C += thirdparty/glew-2.2.0/src/glew.c

SOURCES_RC := assets/gearsystem.rc

UNAME_S=MinGW

include ../desktop-shared/Makefile.common
include ../desktop-shared/Makefile.install

ifeq ($(REAL_UNAME_S), Linux)
    CC=x86_64-w64-mingw32-gcc
    CXX=x86_64-w64-mingw32-g++
    WINDRES=x86_64-w64-mingw32-windres
else
    CC=/mingw64/bin/x86_64-w64-mingw32-gcc
    CXX=/mingw64/bin/x86_64-w64-mingw32-g++
    WINDRES=/mingw64/bin/windres
endif
