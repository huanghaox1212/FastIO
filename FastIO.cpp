//使用前请务必查看readme.md中的使用说明。
#include <bits/stdc++.h>
#define reg register
#define fok (ch!=EOF)
#define sep (ch==' '||ch=='\n'||ch=='\t')
#define dsep !isdigit(ch)
#define neq(a,b) ((a)-(b)>1e-6)
using namespace std;
class FastIO{
    char rbuf[1000002],wbuf[1000002],b,*p1,*p2;
    int rs,ws,S;
    public:
        FastIO():p1(rbuf),p2(wbuf),S(1000000),rs(1000000),ws(-1),b(1){}
        ~FastIO(){fwrite(wbuf,1,ws+1,stdout);}
        inline char getch(){
            return rs==S&&
            (p1=rbuf,rs=-1,(S=fread(rbuf,1,S+1,stdin)-1)==-1)?
            (b=0,EOF):(++rs,*p1++);
        }
        inline void putch(int x){
            ws==1000000&&
            (p2=wbuf,ws=-1,fwrite(wbuf,1,1000001,stdout)),++ws,*p2++=x;
        }
        inline void puts(const char str[]){
            fwrite(wbuf,1,ws+1,stdout)?(ws=-1):0,
            fwrite(str,1,strlen(str),stdout);
        }
        inline void getline(string& s){
            for(reg char ch;(ch=getch())!='\n'&&fok;)s+=ch;
        }
        inline FastIO& operator>>(int& x){
            x=0;reg char f=0,ch=getch();
            while(dsep&&fok)f|=(ch=='-'),ch=getch();
            while(isdigit(ch))
                x=(x<<1)+(x<<3)+(ch^48),ch=getch();
            return x=f?-x:x,*this;
        }
        inline FastIO& operator>>(long long& x){
            x=0;reg char f=0,ch=getch();
            while(dsep&&fok)f|=(ch=='-'),ch=getch();
            while(isdigit(ch))
                x=(x<<1)+(x<<3)+(ch^48),ch=getch();
            return x=f?-x:x,*this;
        }
        inline FastIO& operator>>(char& ch){return ch=getch(),*this;}
        inline FastIO& operator>>(string& s){
            reg char ch=getch();
            while(sep&&fok)ch=getch();
            while(!sep&&fok)s+=ch,ch=getch();
            return *this;
        }
        inline FastIO& operator>>(double& x){
            x=0;reg char f=0,ch=getch();
            double d=0.1;
            while(dsep&&fok)f|=(ch=='-'),ch=getch();
            while(isdigit(ch))x=x*10+(ch^48),ch=getch();
            if(ch=='.')
                while(isdigit(ch=getch()))x+=d*(ch^48),d*=0.1;
            return x=f?-x:x,*this;
        }
        inline FastIO& operator<<(int x){
            reg char ch[10],i=-1;
            !x?(putch('0'),0):0,
            x<0?(putch('-'),x=-x):0;
            while(x)ch[++i]=x%10+48,x/=10;
            while(~i)putch(ch[i]),--i;
            return *this;
        }
        inline FastIO& operator<<(long long x){
            reg char ch[20],i=-1;
            !x?(putch('0'),0):0,
            x<0?(putch('-'),x=-x):0;
            while(x)ch[++i]=x%10+48,x/=10;
            while(~i)putch(ch[i]),--i;
            return *this;
        }
        inline FastIO& operator<<(char ch){return putch(ch),*this;}
        inline FastIO& operator<<(char str[]){return puts(str),*this;}
        inline FastIO& operator<<(const string& s){return puts(s.c_str()),*this;}
        inline FastIO& operator<<(double x){
            int y=int(x);
            *this<<y;
            x-=y;
            while(neq(x,int(x)))x*=10;
            x?*this<<'.'<<int(x):0;
            return *this;
        }
        inline operator bool(){return b;}
}io;
