all: my_mastermind


my_mastermind: main.o make_input.o play_functions.o
	gcc -Wall -Werror -Wextra -o my_mastermind main.o make_input.o play_functions.o

main.o: main.c
	gcc -c -Wall -Werror -Wextra main.c

make_input.o: make_input.c
	gcc -c -Wall -Werror -Wextra make_input.c

play_functions.o: play_functions.c
	gcc -c -Wall -Werror -Wextra play_functions.c

fclean: clean
	rm -f my_mastermind

clean:
	rm main.o
	rm make_input.o
	rm play_functions.o