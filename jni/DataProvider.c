#include <jni.h>
#include <string.h>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// java中的jstring, 转化为c的一个字符数组
char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
	 char*   rtn   =   NULL;
	 jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");
	 jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");
	 jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
	 jbyteArray   barr=   (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
	 jsize   alen   =   (*env)->GetArrayLength(env,barr);
	 jbyte*   ba   =   (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
	 if(alen   >   0)
	 {
	  rtn   =   (char*)malloc(alen+1);         //new   char[alen+1]; "\0"
	  memcpy(rtn,ba,alen);
	  rtn[alen]=0;
	 }
	 (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //释放内存

	 return rtn;
}

//方法签名, Java环境 和 调用native方法的类 必不可少, 后面的参数就是native方法的参数
jint Java_shuliang_han_ndkparameterpassing_DataProvider_add(JNIEnv * env, jobject obj, jint x, jint y)
{
	//Java中的int对应的是C语言中的long类型, 对应JNI中的jint类型, C语言中
	LOGI("JNI_log : x = %d , y = %d" , x , y);
	return x + y;
}


jstring Java_shuliang_han_ndkparameterpassing_DataProvider_sayHelloInc(JNIEnv *env, jobject obj, jstring str)
{
	char *p = (char*)Jstring2CStr(env, str);
	//打印Java传递过来的数据
	LOGI("Java JNI string parameter is : %s", p);
	
	char *append = "append";
	
	//strcat(dest, source) 函数可以将source字符串 添加到dest字符串后面
	return (*env)->NewStringUTF(env, strcat(p, append));
}


jintArray Java_shuliang_han_ndkparameterpassing_DataProvider_intMethod(JNIEnv *env, jobject obj, jintArray arr)
{
	//获取arr大小
	int len = (*env)->GetArrayLength(env, arr);
	
	//在LogCat中打印出arr的大小
	LOGI("the length of array is %d", len);
	
	//如果长度为0, 返回arr
	if(len == 0)
		return arr;
		
	//如果长度大于0, 那么获取数组中的每个元素
	jint* p = (*env)->GetIntArrayElements(env, arr, 0);
	
	//打印出数组中每个元素的值
	int i = 0;
	for(; i < len; i ++)
	{
		LOGI("arr[%d] = %d", i, *(p + i));
	}
	
	return arr;
	
}

