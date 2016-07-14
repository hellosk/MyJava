class HelloJNI
{
	native int printHello(int i);
	native int printSring(String str);

	static { System.loadLibrary("HelloJNI");}

	public static void main(String args[])
	{
		HelloJNI myJNI = new HelloJNI();

		myJNI.printHello(0);
		myJNI.printSring("hello, JNI!\n");
	}
}
