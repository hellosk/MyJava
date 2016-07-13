#include <stdio.h>
#include "HelloJNI.h"

JNIEXPORT jint JNICALL Java_HelloJNI_printHello(JNIEnv *env, jobject obj, jint i)
{
	printf("The value is %d.\n", i);
}


//GetStringUTFChars is JNI function.

JNIEXPORT jint JNICALL Java_HelloJNI_printSring(JNIEnv *env, jobject obj, jstring str)
{
	const char *string = (*env)->GetStringUTFChars(env, str, 0);
	printf("The string is: %s", string);

}
