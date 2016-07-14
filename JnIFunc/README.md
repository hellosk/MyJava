# 调用JNI函数
Java中调用JNI本地函数，C中通过调用JNI函数来设置java中成员变量、调用java中的成员方法。

## 编译运行方法
1.编译java层代码： make java
2.利用javap命令获取类成员的签名： javap -s -p [classname]
3.添加签名到C文件
4.编译C层代码： make local
5.运行程序： make run

## 用到的JNI函数
1.GetStaticFieldID --> 从类中获取static变量ID
2.GetStaticIntField -->  通过static变量ID获取值
3.FindClass --> 通过对象查找类
4.GetMethodID --> 通过类查找方法
5.NewObject --> 生成对象
6.CallIntMethod --> 调用类的方法
7.GetFieldID --> 从类中获取普通变量ID
8.SetIntField --> 设置对象中变量的值
9.GetIntField --> 获取对象中变量的值




