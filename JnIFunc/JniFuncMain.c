#include <stdio.h>
#include "JniFuncMain.h"

JNIEXPORT jobject JNICALL Java_JniFuncMain_createJniObject(JNIEnv *env, jclass clazz)
{
	jclass targetClass;
	jmethodID mid;	//method id
	jobject newObject;
	jstring helloStr;
	jfieldID fid;	//field id
	jint staticIntField, intValue;
	jint intField;
	jint result;
	
	printf("[C]Enter.\n");

	//get FieldID of static member from class, use class for static param.
	fid = (*env)->GetStaticFieldID(env, clazz, "staticIntField", "I");
	staticIntField = (*env)->GetStaticIntField(env, clazz, fid);
	printf("[C]get java value, staticIntField = %d.\n", staticIntField);

	//find the class of object.
	targetClass = (*env)->FindClass(env, "JniTest");

	//get constructor from class, and call it to create object.
	printf("[C]create new object.\n");
	mid = (*env)->GetMethodID(env, targetClass, "<init>", "(I)V");
	newObject = (*env)->NewObject(env, targetClass, mid, 100);
	
	//get java function from class, and call it.
	printf("[C]call java function.\n");
	mid = (*env)->GetMethodID(env, targetClass, "callByNative", "(I)I");
	result = (*env)->CallIntMethod(env, newObject, mid, 200);

	//set the value of the member of class.
	printf("[C]set java value.\n");
	fid = (*env)->GetFieldID(env, targetClass, "intValue", "I");
	(*env)->SetIntField(env, newObject, fid, result);

	//get the value of the member of class, use object for normal param.
	intValue = (*env)->GetIntField(env, newObject, fid);
	printf("[C]get java value, intValue = %d.\n", intValue);

	return newObject;
}

