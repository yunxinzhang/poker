test: test-subseq.o  maxSeq.o
	gcc test-subseq.o maxSeq.o -o test -std=gnu99 -Wall -Werror
maxSeq.o: maxSeq.c
	gcc -c maxSeq.c  -std=gnu99 -Wall
test-subseq.o: test-subseq.c
	gcc -c test-subseq.c -std=gnu99 -Wall -Werror
