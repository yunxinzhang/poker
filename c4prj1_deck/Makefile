test-deck: cards.o deck.o eval.o test-deck.c
	gcc -g -std=gnu99 -Wall -Werror cards.o deck.o eval.o test-deck.c
cards.o: cards.c
	gcc -g -o cards.o -std=gnu99 -Wall -Werror -c cards.c
deck.o: deck.c cards.o
	gcc -g -o deck.o -std=gnu99 -Wall -Werror -c cards.o deck.c
eval.o: cards.o deck.o eval.c
	gcc -g -o eval.o -std=gnu99 -Wall -Werror -c cards.o deck.o eval.c
	
