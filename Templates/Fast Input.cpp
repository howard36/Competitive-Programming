//read integers quickly
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp = _inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

//read unsigned integers quickly
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp = _inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

//even faster (only unsigned)
#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 16384, stdin)] = 0, *_pbuf++))
char _buf[16385], *_pbuf = _buf;

int read() {
	int c, o = 0;
	while ((c = getchar()) < '0');
	do o = (o << 3) + (o << 1) + c - '0';
	while ((c = getchar()) >= '0');
	return o;
}

//when using iostream, add this at start of main
ios::sync_with_stdio(false); // this doesn't work with strings!
cin.tie(0);

// for general optimization
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma comment(linker, "/stack:227420978")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("O3")
