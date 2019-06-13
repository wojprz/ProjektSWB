CC:=gcc
SRCS:=main.cpp liczby.cpp slowa.cpp
OBJ:=$(subset .cpp, .o, $(SRCS))
projekt: $(OBJ)
	@$(CC) $(OBJ) -o projekt

%.o: %.cpp
	@$(CC) -c $<

.PHONY:clean

clean:
	rm -f projekt $(OBJ)