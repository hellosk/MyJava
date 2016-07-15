SK_JAVA_CLASS=InvocationApi
SK_JAVA_SRCS=$(SK_JAVA_CLASS).java
SK_SHARED_LIB=libjnifunc.so
SK_CFLAGS+= -I /usr/java/jdk1.8.0_91/include
SK_CFLAGS+= -I /usr/java/jdk1.8.0_91/include/linux
SK_JVM_DIR=/usr/java/jdk1.8.0_91/jre/lib/i386/client


java:
	@echo make java
	javac $(SK_JAVA_SRCS)

local:
	@echo make local
	gcc -o $(SK_JAVA_CLASS) $(SK_CFLAGS) $(SK_JAVA_CLASS).c -L$(SK_JVM_DIR) -ljvm

run:
	@echo make run
	chmod 755 $(SK_JAVA_CLASS)
	./$(SK_JAVA_CLASS)

clean:
	@echo make clean
	rm -rf *.class *.h *.o *.so *.log $(SK_JAVA_CLASS)
