# 在C程序中运行Java类
主程序用C编写

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




