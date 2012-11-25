all : NativeCode.so

NativeCode.so : NativeCode.obj
	g++ -o bin/libnativecode.so -shared bin/libnativecode.o

NativeCode.obj: cpp_src/NativeCode.cpp java_headers
	g++ -o bin/libnativecode.o -I"/usr/lib/jvm/java-1.7.0-openjdk-amd64/include" -I"/usr/lib/jvm/java-1.7.0-openjdk-amd64/include/linux" -fpic -c cpp_src/NativeCode.cpp
   
java_headers: java_class_files
	javah -jni -o cpp_src/NativeCode.h -classpath bin by.framework.nativeapp.NativeCode

java_class_files: src/by/framework/nativeapp/NativeCode.java src/by/framework/nativeapp/AppClass.java
	mkdir -p bin
	javac -d bin -cp bin src/by/framework/nativeapp/NativeCode.java
	javac -d bin -cp bin src/by/framework/nativeapp/AppClass.java
