CC:=gcc
SRCS:=main.c slowa.c liczby.c
OBJ:=$(subst .c,.o, $(SRCS))
projekt: $(OBJ)
	@$(CC) $(OBJ) -o projekt

%.o: %.c
	@$(CC) -c $<

.PHONY:clean

clean:
	rm -f projekt $(OBJ)
