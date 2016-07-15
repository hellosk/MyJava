#include <stdio.h>
#include <jni.h>

int main()
{
	JNIEnv *env;
	JavaVM *vm;
	JavaVMInitArgs vm_args;
	JavaVMOption options[1];
	jint res;
	jclass cls;
	jmethodID mid;
	jstring jstr;
	jclass stringClass;
	jobjectArray args;

	//set java vm options.
	options[0].optionString = "-Djava.class.path=.";
	vm_args.version = 0x00010002;
	vm_args.options = options;
	vm_args.nOptions = 1; 	//num of options
	vm_args.ignoreUnrecognized = JNI_TRUE;	//ignore unrecognized options

	//create java vm
	res = JNI_CreateJavaVM(&vm, (void **)&env, &vm_args);

	//find and load java class
	cls = (*env)->FindClass(env, "InvocationApiTest");

	//get java fnction
	mid = (*env)->GetStaticMethodID(env, cls, "main", "([Ljava/lang/String;)V");

	//create string object, used as main() param
	jstr = (*env)->NewStringUTF(env, "Hello, world!");
	stringClass = (*env)->FindClass(env, "java/lang/String");
	args =(*env)->NewObjectArray(env, 1, stringClass, jstr);

	//call main()
	(*env)->CallStaticVoidMethod(env, cls, mid, args);

	//destroy java vm
	(*vm)->DestroyJavaVM(vm);

	return 0;
}

