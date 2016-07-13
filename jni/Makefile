SK_JAVA_CLASS=HelloJNI
SK_JAVA_SRCS=$(SK_JAVA_CLASS).java
SK_SHARED_LIB=lib$(SK_JAVA_CLASS).so
SK_CFLAGS+= -I /usr/java/jdk1.8.0_91/include
SK_CFLAGS+= -I /usr/java/jdk1.8.0_91/include/linux

all:
	@echo make all
	javac $(SK_JAVA_SRCS)
	javah $(SK_JAVA_CLASS)
	gcc $(SK_CFLAGS) -c $(SK_JAVA_CLASS).c
	gcc -shared $(SK_JAVA_CLASS).o -o $(SK_SHARED_LIB) 

run:
	@echo make run
	java -Djava.library.path='.' $(SK_JAVA_CLASS)

test:
	echo $(SK_SHARED_LIB)

clean:
	@echo make clean
	rm -rf *.class *.h *.o *.so 
