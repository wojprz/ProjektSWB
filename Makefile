CC:=gcc
SRCS:=main.cpp slowa.cpp liczby.cpp
OBJ:=$(subst .cpp,.o, $(SRCS))
projekt: $(OBJ)
	@$(CC) $(OBJ) -o projekt

%.o: %.c
	@$(CC) -c $<

.PHONY:clean

clean:
	rm -f projekt $(OBJ)
