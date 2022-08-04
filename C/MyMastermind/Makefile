all: my_mastermind

my_mastermind: main.o randoSecret.o
	gcc -Wall -Werror -Wextra -o my_mastermind main.o randoSecret.o

main.o: main.c
	gcc -c -Wall -Werror -Wextra main.c

randoSecret.o: randoSecret.c
	gcc -c -Wall -Werror -Wextra randoSecret.c 


# my_ngram.o: my_ngram.c
# 	gcc -c -Wall -Werror -Wextra my_ngram.c

# functions.o: functions.c
# 	gcc -c -Wall -Werror -Wextra functions.c

fclean: clean
	rm -f my_mastermind

clean:
	rm main.o
	rm randoSecret.o

