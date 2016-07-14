class JniFuncMain
{
	private static int staticIntField = 300;

	static { System.loadLibrary("jnifunc");}

	//loacal function declare.
	public static native JniTest createJniObject();

	public static void main(String args[])
	{
		//jva call c function
		System.out.println("[JAVA] createJniObject().");
		JniTest jniObj = createJniObject();
	}
}

class JniTest
{
	private int intValue;

	public JniTest(int num)
	{
		intValue = num;
		System.out.println("[JAVA]JniTest -> JniTest, intValue: " + intValue);
	}

	public int callByNative(int num)
	{
		System.out.println("[JAVA]JniTest -> callByNative, num: " + num);
		return num;
	}
}









