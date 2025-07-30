TARGET	:= engine
CC	:= g++
LIBS	:= -lSDL2 -lGL -lGLEW -lGLU

CLASSES := /classes

SOURCE := /source

CPPFILES := $(wildcard .$(SOURCE)/*.cpp)

OBJS		:=  $(CPPFILES:.$(SOURCE)/%.cpp=.$(CLASSES)/%.o)

build: $(OBJS)
	$(CC) $(OBJS) -fsanitize=address -g $(LIBS) -o $(TARGET)

.$(CLASSES)/%.o: .$(SOURCE)/%.cpp
	$(CC) $(LIBS) -c $< -o $@

clean:
	rm -rf .$(CLASSES)
	mkdir .$(CLASSES)

test: clean build
	./$(TARGET)
