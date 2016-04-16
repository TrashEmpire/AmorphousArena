#Variables.
LNK_TAGS = -lSDL2main -lSDL2
INC_DIR = -IA:\SoftwareGameDevelopmentTools\SDL\include
LNK_DIR = -LA:\SoftwareGameDevelopmentTools\SDL\lib\win32
FILES = main.cpp Game.cpp Game.h
all:
	g++ $(FILES) $(INC_DIR) $(LNK_DIR) $(LNK_TAGS) -o AmorphousArena.exe
clean:
	rm main.o AmorphousArena.exe
