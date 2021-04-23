CC = g++
SRC = src/Main.cpp src/App.cpp
HEADERS_DIR = headers/
WX_FLAGS = `wx-config --cxxflags --libs`
BUILDDIR = build/
NAME = identitygen

all:
	make createdir
	make comp

createdir:
	mkdir $(BUILDDIR) || echo "FAILED"

comp:
	$(CC) $(SRC) -I$(HEADERS_DIR) $(WX_FLAGS) -o $(BUILDDIR)$(NAME)