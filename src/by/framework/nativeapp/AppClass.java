package by.framework.nativeapp;

public class AppClass {

	public static void main(String[] args) {
		
		NativeCode nc = new NativeCode();

		int i = nc.getInt();

		nc.showInt(++i);
		
		int[] array = new int[i];

		for(int j = 0; j < i; j++) {
			array[j] = nc.getRandomInt();
		}

		nc.showIntArray(array);
		nc.addOneToArray(array);
		nc.showIntArray(array);
		
	}

}
