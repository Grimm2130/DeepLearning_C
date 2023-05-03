CC=gcc
CFLAGS=-g
TARGET:main
LIBS=-lpthread
OBJS=Single_in_Single_out.o			\
		Single_in_Multiple_out.o	\
		Multiple_in_Single_out.o	\
		Multiple_in_Multiple_out.o	\
		HiddenLayer.o				\
		BruteForceLearning.o		\
		testingFuncs.o				\
		MuscleGain.o				\
		Helpers.o

main:main.o ${OBJS}
	${CC} ${CFLAGS} ${OBJS} main.o -o main ${LIBS}

main.o:main.c
	${CC} ${CFLAGS} -c main.c -o main.o

Single_in_Single_out.o:Single_in_Single_out.c
	${CC} ${CFLAGS} -c Single_in_Single_out.c -o Single_in_Single_out.o

Single_in_Multiple_out.o:Single_in_Multiple_out.c
	${CC} ${CFLAGS} -c Single_in_Multiple_out.c -o Single_in_Multiple_out.o

Multiple_in_Single_out.o:Multiple_in_Single_out.c
	${CC} ${CFLAGS} -c Multiple_in_Single_out.c -o Multiple_in_Single_out.o

Multiple_in_Multiple_out.o:Multiple_in_Multiple_out.c
	${CC} ${CFLAGS} -c Multiple_in_Multiple_out.c -o Multiple_in_Multiple_out.o

HiddenLayer.o:HiddenLayer.c
	${CC} ${CFLAGS} -c HiddenLayer.c -o HiddenLayer.o

BruteForceLearning.o:BruteForceLearning.c
	${CC} ${CFLAGS} -c BruteForceLearning.c -o BruteForceLearning.o

testingFuncs.o:testingFuncs.c
	${CC} ${CFLAGS} -c testingFuncs.c -o testingFuncs.o

MuscleGain.o:MuscleGain.c
	${CC} ${CFLAGS} -c MuscleGain.c -o MuscleGain.o

Helpers.o:Helpers.c
	${CC} ${CFLAGS} -c Helpers.c -o Helpers.o

clean:
	rm -f *.o main