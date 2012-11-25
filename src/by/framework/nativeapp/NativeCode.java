package by.framework.nativeapp;

public class NativeCode {

	static
	{
		System.loadLibrary( "nativecode" );
	}

	public NativeCode() {
		srand();
	}


	public native int getInt();
	
	public native void showInt(int i);

	public native void showIntArray(int[] array);

	public native int getRandomInt();
	
	public native void addOneToArray(int[] array);
	
	private native void srand();
	
}
