all: my_mastermind


my_mastermind: main1.o functions.o
	gcc -Wall -Werror -Wextra -o my_mastermind main1.o functions.o

main1.o: main1.c
	gcc -c -Wall -Werror -Wextra main1.c

functions.o: functions.c
	gcc -c -Wall -Werror -Wextra functions.c 

fclean: clean
	rm -f my_mastermind

clean:
	rm main1.o
	rm functions.o

