CC = g++
SRC = src/Main.cpp src/App.cpp
HEADERS_DIR = headers/
WX_FLAGS = `wx-config --cxxflags --libs`
NAME = identitygen

all:
	$(CC) $(SRC) -I$(HEADERS_DIR) $(WX_FLAGS) -o $(NAME)
