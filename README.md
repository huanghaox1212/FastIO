# FastIO
## 简介
用fread和fwrite优化了putchar和getchar函数，平均每次读写1000000字节。  
使用常规方式实现了整数、长整数、浮点数、C风格字符串和C++标准库中的string类型等的读写以及eof的判断（这在读写不定量数据时是必须的，例如while(io>>x)）。  以及控制类型。
所有数据以及方法包装在一个class内，加入了常数优化。
## Note
> 注意，如果您有正确使用freadfwrite的能力，请拆开此模板，使用裸的freadfwrite。本模板为了安全性和完整性包装了许多东西，虽然加了很多常数优化，直接使用freadfwrite还是会更快。

> **有些人说本模板太长，我在这里做出统一答复：模板长是因为要实现全面的操作和维护使用安全性，只需要记忆getch和putch函数以代替getchar和putchar就行。还嫌长那就先去把getchar和putchar学会吧。**

> 所以要记忆本模板时，**比起普通的快速读写只需要多记忆2个函数而已，getch和putch**。

在洛谷的链接：https://www.luogu.org/blog/Howershine950644/post-mu-ban-zhen-zheng-di-du-xie-you-hua
## Updates
update1:应某用户建议，已将模板改为class。  
update2:某用户发现puts函数运行效率存在问题，已更正。  
update3:应某用户建议，已修改go函数至析构函数。  
update4:为防止用户使用错误，将FastIO的对象的定义置于模板中。  
update5:删去了rfile和wfile。  
update6:应某用户建议，输出stringstring的函数参数类型改为了const string&。  
update7: 经核实发现本模板在效率方面有一些问题，进行了全面修改，并加入_endl和_prs和_setprecision等控制类型。  

详情请参照正文。  
如果您按照指定方法使用仍然存在bug，请私信我。
## 使用说明
这一部分非常重要，之前有人因为错误使用而导致代码崩溃。  
如果您已经阅读了代码（在.cpp文件里），那么请看下面的部分：

原理：每次批量读入1000001字节，存到输入项里，读完了继续尝试读入，存到输入项里。每次批量输出1000001字节，最后用析构函数把输出项里剩下的也输出了。如果觉得空间会超限（大约2KB的读写数组，超限的可能还是很小的），请自行调整批量读写的数据大小。

使用说明：

1.本模板的文件流没有兼容用其他的任何输入/输出，包括getchar、putchar、cin、scanf之类。一般情况下该模板足以实现常用的读写功能，如果仍然有特殊需求，请自行添加功能。

2.FastIO的定义必须为全局变量。为了防止有人误用，已经加在模板里，请勿多此一举在代码里写出FastIO io的定义。

3.具体用法如下：

**·** 预处理
```cpp
#include <bits/stdc++.h>//头文件不要乱改，否则会不支持某些函数。
using namespace std;
//在此处，即using语句的下一句加入模板。
//other defines.
int main(){
    freopen(输入文件名，"r",stdin),freopen(输出文件名，"w",stdout);
    //注意在标准输入输出评测时去掉freopen语句
    //调试时一定要用文件读写，否则输入会卡死（评测机上不会）。
    //由于所有评测机本质上皆使用文件式评测，无需担心会在评测机上出错（亲测通过Luogu和OJ评测）。
    return 0;
}
```
**·** 输入输出
```cpp
char ch;int a;long long d;string s1,s2;double aa,bb;
io>>ch>>a>>d>>s1>>aa>>bb,io<<ch<<a<<d<<s1<<aa<<bb;
io.getline(s2),io<<s2,io.puts("123"),io<<"456";
//<<输出操作不能与>>输入操作连在一起!
```
**·** 判断EOF（使用重载类型转换运算符实现）
```cpp
while(io>>ch)io<<ch;//判断方法与cin类似。
if(io)...
```
**·** 控制类型的使用
```cpp
io<<_endl;//换行
io<<_prs(true);//从现在开始，一律选择进行四舍五入
io<<_prs(false);//从现在开始，一律不进行四舍五入
io<<_setprecision(k);//从现在开始，一律保留k位小数
//注意：控制类型仅为方便习惯于iostream的用户来使用，平时尽量不要用，否则会对效率进行影响。
```
**·** 其他
```cpp
//那个模板中，可以把不要的重载运算符删掉，比如只需要输入输出整数，就把输入输出字符串之类的删掉。
//如果需要别的实现，请以getch和putch代替getchar和putchar，然后自行实现。
//以下几个函数/变量千万不能删掉：
//FastIO,~FastIO,getch,putch,rbuf,wbuf,p1,p2,rs,ws
//有时编译时可能会有警告，不用担心，可放心使用。
//警告原因：
//1.输出C风格字符串的函数参数不是const类型，输出字符串常量时会警告。
//2.为了常数优化，部分int换成了char，某些编译器会进行警告。
```
