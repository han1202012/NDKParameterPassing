package shuliang.han.ndkparameterpassing;

public class DataProvider {

	//将Java中的两个int值 传给C语言, 进行相加后, 返回java语言 shuliang.han.ndkparameterpassing.DataProvider
	public native int add(int x, int y);
	
	//将Java字符串传递给C语言, C语言处理字符串之后, 将处理结果返回给java
	public native String sayHelloInc(String s);
	
	//将java中的int数组传递给C语言, C语言为每个元素加10, 返回给Java
	public native int[] intMethod(int[] nums); 
	
}
