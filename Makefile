all: loops recursives loopd recursived mains maindloop maindrec libraryPath

loops: NumClass.h advancedClassificationLoop.o basicClassification.o
	ar rc libclassloops.a advancedClassificationLoop.o basicClassification.o
	ranlib libclassloops.a
	
recursives: NumClass.h advancedClassificationRecursion.o basicClassification.o
	ar rc libclassrec.a advancedClassificationRecursion.o basicClassification.o

loopd: NumClass.h advancedClassificationLoop.o basicClassification.o
	gcc -Wall -shared advancedClassificationLoop.o basicClassification.o -lm -o libclassloops.so

recursived: NumClass.h advancedClassificationRecursion.o basicClassification.o
	gcc -Wall -shared advancedClassificationRecursion.o basicClassification.o -lm -o libclassrec.so

mains: main.o recursives libraryPath	
	gcc -Wall main.o -L. -L/usr/lib/bin -I/usr/lib/include -lclassrec -lm -o mains

maindloop: main.o loopd libraryPath		
	gcc -Wall main.o -L. -L/usr/lib/bin -I/usr/lib/include -lclassloops -lm -o maindloop

maindrec: main.o recursived libraryPath	
	gcc -Wall main.o -L. -L/usr/lib/bin -I/usr/lib/include -lclassrec -lm -o maindrec

clean:
	rm -f *.o *.a *.so mains maindloop maindrec

advancedClassificationLoop.o: NumClass.h advancedClassificationLoop.c
	gcc -Wall -fPIC -c advancedClassificationLoop.c

advancedClassificationRecursion.o: NumClass.h advancedClassificationRecursion.c
	gcc -Wall -fPIC -c advancedClassificationRecursion.c

basicClassification.o: NumClass.h basicClassification.c
	gcc -Wall -fPIC -c basicClassification.c

main.o: NumClass.h main.c 
	gcc -Wall -fPIC -c main.c

libraryPath:
	LD_LIBRARY_PATH="`pwd`"
	export LD_LIBRARY_PATH
