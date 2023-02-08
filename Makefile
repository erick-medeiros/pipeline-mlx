NAME = program.out
CFLAGS = -g
LDLIBS = -lmlx -lXext -lX11

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all \
	--track-origins=yes

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): main.o
	gcc -o $(NAME) main.o $(LDLIBS)

clean:
	rm -r *.o $(NAME)

re: clean all

leaks: $(NAME)
	$(VALGRIND) ./$(NAME)

.PHONY: all clean re leaks