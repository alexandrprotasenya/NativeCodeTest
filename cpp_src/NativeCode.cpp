#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "NativeCode.h"

JNIEXPORT jint JNICALL Java_by_framework_nativeapp_NativeCode_getInt
  (JNIEnv *enc, jobject obj) {
	int input = 1;
	std::cout<<"Input number: ";
	std::cin>>input;
	if(input<0) input = 0;
	return input;
}

JNIEXPORT void JNICALL Java_by_framework_nativeapp_NativeCode_showInt
  (JNIEnv *env, jobject obj, jint i) {
	std::cout<<"Output number: "<<i<<std::endl;
}

JNIEXPORT void JNICALL Java_by_framework_nativeapp_NativeCode_showIntArray
  (JNIEnv *env, jobject obj, jintArray jarray) {
	int len = env->GetArrayLength(jarray);
	std::cout<<"Array length: "<<len<<std::endl;
	jint* arr = env->GetIntArrayElements(jarray, 0);
	for(int i = 0; i < len; i++) {
		std::cout<<std::setw(5)<<i<<": "<<std::setw(4)<<arr[i]<<std::endl;
	}
	env->ReleaseIntArrayElements(jarray, arr, 0);
}

JNIEXPORT jint JNICALL Java_by_framework_nativeapp_NativeCode_getRandomInt
  (JNIEnv *env, jobject obj) {
	int i = rand()%100;
	return i;
}

JNIEXPORT void JNICALL Java_by_framework_nativeapp_NativeCode_addOneToArray
  (JNIEnv *env, jobject obj, jintArray jarray) {
	int len = env->GetArrayLength(jarray);
	jint* arr = env->GetIntArrayElements(jarray, 0);
		for(int i = 0; i < len; i++) {
			++(*(arr+i));
		}
	// Т.к. GetIntArrayElements возвращает нам копию массива, необходимо
	// при необходимости вернуть Java изменнённый массив
	env->ReleaseIntArrayElements(jarray, arr, 0);
}

JNIEXPORT void JNICALL Java_by_framework_nativeapp_NativeCode_srand
  (JNIEnv *env, jobject obj) {
	srand(time(NULL));
}
