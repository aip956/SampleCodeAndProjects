all: my_mastermind

my_mastermind: main1.o 
	gcc -Wall -Werror -Wextra -o my_mastermind main1.o

# my_mastermind: main1.o ranSecret.o
# 	gcc -Wall -Werror -Wextra -o my_mastermind main1.o ranSecret.o

main1.o: main1.c
	gcc -c -Wall -Werror -Wextra main1.c

# randoSecret.o: ranSecret.c
# 	gcc -c -Wall -Werror -Wextra ranSecret.c 


# my_ngram.o: my_ngram.c
# 	gcc -c -Wall -Werror -Wextra my_ngram.c

# functions.o: functions.c
# 	gcc -c -Wall -Werror -Wextra functions.c

fclean: clean
	rm -f my_mastermind

clean:
	rm main1.o
	rm ranSecret.o

