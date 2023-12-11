all: my_printf

my_printf: main.o my_printf.o printing.o
	gcc -Wall -Werror -Wextra -o my_printf main.o my_printf.o printing.o

main.o: main.c
	gcc -c -Wall -Werror -Wextra main.c

my_printf.o: my_printf.c
	gcc -c -Wall -Werror -Wextra my_printf.c

printing.o: printing.c
	gcc -c -Wall -Werror -Wextra printing.c

fclean: clean
	rm -f my_printf

clean:
	rm main.o
	rm my_printf.o
	rm printing.o