include ../desktop-shared/Makefile.sources
include ../desktop-shared/Makefile.source7z

SOURCES_CXX += $(DESKTOP_SRC_DIR)/nfd/nfd_gtk.cpp
CPPFLAGS += `pkg-config --cflags gtk+-3.0`
LDFLAGS += `pkg-config --libs gtk+-3.0`

include ../desktop-shared/Makefile.common
include ../desktop-shared/Makefile.install
