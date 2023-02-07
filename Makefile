NAME = program.out
CFLAGS = -Iminilibx
LDFLAGS = -Lminilibx
LDLIBS = -lmlx -lXext -lX11

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all \
	--track-fds=yes --track-origins=yes

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): main.o
	make -C minilibx
	gcc $(LDFLAGS) -o $(NAME) main.o $(LDLIBS)

clean:
	rm -r *.o $(NAME)

re: clean all

leaks:
	$(VALGRIND) ./$(NAME)

install:
	sudo apt update -y && sudo apt upgrade -y
	sudo apt install gcc make xorg libxext-dev libbsd-dev

.PHONY: all clean re leaks