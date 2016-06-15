/*------------------------------------------------------------------------
 * aaBoost: A better boost
 *
 * Copyright (c) 2009-2016, Ashod Apakian <apakian at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of aaBoost nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *-----------------------------------------------------------------------*/

 #pragma once #ifndef INC_AA
 #define INC_AA
 #define PUB                           extern
 #ifdef __cplusplus
 PUB "C" {
 #endif
/*-----------------------------------------------------------------------*/

 #define  AA_WARNINGS_ON               1
 #undef   UNICODE
 #define  WINVER                       0x0500
 #define  INC_OPENSSL                  1

 #ifndef  INC_WINDOWS
 #define  NODRAWDIB
 #define  NOMCIWND
 #define  NOMETAFILE
 #define  NOSCROLL
 #define  NOKANJI
 #define  NOHELP
 #define  NOCOMM
 #define  NOPROFILER
 #ifdef __BORLANDC__
 #pragma option -a1
 #if     (!AA_WARNINGS_ON)
 #pragma warn -pch
 #pragma warn -use
 #pragma warn -stu
 #pragma warn -csu
 #endif
 #define inline __inline
 #endif
 #ifdef _MSC_VER
 #if     (!AA_WARNINGS_ON)
 #pragma warning(disable : 4005)
 #pragma warning(disable : 4018)
 #pragma warning(disable : 4028)
 #pragma warning(disable : 4047)
 #pragma warning(disable : 4054)
 #pragma warning(disable : 4055)
 #pragma warning(disable : 4068)
 #pragma warning(disable : 4100)
 #pragma warning(disable : 4101)
 #pragma warning(disable : 4127)
 #pragma warning(disable : 4133)
 #pragma warning(disable : 4146)
 #pragma warning(disable : 4200)
 #pragma warning(disable : 4201)
 #pragma warning(disable : 4213)
 #pragma warning(disable : 4214)
 #pragma warning(disable : 4242)
 #pragma warning(disable : 4244)
 #pragma warning(disable : 4245)
 #pragma warning(disable : 4255)
 #pragma warning(disable : 4267)
 #pragma warning(disable : 4305)
 #pragma warning(disable : 4311)
 #pragma warning(disable : 4312)
 #pragma warning(disable : 4389)
 #pragma warning(disable : 4668)
 #pragma warning(disable : 4700)
 #pragma warning(disable : 4701)
 #pragma warning(disable : 4702)
 #pragma warning(disable : 4711)
 #pragma warning(disable : 4820)
 #pragma warning(disable : 4996)
 #endif
 #define inline _inline
 #endif
 #define  _WIN32_WINNT 0x0501
 #include <winsock2.h>
 #include <winsock.h>
 #include <windows.h>
 #include <wincrypt.h>
 #include <iphlpapi.h>
 #include <stdio.h>
 #include <math.h>
 #include <vfw.h>
 #include <shlobj.h>
 #include <lm.h>
 #include <setjmp.h>
 #include <time.h>
 #include <errno.h>
 #include <stdint.h>
 #endif

 #ifndef NULL_POINTR
 #define NULL_POINTR                   ((VP)0)
 #endif

 #ifndef LIKELY
 #define LIKELY(x)                     (x)
 #endif

 #ifndef UNLIKELY
 #define UNLIKELY(x)                   (x)
 #endif

/*-----------------------------------------------------------------------*/
 ///#pragma pack(1)
/*-----------------------------------------------------------------------*/

 #if defined(_MSC_VER) || (__BORLANDC__ >= 0x0551) || defined(__GNUC__)
 #define L64                           __int64
 #define H64                           unsigned __int64
 #else
 #define L64                           LONGLONG
 #define H64                           DWORDLONG
 #endif

 #define UNUSE(x)                      (V)x

 #define T                             typedef
 #define structure                     typedef struct
 #define unite                         typedef union

 #define xstruct(strct)                _##strct; _##strct strct
 #define xstructn(strct,n)             _##strct; _##strct strct[n]
 #define xstrux(strct)                 _##strct strct

 #define aaMultiLine(...)              #__VA_ARGS__
 #define aaCString(vstr,vbody)         CP vstr=#vbody
 #define aaBString(vstr,vbody)         BP vstr=#vbody

 #ifdef __GNUC__
 #define xstruct_isstarted(strct,memb) _##strct strct={.memb=NO};
 #else
 #define xstruct_isstarted(strct,memb) _##strct strct={NO};
 #endif

//-------------------------------------------

 #define objInit(optr,ofun)            if((optr)==NULL)               { return RET_BADPARM; }  \
                                       aaMemoryFill(optr,sizeof(_##optr),0);                   \
                                       (optr)->magic=aaHPP(ofun);

 #define objTest(optr,ofun)            if((optr)==NULL)               { return RET_BADPARM; }   \
                                       if((optr)->magic!=aaHPP(ofun)) { return RET_NOTINITIALIZED; }

 #define objClear(optr)                aaMemoryFill(optr,sizeof(_##optr),0);

//-------------------------------------------

 #define E                             enum
 #define S                             static
 #define K                             LRESULT CALLBACK
 #define TE                            T E

 #define oow                           aaWinErrorGet(0,__LINE__)
 #define oof                           aaNote(0,"%s\n%s\n#%i",__FILE__,__FUNCTION__,__LINE__)
 #define oops                          aaNote(0,"%s\n%s\n#%i\n%s",__FILE__,__FUNCTION__,__LINE__,ret_string[ret])
 #define oopsx(xxx)                    aaNote(0,"%s\n%s\n#%i\n%s\n%s",__FILE__,__FUNCTION__,__LINE__,ret_string[ret],xxx)
 #define dooops                        if(ret!=YES) { oops; }
 #define oofoo(rrr,xxx)                aaNote(0,"%s\n\n%s\nTime: %s\n\nSource file: %s\nSource line #%i",(xxx)?xxx:"...",ret_string[rrr],__TIME__,__FILE__,__LINE__)
 #define arets                         ret_string[ret]

 #define ifoops                        if(ret!=RET_YES)
 #define ifoopsoops                    ifoops { oops; }

 #define abort                         aaAbort("%s %i",__FILE__,__LINE__)
 #define aaAbortLine                   aaAbort("%s\n%s\nLine #%i",__FILE__,__FUNCTION__,__LINE__)

 #define aaComment(x)
 #define aaLineLog()                   aaLog(-555,"line=%i   file=%s",__LINE__,__FILE__)
 #define aaLineLogEx()                 aaLog(-777,"line=%i   file=%s",__LINE__,__FILE__)

 #define ZUGGY                         aaLog(-1,"%s line #%i",__FILE__,__LINE__);
 #define ASRET(rvar,cod,act)           if((rvar=cod)!=YES) act

 #define LE_CHAR(a,b,c,d)              (((a)<<24)|((b)<<16)|((c)<<8)|(d))

 #define aaTimeOfLastCompile(buf)      { aaStringCopy(buf,__DATE__);                     \
                                         aaStringAppend(buf,"/");                        \
                                         aaStringAppend(buf,__TIME__);                   \
                                         aaStringUpper(buf,20,0);                        \
                                         if(buf[4]==SPACE_CHAR) { buf[4]='0'; }          \
                                         if(buf[12]=='0') { buf[21]='A'; } else          \
                                         if(buf[12]=='2') { buf[21]='P'; } else          \
                                         if(buf[13]>='2') { buf[21]='P'; }               \
                                         if(buf[21]==' ') { buf[21]='A'; } buf[22]='M';  }

/*-----------------------------------------------------------------------*/

 T void                                v00;
 T void           *                    v00p;
 T void           **                   v00pp;

 T char                                s8;
 T short                               s16;
 T s8                                  s24[3];
 T long                                s32;

 T unsigned char                       u8;
 T unsigned short                      u16;
 T u8                                  u24[3];
 T unsigned long                       u32;

 T char           *                    s8p;
 T short          *                    s16p;
 T s24            *                    s24p;
 T long           *                    s32p;

 T unsigned char  *                    u8p;
 T unsigned short *                    u16p;
 T u24            *                    u24p;
 T unsigned long  *                    u32p;

 T float                               f32;
 T float          *                    f32p;

 T double                              d64;
 T double         *                    d64p;


 #ifdef __GNUC__
 T long long                           s64;
 T unsigned long long                  u64;
 T s64            *                    s64p;
 T u64            *                    u64p;

 #ifndef LLONG_MAX
 #define SHRT_MIN                      (-32768)
 #define SHRT_MAX                      32767
 #define USHRT_MAX                     65535
 #define INT_MAX                       2147483647
 #define INT_MIN                       (-INT_MAX-1)
 #define UINT_MAX                      4294967295U
 #define LLONG_MAX	             9223372036854775807LL
 #define LLONG_MIN                     (-LLONG_MAX-1LL)
 #define ULLONG_MAX	             18446744073709551615ULL
 #define CHAR_BIT                      8
 #endif

 #if (LLONG_MAX >> 31) >> 31 == 1
 #else
 #error                                "No 64-bit integer type!"
 #endif
 #endif

 T char                                string[1025];

 T char                                C;
 T unsigned char                       B;
 T short                               I;
 T unsigned short                      W;
 T long                                N;
 T unsigned long                       H;
 T void                                V;
 T float                               F;
 T double                              D;
 T L64                                 G;
 T H64                                 Q;
 T char           *                    CP;
 T unsigned char  *                    BP;
 T short          *                    IP;
 T unsigned short *                    WP;
 T long           *                    NP;
 T unsigned long  *                    HP;
 T void           *                    VP;
 T float          *                    FP;
 T double         *                    DP;
 T L64            *                    GP;
 T H64            *                    QP;
 T void          **                    PP;
 T int                                 Z;
 T int            *                    ZP;
 T unsigned int                        Y;
 T unsigned int   *                    YP;


/*-----------------------------------------------------------------------*/

 structure { u32 len; u8 buf[1025];  } _str1k;
 structure { u32 len; u8 buf[2049];  } _str2k;
 structure { u32 len; u8 buf[3073];  } _str3k;
 structure { u32 len; u8 buf[4097];  } _str4k;
 structure { u32 len; u8 buf[8193];  } _str8k;
 structure { u32 len; u8 buf[16385]; } _str16k;
 structure { u32 len; u8 buf[32769]; } _str32k;
 structure { u32 len; u8 buf[65537]; } _str64k;


/*-----------------------------------------------------------------------*/

 structure
 {
 s8p cp;
 u8p bp;
 s16p ip;
 u16p wp;
 s32p np;
 u32p hp;
 DP dp;
 }
 _emptr;

 #define aaEmptr(eob,ptr)              eob.cp=(s8p)ptr;  eob.bp=(u8p)ptr; \
                                       eob.ip=(s16p)ptr; eob.wp=(u16p)ptr; \
                                       eob.np=(s32p)ptr; eob.hp=(u32p)ptr; \
                                       eob.np=(DP)ptr;

/*-----------------------------------------------------------------------*/

 V aaDummyFunction1                    ();
 V aaDummyFunction2                    ();

/*-----------------------------------------------------------------------*/

 #define F4                            0xF
 #define F8                            0xFF
 #define F12                           0xFFF
 #define F16                           0xFFFF
 #define F20                           0xFFFFF
 #define F24                           0xFFFFFF
 #define F28                           0xFFFFFFF
 #define F32                           0xFFFFFFFF
 #define F36                           0xFFFFFFFFF
 #define F40                           0xFFFFFFFFFF
 #define F44                           0xFFFFFFFFFFF
 #define F48                           0xFFFFFFFFFFFF
 #define F52                           0xFFFFFFFFFFFFF
 #define F56                           0xFFFFFFFFFFFFFF
 #define F60                           0xFFFFFFFFFFFFFFF
 #define F64                           0xFFFFFFFFFFFFFFFF

 #define _U64Min                       0
 #define _U64Max                       18446744073709551615
 #define _I64Min                       -9223372036854775806
 #define _I64Max                       9223372036854775807

 #define _0K                           0
 #define _qK                           256
 #define _hK                           512
 #define _1K                           1024
 #define _2K                           2048
 #define _3K                           3072
 #define _4K                           4096
 #define _5K                           5120
 #define _6K                           6144
 #define _8K                           8192
 #define _10K                          10240
 #define _16K                          16384
 #define _20K                          20480
 #define _24K                          24576
 #define _32K                          32768
 #define _50K                          51200
 #define _64K                          65536
 #define _70K                          71680
 #define _100K                         102400
 #define _128K                         131072
 #define _150K                         153600
 #define _256K                         262144
 #define _384K                         393216
 #define _512K                         524288
 #define _1MEG                         1048576
 #define _2MEG                         2097152
 #define _4MEG                         4194304
 #define _8MEG                         8388608
 #define _16MEG                        16777216
 #define _24MEG                        25165824
 #define _32MEG                        33554432
 #define _64MEG                        67108864
 #define _128MEG                       134217728
 #define _256MEG                       268435456
 #define _512MEG                       536870912
 #define _1GIG                         1073741824
 #define _2GIG                         2147483648
 #define _3GIG                         3221225472
 #define _4GIG                         4294967296

 #define _65Kd                         65536.0
 #define _4Bd                          4294967296.0

 #define aaHundred(v)                  (v*100)
 #define aaThousand(v)                 (v*1000)
 #define aaTenThousand(v)              (v*10000)
 #define aaHundredThousand(v)          (v*100000)
 #define aaMillion(v)                  (v*1000000)
 #define aaBillion(v)                  (v*1000000000)

 #define ZERO                          0

 #define BOTH                          2
 #define EITHER                        2
 #define NEITHER                       2
 #define UNKNOWN                       2
 #define OTHER                         2
 #define NONE                          2

 #define TOGGLE                        3

 #define YES                           1
 #define NO                            0

 #define OFF                           0
 #define ON                            1


/*-----------------------------------------------------------------------*/


 PUB B aa_starchar[4];

 #define aa_spacestring(x)             aaBoolStrings((x==0),"",(aaBoolStrings((x==1)," ",aaBoolStrings((x==2),"  ",(aaBoolStrings((x==3),"   ",aaBoolStrings((x==4),"    ","     ")))))))

 #define CR_CHAR                       '\r'
 #define LF_CHAR                       '\n'
 #define HTAB_CHAR                     '\t'
 #define SPACE_CHAR                    ' '
 #define NULL_CHAR                     '\0'
 #define VTAB_CHAR                     '\x0b'
 #define FF_CHAR                       '\f'
 #define EOF_CHAR                      0x01a
 #define BSLASH_CHAR                   '\\'
 #define DQUOTE_CHAR                   '\"'
 #define QUOTE_CHAR                    '\''
 #define FSLASH_CHAR                   '/'
 #define AT_CHAR                       '@'
 #define DOT_CHAR                      '.'
 #define COMMA_CHAR                    ','
 #define PERC_CHAR                     '%'
 #define HYPHON_CHAR                   '-'
 #define COLON_CHAR                    ':'
 #define SEMICOLON_CHAR                ';'
 #define EQUAL_CHAR                    '='
 #define VBAR_CHAR                     '|'

/*-----------------------------------------------------------------------*/

 #define aaSpecialCharString           "‚„…‘’“”•¨°´·¸"

/*-----------------------------------------------------------------------*/

 #define aaCharStar(x)                 aa_starchar[x%4]
 #define aaCharStarCycle               aaCharStar(aa_cycle)

 #define aaCharIsBlank(x)              ((x==SPACE_CHAR)||(x==HTAB_CHAR))
 #define aaCharIsLineControl(x)        ((x==CR_CHAR)||(x==LF_CHAR))
 #define aaCharIsWhiteSpace(x)         ((aaCharIsBlank(x)||aaCharIsLineControl(x)))
 #define aaCharIsNotWhiteSpace(x)      ((x!=SPACE_CHAR)&&(x!=HTAB_CHAR)&&(x!=CR_CHAR)&&(x!=LF_CHAR))

 #define aaCharIsAlphaLo(x)            (((x) >= 'a') && ((x) <= 'z'))
 #define aaCharIsAlphaHi(x)            (((x) >= 'A') && ((x) <= 'Z'))
 #define aaCharIsAlpha(x)              (aaCharIsAlphaLo(x) || aaCharIsAlphaHi(x))
 #define aaCharIsNum(x)                (((x) >= '0') && ((x) <= '9'))
 #define aaCharIsAlphaNum(x)           (aaCharIsAlpha(x)  || aaCharIsNum(x))
 #define aaCharIsHex(x)                ((aaCharIsNum(x))  || (((x) >= 'a') && ((x) <= 'f')) ||(((x) >= 'A') && ((x) <= 'F')))
 #define aaCharIsControl(x)            ((x)<32||(x>=127))
 #define aaCharIsPrintable(x)          (((x)>=32&&(x)<=126))
 #define aaCharIsPunctuation(x)        ((aaCharIsPrintable(x))&&(!aaCharIsAlphaNum(x))&&(!aaCharIsWhiteSpace(x)))
 #define aaCharIsSign(x)               ((x=='+')||(x=='-'))
 #define aaCharIsValue(x)              (aaCharIsNum(x)||(x=='.'))
 #define aaCharIsName(x)               (aaCharIsAlpha(x)||(x=='_'))
 #define aaCharIsVisible(x)            (aaCharIsPrintable(x)&&(x!=SPACE_CHAR))

 #define aaCharIsBrace(x)              ((x)=='{'||(x=='}'))
 #define aaCharIsParenthesis(x)        ((x)=='('||(x==')'))
 #define aaCharIsArith(x)              ((x=='+')||(x=='-')||(x=='/')||(x=='*')||(x=='^')||(x=='%'))
 #define aaCharToAlphaLo(x)            (x+(aaCharIsAlphaHi(x)*32))
 #define aaCharToAlphaHi(x)            (x-(aaCharIsAlphaLo(x)*32))

/*-----------------------------------------------------------------------*/

 #define aaFourCc(val)                 (B)(val&F8),(B)((val&F16)>>8),(B)((val>>16)&F8),(B)((val>>24)&F8)
 #define aaFourCcSet(c1,c2,c3,c4)	((H)(B)(c1)|((H)(B)(c2)<<8)|((H)(B)(c3)<<16)|((H)(B)(c4)<<24))

 #define M                             __declspec(dllimport) B
 #define X                             __declspec(dllexport) B

 #define DLL_EXPORT                    __declspec(dllexport)
 #define DLL_IMPORT                    __declspec(dllimport)

 #define aaCast(ptr,type,obj)          ptr=(type)obj
 #define aaHPP(obj)                    (H)(PP)obj

 #define aaStructOff(s,m)              ((u8p)(&(s).m)-(u8p)(&(s)))
 #define aaStructOffp(s,m)             ((u8p)(&(s)->m)-(u8p)((s)))
 #define aaStructurize(x)              _##x; _##x x;

 #define aaTypeIsUnsigned(t)           (t>=0&&((t=~t)>=0?(t=~t,1):(t=~t,0)))
 #define aaPtrToDword(ptr)             ((H)(*(HP)&ptr))
 #define aaPtrFromDword(val)           ((VP)val)

 #define aaElementCount(a)             (sizeof(a)/sizeof(a[0]))
 #define aaSource(ref)                 BP ref##=
 #define aaSoz(x)                      sizeof(x)

 #define aaSizeofProto(p,o)            sizeof(((p*)0)->o)
 #define aaSizeofProtoStructure(p)     sizeof(((p*)0)[0])
 #define aaSilentVar(type,var)         type var; (void)var

 #define aaJiffys(ms)                  (ms*10)
 #define aaSecs(ms)                    (ms*1000)
 #define aaMins(ms)                    (ms*60000)
 #define aaHours(ms)                   (ms*3600000)
 #define aaDays(ms)                    (ms*86400000);

 #define aaMegs(m)                     ((H)(m*1048576.0))
 #define aaKays(k)                     ((H)(k*1024.0))

/*-----------------------------------------------------------------------*/

 #define aaPi                          3.14159265358979323846
 #define aaE                           2.71828182845904523536
 #define aa169                         1.77777
 #define aa43                          1.33333
 #define aa916                         0.5625
 #define aa34                          0.75

 #define aaLoopBack                    16777343
 #define aaLocalHost                   "127.0.0.1"
 #define aaBroadCast                   0xFFFFFFFF

 structure { B name[65],pass[65]; }    _user;
 structure { H slots,count; VP mem; }  _cell;

/*-----------------------------------------------------------------------*/

 unite                                 { CP cp; BP bp; IP ip; WP up; NP np; HP hp; GP gp; QP qp; FP fp; DP dp; } _aaClaw;

 #define aaClawSet(aac,obj)            aaCast(aac.bp,u8p,obj);
 #define aaClawAdjust(aac,amnt)        aaCast(aac.bp,u8p,&aac.bp[amnt]);
 #define aaClawDifference(aac,obj)     aac.bp-obj
 #define aaClawAppend(aac,bytes,mem)   aaMemoryCopy(&aac.hp[0],bytes,mem); aaClawAdjust(aac,bytes)
 #define aaClawCopy(dc,ac)             dc=ac;
 #define aaClawIsNull(aac)             (aac.bp==NULL)

 #define aaClawDoubleAppend(aac,val)   aac.dp[0]=val; aaClawAdjust(aac,sizeof(D))
 #define aaClawFloatAppend(aac,val)    aac.fp[0]=val; aaClawAdjust(aac,sizeof(F))
 #define aaClawQuadAppend(aac,val)     aac.qp[0]=val; aaClawAdjust(aac,sizeof(Q))
 #define aaClawDwordAppend(aac,val)    aac.hp[0]=val; aaClawAdjust(aac,sizeof(H))
 #define aaClawWordAppend(aac,val)     aac.wp[0]=val; aaClawAdjust(aac,sizeof(W))
 #define aaClawByteAppend(aac,val)     aac.bp[0]=val; aaClawAdjust(aac,sizeof(B))

/*-----------------------------------------------------------------------*/

 #define aaBool(obj)                   (!(!(obj)))
 #define aaBoolString(obj)             (obj)?"YES":"NO "
 #define aaBoolStrings(obj,ts,fs)      (obj)?ts:fs
 #define aaBoolChar(obj)               (obj)?'Y':'N'
 #define aaBoolChars(obj,tc,fc)        (obj)?tc:fc

/*-----------------------------------------------------------------------*/

 #define aaBitSet(obj,pos)             ((obj) | (1LL << (pos)))
 #define aaBitClr(obj,pos)             ((obj) & ~(1LL << (pos)))
 #define aaBitGet(obj,pos)             aaBool((obj) & (1LL << (pos)))
 #define aaBitIsOn(obj,pos)            aaBool((obj) & (1LL << (pos)))
 #define aaBitIsOff(obj,pos)           (!aaBool((obj) & (1LL << (pos))))
 #define aaBitToggle(obj,pos)          ((obj) ^ (1LL << (pos)))
 #define aaBitAdd(obj,pos,val)         ((obj)+((Q)val<<pos))
 #define aaBitSub(obj,pos,val)         ((obj)-((Q)val<<pos))
 #define aaBitAnd(obj,val)             ((obj)&(Q)val)
 #define aaBitShl(obj,cnt)             ((obj)<<(Q)cnt)
 #define aaBitShr(obj,cnt)             ((obj)>>(Q)cnt)


/*-----------------------------------------------------------------------*/

 #define aa_Lacro(line)                label##line
 #define aa_Fabel(line)                aa_Lacro(line)

 #define SWITCH(str)                   CP aacpx##__LINE__=NULL; CP aacpxptr=aacpx##__LINE__; while((aacpxptr=((CP)str)))
 #define CASE(str)                     if(aaStringICompare((VP)aacpxptr,(VP)str,0)==YES) { aa_Fabel(__LINE__): if(0) { goto aa_Fabel(__LINE__); }
 #define BREAK                         break; }
 #define DEFAULT                       if(1)  { aa_Fabel(__LINE__): if(0) goto aa_Fabel(__LINE__);
 #define BRANCH(str)                   aaStringCopy(aacpxptr,str)

/*-----------------------------------------------------------------------*/

 #define aaRep(n)                      for(H (x)=0;(x)<n;(x)++)

/*-----------------------------------------------------------------------*/

 #define aaBlockBegin                  do {
 #define aaBlockEnd                    } while(0);
 #define aaBlockLoop                   } while(1);
 #define aaBlockWhile(exp)             } while(exp);
 #define aaBlockBreak                  break;
 #define aaBlockExit                   break;

 #define aaLoopBegin                   while(1) {
 #define aaLoopWhile(exp)              while(exp) {
 #define aaLoopEnd                     }
 #define aaLoopBreak                   break
 #define aaLoopExit                    break; }
 #define aaLoopAgain                   continue
 #define aaLoopTo(x,e)                 for((x)=0;(x)<e;(x)++) {
 #define aaLoopFrom(x,e)               for((x)=e;(x)!=F32;(x)--) {

/*-----------------------------------------------------------------------*/

 #define Qundefined                    -9223372036854775807
 #define Qmin                          -9223372036854775806
 #define Qmax                          +9223372036854775806

/*-----------------------------------------------------------------------*/

 #define aaNumIsLesser(a,b)            ((N)((a)-(b))<0)
 #define aaNumIsLesserEqual(a,b)       ((N)((a)-(b))<=0)
 #define aaNumIsGreater(a,b)           ((N)((a)-(b))>0)
 #define aaNumIsGreaterEqual(a,b)      ((N)((a)-(b))>=0)

 #define aaNumMin(x,y)                 (((x)<(y))?(x):(y))
 #define aaNumMax(x,y)                 (((x)>(y))?(x):(y))
 #define aaNumMid(x,y,z)               (aaNumMax((x),aaNumMin((y),(z))))
 #define aaNumAbs(x)                   ((x)<0LL?-(x):(x))
 #define aaNumNeg(x)                   (-(x))
 #define aaNumSgn(x)                   (((x)>=0)?1:-1)
 #define aaNumSignSwap(x)              (x<0?aaNumAbs(x):(x>0)?aaNumNeg(x):0)
 #define aaNumClamp(x,lo,hi)           (((x)>(hi))?(hi):(((x)<(lo))?(lo):(x)))

 #define aaNumRound(x,by)              (((x)<0)?((x)-by):((x)+by))
 #define aaNumRoof(x,hi)               (((x)>(hi))?(hi):(x))
 #define aaNumFloor(x,lo)              (((x)<(lo))?(lo):(x))

 #define aaNumCeilingUp(x)             ((x-(G)(x))>0LL?(G)(x+1LL):(G)(x))
 #define aaNumCeilingDown(x)           ((x-(G)(x))<0LL?(G)(x-1LL):(G)(x))
 #define aaNumCeiling(x)               (((x)>0LL)?aaNumCeilingUp(x):aaNumCeilingDown(x))

 #define aaNumRoll(x,n)                (((x)<<(n))|((x)>>(32-(n))))
 #define aaNumAverage(a,b)             (((a)+(b))>>1)
 #define aaNumIsMod(x,v)               ((x%v)==0)
 #define aaNumIsModOf(x,v,o)           ((x%v)==o)
 #define aaNumIsNotMod(x,v)            ((x%v)!=0)
 #define aaNumIsNotModOf(x,v,o)        ((x%v)!=o)
 #define aaNumIsAtMod(x,v,a)           ((x%v)==(a%v))
 #define aaNumIsNotAtMod(x,v,a)        ((x%v)!=(a%v))

 #define aaNumDoClamp(x,lo,hi)         x=aaNumClamp(x,lo,hi)
 #define aaNumDoRoof(x,hi)             x=aaNumRoof(x,hi)
 #define aaNumDoFloor(x,lo)            x=aaNumFloor(x,lo)

 #define aaNumSwapQuad(val)            (val<<32LL)|((val>>32LL)&0xFFFFFFFF)
 #define aaNumSwapDword(val)           (((val&0xff)<<24)+((val&0xff00)<<8)+((val&0xff0000)>>8)+((val&0xff000000)>>24))
 #define aaNumSwapWord(val)            (((val&0xff)<<8)+((val&0xff00)>>8))


 #define aaNumAlignUp(val,ali)         ((val+ali-1)-(val+ali-1)%ali)

 #define aaNumLowestBitSet(val)        ((val)&-(val))

 #define aaNumHertz(a,ms)              ((F)a/(((F)ms/1000.0)+0.0001))

 #define aaNumPercentIs(v,tot)         ((F)((100.0/((F)tot))*(F)v))
 #define aaNumPercentOf(v,tot)         ((F)((tot/100.0)*v))

 structure { H inc,cur,result; }       _aaDiv;

 #define aaNumDivInit(ad,val,by)       ad.inc=((H)(val<<16)/(H)by);
 #define aaNumDivReset(ad,i)           ad.result=i; ad.cur=i
 #define aaNumDivStepInc(ad)           ad.cur+=(ad.inc); ad.result+=(ad.cur/65536); ad.cur&=F16
 #define aaNumDivStepDec(ad)           ad.cur+=(ad.inc); ad.result-=(ad.cur/65536); ad.cur&=F16

/*-----------------------------------------------------------------------*/

 #define aaCrash(v)                    *(int*)0=v

/*-----------------------------------------------------------------------*/

 #ifndef printf
 #define printf                        aaDebugf
 #endif

/*-----------------------------------------------------------------------*/

 #define aaFmt(format,aptr,outtxt)     *((u8p)outtxt)=NULL_CHAR;               \
                                       if(format!=NULL)                        \
                                        {                                      \
                                        va_start(aptr,format);                 \
                                        vsprintf((VP)outtxt,format,aptr);      \
                                        va_end(aptr);                          \
                                        }


 #define aaVargsf(format)              va_list argptr;                              \
                                       _str64k str64k={.buf[0]=NULL_CHAR,.len=0};   \
                                       aaFmt(format,argptr,str64k.buf);             \
                                       aaStringLen(str64k.buf,&str64k.len);

 #define aaVargsf4K(format)            va_list argptr;                              \
                                       _str4k str4k={.buf[0]=NULL_CHAR,.len=0};     \
                                       aaFmt(format,argptr,str4k.buf);              \
                                       aaStringLen(str4k.buf,&str4k.len);



 #define aaMissingParm(x)              if(x==NULL) { oof; return RET_BADPARM; }
 #define aaMagicSet(x,m)               (x)->magic=aaHPP(m)
 #define aaMagicIs(x,m)                (x)->magic==aaHPP(m)
 #define aaMagicIsNot(x,m)             (x)->magic!=aaHPP(m)
 #define aaMagicCheck(x,m)             aaMissingParm(x);  \
                                       if(aaMagicIsNot(x,m)) { return RET_NOTINITIALIZED; }

/*-----------------------------------------------------------------------*/

 #define RET_NO                        0
 #define RET_OK                        1
 #define RET_YES                       1
 #define RET_BADPARM                   2
 #define RET_FAILED                    3
 #define RET_BOUNDS                    4
 #define RET_FORBIDDEN                 5
 #define RET_NOMEMORY                  6
 #define RET_BADHANDLE                 7
 #define RET_NOTFOUND                  8
 #define RET_NOTREADY                  9
 #define RET_EXISTS                    10
 #define RET_ALREADYOPEN               11
 #define RET_NOTOPEN                   12
 #define RET_INUSE                     13
 #define RET_NOTSTARTED                14
 #define RET_CORRUPTED                 15
 #define RET_NOTSUPPORTED              16
 #define RET_DENIED                    17
 #define RET_TIMEOUT                   18
 #define RET_FATAL                     19
 #define RET_BADSTATE                  20
 #define RET_FINISHED                  21
 #define RET_NOTINITIALIZED            22
 #define RET_PARTIAL                   23
 #define RET_ALREADYSTARTED            24
 #define RET_ATTENTION                 25
 #define RET_BADFORMAT                 26
 #define RET_CANCELLED                 27
 #define RET_WORKING                   28
 #define RET_COLLISION                 29
 #define RET_POSSIBLE                  30
 #define RET_IGNORE                    31
 #define RET_INCOMPLETE                32
 #define RET_OTHER                     33
 #define RET_UNKNOWN                   34

 PUB CP ret_string[256];

/*-----------------------------------------------------------------------*/
 PUB B is_aa_quit_posted;
 PUB B is_aa_started;
 PUB B is_aa_started_by_winmain;
/*-------------------------------*/
 PUB B aa_is_quit_called;
 PUB B aa_is_quit_received;
 PUB B aa_is_esc;
 PUB H aa_stage;
 PUB H aa_nextstage;
 PUB H aa_prevstage;
 PUB B aa_is_64bit;
 PUB B aa_i_am;
 PUB H aa_craperr;
 PUB B aa_littleendian;
 PUB B aa_bigendian;
 PUB Q aa_cycle;
 PUB H aa_firsttik;
 PUB H aa_launchtik;
 PUB H aa_discovery_id;
 PUB D aa_curhz;
 PUB D aa_askhz;
 PUB D aa_curcpuload;
 PUB D aa_curprocessload;
 PUB D aa_avgcpuload;
 PUB D aa_avgprocessload;
 PUB Q aa_msrunning;
 PUB Q aa_microsecsrunning;
 PUB D aa_secsrunning;
 PUB B aa_hide_diag;
 PUB B aa_hide_leak;
 PUB H aa_oof_count;
 PUB Q aa_stats[50];
 PUB u8p aa_cdecl;

 PUB C aa_last_executed[257];

/*-----------------------------------------------------------------------*/

 #define aaTraceResetAlways            YES
 #define aaTraceDebugf                 YES

/*-----------------------------------------------------------------------*/

 #define aaLastExecutedUpdate          aaStringCopyf(aa_last_executed,"%s:%u %s",__FILE__,__LINE__,__func__)
 #define aaLastExecutedTrace           aaLog(-555,"%s:#%u %s",__FILE__,__LINE__,__func__)

 #define aaLeu                         aaLastExecutedUpdate

/*-----------------------------------------------------------------------*/

 #define aaHz(hz)                      aaNumIsMod((aa_cycle-1),((Q)(aa_askhz*(1.0/hz))+1))

/*-----------------------------------------------------------------------*/
 PUB CP aa_common_name[2][26];

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

 PUB HWND aa_hwnd_ignore[16];

 #define aaIgnoreHwnd(hw)              { H hilc=(H)aa_hwnd_ignore[0]; aa_hwnd_ignore[hilc+1]=(HWND)hw; hilc++; aa_hwnd_ignore[0]=(HWND)hilc; }

/*-----------------------------------------------------------------------*/

 B aaStart                             (HINSTANCE thisinst,HINSTANCE previnst,LPSTR cmdline,Z cmdshow);
 Z aaStop                              (V);
 B aaExitCodeSet                       (H code);
 V aaMain                              (V);

/*-----------------------------------------------------------------------*/

 #define aaStageJump(x)                aaStageSet(x); break

 #define aa_LOGX_aaLog                 1
 #define aa_LOGX_aaDebugf              2
 #define aa_LOGX_aaHistory             4

 V aaAbort                             (VP fmt,...);
 B aaQuit                              (V);
 B aaTrace                             (VP fmt,...);
 B aaTraceFileSet                      (VP fmt,...);
 B aaCallStackGet                      (H maxitems,HP addresses);
 B aaCpuIdGet                          (Z cpuinfo[4],Z infotype);
 Q aaMsRunning                         (V);
 Q aaMicrosecsRunning                  (V);
 B aaConsoleAttach                     (V);
 B aaConsoleDetach                     (V);
 B aaConsolePrintf                     (VP fmt,...);
 B aaLog                               (H line,VP fmt,...);
 B aaLogX                              (B how,VP fmt,...);
 B aaAaFilesBackup                     (B aatrace,B aacrash,B aahistory,B aaoofs);
 B aaAaFilesDelete                     (B aatrace,B aacrash,B aahistory,B aaoofs);
 B aaAaFilesBackupOnSize               (Q aatracesize,Q aacrashsize,Q aahistorysize,Q aaoofssize);
 B aaAaFilesDeleteOnSize               (Q aatracesize,Q aacrashsize,Q aahistorysize,Q aaoofssize);
 B aaHistory                           (H line,VP fmt,...);
 B aaJournal                           (VP filename,VP fmt,...);
 B aaNotes                             (VP filename,VP fmt,...);
 B aaBeep                              (W freq,W ms);
 B aaWinErrorGet                       (VP buf,H line);
 B aaWinEventLog                       (B mode,VP srce,W eid,W cat,VP fmt,...);
 B aaNote                              (H surfacehandle,VP fmt,...);
 B aaNotex                             (H surfacehandle,VP fmt,...);
 B aaField                             (H surfacehandle,B multiline,H maxchars,VP buf,VP title);
 B aaYesNoBox                          (H surfacehandle,VP fmt,...);
 B aaSleep                             (H ms);
 B aaSleepPrecise                      (Q microsecs);
 B aaSleepHz                           (D hz);
 B aaSleepLoad                         (D percent);
 B aaStageSet                          (H stage);
 B aaStageAndNextSet                   (H stage,H next);
 B aaStageAdjust                       (N amount);
 B aaStagePrev                         (V);
 B aaStageNext                         (V);
 B aaFocusToDbg                        (B clr);
 B aaFocusToBorland                    (V);
 B aaFocusToCodeBlocks                 (V);
 B aaFocusToFirefox                    (V);
 B aaFocusToHwnd                       (HWND hwnd);
 B aaHwndGroupGet                      (HWND*active,HWND*focus,HWND*foreground);//,HWND*top);
 B aaHwndInfoGet                       (HWND hwnd,HWND*phwnd,HWND*ohwnd,RECT*winrect,VP strclass,VP strtitle);
 B aaHwndIsObscured                    (HWND hwnd,B detail,DP visipc);
 B aaIsRemoteSession                   (V);
 B aaIsDebug                           (V);
 B aaIsRemoteDebug                     (V);
 B aaIsProfiling                       (V);
 B aaProfilingPause                    (B state);
 B aaDebugf                            (VP fmt,...);
 B aaDebugfBlankLine                   (B count);
 B aaDebugfLogWriteSet                 (B state);
 B aaDebugfLogStyleSet                 (B style);
 B aaDebugfMemoryDump                  (V);
 B aaLimiterSet                        (VP uid,V(*LimiterMessageProc)(H bytes,VP data));
 B aaLimiterCheck                      (VP uid);
 B aaLimiterPost                       (VP uid,HWND hwnd,H bytes,VP msg);
 B aaLimiterPostf                      (VP uid,HWND hwnd,VP fmt,...);
 V aaLimiterNullProc                   (H bytes,VP data);
 B aaRetroMain                         (Z(*mainfunc)(Z argc,CP argv[]),ZP mainret,VP sourcearg,...);
 B aaMorph                             (VP processfilename,VP cmdline);
 B aaRestart                           (V);
 B aaReboot                            (B force);
 B aaRoutineAdd                        (V(*ProcYield)(VP),VP yparm,V(*ProcStop)(VP),VP sparm);
 B aaCopyDataProcSet                   (V(*CopyDataProc)(HWND,HWND,H,H,VP));
 B aaCopyDataPost                      (HWND from,HWND to,H ms,H data,H bytes,VP buf);
 B aaYieldRaw                          (V);
 B aaYield                             (D hz);


/*-----------------------------------------------------------------------*/

 #define aaCase(s,str)                 if(aaCheck(s,str))

 structure
 {
 H magic;
 H hash;
 B stage[128];
 }
 _aaswitcher;


 H aaSwitch                            (_aaswitcher*aaswitcher);
 B aaCheck                             (_aaswitcher*aaswitcher,VP fmt,...);
 H aaJump                              (_aaswitcher*aaswitcher,VP fmt,...);
 H aaFall                              (_aaswitcher*aaswitcher,VP fmt,...);



/*-----------------------------------------------------------------------*/

 structure
 {
 H stage;
 H prevstage;
 H nextstage;
 H history[10];
 }
 _substage;

 B aaSubStageInit                      (_substage*substage,H stage);
 B aaSubStageSet                       (_substage*substage,H stage);
 B aaSubStageAdjust                    (_substage*substage,N amount);
 B aaSubStagePrev                      (_substage*substage);
 B aaSubStageNext                      (_substage*substage);
 B aaSubStageNextSet                   (_substage*substage,H stage);
 B aaSubStageAndNextSet                (_substage*substage,H stage,H next);

/*-----------------------------------------------------------------------*/


 #define aa_FLAGMAP_IsSet              0
 #define aa_FLAGMAP_IsChanged          1
 #define aa_FLAGMAP_IsAcked            2
 #define aa_FLAGMAP_IsFirstChange      3

 structure
 {
 Q field_map;
 Q delta_ack;
 Q delta_bit;
 H field_cnt;
 H delta_cnt;
 H acked_cnt;
 B attention;
 }
 _flagmap;


 B aaFlagMapInit                       (_flagmap*flagmap);
 B aaFlagMapSet                        (_flagmap*flagmap,H bit,B ack);
 B aaFlagMapCheckSet                   (_flagmap*flagmap,H bit,H how,HP map,B ack);
 B aaFlagMapClear                      (_flagmap*flagmap,H bit,B ack);
 B aaFlagMapCheck                      (_flagmap*flagmap,H bit,H how,HP map);
 B aaFlagMapAck                        (_flagmap*flagmap,H bit);


/*-----------------------------------------------------------------------*/

 #define PROFILER_COUNTER              0
 #define PROFILER_MS                   1
 #define PROFILER_MICRO                2
 #define PROFILER_NANO                 3


 structure
 {
 H weeks;
 H days;
 H hours;
 H mins;
 H secs;
 H ms;
 }
 _duration;


 structure
 {
 H magic;
 H tik;
 H elapsed;
 }
 _timer;


 structure
 {
 H magic;
 Q c;
 G ms;
 G micro;
 G nano;
 G counter;
 }
 _profiler;


 B aaTimerNull                         (_timer*timer,H count);
 B aaTimerInit                         (_timer*timer,H count);
 B aaTimerUpdate                       (_timer*timer,H count);
 B aaTimerPulse                        (_timer*timer,H ms);
 B aaTimerElapsed                      (_timer*timer,H ms,B reinit);
 B aaTimerAdjust                       (_timer*timer,H count,N amnt);

 B aaTimerProfilerNull                 (_profiler*profiler);
 B aaTimerProfilerInit                 (_profiler*profiler,H count);
 B aaTimerProfilerUpdate               (_profiler*profiler,H count);
 B aaTimerProfilerAdjust               (_profiler*profiler,H count,B what,G amnt);
 B aaTimerProfilerPulse                (_profiler*profiler,B what,G elapsed);
 G aaTimerProfilerRead                 (_profiler*profiler,B what);
 B aaTimerProfilerGet                  (QP counter);
 B aaTimerProfilerElapsed              (Q counter,GP mselapsed,GP microelapsed,GP nanoelapsed,GP counterelapsed);

 B aaTimerCalculate                    (B what,Q elapsed,GP ms,GP micro,GP nano,GP counters);

 B aaTimerTikGet                       (HP tik);
 B aaTimerTikAdjust                    (HP tik,N amnt);
 B aaTimerTikElapsed                   (H tik,HP mselapsed);
 B aaTimerTikElapsedUsingTik           (H tik,H now,HP mselapsed);
 B aaTimerTikToDuration                (H tik,_duration*duration);

 B aaTimerMsToDuration                 (H ms,_duration*duration);

 B aaTimerPrimitive                    (H nowms,H prevms,HP elapsedms);

/*-----------------------------------------------------------------------*/

 PUB B  aa_geo_country_code[251][3];
 PUB CP aa_geo_country_name[251];
 PUB B  aa_geo_continent[251][3];

/*-----------------------------------------------------------------------*/

 PUB CP aa_timemonth[12];
 PUB CP aa_timemonthex[12];
 PUB CP aa_timeday[7];
 PUB CP aa_timedayex[7];


 structure
 {
 Y dow:3;
 Y year:20;
 Y month:4;
 Y date:5;
 Y hour:5;
 Y minute:6;
 Y second:6;
 Y ms:10;
 Y gmt_dif:5;
 }
 _systime;


 B aaTimeNull                          (_systime*systime);
 B aaTimeIsNull                        (_systime*systime);
 B aaTimeIsValid                       (_systime*systime);
 B aaTimeEqualsTime                    (_systime*systime,_systime*systime2,B extended);
 B aaTimeCopy                          (_systime*systime,_systime*ssystime);
 B aaTimeSet                           (_systime*systime,H dow,H year,H month,H date,H hour,H minute,H second,H ms,N gmtdif);
 B aaTimeLocalGet                      (_systime*systime);
 B aaTimeSystemGet                     (_systime*systime);
 B aaTimeApply                         (_systime*systime);
 B aaTimeToCookieTimeString            (_systime*st,VP str);
 B aaTimeDayOfWeekGet                  (H date,H month,H year,HP dow);
 B aaTimeFirstDayOfMonthGet            (H month,H year,HP dow);
 B aaTimeIsLeapYear                    (H year);
 B aaTimeDaysInMonthGet                (H month,H year,HP days);
 B aaTimeToString                      (_systime*systime,VP str,VP tzstr,B longday);
 B aaTimeFromString                    (_systime*systime,VP str);
 B aaTimeCompare                       (_systime*systime,_systime*systime2,GP secdif);
 B aaTimeAdjust                        (_systime*systime,_systime*ressystime,G secdif);
 B aaTimeMsRunning                     (HP ms);
 B aaTimeLaunchTikGet                  (HP ms);
 B aaTimeUtcGet                        (QP utc);
 B aaTimeSecsToDuration                (H s,_duration*duration);
 B aaTimeToUnixTime                    (_systime*systime,QP unixtime);
 B aaTimeFromUnixTime                  (_systime*systime,Q unixtime);
 B aaTimeGetOfDay                      (struct timeval*tv);


/*-----------------------------------------------------------------------*/

 B aaGeoLookup                         (VP countrycode,VP countryname,VP continent,HP index);
 B aaGeoCountryNameToIndex             (VP countryname,HP index);
 B aaGeoCountryCodeToIndex             (VP countrycode,HP index);

/*-----------------------------------------------------------------------*/


 structure
 {
 Q os_physical_total;
 Q os_physical_allocated;
 D os_physical_perc;
 Q os_virtual_total;
 Q os_virtual_allocated;
 D os_virtual_perc;
 F os_memory_load;
 H os_hardware_page_size;
 H os_page_fault_count;
 H globalalloc_calls;
 Q globalalloc_bytes;
 Q process_virtual_usage;
 H bytes_allocated;
 H blocks_allocated;
 H pages_allocated;
 H pages_commited;
 H peak_bytes_allocated;
 H peak_blocks_allocated;
 H peak_pages_allocated;
 H peak_pages_commited;
 H peak_user_bytes_allocated;
 H peak_user_blocks_allocated;
 H peak_user_pages_allocated;
 H user_bytes_allocated;
 H user_blocks_allocated;
 H user_pages_allocated;
 H working_set_size_min;
 H working_set_size_max;
 H working_set_size_peak;
 Q working_set_flush_count;
 Q bytes_copied;
 H copy_calls;
 Q bytes_filled;
 H fill_calls;
 H temp_calls;
 H object_handle_count[256];
 H total_object_handles;
 }
 _memorystatus;


 structure
 {
 u8p block[8192];
 }
 _memorytable;


 structure
 {
 u8p mem;
 H bytes;
 H used;
 }
 _memoryunit;


 B aaMemoryStatus                      (_memorystatus*memorystatus);
 B aaMemoryTableGet                    (_memorytable*memorytable);
 B aaMemoryZero                        (VP dst,H bytes);
 B aaMemoryFill                        (VP dst,H bytes,B val);
 B aaMemoryCopy                        (VP dst,H bytes,VP src);
 B aaMemoryMove                        (VP dst,H bytes,VP src);
 B aaMemorySwap                        (VP dst,H bytes,VP src);
 B aaMemoryTemp                        (PP mem,H bytes);
 B aaMemoryAllocate                    (PP mem,H bytes);
 B aaMemoryReAllocate                  (PP mem,H bytes);
 B aaMemoryResize                      (PP mem,H bytes);
 B aaMemoryDuplicate                   (PP mem,VP src);
 B aaMemoryMake                        (PP mem,H bytes);
 B aaMemoryIsAllocated                 (VP mem,HP bytes);
 B aaMemoryNameSet                     (VP mem,VP fmt,...);
 B aaMemoryNameGet                     (VP mem,VP name);
 B aaMemoryBytesGet                    (VP mem,HP bytes);
 B aaMemoryBlockGet                    (PP mem,HP bytes,H id);
 B aaMemoryRelease                     (VP mem);
 B aaMemoryAdlerCrcGet                 (VP mem,H bytes,HP crc);
 B aaMemoryCrcGet                      (VP mem,H bytes,HP crc);
 B aaMemoryCrc64Get                    (VP mem,H bytes,QP crc);
 B aaMemoryHashGet                     (VP mem,H bytes,HP hash);
 B aaMemoryValueFill                   (VP mem,H count,H valbytes,VP valmem);
 B aaMemoryPokeByte                    (VP mem,H offset,B val);
 B aaMemoryPokeWord                    (VP mem,H offset,W val);
 B aaMemoryPokeDword                   (VP mem,H offset,H val);
 B aaMemoryPokeQuad                    (VP mem,H offset,Q val);
 B aaMemoryPeekByte                    (VP mem,H offset,u8p val);
 B aaMemoryPeekWord                    (VP mem,H offset,WP val);
 B aaMemoryPeekDword                   (VP mem,H offset,HP val);
 B aaMemoryPokeDwordAndInc             (VP mem,HP offset,H val);
 B aaMemoryPeekDwordAndInc             (VP mem,HP offset,HP val);
 B aaMemoryCompare                     (VP dst,H bytes,VP src,NP dif);
 B aaMemoryRandomSet                   (VP dst,H bytes);
 B aaMemoryRandomDwordSet              (HP val,H lo,H hi);
 B aaMemoryRandomHit                   (H lo,H hi,H eq);
 B aaMemoryPageAllocate                (HP handle);
 B aaMemoryPageRelease                 (H handle);
 B aaMemoryPageProtect                 (H handle,B state);
 B aaMemoryPageGet                     (H handle,PP mem,u8p isprotected);
 B aaMemoryCodeAllocate                (PP mem,H bytes);
 B aaMemoryCodeRelease                 (VP mem);
 B aaMemorySearch                      (VP mem,H entries,H entrybytes,VP usrdata,VP data,HP index,B(*proc)(VP,H,H,VP,VP,VP,NP));
 B aaMemorySort                        (VP mem,H entries,H entrybytes,VP usrdata,B(*proc)(VP,H,H,VP,VP,VP,NP));
 B aaMemoryCompareProc                 (VP mem,H entries,H entrybytes,VP usrdata,VP itema,VP itemb,NP dif);
 B aaMemoryOrderSort                   (VP mem,H entries,H stride,H offset,H size,B issigned,B des,HP order);
 B aaMemoryUnitAllocate                (_memoryunit*memoryunit,H bytes);
 B aaMemoryUnitReAllocate              (_memoryunit*memoryunit,H bytes);
 B aaMemoryUnitMake                    (_memoryunit*memoryunit,H bytes);
 B aaMemoryUnitRelease                 (_memoryunit*memoryunit);
 B aaMemoryWorkingSetSizeSet           (H minbytes,H maxbytes);
 B aaMemoryWorkingSetFlush             (V);


/*-----------------------------------------------------------------------*/


 structure
 {
 H rsvd;
 B name[61];
 VP adr;
 }
 _memorymoduleproc;


 structure
 {
 H magic;
 B is_attached;
 Z module_count;
 HMODULE*module_list;
 _memoryunit sys;
 H proc_count;
 _memorymoduleproc*proc_entry;
 }
 _memorymodule;



 B aaMemoryModuleLoad                  (_memorymodule*memorymodule,H bytes,VP mem);
 B aaMemoryModuleRelease               (_memorymodule*memorymodule);
 B aaMemoryModuleAttach                (_memorymodule*memorymodule);


/*-----------------------------------------------------------------------*/


 structure
 {
 Z level;
 B tree[1];
 }
 _scrapnode;


 structure
 {
 H magic;
 H level;
 H bytes_possible;
 H bytes_allocated;
 H blocks_allocated;
 BP mem;
 _scrapnode*node;
 }
 _scrap;


 B aaScrapNew                          (_scrap*scrap,H bytes);
 B aaScrapDelete                       (_scrap*scrap);
 B aaScrapBytesGet                     (_scrap*scrap,Z offset,HP bytes);
 B aaScrapInfoFromMemory               (_scrap*scrap,ZP offset,HP bytes,VP mem);
 B aaScrapInfoFromOffset               (_scrap*scrap,Z offset,HP bytes,PP mem);
 B aaScrapAllocate                     (_scrap*scrap,H reqbytes,ZP offset,HP bytes,PP mem);
 B aaScrapReAllocate                   (_scrap*scrap,H reqbytes,ZP offset,HP bytes,PP mem);
 B aaScrapRelease                      (_scrap*scrap,Z offset);
//



/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 H slots;
 H count;
 H width;
 H allocs;
 BP rsvd;
 BP mem;
 }
 _groupof;


 B aaGroupofCreate                     (_groupof*groupof,H width,H initialslots);
 B aaGroupofDestroy                    (_groupof*groupof);
 B aaGroupofNew                        (_groupof*groupof,HP index,PP mem);
 B aaGroupofGet                        (_groupof*groupof,H index,PP mem);


/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 H req_bytes;
 H adj_bytes;
 BP memory;
 VP base;
 }
 _serialmem;


 B aaSerialMemNew                      (_serialmem*serialmem,H bytes);
 B aaSerialMemDelete                   (_serialmem*serialmem);
 B aaSerialMemMalloc                   (_serialmem*serialmem,H bytes,PP xptr);
 B aaSerialMemFree                     (_serialmem*serialmem,VP ptr);
 B aaSerialMemInfoToString             (_serialmem*serialmem,H maxchars,VP str);
 B aaSerialMemMap                      (_serialmem*serialmem,VP file,...);
 B aaSerialMemUnMap                    (_serialmem*serialmem,PP physaddr,VP file,...);
VP aaSerialMemPhys                     (_serialmem*serialmem,Y virtaddr);
 Y aaSerialMemVirt                     (_serialmem*serialmem,VP physaddr);

/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 D error;
 H max_entries;
 N bits;
 N bytes;
 N hashes;
 D bpe;
 BP bf;
 }
 _bloom;


 B aaBloomNew                          (_bloom*bloom,H maxentries,D error);
 B aaBloomLoad                         (_bloom*bloom,VP file,...);
 B aaBloomDelete                       (_bloom*bloom);
 B aaBloomSave                         (_bloom*bloom,VP file,...);
 B aaBloomFind                         (_bloom*bloom,H bytes,VP data);
 B aaBloomFindf                        (_bloom*bloom,VP fmt,...);
 B aaBloomAdd                          (_bloom*bloom,H bytes,VP data);
 B aaBloomAddf                         (_bloom*bloom,VP fmt,...);



/*-----------------------------------------------------------------------*/

 #define CHAINLINK_NULL                0xffffffff
 #define CHAINLINK_LAST                0xfffffffd
 #define CHAINLINK_FIRST               0xfffffffe


 structure
 {
 H state;
 H offset;
 H bytes;
 H have;
 H self;
 H prev;
 H next;
 }
 _chainlink;




 structure
 {
 H magic;
 H link_count;
 H link_usage;
 H link_slots;
 H link_avail;
 H link_removes;
 _chainlink*link;
 H link_first;
 H link_last;
 _memoryunit mem;
 }
 _chain;



 B aaChainNew                          (_chain*chain);
 B aaChainDelete                       (_chain*chain);

 B aaChainLinkClear                    (_chain*chain,_chainlink*link);
 B aaChainLinkNew                      (_chain*chain,_chainlink*link,H bytes,PP data);
 B aaChainLinkLengthSet                (_chain*chain,_chainlink*link,H bytes,PP data);
 B aaChainLinkSet                      (_chain*chain,_chainlink*link);
 B aaChainLinkGet                      (_chain*chain,H linkindex,_chainlink*link,PP data);

 B aaChainLinkTraverse                 (_chain*chain,H linkindex,N amount,HP nlinkindex,_chainlink*link,PP data);

 B aaChainLinkInsert                   (_chain*chain,H linkindex,H destindex);
 B aaChainLinkRemove                   (_chain*chain,H linkindex);

/*-----------------------------------------------------------------------*/

 #define SORTER_GET                    1
 #define SORTER_CMP                    2
 #define SORTER_SWP                    3



 structure
 {
 H magic;
 H stage;
 B is_ineffecient;
 G entries;
 G total_its;
 G top;
 G stack_size;
 G stack_left;
 D eff;
 GP stack;
 GP order;
 G p,h,l,oh;
 G j,t,i;
 B tmp_buf[_8K];
 VP proc;
 B user_data[64];
 VP data;
 G hit[10];
 }
 _sorter;



 B aaSorterNew                         (_sorter*sorter,G entries,VP data,B(*proc)(_sorter*,H,G,G,VP,NP));
 B aaSorterDelete                      (_sorter*sorter);
 B aaSorterSort                        (_sorter*sorter,H ita);
 B aaSorterProc                        (_sorter*sorter,H cmd,G index,G parm,VP buf,NP arg);


/*-----------------------------------------------------------------------*/


 structure
 {
 Q id;
 H key_off;
 H key_len;
 H hash;
 H val_off;
 H val_len;
 H rsvd[4];
 B user_data[32];
 }
 _listentry;


 structure
 {
 H magic;
 H slots;
 H count;
 H offset;
 Q id_counter;
 H allocs;
 H remove_count;
 H user_index;
 B user_data[64];
 _memoryunit mun;
 _listentry*entry;
 }
 _list;


 B aaListNew                           (_list*list);
 B aaListOpen                          (_list*list,VP fmt,...);
 B aaListSave                          (_list*list,VP fmt,...);
 B aaListClone                         (_list*list,_list*slist);
 B aaListDelete                        (_list*list);
 B aaListAppend                        (_list*list,HP index,VP key,H bytes,VP val);
 B aaListAppendf                       (_list*list,HP index,VP key,VP fmt,...);
 B aaListFind                          (_list*list,H from,HP index,VP key,...);
 B aaListRemove                        (_list*list,H index);
 B aaListPointerGet                    (_list*list,H index,PP key,PP val);
 B aaListPointerGetByNumber            (_list*list,HP index,H numbr,PP key,PP val);
 B aaListReset                         (_list*list);


/*-----------------------------------------------------------------------*/


 structure
 {
 H magic;
 _list list;
 B buf[_1K];
 }
 _options;


 B aaOptionsNew                        (_options*options);
 B aaOptionsDelete                     (_options*options);
 B aaOptionsSet                        (_options*options,VP data,...);
VP aaOptionsGet                        (_options*options,DP num,VP data,...);

/*-----------------------------------------------------------------------*/




 structure
 {
 H magic;
 HP field_array;
 H field_slots;
 H field_count;
 H total_bytes;
 }
 _data;


 B aaDataAllocate                      (_data*data);
 B aaDataRelease                       (_data*data);
 B aaDataReset                         (_data*data);
 B aaDataFieldAdd                      (_data*data,HP index,H bytes,H alias,PP mem);
 B aaDataFieldRemove                   (_data*data,H index);
 B aaDataFieldWrite                    (_data*data,HP index,H bytes,H alias,VP mem);
 B aaDataFieldWritef                   (_data*data,HP index,H alias,VP fmt,...);
 B aaDataFieldRead                     (_data*data,H index,HP bytes,HP alias,H maxbytes,VP mem);
 B aaDataFieldSizeSet                  (_data*data,H index,H bytes,PP mem);
 B aaDataFieldInfoGetByNumber          (_data*data,H numbr,HP bytes,HP index,HP alias,PP mem);
 B aaDataFieldInfoGetByAlias           (_data*data,H alias,HP bytes,HP index,PP mem);
 B aaDataFieldInfoGetByIndex           (_data*data,H index,HP bytes,HP alias,PP mem);

/*-----------------------------------------------------------------------*/


 #define OR_CONTAINS                   0
 #define AND_CONTAINS                  1

 #define aa_STRINGMODE_CR              1
 #define aa_STRINGMODE_LF              2
 #define aa_STRINGMODE_CRLF            3
 #define aa_STRINGMODE_LFCR            4
 #define aa_STRINGMODE_NULL            5

 structure
 {
 H count;
 B buf[32][_1K];
 H hashs[32];
 H hashi[32];
 H off[32];
 H sl[32];
 BP ptr[32];
 }
 _stringtoker;

 structure
 {
 H count;
 H hashs[64];
 H hashi[64];
 H off[64];
 H sl[64];
 BP ptr[64];
 }
 _stringtokermini;

 structure
 {
 H count;
 H hashs[256];
 H hashi[256];
 H off[256];
 H sl[256];
 BP ptr[256];
 }
 _stringtokermaxi;

 structure
 {
 H count;
 H off[2048];
 H len[2048];
 B type[2048];
 H value[2048];
 }
 _stringexplode;


 B aaStringNull                        (VP str);
 B aaStringIsNull                      (VP str);
 B aaStringIsEmpty                     (VP str,B onlybool);
 B aaStringCopy                        (VP dst,VP src);
 B aaStringNCopy                       (VP dst,VP src,H chars,B appendnull);
 B aaStringCopyLen                     (VP dst,VP src,HP chars);
 B aaStringLen                         (VP str,HP chars);
 B aaStringNLen                        (VP str,H maxchars,HP chars);
 B aaStringLenSet                      (VP str,H chars);
 B aaStringFill                        (VP str,H chars,B ascii,B appendnull);
 B aaStringAppendChar                  (VP str,B ch);
 B aaStringAppendChars                 (VP str,B ch,H count,B appendnull);
 B aaStringAppend                      (VP dst,VP src);
 B aaStringVSprintf                    (VP dst,VP fmt,va_list arglist);
 B aaStringNCopyf                      (VP dst,H maxchars,VP fmt,...);
 B aaStringCopyf                       (VP dst,VP fmt,...);
 B aaStringCopyfLen                    (VP dst,HP chars,VP fmt,...);
 B aaStringAppendCopyf                 (VP dst,HP chars,VP afmt,VP fmt,...);
 B aaStringConcat                      (VP str,...);
 B aaStringAppendf                     (VP dst,VP fmt,...);
 B aaStringAppendfLen                  (VP dst,HP chars,VP fmt,...);
 B aaStringSpacedAppendf               (VP dst,VP fmt,...);
 B aaStringCopyx                       (VP dst,VP fmt,...);
 B aaStringCompare                     (VP dst,VP src,NP dif);
 B aaStringICompare                    (VP dst,VP src,NP dif);
 B aaStringNCompare                    (VP dst,VP src,H chars,NP dif);
 B aaStringNICompare                   (VP dst,VP src,H chars,NP dif);
 B aaStringUpper                       (VP str,H chars,VP ostr);
 B aaStringLower                       (VP str,H chars,VP ostr);
 B aaStringReverse                     (VP str,H chars,VP ostr,B appendnull);
 B aaStringInsertChar                  (VP str,H chars,H pos,C ch);
 B aaStringInsertChars                 (VP str,H chars,H pos,C ch,H inscount);
 B aaStringDeleteChar                  (VP str,H chars,H pos);
 B aaStringDeleteChars                 (VP str,H chars,H pos,H delcount);
 B aaStringDeleteCharsTillChar         (VP str,H chars,B ch,B incch,HP len);
 B aaStringCharGet                     (VP str,H chars,N pos,BP ch);
 B aaStringCharSet                     (VP str,H chars,N pos,B ch);
 B aaStringCharUpper                   (VP str,H chars,N pos);
 B aaStringCharLower                   (VP str,H chars,N pos);
 B aaStringLastCharGet                 (VP str,H chars,BP ch);
 B aaStringLastCharSet                 (VP str,H chars,B ch,B appendnull);
 B aaStringIsLastChar                  (VP str,H chars,B ch);
 B aaStringLastCharNonVisibleRemove    (VP str,H chars);
 B aaStringFirstCharNonVisibleRemove   (VP str,H chars);
 B aaStringInsertString                (VP str,H chars,H pos,VP istr,H ichars);
 B aaStringInsertStringf               (VP str,H chars,H pos,B appendnull,VP fmt,...);
 B aaStringIsString                    (VP str,NP which,...);
 B aaStringIsIString                   (VP str,NP which,...);
 B aaStringIsStringPartial             (VP str,NP which,...);
 B aaStringIsIStringPartial            (VP str,NP which,...);
 B aaStringIsNumerical                 (VP str,B allowfloat,B allowsign,H chars);
 B aaStringIsDeliminated               (VP str,H chars,WP type,BP mode);
 B aaStringCountNumbers                (VP str,H chars,HP count,B consecutive);
 B aaStringCountHex                    (VP str,H chars,HP count,B consecutive);
 B aaStringCountAlpha                  (VP str,H chars,HP count,B upper,B lower,B underscore,B consecutive);
 B aaStringCountAlphaNum               (VP str,H chars,HP count,B upper,B lower,B underscore,B numerical,B consecutive);
 B aaStringCountVisibleChars           (VP str,H chars,HP count,B logic,B consecutive,B fwd);
 B aaStringIsPrintable                 (VP str,H chars);
 B aaStringCountPrintable              (VP str,H chars,HP count);
 B aaStringToDouble                    (VP str,H chars,DP dub);
 B aaStringToNumber                    (VP str,H chars,HP loh,HP hih,GP gv,QP qv);
 B aaStringHexToNumber                 (VP str,H chars,HP loh,HP hih,GP gv,QP qv);
 B aaStringFromBinary                  (VP str,H from,H nbits,H gbits,B dir,VP mem);
 B aaStringCountChars                  (VP str,H chars,HP count,B ch,B consecutive,B logic);
 B aaStringFindChar                    (VP str,H chars,HP pos,B ch,B logic,H number,B fwd);
 B aaStringFindCharList                (VP str,H chars,HP pos,VP chlist,B logic,H number,B fwd);
 B aaStringFindFirstAlpha              (VP str,H chars,HP pos,B logic);
 B aaStringFindFirstNumber             (VP str,H chars,HP pos,B logic);
 B aaStringFindCharVisible             (VP str,H chars,HP pos,B logic,H number,B fwd);
 B aaStringReplaceChar                 (VP str,H chars,B fromch,B toch);
 B aaStringReplaceString               (VP str,H chars,VP fstr,H fchars,VP tstr,H tchars,B iscasesensitive,VP ostr);
 B aaStringFindFirstString             (VP str,H chars,VP fstr,H fchars,HP pos); // added flag to return pos at start or end of the match
 B aaStringFindFirstIString            (VP str,H chars,VP fstr,H fchars,HP pos);
 B aaStringCleanup                     (VP str,H chars,B ignorequoted,HP newlen);
 B aaStringRemoveMultipleSpaces        (VP str,H chars,B ignorequoted);
 B aaStringRemoveSpaces                (VP str,H chars,B removeleading,B removetrailing);
 B aaStringRemoveChars                 (VP str,H chars,B ch);
 B aaStringDespace                     (VP str,H chars);
 B aaStringFindFirstIStrings           (VP str,H chars,HP pos,HP len,NP which,...);
 B aaStringIsQuoted                    (VP str,H chars,BP qchar);
 B aaStringIsBraced                    (VP str,H chars);
 B aaStringIsBracketed                 (VP str,H chars);
 B aaStringIsParenthesized             (VP str,H chars);
 B aaStringQuotify                     (VP str,H chars,B qchar);
 B aaStringRandomSet                   (VP str,H chars,B alphalo,B alphahi,B numerical,B appendnull);
 B aaStringHashGet                     (VP str,H chars,HP hash,B iscasesensitive);
 B aaStringHashIsTrue                  (VP str,H chars,H hash,B iscasesensitive);
 B aaStringHashBothGet                 (VP str,H chars,HP hash,HP hashi);
 B aaStringGuid                        (VP str,B appendnull);
 B aaStringIsGuid                      (VP str);
 B aaStringFromWideString              (VP str,WCHAR*wstr);
 B aaStringToWideString                (VP str,WCHAR*wstr);
 B aaStringPathSanitize                (VP str,H chars,VP ostr);
 B aaStringRot13                       (VP str,H chars,VP ostr);
 B aaStringTranspose                   (VP str,H chars,N amnt,VP ostr);
 B aaStringFromDword                   (VP str,H val);
 B aaStringFromArrayHex                (VP str,H sizet,H count,H cols,B dooffs,B doascii,VP mem);
 B aaStringHexDump                     (VP str,H sizet,H count,H cols,B dooffs,B doascii,VP buf,VP fmt,...);
 B aaStringSplit                       (VP str,H chars,H pos,B incsplit,VP str1,VP str2);
 B aaStringSplitChar                   (VP str,H chars,B ch,B incsplit,B logic,H number,B fwd,VP str1,VP str2);
 B aaStringExplode                     (VP str,H chars,_stringexplode*explode,B dch);
 B aaStringExplodeTokenGet             (VP str,H index,_stringexplode*explode,VP token);
 B aaStringExplodePtrGet               (VP str,H index,_stringexplode*explode,PP token);
 B aaStringEncode                      (VP str,H chars,VP ostr,B appendnull,VP ignorecharlist);
 B aaStringDecode                      (VP str,H chars,VP ostr,B fully,B appendnull);
 B aaStringEntityToPseudoEnglish       (VP str,H chars,VP ostr);
 B aaStringLineCountGet                (VP str,H chars,HP lines);
 B aaStringLineCountGetToMemory        (VP str,H chars,HP lines,H maxinfolines,PP lineoff,PP linechars);
 B aaStringLineCountGetToBuffer        (VP str,H chars,HP lines,H maxinfolines,HP lineoff,HP linechars);
 B aaStringLineGet                     (VP str,H chars,HP strchars,HP modechars,HP totchars,BP mode);
 B aaStringMatchCount                  (VP str,H chars,VP fstr,H fchars,B iscasesensitive,HP count,B logic);
 B aaStringLengthModeAdjust            (B mode,H chars,B addflag,HP adjustedchars);
 B aaStringToker                       (VP str,H chars,_stringtoker*toker,B dohash,B dobuf);
 B aaStringTokerMini                   (VP str,H chars,_stringtokermini*tokermini);
 B aaStringTokerMaxi                   (VP str,H chars,_stringtokermaxi*tokermaxi);
 B aaStringTokerMiniStringGet          (VP str,H index,H maxchars,_stringtokermini*tokermini);
 B aaStringTokerMaxiStringGet          (VP str,H index,H maxchars,_stringtokermaxi*tokermaxi);
 B aaStringUnicodeToClosestEnglish     (VP str,H chars,VP ostr);
 B aaStringContract                    (VP str,H chars,N amnt);
 B aaStringUtfLen                      (VP str,H chars,HP uchars);
 B aaStringUtfPosGet                   (VP str,H uchrs,H pos,HP off);
 B aaStringUtfTypeGet                  (VP str,H chars,HP type);
 B aaStringToUtf8                      (VP str,H chars,HP ochars,H maxochars,VP ostr);
 B aaStringTokenGet                    (VP str,H chars,B ch,H ti,HP toff,HP tchars,VP tok);
 B aaStringFix                         (VP str);
 B aaStringWildCompare                 (VP str,H chars,VP wildcard);
 B aaStringStartsWithContains          (VP str,H chars,VP sstr,H schars,B isand,VP contains,...);

/*-----------------------------------------------------------------------*/

VP aaf                                (VP buf,H off,VP fmt,...);

/*-----------------------------------------------------------------------*/

 B aaBase64Encode                      (VP mem,H bytes,VP str,HP chars);
 B aaBase64Decode                      (VP str,H chars,VP mem,HP bytes);

/*-----------------------------------------------------------------------*/

 structure
 {
 H time_low;
 W time_mid;
 W time_hi_and_version;
 B clock_seq_hi_and_reserved;
 B clock_seq_low;
 B node[6];
 }
 _guid;

 B aaGuidInit                          (_guid*guid,VP node);
 B aaGuidSet                           (_guid*guid,W cseq,Q tstamp,VP node);
 B aaGuidToString                      (_guid*guid,VP str);



/*-----------------------------------------------------------------------*/

 #define PARSERFLAG_SAFE               1
 #define PARSERFLAG_PAST               2
 #define PARSERFLAG_PUSH               4

 structure
 {
 H magic;
 BP string;
 BP bp;
 B ch;
 H length;
 H offset;
 H to_end;
 B is_start;
 B is_end;
 B stack_len;
 H stack_buf[4];
 }
 _parser;

 B aaParserInit                        (_parser*parser,VP string,H chars);
 B aaParserCopy                        (_parser*parser,_parser*sparser,B reset);
 B aaParserSeek                        (_parser*parser,N amnt);
 B aaParserOffsetSet                   (_parser*parser,H offset);
 B aaParserDeleteChars                 (_parser*parser,H amnt);
 B aaParserReset                       (_parser*parser);
 B aaParserSeekToChar                  (_parser*parser,B ch,B logic,B fwd);
 B aaParserSeekToCharList              (_parser*parser,VP chlist,B logic);
 B aaParserSeekToNumber                (_parser*parser,B logic);
 B aaParserSeekToVisibleChar           (_parser*parser,B logic);
 B aaParserSeekToString                (_parser*parser,VP string,B cs,B logic,B flags);
 B aaParserSeekToStringf               (_parser*parser,B cs,B logic,B flags,VP fmt,...);
 B aaParserStringCopy                  (_parser*parser,VP buf,H chars,B appendnull);
 B aaParserStackPush                   (_parser*parser);
 B aaParserStackPop                    (_parser*parser);
 B aaParserStackPeek                   (_parser*parser,H index,HP offset);
 B aaParserStackDiscard                (_parser*parser);
 B aaParserStackString                 (_parser*parser,HP chars,H maxchars,VP buf,B appendnull);


/*-----------------------------------------------------------------------*/

 #define aa_ALIGN_NONE                 0
 #define aa_ALIGN_TOP                  1
 #define aa_ALIGN_LEFT                 2
 #define aa_ALIGN_BOTTOM               3
 #define aa_ALIGN_RIGHT                4
 #define aa_ALIGN_MIDDLE               5
 #define aa_ALIGN_LMIDDLE              6
 #define aa_ALIGN_RMIDDLE              7
 #define aa_ALIGN_TMIDDLE              8
 #define aa_ALIGN_BMIDDLE              9

/*-----------------------------------------------------------------------*/

 #define aaSizeParts(s)                s.w,s.h
 #define aaCordParts(c)                c.x,c.y
 #define aaRectParts(r)                r.x,r.y,r.w,r.h
 #define aaRectPartsAsCords(r)         r.x,r.y,((r.x+r.w)-1),((r.y+r.h)-1)

 #define aaGridX(xx,yy,ww,hh)          xx*100.0,yy*100.0,ww*100.0,hh*100.0


 structure
 {
 N x,y;
 }
 _cord;


 structure
 {
 H w,h;
 }
 _size;


 structure
 {
 N x,y;
 H w,h;
 }
 _rect;

///---------- common dimensions

 PUB _size aa_size_32x32;
 PUB _size aa_size_320x240;
 PUB _size aa_size_640x480;
 PUB _size aa_size_800x600;
 PUB _size aa_size_1024x768;

///------------------------------------------


 B aaCordNull                          (_cord*cord);
 B aaCordSet                           (_cord*cord,N x,N y);
 B aaCordGet                           (_cord*cord,NP x,NP y);
 B aaCordCopy                          (_cord*cord,_cord*scord);
 B aaCordAdjust                        (_cord*cord,N xa,N ya);
 B aaCordsAdjust                       (_cord*cord1,_cord*cord2,N x1a,N y1a,N x2a,N y2a);
 B aaCordEqualsCord                    (_cord*cord,_cord*cord2);
 B aaCordSubtract                      (_cord*cord,_cord*cord2,_cord*rescord);
 B aaCordAdd                           (_cord*cord,_cord*cord2,_cord*rescord);
 B aaCordIsWithinRect                  (_cord*cord,_rect*rect);
 B aaCordIsWithinRects                 (_cord*cord,_rect*rect,H count,HP which);
 B aaCordsSet                          (_cord*cord1,_cord*cord2,N x1,N y1,N x2,N y2);
 B aaCordsToRect                       (_cord*cord1,_cord*cord2,_rect*rect);
 B aaCordIsZero                        (_cord*cord);
 B aaCordCopyFromRect                  (_cord*cord,_rect*srect);

 B aaSizeNull                          (_size*size);
 B aaSizeSet                           (_size*size,H w,H h);
 B aaSizeGet                           (_size*size,HP w,HP h);
 B aaSizeCopy                          (_size*size,_size*ssize);
 B aaSizeAdjust                        (_size*size,N wa,N ha);
 B aaSizeEqualsSize                    (_size*size,_size*size2);
 B aaSizeToRect                        (_size*size,_rect*rect);
 B aaSizeIsValid                       (_size*size);
 B aaSizeCordCenterGet                 (_size*size,_cord*cord);

 B aaRectNull                          (_rect*rect);
 B aaRectIsEmpty                       (_rect*rect);
 B aaRectSet                           (_rect*rect,N x,N y,H w,H h);
 B aaRectGet                           (_rect*rect,NP x,NP y,HP w,HP h);
 B aaRectCopy                          (_rect*rect,_rect*srect);
 B aaRectAdjust                        (_rect*rect,N xa,N ya,N wa,N ha);
 B aaRectCordSet                       (_rect*rect,N x,N y);
 B aaRectSizeSet                       (_rect*rect,H w,H h);
 B aaRectEqualsRect                    (_rect*rect,_rect*rect2);
 B aaRectIntersect                     (_rect*rect,_rect*rect2,_rect*resrect);
 B aaRectIsInsideRect                  (_rect*rect,_rect*rect2);
 B aaRectIsOutsideRect                 (_rect*rect,_rect*rect2);
 B aaRectIsOverlappingRect             (_rect*rect,_rect*rect2);
 B aaRectAdd                           (_rect*rect,_rect*rect2,_rect*resrect);
 B aaRectSubtract                      (_rect*rect,_rect*rect2,_rect*resrect);
 B aaRectToCords                       (_rect*rect,_cord*cord1,_cord*cord2);
 B aaRectToSize                        (_rect*rect,_size*size);
 B aaRectIsValid                       (_rect*rect);
 B aaRectCordCenterGet                 (_rect*rect,_cord*cord);
 B aaRectExpand                        (_rect*rect,N wamnt,N hamnt);
 B aaRectToCornerCords                 (_rect*rect,_cord*cord1,_cord*cord2,_cord*cord3,_cord*cord4);
 B aaRectToSideCords                   (_rect*rect,_cord*cord1,_cord*cord2,_cord*cord3,_cord*cord4);
 B aaRectAlignRect                     (_rect*rect,_rect*rect2,B ha,B va,_rect*resrect);
 B aaRectFromWinRect                   (_rect*rect,RECT*winrect);

 B aaGridToCord                        (_rect*rect,_cord*g1,_cord*c1);
 B aaGridToCords                       (_rect*rect,_cord*g1,_cord*g2,_cord*c1,_cord*c2);
 B aaGridToRect                        (_rect*rect,_cord*g1,_cord*g2,_rect*r1);
 B aaGridRectToCord                    (_rect*rect,_rect*r1,_cord*c1);
 B aaGridRectToCords                   (_rect*rect,_rect*r1,_cord*c1,_cord*c2);
 B aaGridRectToRect                    (_rect*rect,_rect*r1,_rect*r2);

 B aaCordToGrid                        (_rect*rect,_cord*c1,_cord*g1);
 B aaCordToGrids                       (_rect*rect,_cord*c1,_cord*c2,_cord*g1,_cord*g2);
 B aaRectToGrid                        (_rect*rect,_rect*r1,_cord*g1,_cord*g2);

 B aaGridFromFloats                    (_cord*cord1,_cord*cord2,D x1,D y1,D x2,D y2);

/*-----------------------------------------------------------------------*/

 structure
 {
 F x,y;
 }
 _fcord;

 structure
 {
 F w,h;
 }
 _fsize;

 structure
 {
 F x,y,w,h;
 }
 _frect;


 B aaFCordSet                          (_fcord*fcord,F x,F y);
 B aaFCordCopy                         (_fcord*fcord,_fcord*sfcord);

 B aaFSizeSet                          (_fsize*fsize,F w,F h);
 B aaFsizeCopy                         (_fsize*fsize,_fsize*sfsize);

 B aaFRectSet                          (_frect*frect,F x,F y,F w,F h);
 B aaFRectCopy                         (_frect*frect,_frect*sfrect);


/*-----------------------------------------------------------------------*/

 #define aaRgbaParts(p)                p.r,p.g,p.b,p.a

 #define colmap_gray                   0
 #define colmap_red                    32
 #define colmap_green                  64
 #define colmap_blue                   96
 #define colmap_purple                 128
 #define colmap_yellow                 160
 #define colmap_cyan                   192
 #define colmap_orange                 224
 #define colmap_sky                    256
 #define colmap_pastelred              288
 #define colmap_pastelgreen            320
 #define colmap_pastelblue             352
 #define colmap_pastelpurple           384
 #define colmap_pastelyellow           416
 #define colmap_pastelcyan             448
 #define colmap_pastelorange           480
 #define colmap_pastelsky              512


 #define aaColMap(a,b)                 ((a*32)+b)


 structure
 {
 B b,g,r,a;
 }
 _rgba;

 structure
 {
 _rgba bg;
 _rgba fg;
 }
 _rgbabf;


 PUB _rgba col_null,col_black,col_white,col_gray[32];
 PUB _rgba col_red[32],col_green[32],col_blue[32];
 PUB _rgba col_purple[32],col_yellow[32],col_cyan[32];
 PUB _rgba col_orange[32],col_sky[32];
 PUB _rgba col_pastelred[32],col_pastelgreen[32],col_pastelblue[32];
 PUB _rgba col_pastelpurple[32],col_pastelyellow[32],col_pastelcyan[32];
 PUB _rgba col_pastelorange[32],col_pastelsky[32];
 PUB _rgba*col_map[576];


 B aaRgbaSet                           (_rgba*rgba,B r,B g,B b,B a);
 B aaRgbaCopy                          (_rgba*rgba,_rgba*srgba);
 B aaRgbaCopyWithAlpha                 (_rgba*rgba,_rgba*srgba,B a);
 B aaRgbaAdjust                        (_rgba*rgba,N ramnt,N gamnt,N bamnt,N aamnt);
 B aaRgbaEqualsRgba                    (_rgba*rgba,_rgba*rgba2);
 B aaRgbaGradientArray                 (_rgba*rgba1,_rgba*rgba2,H count,_rgba*rgbaarray);
 B aaRgbaDwordSet                      (_rgba*rgba,H dword);
 B aaRgbaYuvaSet                       (_rgba*rgba,B y,B u,B v,B a);
 B aaRgbaSetUsingHlsa                  (_rgba*rgba,B h,B l,B s,B a);
 B aaRgbaMix                           (_rgba*p1,_rgba*p2,_rgba*p3);
 B aaRgbaAdjustUsingHlsa               (_rgba*p1,N hamnt,N lamnt,N samnt,N aamnt,_rgba*p2);
 B aaRgbaShadeSet                      (_rgba*p1,_rgba*p2,F amnt);
 B aaRgbaSwap                          (_rgba*p1,_rgba*p2);

 B aaRgbabfSet                         (_rgbabf*rgbabf,B rb,B gb,B bb,B ab,B rf,B gf,B bf,B af);
 B aaRgbabfCopy                        (_rgbabf*rgbabf,_rgba*rgbab,_rgba*rgbaf);



/*-----------------------------------------------------------------------*/

 #define aaYuvaParts(t)                t.y,t.u,t.v,t.a
 #define aaYuvaArgs(n)                 B y##n,B u##n,B v##n,B a##n


 structure
 {
 B y,u,v,a;
 }
 _yuva;

 B aaYuvaSet                           (_yuva*yuva,B y,B u,B v,B a);
 B aaYuvaCopy                          (_yuva*yuva,_yuva*syuva);
 B aaYuvaAdjust                        (_yuva*yuva,N yamnt,N uamnt,N vamnt,N aamnt);
 B aaYuvaToRgba                        (_yuva*yuva,_rgba*rgba);
 B aaYuvaFromRgba                      (_yuva*yuva,_rgba*rgba);

/*-----------------------------------------------------------------------*/

 #define aaHlsaParts(t)                t.h,t.l,t.s,t.a
 #define aaHlsaArgs(n)                 B h##n,B l##n,B s##n,B a##n


 structure
 {
 B h,l,s,a;
 }
 _hlsa;


 B aaHlsaSet                           (_hlsa*hlsa,B h,B l,B s,B a);
 B aaHlsaCopy                          (_hlsa*hlsa,_hlsa*shlsa);
 B aaHlsaAdjust                        (_hlsa*hlsa,N hamnt,N lamnt,N samnt,N aamnt);
 B aaHlsaToRgba                        (_hlsa*hlsa,_rgba*rgba);
 B aaHlsaFromRgba                      (_hlsa*hlsa,_rgba*rgba);

/*-----------------------------------------------------------------------*/

 _cord*aaCord                          (_cord*cd,N x,N y);
 _size*aaSize                          (_size*sz,H w,H h);
 _rect*aaRect                          (_rect*rc,N x,N y,H w,H h);
 _rgba*aaRgba                          (_rgba*pn,B r,B g,B b,B a);
 _yuva*aaYuva                          (_yuva*yu,B y,B u,B v,B a);
 _hlsa*aaHlsa                          (_hlsa*hl,B h,B l,B s,B a);

/*-----------------------------------------------------------------------*/


 structure
 {
 _rect rc0,rc1,rc2,rc3;
 _size sz0,sz1,sz2,sz3;
 _cord cd0,cd1,cd2,cd3;
 _rgba pn0,pn1,pn2,pn3;
 _yuva yv0,yv1,yv2,yv3;
 _hlsa hl0,hl1,hl2,hl3;
 _rect*rc[4];
 _size*sz[4];
 _cord*cd[4];
 _rgba*pn[4];
 _yuva*yv[4];
 _hlsa*hl[4];
 }
 _gfxclaw;

 B aaGfxClawInit                       (_gfxclaw*gfxclaw);



/*-----------------------------------------------------------------------*/

 #define aaThreadQuit(handle,ecode)    if(handle==0) {} ExitThread(ecode); return(ecode)


 structure
 {
 B is_locked;
 B is_paused;
 B is_exiting;
 B is_exited;
 H data;
 H exit_code;
 }
 _threadstatus;



 structure
 {
 H handle;
 _threadstatus status;
 }
 _threadunit;


 B aaThreadCreate                      (HP handle,H(*function)(VP parm),H data,B startpaused);
 B aaThreadDestroy                     (H handle);
 B aaThreadExit                        (H handle);
 B aaThreadStatus                      (H handle,_threadstatus*threadstatus);
 B aaThreadWait                        (H handle,B waitexit);
 B aaThreadPause                       (H handle,B state);
 B aaThreadLock                        (H handle,B wait);
 B aaThreadUnLock                      (H handle);


/*-----------------------------------------------------------------------*/

 structure
 {
 B is_paused;
 B is_exiting;
 B is_exited;
 B is_ready;
 B is_inherit;
 B is_detached;
 B is_newroot;
 B is_console;
 B is_login;
 B is_unresponsive;
 H unresponsive_count;
 H unresponsive_timeout;
 B delete_user;
 H exit_code;
 H ms;
 H tid;
 H pid;
 B desktop[129];
 HANDLE thread_handle;
 HANDLE process_handle;
 _threadunit crash_thread;
 B user[65];
 B pass[65];
 HWND hwnd;
 B file_name[257];
 B cmd_line[_1K];
 }
 _processstatus;


 structure
 {
 H module_id;
 H process_id;
 HANDLE process_handle;
 H thread_count;
 H parent_process_id;
 B dev_path[513];
 B exe_file[513];
 B exe_path[513];
 B cmd_line[_1K];
 }
 _processentry;



 structure
 {
 H magic;
 H entries;
 _processentry*entry;
 }
 _processlist;


 structure
 {
 H thread_id;
 H owner_process_id;
 }
 _processthreadentry;




 structure
 {
 H handle;
 _processstatus status;
 }
 _processunit;


 B aaProcessCreate                     (HP handle,VP fname,VP cmdline,B clmode,B inherit,B startpaused,B detach,B newroot,W showcmd,B isconsole,VP desktop);
 B aaProcessCreateWithLogin            (HP handle,VP fname,VP cmdline,VP user,VP pass,B detach,B newroot);
 B aaProcessDestroy                    (H handle);
 B aaProcessExit                       (H handle);
 B aaProcessPause                      (H handle,B state);
 B aaProcessStatus                     (H handle,_processstatus*processstatus);
 B aaProcessStatusToString             (H handle,_processstatus*processstatus,VP str);
 B aaProcessUnresponsiveTimeoutSet     (H handle,H ms);
 B aaProcessRetry                      (H handle);
 B aaProcessSpawn                      (VP fname,VP cmdline,W showcmd,HP prochan,HP procid);
 B aaProcessLaunch                     (VP exefile,VP exeargs,VP workdir,W showcmd,HP prochan,HP procid);
 B aaProcessIsRunning                  (VP exename,HP count);
 B aaProcessThreadList                 (HP handle,H index,_processthreadentry*processthreadentry);
 B aaProcessThreadListDestroy          (H handle);
 B aaProcessTerminateByHandle          (HANDLE handle,W ecode);
 B aaProcessTerminateByPid             (H pid,W ecode);
 B aaProcessRestart                    (VP exename,VP cmdline,HP prochan,HP procid);
 B aaProcessListGather                 (_processlist*processlist);
 B aaProcessListRelease                (_processlist*processlist);


/*-----------------------------------------------------------------------*/


 structure
 {
 H switch_count;
 B is_converted;
 H extra_bytes;
 BP extra_data;
 }
 _fiberstatus;


 structure
 {
 H handle;
 H data;
 }
 _fiberparm;


 structure
 {
 H handle;
 _fiberstatus status;
 }
 _fiberunit;


 B aaFiberCreate                       (HP handle,H ssize,V(*proc)(VP),H data);
 B aaFiberDestroy                      (H handle);
 B aaFiberStatus                       (H handle,_fiberstatus*fiberstatus);
 B aaFiberConvert                      (H handle);
 B aaFiberSwitch                       (H handle);
 B aaFiberReturn                       (H handle);
 B aaFiberExtraDataSet                 (H handle,H bytes);

/*-----------------------------------------------------------------------*/


 structure
 {
 Q id;
 H index;
 B state;
 BP mem;
 }
 _poolblock;


 structure
 {
 H bytes_per_block;
 H blocks_per_page;
 H max_pages;
 Q max_possible_blocks;
 Q max_possible_memory;
 H block_count;
 }
 _poolstatus;



 structure
 {
 H handle;
 _poolstatus status;
 }
 _poolunit;



 B aaPoolCreate                        (HP handle,H bytesperblock,H blocksperpage,H maxpages);
 B aaPoolDestroy                       (H handle);
 B aaPoolStatus                        (H handle,_poolstatus*poolstatus);
 B aaPoolStatusToString                (H handle,_poolstatus*poolstatus,VP str);

 B aaPoolBlockNew                      (H handle,_poolblock*poolblock);
 B aaPoolBlockDelete                   (H handle,VP block);
 B aaPoolBlockDeleteByIndex            (H handle,H bindex);
 B aaPoolBlockInfoGet                  (H handle,VP block,_poolblock*poolblock);
 B aaPoolBlockGetByIndex               (H handle,H bindex,_poolblock*poolblock);


/*-----------------------------------------------------------------------*/

 #define aa_WINENUM_THREADID           1
 #define aa_WINENUM_STANDARD           2
 #define aa_WINENUM_CHILDREN           3

 structure
 {
 HWND hwnd;
 HWND parent_hwnd;
 HWND owner_hwnd;
 B c_txt[300];
 B t_txt[300];
 B is_visible;
 B is_child;
 H pid;
 H tid;
 B user_data[64];
 }
 _winenumentry;


 structure
 {
 B in_progress;
 B is_completed;
 B is_fail;
 B is_success;
 B mode;
 H hanhwn;
 H total_entries;
 H total_windows;
 H total_children;
 H total_visible;
 _winenumentry*entry;
 }
 _winenumstatus;


 structure
 {
 H handle;
 _winenumstatus status;
 }
 _winenumunit;


 B aaWinEnumCreate                     (HP handle,B mode,H hanhwn);
 B aaWinEnumDestroy                    (H handle);
 B aaWinEnumStatus                     (H handle,_winenumstatus*winenumstatus);

/*-----------------------------------------------------------------------*/

 structure
 {
 H bytes_used;
 H bytes_allocated;
 H bytes_left;
 H bits_used;
 BP mem;
 }
 _dynbufstatus;

 structure
 {
 H handle;
 _dynbufstatus status;
 }
 _dynbufunit;

 B aaDynbufCreate                      (HP handle);
 B aaDynbufDestroy                     (H handle);
 B aaDynbufStatus                      (H handle,_dynbufstatus*dynbufstatus);
 B aaDynbufReset                       (H handle);
 B aaDynbufSeek                        (H handle,H offset);
 B aaDynbufAppendByte                  (H handle,B val);
 B aaDynbufAppendWord                  (H handle,W val);
 B aaDynbufAppendDword                 (H handle,H val);
 B aaDynbufAppend                      (H handle,H bytes,VP data);
 B aaDynbufAppendf                     (H handle,VP fmt,...);
 B aaDynbufAppendBits                  (H handle,H bits,N data,B issigned);

/*-----------------------------------------------------------------------*/

 structure
 {
 H length;
 }
 _arraystatus;

 structure
 {
 H handle;
 _arraystatus status;
 }
 _arrayunit;


 B aaArrayCreate                       (HP handle);
 B aaArrayDestroy                      (H handle);
 B aaArrayStatus                       (H handle,_arraystatus*arraystatus);
 B aaArrayLengthSet                    (H handle,H bytes);
 B aaArrayWrite                        (H handle,H offset,H bytes,VP data);
 B aaArrayRead                         (H handle,H offset,H bytes,VP data);
 B aaArrayFill                         (H handle,H offset,H bytes,B val);

/*-----------------------------------------------------------------------*/


 structure
 {
 H bytes;
 Q total_bytes_read;
 Q total_bytes_written;
 }
 _questatus;

 structure
 {
 H handle;
 _questatus status;
 }
 _queunit;

 B aaQueCreate                         (HP handle);
 B aaQueDestroy                        (H handle);
 B aaQueStatus                         (H handle,_questatus*questatus);
 B aaQueWrite                          (H handle,H bytes,VP data);
 B aaQueWritef                         (H handle,VP fmt,...);
 B aaQueWriteByte                      (H handle,B val);
 B aaQueWriteWord                      (H handle,W val);
 B aaQueWriteDword                     (H handle,H val);
 B aaQueWriteQuad                      (H handle,Q val);
 B aaQueRead                           (H handle,H bytes,VP data);
 B aaQueReadByte                       (H handle,BP val);
 B aaQueReadWord                       (H handle,WP val);
 B aaQueReadDword                      (H handle,HP val);
 B aaQueReadQuad                       (H handle,QP val);
 B aaQuePeek                           (H handle,H offset,H bytes,VP data);
 B aaQuePeekByte                       (H handle,H offset,BP val);
 B aaQuePeekWord                       (H handle,H offset,WP val);
 B aaQuePeekDword                      (H handle,H offset,HP val);
 B aaQuePeekQuad                       (H handle,H offset,QP val);
 B aaQueFindByte                       (H handle,H offset,H bytes,HP pos,B val,B logic,H number);
 B aaQueDiscard                        (H handle,H bytes);
 B aaQueStringLen                      (H handle,HP chars,BP stringmode);
 B aaQueStringRead                     (H handle,HP chars,BP stringmode,H maxchars,VP buf);
 B aaQueReturn                         (H handle,H bytes);
 B aaQueTrim                           (H handle,H bytes);


/*-----------------------------------------------------------------------*/



 structure
 {
 BP ptr;
 H data_bytes;
 BP data_ptr;
 }
 _aavectorslot;


 structure
 {
 H magic;
 H count;
 H bytes;
 H used;
 H left;
 VP mem;
 Q total_data_bytes;
 }
 _aavector;


 B aaVectorNew                         (_aavector*aavector,H slotbytes,H initialslots);
 B aaVectorDelete                      (_aavector*aavector);
 B aaVectorExtendSlots                 (_aavector*aavector,H amnt);
 B aaVectorDataBytesSet                (_aavector*aavector,H slot,H bytes,_aavectorslot*aavectorslot);
 B aaVectorSlotGet                     (_aavector*aavector,H slot,_aavectorslot*aavectorslot);
 B aaVectorUsageAdjust                 (_aavector*aavector,N amount);


/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 B is_initialized;
 _memoryunit heap_buf;
 }
 _aahuff;


 B aaHuffNew                           (_aahuff*aahuff);
 B aaHuffDelete                        (_aahuff*aahuff);
 B aaHuffEncode                        (_aahuff*aahuff,H ibytes,VP ibuf,HP obytes,H obufmax,VP obuf);
 B aaHuffDecode                        (_aahuff*aahuff,H ibytes,VP ibuf,HP obytes,H obufmax,VP obuf);


/*-----------------------------------------------------------------------*/

 B aaLz4Encode                         (VP source,H sbytes,VP dest,HP dbytes);
 B aaLz4Decode                         (VP source,H sbytes,VP dest,HP dbytes,H maxdbytes);

/*-----------------------------------------------------------------------*/


 structure
 {
 H magic;
 H head,tail;
 H bytes,left;
 B buf[_8K];
 }
 _minique;

 B aaMiniQueInit                       (_minique*minique);
 B aaMiniQueWrite                      (_minique*minique,H bytes,VP data);
 B aaMiniQueRead                       (_minique*minique,H bytes,VP data);
 B aaMiniQuePeek                       (_minique*minique,H offset,H bytes,VP data);
 B aaMiniQueDiscard                    (_minique*minique,H bytes);
 B aaMiniQueReturn                     (_minique*minique,H bytes);

/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 H bytes,left;
 N height;
 B buf[_8K];
 }
 _ministack;

 B aaMiniStackInit                     (_ministack*ministack);
 B aaMiniStackPush                     (_ministack*ministack,H bytes,VP data);
 B aaMiniStackPushByte                 (_ministack*ministack,B val);
 B aaMiniStackPushWord                 (_ministack*ministack,W val);
 B aaMiniStackPushDword                (_ministack*ministack,H val);
 B aaMiniStackPushQuad                 (_ministack*ministack,Q val);
 B aaMiniStackPushStringf              (_ministack*ministack,VP fmt,...);
 B aaMiniStackPushMulti                (_ministack*ministack,VP fmt,...);
 B aaMiniStackPop                      (_ministack*ministack,H bytes,VP data);
 B aaMiniStackPopByte                  (_ministack*ministack,BP val);
 B aaMiniStackPopWord                  (_ministack*ministack,WP val);
 B aaMiniStackPopDword                 (_ministack*ministack,HP val);
 B aaMiniStackPopQuad                  (_ministack*ministack,QP val);
 B aaMiniStackPopString                (_ministack*ministack,HP chars,H maxchars,VP str);
 B aaMiniStackPopMulti                 (_ministack*ministack,VP fmt,...);
 B aaMiniStackPeek                     (_ministack*ministack,H offset,H bytes,VP data);
 B aaMiniStackPeekByte                 (_ministack*ministack,H offset,BP val);
 B aaMiniStackPeekWord                 (_ministack*ministack,H offset,WP val);
 B aaMiniStackPeekDword                (_ministack*ministack,H offset,HP val);
 B aaMiniStackPeekQuad                 (_ministack*ministack,H offset,QP val);
 B aaMiniStackPeekString               (_ministack*ministack,H index,HP chars,H maxchars,VP str);
 B aaMiniStackDiscard                  (_ministack*ministack,H bytes);




/*-----------------------------------------------------------------------*/


 structure
 {
 B is_ok;
 H waiting;
 H number;
 H ms,lag;
 H msg;
 N lparm;
 H hparm;
 H bytes;
 B data[257];
 }
 _generalevent;


 B aaGeneralEventWaitingGet            (H id,HP count);
 B aaGeneralEventWrite                 (H id,H msg,N lparm,H hparm,H bytes,VP data);
 B aaGeneralEventWritef                (H id,H msg,N lparm,H hparm,VP fmt,...);
 B aaGeneralEventRead                  (H id,_generalevent*genevent);
 B aaGeneralEventPeek                  (H id,H index,_generalevent*genevent);
 B aaGeneralEventDiscard               (H id);
 B aaGeneralEventPurge                 (H id);



/*-----------------------------------------------------------------------*/


 structure
 {
 H incoming_tcp_ports_inuse;
 H max_tcp_ports;
 H total_outgoing_tcp_call_count;
 H total_incoming_tcp_call_count;
 H total_tcp_call_count;
 H current_outgoing_tcp_call_count;
 H current_incoming_tcp_call_count;
 H current_tcp_calls_connected;
 H max_tcp_calls;
 Q total_udp_packets_received;
 Q total_udp_packets_sent;
 Q total_tcp_bytes_out;
 Q total_tcp_bytes_in;
 H public_ip_count;
 H public_ip[256];
 H broadcast_ip[256];
 }
 _netstatus;


 structure
 {
 H ip;
 B ip_dot[16];
 H subnet;
 B subnet_dot[16];
 }
 _netinfoadapteraddress;


 structure
 {
 B description[257];
 B physical_address[65];
 B is_type_other;
 B is_type_ethernet;
 B is_type_tokenring;
 B is_type_fddi;
 B is_type_ppp;
 B is_type_loopback;
 B is_type_slip;
 B is_type_unknown;
 H gateway;
 B gateway_dot[16];
 H dhcp;
 B dhcp_dot[16];
 H primary_wins;
 B primary_wins_dot[16];
 H secondary_wins;
 B secondary_wins_dot[16];
 H address_count;
 _netinfoadapteraddress address[8];

 }
 _netinfoadapter;


 structure
 {
 B host_name[257];
 B domain_name[257];
 H dns_server_ip[32];
 B dns_server_dot[32][16];
 H dns_server_count;
 B is_broadcast_node;
 B is_ppp_node;
 B is_mixed_node;
 B is_hybrid_node;
 B is_unknown_node;
 B dhcp_scope_name[257];
 B is_routing_enabled;
 B is_arpproxy_enabled;
 B is_dns_enabled;
 H adapter_count;
 _netinfoadapter adapter[8];
 }
 _netinfo;



 structure
 {
 H ip[32];
 B type[32];
 B dot[32][17];
 B mac[32][6];
 B mac_dot[32][18];
 H bcast_ip[32];
 B bcast_dot[32][18];
 B count;
 }
 _localip;


 structure
 {
 B title[17];
 B first[33];
 B middle[33];
 B last[33];
 B gender;
 B dob;
 B mob;
 W yob;
 B country[90];
 B email[90];
 }
 _randomuser;


 structure
 {
 B first_name[65];
 B last_name[65];
 B email[129];
 }
 _wabentry;



 structure
 {
 H ip;
 W port;
 }
 _netadr;



 structure
 {
 H ip;
 H mask;
 H prefix;
 H network_ip;
 H broadcast_ip;
 H min_ip;
 H max_ip;
 }
 _netsubnet;


 structure
 {
 B scheme[129];
 B raw_url[_1K];
 B dec_url[_1K];
 B absolute[_1K];
 B relative[513];
 B filename[257];
 B parms[_1K];
 B ext[65];
 B file[257];
 B path[513];
 B host[129];
 _netadr adr;
 }
 _urlparts;



 structure
 {
 B name[257];
 B value[513];
 _systime expires;
 B expires_text[129];
 B path[257];
 B domain[129];
 B is_http_only;
 B is_expired;
 B is_secure;
 G expires_in;
 }
 _cookie;


 structure
 {
 BP ptr[65];
 B server_software[257];
 B server_name[129];
 B gateway_interface[129];
 B server_protocol[33];
 B server_port[33];
 B request_uri[1025];
 B request_method[129];
 B script_name[1025];
 B script_filename[1025];
 B url[1025];
 B query_string[1025];
 B remote_host[129];
 B remote_addr[33];
 B remote_port[17];
 B content_type[1025];
 B content_length[17];
 B document_root[1025];
 B instance_id[65];
 B http_accept[2049];
 B http_user_agent[513];
 B http_connection[65];
 B http_cookie[2049];
 B http_host[129];
 B http_referer[1025];
 B https[33];
 B path_info[1025];
 B path_translated[1025];
 B auth_type[2049];
 B auth_user[1025];
 B remote_user[1025];
 B remote_ident[2049];
 B server_admin[257];
 B server_signature[1025];
 }
 _cgienv;



 structure
 {
 B is_exited;
 B is_ready;
 B is_failed;
 B is_hidden;
 H exit_code;
 H tid;
 H pid;
 HANDLE thread_handle;
 HANDLE process_handle;
 Q total_rcve_bytes;
 Q total_xmit_bytes;
 H rcve_bytes;
 H xmit_bytes;
 H rcve_inactivity;
 H xmit_inactivity;
 H line_inactivity;
 H ms;
 }
 _cgiclientstatus;



 #define aa_DNS_MODE_A                 1
 #define aa_DNS_MODE_NS                2
 #define aa_DNS_MODE_CNAME             5
 #define aa_DNS_MODE_SOA               6
 #define aa_DNS_MODE_MX                15
 #define aa_DNS_MODE_TXT               16

 structure
 {
 B is_inprogress;
 B is_failed;
 B is_found;
 B is_notfound;
 B is_forward;
 H attempt;
 C query[129];
 B mode;
 B bypass;
 H result_count;
 C type[32];
 N priority[32];
 C host[32][65];
 H ip[32];
 H ttl[32];
 C name[32][65];
 H data[32][8];
 B etc[32][257];
 H ms;
 }
 _dnsstatus;


 structure
 {
 B hlen:4;
 B version:4;
 B type;
 W tot_len;
 W packet_id;
 W frag_offset:13;
 W frag_flags:3;
 B ttl;
 B protocol;
 W hdr_crc;
 H src_ip;
 H dst_ip;
 }
 _sniffheaderip;


 structure
 {
 W src_port;
 W dst_port;
 W length;
 W crc;
 }
 _sniffheaderudp;


 structure
 {
 W src_port;
 W dst_port;
 H seq_number;
 H ack_number;
 W flag_ens:1;
 W rsvd:3;
 W data_offset:4;
 W flag_fin:1;
 W flag_syn:1;
 W flag_rst:1;
 W flag_psh:1;
 W flag_ack:1;
 W flag_urg:1;
 W flag_ecn:1;
 W flag_cwr:1;
 W window;
 W crc;
 W urg_pointer;
 }
 _sniffheadertcp;


 structure
 {
 Q time_stamp;
 H total_length;
 H header_ip_length;
 H header_udp_length;
 H header_tcp_length;
 H data_length;
 _sniffheaderip header_ip;
 _sniffheaderudp header_udp;
 _sniffheadertcp header_tcp;
 H tcp_stream_id;
 Q tcp_stream_offset;
 Q tcp_stream_bytes;
 B data[65536];
 }
 _sniffpkt;



 structure
 {
 H local_ip;
 H rcve_pkts_qued;
 H total_pkts_received;
 H total_bytes_received;
 H rcve_pkt_rate;
 H rcve_byte_rate;
 H ms;
 H inactivity;
 }
 _sniffstatus;



 structure
 {
 H local_ip;
 H remote_ip;
 B type;
 B code;
 W id;
 W seq;
 W data_bytes;
 }
 _icmppkt;



 structure
 {
 H rcve_pkts_qued;
 H xmit_pkts_qued;
 H total_pkts_sent;
 H total_pkts_received;
 H total_bytes_sent;
 H total_bytes_received;
 H xmit_pkt_rate;
 H rcve_pkt_rate;
 H rcve_byte_rate;
 H xmit_byte_rate;
 H ms;
 H inactivity;
 }
 _icmpstatus;




 #define aa_NET_STUN_BLOCKED           1
 #define aa_NET_STUN_FULLCONE          2
 #define aa_NET_STUN_SYMETRICNAT       3
 #define aa_NET_STUN_RESTRICTEDPORT    4
 #define aa_NET_STUN_RESTRICTEDCONE    5
 #define aa_NET_STUN_SYMETRICFIREWALL  6
 #define aa_NET_STUN_OPEN              7



 structure
 {
 _netadr address;
 W data_bytes;
 B data[65536];
 }
 _udppkt;



 structure
 {
 _netadr local_adr;
 _netadr bcast_adr;
 B is_direct;
 B is_checksum_set;
 B is_flowcontrol_set;
 H rcve_pkts_qued;
 H xmit_pkts_qued;
 Q rcve_pkts_total;
 Q xmit_pkts_total;
 Q rcve_bytes_total;
 Q xmit_bytes_total;
 H ms;
 H inactivity;
 H rcve_pkt_rate;
 H xmit_pkt_rate;
 H rcve_byte_rate;
 H xmit_byte_rate;
 H rcve_buffer_length;
 H xmit_buffer_length;
 D xmit_speed;
 H xmit_que_misses;
 H xmit_direct_misses;
 H user_bytes;
 BP user_data;
 H extra_bytes;
 BP extra_data;
 }
 _udpstatus;



 structure
 {
 B flags;
 B stratum;
 B poll;
 B precision;
 H root_delay;
 H root_dispersion;
 B referenceID[4];
 H ref_ts_sec;
 H ref_ts_frac;
 H origin_ts_sec;
 H origin_ts_frac;
 H recv_ts_sec;
 H recv_ts_frac;
 H trans_ts_sec;
 H trans_ts_frac;
 }
 _ntppkt;


 structure
 {
 B is_inprogress;
 B is_complete;
 B is_failed;
 H ms;
 _netadr local_adr;
 _netadr server_adr;
 _netadr other_adr;
 _netadr mapped_adr;
 _netadr remapped_adr;
 B type;
 }
 _stunclientstatus;



 structure
 {
 H magic;
 H stage;
 _netadr adr;
 _user user;
 }
 _socks;




 structure
 {
 _netadr local_adr;
 B local_dot[30];
 H calls_waiting;
 H calls_answered;
 H calls_inuse;
 H calls_total;
 H extra_bytes;
 }
 _tcpportstatus;



 structure
 {
 W is_inprogress:1;
 W is_incoming:1;
 W is_connected:1;
 W is_failed:1;
 W is_notfound:1;
 W is_close_protected:1;
 W is_closed:1;
 W is_closed_by_local:1;
 W is_closed_by_remote:1;
 W is_resolving:1;
 W is_rcve_paused:1;
 W is_xmit_paused:1;
 W is_nodelay:1;
 W is_rsvd:3;
 B host[65];
 _netadr src_adr;
 B src_dot[25];
 _netadr local_adr;
 B local_dot[25];
 _netadr remote_adr;
 B remote_dot[25];
 SOCKET sock;
 H protocol;
 H rcve_bytes;
 H xmit_bytes;
 Q rcve_bytes_total;
 Q xmit_bytes_total;
 H rcve_rate;
 H xmit_rate;
 H max_xmit_rate;
 H max_rcve_rate;
 H rcve_buffer_length;
 H xmit_buffer_length;
 H rcve_slicer_length;
 H xmit_slicer_length;
 H adoption_handle;
 H session;
 H index;
 H number;
 H ms;
 H local_closed_ms;
 H remote_closed_ms;
 H closed_ms;
 H rcve_inactivity;
 H xmit_inactivity;
 H stage;
 H user_bytes;
 BP user_data;
 H extra_bytes;
 BP extra_data;
 B hancock[33];
 V(*proc)(H);
 }
 _tcpcallstatus;






 #define aa_HTTPMETHOD_GET             1
 #define aa_HTTPMETHOD_HEAD            2
 #define aa_HTTPMETHOD_POST            3
 #define aa_HTTPMETHOD_PUT             4
 #define aa_HTTPMETHOD_TRACE           5
 #define aa_HTTPMETHOD_DELETE          6
 #define aa_HTTPMETHOD_OPTIONS         7
 #define aa_HTTPMETHOD_CONNECT         8

 #define aa_HTTPCONDTYPE_IFMODSINCE    1
 #define aa_HTTPCONDTYPE_IFRANGE       2

 #define aa_HTTPFIELD_BLANK            1
 #define aa_HTTPFIELD_VARY             2
 #define aa_HTTPFIELD_ACCEPTRANGES     3
 #define aa_HTTPFIELD_LOCATION         4
 #define aa_HTTPFIELD_P3P              5
 #define aa_HTTPFIELD_XASPNETVER       6
 #define aa_HTTPFIELD_XPOWEREDBY       7
 #define aa_HTTPFIELD_EXPIRES          8
 #define aa_HTTPFIELD_PRAGMA           9
 #define aa_HTTPFIELD_SETCOOKIE        10
 #define aa_HTTPFIELD_ETAG             11
 #define aa_HTTPFIELD_XCACHE           12
 #define aa_HTTPFIELD_CACHECONTROL     13
 #define aa_HTTPFIELD_CONTENTTYPE      14
 #define aa_HTTPFIELD_LASTMODIFIED     15
 #define aa_HTTPFIELD_SERVER           16
 #define aa_HTTPFIELD_DATE             17
 #define aa_HTTPFIELD_CONTENTLENGTH    18
 #define aa_HTTPFIELD_CONTENTRANGE     19
 #define aa_HTTPFIELD_CONNECTION       20
 #define aa_HTTPFIELD_KEEPALIVE        21
 #define aa_HTTPFIELD_HOST             22
 #define aa_HTTPFIELD_COOKIE           23
 #define aa_HTTPFIELD_COOKIE2          24
 #define aa_HTTPFIELD_USERAGENT        25
 #define aa_HTTPFIELD_ACCEPTENCODING   26
 #define aa_HTTPFIELD_ACCEPTLANGUAGE   27
 #define aa_HTTPFIELD_ACCEPTCHARSET    28
 #define aa_HTTPFIELD_TRANSFERENCODING 29
 #define aa_HTTPFIELD_REFERER          30
 #define aa_HTTPFIELD_ACCEPT           31
 #define aa_HTTPFIELD_IFMODIFIEDSINCE  32
 #define aa_HTTPFIELD_TE               33
 #define aa_HTTPFIELD_VIA              34
 #define aa_HTTPFIELD_STATUS           35
 #define aa_HTTPFIELD_XFORWARDEDFOR    36
 #define aa_HTTPFIELD_AGE              37
 #define aa_HTTPFIELD_XPAD             38
 #define aa_HTTPFIELD_UAOS             39
 #define aa_HTTPFIELD_UACPU            40
 #define aa_HTTPFIELD_UAPIXELS         41
 #define aa_HTTPFIELD_UACOLOR          42
 #define aa_HTTPFIELD_FROM             43
 #define aa_HTTPFIELD_XCACHELOOKUP     44
 #define aa_HTTPFIELD_AUTHORIZATION    45
 #define aa_HTTPFIELD_CONXFERENCODING  46
 #define aa_HTTPFIELD_ORIGIN           47
 #define aa_HTTPFIELD_ACCESSCTRLRQMETH 48
 #define aa_HTTPFIELD_ACCESSCTRLALWORG 49
 #define aa_HTTPFIELD_CONTENTENCODING  50
 #define aa_HTTPFIELD_LAST             51
 #define aa_HTTPFIELD_UNIMPLEMENTED    F32

 #define aa_HTTPFORM_URLENCODED        1
 #define aa_HTTPFORM_MULTIPART         2
 #define aa_HTTPFORM_PLAIN             3
 #define aa_HTTPFORM_MULTIPARTMIXED    4


 structure
 {
 B is_failed;
 B is_success;
 H code;
 B version[2];
 }
 _httpresult;


 structure
 {
 B is_failed;
 B is_success;
 B method;
 B version[2];
 H url_chars;
 B url[_1K];
 }
 _httprequest;



 structure
 {
 B is_failed;
 B is_success;
 H field_code;
 B field[65];
 _systime time;
 H value[3];
 H bytes;
 H data_bytes;
 B data[_2K];
 }
 _httpheader;



 structure
 {
 B is_failed;
 B is_success;
 B is_fold;
 H code;
 B text[2049];
 }
 _smtpresult;



 E{
 FTP_DATACONN=150,
 FTP_NOOPOK=200,FTP_TYPEOK=200,FTP_PORTOK=200,
 FTP_UMASKOK=200,FTP_CHMODOK=200,FTP_CDUPOK=200,
 FTP_SIZEOK=213,FTP_MDTMOK=213,FTP_SYSTOK=215,FTP_GREET=220,
 FTP_GOODBYE=221,FTP_ABOR_NOCONN=225,FTP_TRANSFEROK=226,
 FTP_ABOROK=226,FTP_PASVOK=227,FTP_LOGINOK=230,
 FTP_CWDOK=250,FTP_RMDIROK=250,FTP_DELEOK=250,
 FTP_RENAMEOK=250,FTP_PWDOK=257,FTP_MKDIROK=257,
 FTP_GIVEPWORD=331,FTP_RESTOK=350,FTP_RNFROK=350,
 FTP_IDLE_TIMEOUT=421,FTP_DATA_TIMEOUT=421,FTP_TOO_MANY_USERS=421,
 FTP_IP_LIMIT=421,FTP_IP_DENY=421,FTP_BADSENDCONN=425,
 FTP_BADSENDNET=426,FTP_BADSENDFILE=451,
 FTP_BADCMD=500,FTP_BADHELP=502,FTP_NEEDUSER=503,FTP_NEEDRNFR=503,
 FTP_LOGINERR=530,FTP_FILEFAIL=550,FTP_EXISTS=550,
 FTP_NOTFOUND=550,FTP_NOPERM=550,FTP_UPLOADFAIL=553
 };



 structure
 {
 B is_failed;
 B is_success;
 B is_fold;
 H code;
 B text[2049];
 _netadr pasv_adr;
 }
 _ftpresult;


 structure
 {
 B type;
 B is_file;
 B is_dir;
 B is_parent_dir;
 B is_current_dir;
 B name[129];
 Q bytes;
 _systime modified;
 B modified_string[33];
 B permission[11];
 }
 _ftpmlsd;


 structure
 {
 B address[129];
 B nick[65];
 B user[65];
 B host[65];
 }
 _ircadrparts;


 structure
 {
 B is_failed;
 B is_success;
 B is_prefix;
 B is_command;
 B is_target;
 B is_params;
 B is_trailer;
 B prefix[_1K];
 B prefix_is_adr;
 _ircadrparts prefix_adr;
 B command[_1K];
 H command_code;
 B command_is_num;
 B target[_1K];
 B params[_1K];
 H param_count;
 H param_offlen[16][2];
 B param_is_adr[16];
 B param[16][513];
 _ircadrparts param_adr[16];
 B trailer[_1K];
 B trailer_is_adr;
 _ircadrparts trailer_adr;
 }
 _ircmsg;


 #define aa_REDISTYPE_Status           1
 #define aa_REDISTYPE_Error            2
 #define aa_REDISTYPE_Integer          3
 #define aa_REDISTYPE_Bulk             4
 #define aa_REDISTYPE_Multi            5

 #define aa_REDISARG_OK                1
 #define aa_REDISARG_QUEUED            2


 structure
 {
 H state;
 _netadr local_adr;
 _netadr remote_adr;
 }
 _netportlistentry;


 structure
 {
 H total_entries;
 H udp_entries;
 H tcp_entries;
 _netportlistentry*tcp_entry;
 _netportlistentry*udp_entry;
 }
 _netportlist;




 structure
 {
 H magic;
 H timeout;
 H min_timeout;
 H max_timeout;
 }
 _netrtt;



 structure
 {
 H handle;
 _udpstatus status;
 }
 _udpunit;



 structure
 {
 H handle;
 _tcpcallstatus status;
 }
 _tcpcallunit;



 structure
 {
 H handle;
 _tcpportstatus status;
 }
 _tcpportunit;





 structure
 {
 H handle;
 _dnsstatus status;
 }
 _dnsunit;



 structure
 {
 H handle;
 _cgiclientstatus status;
 }
 _cgiclientunit;


 structure
 {
 H handle;
 _sniffstatus status;
 }
 _sniffunit;



 structure
 {
 _tcpportunit port;
 H max_calls;
 H extra_bytes;
 B is_calls_allowed;
 }
 _serverstatus;


 structure
 {
 H handle;
 _serverstatus status;
 }
 _serverunit;



 E{
 WOCK_STAGE_HANDSHAKE=50,
 WOCK_STAGE_OPEN=100,
 WOCK_STAGE_CLOSED=200
 };



 E{
 WOCK_OPCODE_CONTINUE=0x0,
 WOCK_OPCODE_TEXT=0x1,
 WOCK_OPCODE_BINARY=0x2,
 WOCK_OPCODE_CLOSE=0x8,
 WOCK_OPCODE_PING=0x9,
 WOCK_OPCODE_PONG=0xa,
 };



 structure
 {
 H stage;
 B is_inbound;
 H call_handle;
 _tcpcallstatus call_status;
 B url[_1K];
 _urlparts up;
 B close_frame_received;
 B close_frame_sent;
 H rcve_pkts;
 H rcve_pkts_total;
 H xmit_pkts;
 H xmit_pkts_total;
 H ms;
 }
 _wockstatus;



 structure
 {
 H handle;
 _wockstatus status;
 }
 _wockunit;


 structure
 {
 H magic;
 H pid;
 B is_over_tcpcall;
 _tcpcallunit call;
 SOCKET sock;
 WSAPROTOCOL_INFO prot_info;
 }
 _tcpcallterms;



 B aaNetStatus                         (_netstatus*netstatus);
 B aaNetLocalIpGet                     (_localip*localip,B getmac,B getbcast);
 B aaNetInfoGet                        (_netinfo*netinfo);
 B aaNetInfoToString                   (_netinfo*netinfo,H maxchars,VP str);
 B aaNetOnlineStateGet                 (BP state);
 B aaNetMacGet                         (VP mac,H ip,VP txt);
 B aaNetIpPublicNext                   (HP ip,HP iterator);
 B aaNetIpFromString                   (VP dot,HP ip);
 B aaNetIpToString                     (H ip,VP dot);
 B aaNetIpIsValid                      (VP dot);
 B aaNetIpIsLoopBack                   (H bin);
 B aaNetIpIsInternal                   (H bin);
 B aaNetIpIsReserved                   (H bin);
 B aaNetIpIsPublic                     (H bin);
 B aaNetIpTypeGet                      (H bin,BP type);
 B aaNetIpToDword                      (H ip,HP val);
 B aaNetIpClassGet                     (H ip,BP cls);
 B aaNetEmailIsValid                   (VP email);
 B aaNetHostToDomain                   (VP host,VP domain);
 B aaNetRfcCrcGet                      (VP mem,H bytes,WP crc);
 B aaNetBrowserWritef                  (HP hinst,VP fmt,...);
 B aaNetMimeToExtension                (VP mime,VP extension);
 B aaNetExtensionToMime                (VP extension,VP mime);
 B aaNetHostsFileEntryGet              (H index,VP domain,VP dotted,HP ip,BP iscmnt);
 B aaNetHostsFileEntrySet              (H index,VP domain,VP dotted,H ip,B iscmnt);
 B aaNetIsPortAvailable                (H ip,W port,B isudp);
 B aaNetRandomUser                     (_randomuser*randomuser);

 B aaNetCgiEnvGet                      (_cgienv*cgienv);

 B aaNetCgiClientCreate                (HP handle,B hidden,VP env,VP dir,VP processfilename,VP command);
 B aaNetCgiClientDestroy               (H handle);
 B aaNetCgiClientStatus                (H handle,_cgiclientstatus*cgiclientstatus);
 B aaNetCgiClientWrite                 (H handle,H bytes,VP data);
 B aaNetCgiClientWritef                (H handle,VP fmt,...);
 B aaNetCgiClientRead                  (H handle,H bytes,VP data);
 B aaNetCgiClientPeek                  (H handle,H offset,H bytes,VP data);
 B aaNetCgiClientDiscard               (H handle,H bytes);
 B aaNetCgiClientStringLen             (H handle,HP chars,BP isdossy,BP stringmode);
 B aaNetCgiClientStringRead            (H handle,HP chars,BP isdossy,BP stringmode,H maxchars,VP buf);
 B aaNetCgiClientStringPeek            (H handle,HP chars,BP isdossy,BP stringmode,H maxchars,VP buf);
 B aaNetCgiClientStringReadQuick       (H handle,H promptms,HP chars,BP isprompt,BP stringmode,H maxchars,VP buf);
 B aaNetCgiClientInactivityReset       (H handle,B rflag,B xflag);
 B aaNetCgiClientChildrenTerminate     (H handle);

 B aaNetUrlSimplify                    (VP url,H chars,VP ourl);
 B aaNetUrlDecode                      (VP url,H chars,VP durl);
 B aaNetUrlPartsGet                    (_urlparts*urlparts,VP url,B spaceplus,B decode);
 B aaNetUrlPartsToString               (_urlparts*urlparts,VP buf);
 B aaNetUrlToFilename                  (VP rootpath,VP relative,VP filename);
 B aaNetSetCookieDecode                (VP str,H chars,_cookie*cookie);

 B aaNetAdrSet                         (_netadr*netadr,H ip,W port);
 B aaNetAdrSetFromString               (_netadr*netadr,VP ip,W port);
 B aaNetAdrCopy                        (_netadr*netadr,_netadr*snetadr);
 B aaNetAdrToString                    (_netadr*netadr,VP string);
 B aaNetAdrFromString                  (_netadr*netadr,VP string);
 B aaNetAdrEqualsAdr                   (_netadr*netadr,_netadr*netadr2);
 B aaNetAdrToHashGet                   (_netadr*netadr,BP hash);
 B aaNetAdrFromFtpAdr                  (_netadr*netadr,VP string);

 B aaNetSubnetFromIp                   (_netsubnet*netsubnet,H ip,H mask);


 B aaNetDnsCreate                      (HP handle,VP address,B mode,B bypass);
 B aaNetDnsDestroy                     (H handle);
 B aaNetDnsStatus                      (H handle,_dnsstatus*dnsstatus);

 B aaNetSniffCreate                    (HP handle,H ip);
 B aaNetSniffDestroy                   (H handle);
 B aaNetSniffStatus                    (H handle,_sniffstatus*sniffstatus);
 B aaNetSniffPktRead                   (H handle,_sniffpkt*sniffpkt);
 B aaNetSniffPktPeek                   (H handle,H index,_sniffpkt*sniffpkt,B dataflag);
 B aaNetSniffPktDiscard                (H handle);
 B aaNetSniffPktReturn                 (H handle);


 B aaNetIcmpPktSet                     (_icmppkt*icmppkt,H remoteip,B type,B code,W id,W seq,W databytes);
 B aaNetIcmpPktCopy                    (_icmppkt*icmppkt,_icmppkt*sicmppkt);
 B aaNetIcmpCreate                     (HP handle);
 B aaNetIcmpDestroy                    (H handle);
 B aaNetIcmpStatus                     (H handle,_icmpstatus*icmpstatus);
 B aaNetIcmpPktWrite                   (H handle,_icmppkt*icmppkt,VP data);
 B aaNetIcmpPktRead                    (H handle,_icmppkt*icmppkt,H maxbytes,VP data);
 B aaNetIcmpPktPeek                    (H handle,_icmppkt*icmppkt,H maxbytes,VP data);
 B aaNetIcmpPktDiscard                 (H handle);

 B aaNetUdpOpen                        (HP handle,H ip,W port);
 B aaNetUdpCreate                      (HP handle,H ip,W port);
 B aaNetUdpCreateAny                   (HP handle,H ip,W portstart,W portend);
 B aaNetUdpDestroy                     (H handle);
 B aaNetUdpFlowControlSet              (H handle,B state);
 B aaNetUdpChecksumSet                 (H handle,B state);
 B aaNetUdpStatus                      (H handle,_udpstatus*udpstatus);
 B aaNetUdpBufferLengthSet             (H handle,H rbytes,H xbytes);
 B aaNetUdpXmitSpeedSet                (H handle,D micro);
 B aaNetUdpExtraDataSet                (H handle,H bytes);
 B aaNetUdpPktDirectSet                (H handle,B state);
 B aaNetUdpPktWrite                    (H handle,_udppkt*udppkt);
 B aaNetUdpPktRead                     (H handle,_udppkt*udppkt);
 B aaNetUdpPktPeek                     (H handle,_udppkt*udppkt,H pktoff,H maxbytes);
 B aaNetUdpPktDiscard                  (H handle);
 B aaNetUdpPktReturn                   (H handle);

 B aaNetUdpPktAllocate                 (_udppkt**udppkt);
 B aaNetUdpPktRelease                  (_udppkt*udppkt);
 B aaNetUdpPktSet                      (_udppkt*udppkt,H remoteip,W remoteport,W databytes);
 B aaNetUdpPktCopy                     (_udppkt*udppkt,_udppkt*sudppkt,B copydata);
 B aaNetUdpPktAppend                   (_udppkt*udppkt,H bytes,VP data);
 B aaNetUdpPktByteAppend               (_udppkt*udppkt,B val);
 B aaNetUdpPktWordAppend               (_udppkt*udppkt,W val);
 B aaNetUdpPktDwordAppend              (_udppkt*udppkt,H val);
 B aaNetUdpPktQuadAppend               (_udppkt*udppkt,Q val);
 B aaNetUdpPktTrim                     (_udppkt*udppkt,H bytes);

 B aaNetStunClientCreate               (HP handle,H udphandle,H serverip,W serverport);
 B aaNetStunClientDestroy              (H handle);
 B aaNetStunClientStatus               (H handle,_stunclientstatus*stunclientstatus);

 B aaNetTcpPortCreate                  (HP handle,H ip,W port,H extrabytes);
 B aaNetTcpPortCreateAny               (HP handle,H ip,W portstart,W portend,H extrabytes);
 B aaNetTcpPortDestroy                 (H handle);
 B aaNetTcpPortStatus                  (H handle,_tcpportstatus*tcpportstatus);
 B aaNetTcpPortCallNext                (H handle,HP callhandle,_tcpcallstatus*tcpcallstatus,HP iterator);

 B aaNetTcpCallCreate                  (HP handle,H sip,W sport,VP host,H ip,W port);
 B aaNetTcpCallDestroy                 (H handle);
 B aaNetTcpCallDestroyProcSet          (H handle,V(*proc)(H));
 B aaNetTcpCallCloseProtect            (H handle,B state);
 B aaNetTcpCallClose                   (H handle);
 B aaNetTcpCallVitalityGet             (H handle,HP state);
 B aaNetTcpCallStatus                  (H handle,_tcpcallstatus*tcpcallstatus);
 B aaNetTcpCallOfferWrite              (H handle,H pid,H tcpcallhandle,_tcpcallterms*tcpcallterms);
 B aaNetTcpCallOfferRead               (H handle,_tcpcallterms*tcpcallterms);
 B aaNetTcpCallOfferAccept             (HP handle,_tcpcallterms*tcpcallterms);
 B aaNetTcpCallNext                    (HP handle,_tcpcallstatus*tcpcallstatus,HP iterator);
 B aaNetTcpCallByIndex                 (HP handle,H index,_tcpcallstatus*tcpcallstatus);
 B aaNetTcpCallAdopt                   (H handle,H adopteehandle);
 B aaNetTcpCallAnswer                  (H handle);
 B aaNetTcpCallWrite                   (H handle,H bytes,VP data);
 B aaNetTcpCallWritef                  (H handle,VP fmt,...);
 B aaNetTcpCallWriteByte               (H handle,B val);
 B aaNetTcpCallWriteWord               (H handle,W val);
 B aaNetTcpCallWriteDword              (H handle,H val);
 B aaNetTcpCallWriteQuad               (H handle,Q val);
 B aaNetTcpCallRead                    (H handle,H bytes,VP data);
 B aaNetTcpCallReadByte                (H handle,BP val);
 B aaNetTcpCallReadWord                (H handle,WP val);
 B aaNetTcpCallReadDword               (H handle,HP val);
 B aaNetTcpCallReadQuad                (H handle,QP val);
 B aaNetTcpCallPeek                    (H handle,H offset,H bytes,VP data);
 B aaNetTcpCallDiscard                 (H handle,H bytes);
 B aaNetTcpCallFindByte                (H handle,H offset,H bytes,HP pos,B ch,B logic,H number);
 B aaNetTcpCallReturn                  (H handle,H bytes);
 B aaNetTcpCallPush                    (H handle,H bytes,VP data);
 B aaNetTcpCallRelay                   (H handle,H bytes,H relayhandle,B how);
 B aaNetTcpCallMirror                  (H handle,_tcpcallstatus*callstatus,H bytes,H han2,_tcpcallstatus*callstatus2,VP buf);
 B aaNetTcpCallStringLen               (H handle,HP chars,BP stringmode);
 B aaNetTcpCallStringRead              (H handle,HP chars,BP stringmode,H maxchars,VP buf);
 B aaNetTcpCallStringPeek              (H handle,HP chars,BP stringmode,H maxchars,VP buf);
 B aaNetTcpCallStringLook              (H handle,H fromoff,H index,HP count,HP offset,HP chars,BP stringmode,H maxchars,VP buf);
 B aaNetTcpCallStringDiscard           (H handle);
 B aaNetTcpCallPause                   (H handle,B rstate,B xstate);
 B aaNetTcpCallExtraDataSet            (H handle,H bytes);
 B aaNetTcpCallExtraDataGet            (H handle,HP bytes,PP ptr);
 B aaNetTcpCallBufferLengthSet         (H handle,H rbytes,H xbytes);
 B aaNetTcpCallSlicerLengthSet         (H handle,H rbytes,H xbytes);
 B aaNetTcpCallNoDelaySet              (H handle,B state);
 B aaNetTcpCallProtocolSet             (H handle,H protocol);
 B aaNetTcpCallStageSet                (H handle,H stage);
 B aaNetTcpCallMaxRateSet              (H handle,H rrate,H xrate);
 B aaNetTcpCallInactivityReset         (H handle,B rflag,B xflag);

 B aaNetSocksInit                      (_socks*socks,H ip,W port,VP user,VP pass);
 B aaNetSocksHelloWrite                (H tcpcallhandle);
 B aaNetSocksConnectIp4Write           (H tcpcallhandle,H ip,W port);

 B aaNetHttpHeaderPrepare              (VP str,N result,B close,N cache,B chunked,G conlen,VP contype);
 B aaNetHttpHeaderCookiePrepare        (VP str,B servermode,VP domain,VP path,G expires,VP name,VP fmt,...);
 B aaNetHttpHeaderFieldCodeGet         (VP str,H chars,NP which,HP len);

 B aaNetHttpResultReadFromString       (_httpresult*httpresult,H bytes,VP str);
 B aaNetHttpHeaderReadFromString       (_httpheader*httpheader,H bytes,VP str);
 B aaNetHttpRequestReadFromString      (_httprequest*httprequest,H bytes,VP str);

 B aaNetHttpRequestWrite               (H tcpcallhandle,VP host,VP path,H start,H end,B condtype,_systime*condtime,B head,N cache,B close,VP fmt,...);
 B aaNetHttpResultWrite                (H tcpcallhandle,H code,VP fmt,...);
 B aaNetHttpResultRead                 (H tcpcallhandle,_httpresult*httpresult);
 B aaNetHttpHeaderRead                 (H tcpcallhandle,_httpheader*httpheader);
 B aaNetHttpRequestRead                (H tcpcallhandle,_httprequest*httprequest);
 B aaNetHttpBasicAuthorizationWrite    (H tcpcallhandle,VP username,VP password);
 B aaNetHttpCookieSet                  (H tcpcallhandle,VP domain,VP path,G expires,VP name,VP fmt,...);
 B aaNetHttpChunkSizePeek              (H tcpcallhandle,HP bytes);
 B aaNetHttpChunkSizeRead              (H tcpcallhandle,HP bytes);
 B aaNetHttpChunkSizeWrite             (H tcpcallhandle,H bytes);
 B aaNetHttpChunkWritef                (H tcpcallhandle,VP fmt,...);
 B aaNetHttpChunkWrite                 (H tcpcallhandle,H bytes,VP data);

 B aaNetSmtpResultRead                 (H tcpcallhandle,_smtpresult*smtpresult);
 B aaNetFtpResultRead                  (H tcpcallhandle,_ftpresult*ftpresult);
 B aaNetFtpMlsdRead                    (H tcpcallhandle,_ftpmlsd*ftpmlsd);

 B aaNetRedisPacketRead                (H tcpcallhandle,BP type,GP arg,HP chars,H maxchars,VP buf);
 B aaNetRedisPacketWritef              (H tcpcallhandle,VP fmt,...);
 B aaNetRedisRespBegin                 (H tcpcallhandle,H elcount);
 B aaNetRedisRespBulkAppend            (H tcpcallhandle,H bytes,VP data);
 B aaNetRedisRespBulkAppendf           (H tcpcallhandle,VP fmt,...);
 B aaNetRedisRespIntegerAppend         (H tcpcallhandle,G val);

 B aaNetSsDbSizeRead                   (H tcpcallhandle,HP size);
 B aaNetSsDbPacketWrite                (H tcpcallhandle,VP fmt,...);

 B aaNetIrcAdrToParts                  (VP address,_ircadrparts*ircadrparts);
 B aaNetIrcMsgRead                     (H tcpcallhandle,_ircmsg*ircmsg,VP raw);
 B aaNetIrcMsgToString                 (_ircmsg*ircmsg,VP raw,VP str);

 B aaNetPortListRead                   (_netportlist*netportlist);
 B aaNetPortListStop                   (V);

 B aaNetRttInit                        (_netrtt*rtt,H mintimeout,H maxtimeout,H initialtimeout);
 B aaNetRttUpdate                      (_netrtt*rtt,H ms,B lost);

 B aaNetServerCreate                   (HP handle,H ip,W port,H maxcalls,H extra);
 B aaNetServerDestroy                  (H handle);
 B aaNetServerStatus                   (H handle,_serverstatus*serverstatus,_tcpcallunit*tcpcallunit);
 B aaNetServerCallsAllow               (H handle,B state);


 B aaNetWockCreate                     (HP handle,H tcpcallhandle,B inbound,VP fmt,...);
 B aaNetWockDestroy                    (H handle);
 B aaNetWockStatus                     (H handle,_wockstatus*wockstatus);
 B aaNetWockClose                      (H handle);
 B aaNetWockPktWrite                   (H handle,B opc,B fin,H bytes,VP data);
 B aaNetWockPktWritef                  (H handle,VP fmt,...);
 B aaNetWockPktPeek                    (H handle,HP bytes,H maxbytes,BP opc,BP fin,VP data);
 B aaNetWockPktRead                    (H handle,HP bytes,H maxbytes,BP opc,BP fin,VP data);
 B aaNetWockPktDiscard                 (H handle);


/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 B is_ready;
 H call_handle;
 Z chunk_size;
 Z chunk_done;
 _memoryunit chunk;
 }
 _chunkreader;


 B aaNetChunkReaderNew                 (_chunkreader*chunkreader,H tcpcallhandle);
 B aaNetChunkReaderDelete              (_chunkreader*chunkreader);
 B aaNetChunkReaderYield               (_chunkreader*chunkreader);
 B aaNetChunkReaderDiscard             (_chunkreader*chunkreader);


/*-----------------------------------------------------------------------*/

 structure
 {
 Q seq;
 B type;
 G arg;
 H chars;
 _memoryunit mu;
 }
 _redcallpkt;


 structure
 {
 H magic;
 B is_ready;
 H stage;
 B host[65];
 W port;
 B auth[129];
 _tcpcallunit tcpcall;
 _redcallpkt rpkt;
 Q rpkt_seq;
 Q rpkt_multi_left;
 Q rpkt_seq_prev;
 Q xpkt_seq;
 VP proc;
 }
 _redcall;



 B aaRedcallNew                        (_redcall*redcall,VP host,W port,VP auth,B(*proc)(_redcall*,Q,B,B,_redcallpkt*));
 B aaRedcallDelete                     (_redcall*redcall);
 B aaRedcallYield                      (_redcall*redcall,QP seq,BP isnew,BP isend);
 B aaRedcallPktWritef                  (_redcall*redcall,QP seq,VP fmt,...);
 B aaRedcallPktPeek                    (_redcall*redcall,QP seq,BP isnew,BP isend);
 B aaRedcallPktDiscard                 (_redcall*redcall);
 B aaRedcallPktBug                     (_redcall*redcall);
 B aaRedcallProc                       (_redcall*redcall,Q seq,B isnew,B isend,_redcallpkt*redcallpkt);

/*-----------------------------------------------------------------------*/


 structure
 {
 Q seq;
 H line_index;
 H line_count;
 N code;
 H bytes;
 H is_number;
 G number;
 B data[];
 }
 _ssdblistentry;


 structure
 {
 H magic;
 B is_ready;
 H stage;
 B host[65];
 W port;
 B auth[129];
 _tcpcallunit call;
 H rcve_stage;
 H rcve_bytes;
 H rcve_lines;
 _memoryunit rcve_mem;
 Q rcve_seq;
 Q xmit_seq;
 Q rcve_msges_waiting;
 Q rcve_lines_waiting;
 Q xmit_msges_waiting;
 _queunit rcve_que;
 _queunit xmit_que;
 _list rcve_list;
 }
 _ssdbclient;


 B aaSsDbClientNew                     (_ssdbclient*ssdbclient,VP host,W port,VP auth);
 B aaSsDbClientDelete                  (_ssdbclient*ssdbclient);
 B aaSsDbClientYield                   (_ssdbclient*ssdbclient);
 B aaSsDbClientWrite                   (_ssdbclient*ssdbclient,QP seq,VP fmt,...);
 B aaSsDbClientRead                    (_ssdbclient*ssdbclient,QP seq,HP bytes,HP lineidx,HP linecnt,NP code,H maxbytes,VP buf);
 B aaSsDbClientPeek                    (_ssdbclient*ssdbclient,QP seq,HP bytes,HP lineidx,HP linecnt,NP code,H maxbytes,VP buf);
 B aaSsDbClientDiscard                 (_ssdbclient*ssdbclient);
 B aaSsDbClientListReceive             (_ssdbclient*ssdbclient,QP seq);
 B aaSsDbClientListEntryGet            (_ssdbclient*ssdbclient,H index,_ssdblistentry*ssdblistentry);

/*-----------------------------------------------------------------------*/

 structure
 {
 H pid;
 B exe_file[257];
 B is_strict_nodes;
 H exclude_nodes_count;
 B exclude_nodes[32][17];
 H exclude_exit_nodes_count;
 B exclude_exit_nodes[32][17];
 B is_daemon;
 B is_cookie_authentication;
 B hashed_control_password[65];
 B pid_path[257];
 B pid_file[65];
 B data_path[257];
 W c_port;
 W s_port;
 H new_circuit_period;
 H max_circuit_dirtiness;
 }
 _torprocessentry;


 B aaTorProcessSnapshot                (_list*list);
 B aaTorProcessEntryGet                (_list*list,H index,_torprocessentry**tpep);
 B aaTorProcessKill                    (_list*list,H index);
 B aaTorProcessLaunch                  (W cport,W sport,H maxage,VP exefile,...);


/*-----------------------------------------------------------------------*/

 #define MYSQL_TYPE_DECIMAL            0x00
 #define MYSQL_TYPE_TINY               0x01
 #define MYSQL_TYPE_SHORT              0x02
 #define MYSQL_TYPE_LONG               0x03
 #define MYSQL_TYPE_FLOAT              0x04
 #define MYSQL_TYPE_DOUBLE             0x05
 #define MYSQL_TYPE_NULL               0x06
 #define MYSQL_TYPE_TIMESTAMP          0x07
 #define MYSQL_TYPE_LONGLONG           0x08
 #define MYSQL_TYPE_INT24              0x09
 #define MYSQL_TYPE_DATE               0x0a
 #define MYSQL_TYPE_TIME               0x0b
 #define MYSQL_TYPE_DATETIME           0x0c
 #define MYSQL_TYPE_YEAR               0x0d
 #define MYSQL_TYPE_NEWDATE            0x0e
 #define MYSQL_TYPE_VARCHAR            0x0f
 #define MYSQL_TYPE_BIT                0x10
 #define MYSQL_TYPE_NEWDECIMAL         0xf6
 #define MYSQL_TYPE_ENUM               0xf7
 #define MYSQL_TYPE_SET                0xf8
 #define MYSQL_TYPE_TINY_BLOB          0xf9
 #define MYSQL_TYPE_MEDIUM_BLOB        0xfa
 #define MYSQL_TYPE_LONG_BLOB          0xfb
 #define MYSQL_TYPE_BLOB               0xfc
 #define MYSQL_TYPE_VAR_STRING         0xfd
 #define MYSQL_TYPE_STRING             0xfe
 #define MYSQL_TYPE_GEOMETRY           0xff


 E{
 MYSQL_QRY=1,
 MYSQL_FLD=2,
 MYSQL_VAL=3,
 MYSQL_RES=4,
 };


 structure
 {
 Q seq;
 H msg;
 H row,col;
 H code;
 H len;
 B data[];
 }
 _mysqlentry;


 structure
 {
 H magic;
 H stage;
 _list list;
 H col_count;
 H col_size[128];
 B fmt[128][33];
 Q seq;
 H msg;
 H row;
 H iter_i;
 H iter_c;
 H result;
 }
 _mysqlbeautifier;



 structure
 {
 H magic;
 H stage;
 B host[65];
 H ip;
 W port;
 _user user;
 _tcpcallunit call;
 H max_its;
 HCRYPTPROV prov;
 HCRYPTHASH hash;
 H no;
 CP b,d,p;
 B g;
 _queunit query_que;
 _queunit response_que;
 B qry_buf[_4K];
 B cmd[_1K];
 C txt[_1K];
 B typ[_1K];
 Z fields,field,value,row,exit,rc,i;
 G len;
 W charset,flags;
 N length;
 B digits;
 CP cat;
 CP db;
 CP table;
 CP table_;
 CP name;
 CP name_;
 VP proc;
 Q seq_i;
 Q seq_o;
 Q queries_sent;
 Q responses_received;
 B is_ready;
 G io_dif;
 H entry_count;
 _mysqlbeautifier beautifier;
 B user_data[64];
 }
 _mysql;



 B aaMySqlNew                          (_mysql*mysql,_options*options,B(*proc)(_mysql*,Q,H,H,H,H,H,VP));
 B aaMySqlNewEx                        (_mysql*mysql,VP host,W port,VP user,VP pass,B(*proc)(_mysql*,Q,H,H,H,H,H,VP));
 B aaMySqlDelete                       (_mysql*mysql);
 B aaMySqlYield                        (_mysql*mysql);
 B aaMySqlQuery                        (_mysql*mysql,QP seq,VP fmt,...);
 B aaMySqlPeek                         (_mysql*mysql,H indexoff,H maxbytes,VP data);
 B aaMySqlDiscard                      (_mysql*mysql);
 B aaMySqlRead                         (_mysql*mysql,H maxbytes,VP data);
 B aaMySqlQueryExInit                  (_mysql*mysql);
 B aaMySqlQueryExMore                  (_mysql*mysql,VP fmt,...);
 B aaMySqlQueryExExec                  (_mysql*mysql,QP seq);
 B aaMySqlBeautifierReset              (_mysql*mysql);
 B aaMySqlBeautifierRead               (_mysql*mysql,H maxchars,VP str);
 B aaMySqlProc                         (_mysql*mysql,Q seq,H msg,H row,H col,H code,H len,VP data);


/*-----------------------------------------------------------------------*/


 structure
 {
 H magic;
 H stage;
 H next;
 H reset_count;
 B cmd[_1K];
 _cgiclientunit cgi;
 B is_prompt;
 H chars;
 B txt[_4K];
 _list line;
 }
 _shell;


 B aaShellNew                          (_shell*shell,VP fmt,...);
 B aaShellDelete                       (_shell*shell);
 B aaShellYield                        (_shell*shell,H iterations);
 B aaShellLinePointer                  (_shell*shell,H line,HP chars,PP ptr);

/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 B state;
 _rect rect;
 }
 _updatearea;


 B aaUpdateAreaReset                   (_updatearea*updatearea);
 B aaUpdateAreaAdd                     (_updatearea*updatearea,_rect*rect);
 B aaUpdateAreaRemove                  (_updatearea*updatearea,_rect*rect);


/*-----------------------------------------------------------------------*/

 B aaColorHalfToneGet                  (_rgba*rgba,B index);
 B aaColorHalfToneCalculate            (_rgba*rgba,_cord*cord,BP index,_rgba*orgba);

/*-----------------------------------------------------------------------*/

 PUB H font_4x8;
 PUB H font_4x16;
 PUB H font_8x8;
 PUB H font_8x16;
 PUB H font_8x32;
 PUB H font_16x16;
 PUB H font_16x32;


 structure
 {
 B is_mono_width;
 B is_mono_forced;
 B is_italic;
 B is_underline;
 C face_name[33];
 _size size;
 B mono_char;
 N logw,logh;
 _size init_mono_size;
 _size curr_mono_size;
 H charset;
 }
 _fontstatus;

 structure
 {
 H handle;
 _fontstatus status;
 }
 _fontunit;


 B aaFontCreate                        (HP handle,VP facettf,N logw,N logh,B weight,B italic,B underline,B prefmono,B smoothed,H charset);
 B aaFontCreateUsingResource           (HP handle,H resnum,N logw,N logh,B weight,B italic,B underline,B prefmono,B smoothed,H charset);
 B aaFontCreateFixedWidth              (HP handle,N logw,N logh,B weight,B italic,B underline,B smoothed,H charset);
 B aaFontDestroy                       (H handle);
 B aaFontMonoForceSet                  (H handle,B state);
 B aaFontMonoForceSizeSet              (H handle,_size*size);
 B aaFontStatus                        (H handle,_fontstatus*fontstatus);
 B aaFontCharRectGet                   (H handle,_rect*rect,B ch);
 B aaFontStringCharRectsGet            (H handle,H maxrects,_rect*rects,H maxchars,VP fmt,...);;

 B aaFontStringSizeGet                 (H handle,_size*size,H maxchars,VP fmt,...);
 B aaFontStringSizeFit                 (H handle,_size*size,_size*rsize,VP rstr,VP fmt,...);
 B aaFontStringCharRectGet             (H handle,_rect*rect,H pos,H maxchars,VP fmt,...);

 B aaFontFamilyList                    (_data*data);

/*-----------------------------------------------------------------------*/

 #define aa_GRADIENT_Linear            0
 #define aa_GRADIENT_Radial            1
 #define aa_GRADIENT_Square            2
 #define aa_GRADIENT_Cone              3

 #define aa_DIRECTION_N                aa_ALIGN_TOP
 #define aa_DIRECTION_E                aa_ALIGN_LEFT
 #define aa_DIRECTION_S                aa_ALIGN_BOTTOM
 #define aa_DIRECTION_W                aa_ALIGN_RIGHT

 #define aa_DIRECTION_NW               5
 #define aa_DIRECTION_NE               6
 #define aa_DIRECTION_SE               7
 #define aa_DIRECTION_SW               8


 structure
 {
 H mode;
 N nparm0;
 N nparm1;
 N nparm2;
 N nparm3;
 D dparm0;
 D dparm1;
 B etc[28];
 }
 _pixelstyle;



 B aaPixelStyleInit                    (_pixelstyle*pixelstyle);
 B aaPixelStyleSet                     (_pixelstyle*pixelstyle,H setbit,B mode,N np0,N np1,N np2,N np3,D dp0,D dp1,H applyhandle);


/*-----------------------------------------------------------------------*/


 structure
 {
 H id;
 H index;
 H type;
 Z depth;
 _rect rect;
 B is_press;
 B is_over;
 B is_focus;
 B is_paint;
 B user_data[20];
 }
 _surfacespot;


 structure
 {
 H self_handle;
 B is_visual;
 B is_tool;
 B is_shown;
 B is_focus;
 B is_made;
 B is_top;
 B is_parent;
 B is_child;
 B is_hflip;
 B is_vflip;
 B is_minimized;
 B is_maximized;
 C title[65];
 B is_rounded;
 B is_blend;
 B is_clipper;
 B is_systray;
 B is_systray_clicked;
 B is_log_write;
 _cord systray_click_cord;
 B is_systray_right_clicked;
 B is_closed;
 B is_cursor_captured;
 B is_moveable;
 B is_sizeable;
 B is_ignore_wmpaint;
 B alpha;
 B is_mask;
 B is_masknot;
 _rgba mask;
 _rgba mask_not;
 H resize_counter;
 _rect viewport_rect;
 _rect clipper_rect;
 _cord corner[4];
 _rect rect;
 _size initial_size;
 _size size;
 _size min_size;
 _size max_size;
 _rect last_rect;
 _rect last_rect_max;
 _rgba*mem;
 H pixel_count;
 H real_pixel_count;
 B is_caret_shown;
 _rect caret_rect;
 H caret_speed;
 H caret_counter;
 _updatearea update_area;
 HICON icon;
 _size icon_size;
 BP icon_mem;
 H icon_resnum;
 H icon_index;
 HWND hwnd;
 HRGN region;
 HDC dc;
 N(*ElseProc)(HWND hWindow,H uiMessage,H uiParam,N ulParam,BP issuedef);
 ///N wheel;
 B is_disabled;
 _pixelstyle pixl_style;
 H spot_count;
 H spot_slots;
 _surfacespot*spot;
 HP spot_id_order;
 B spot_order_ok;
 _rect spot_depth_rect;
 ZP spot_depth_map;
 HP spot_id_map;
 H spot_press_count;
 H spot_over_count;
 H spot_focus_count;
 H spot_paint_count;
 H spot_focus_id;
 H child_count;
 H parent_handle;
 HWND parent_hwnd;
 H extra_bytes;
 BP extra_data;
 B is_drop_accept;
 H drop_count;
 _list drop_list;
 }
 _surfacestatus;


 structure
 {
 H handle;
 _surfacestatus status;
 }
 _surfaceunit;


 B aaSurfaceCreate                     (HP handle,_size*size);
 B aaSurfaceMinMaxCreate               (HP handle,_size*size,_size*minsize,_size*maxsize);
 B aaSurfaceMake                       (HP handle,_size*size,VP mem);
 B aaSurfaceLoad                       (HP handle,VP filename,VP useextension);
 B aaSurfaceLoadUsingResource          (HP handle,H resnum,VP useextension);
 B aaSurfaceLoadFromMemory             (HP handle,H bytes,VP mem,VP useextension);
 B aaSurfaceDuplicate                  (HP handle,H shandle);
 B aaSurfaceFindByHwnd                 (HP handle,HWND hwnd);
 B aaSurfaceSave                       (H handle,_rect*r1,B flip,VP filename);
 B aaSurfaceSaveToMemory               (H handle,_rect*r1,B flip,VP useextension,HP bytes,H maxbytes,VP mem);
 B aaSurfaceReMake                     (H handle,_size*size,VP mem);
 B aaSurfaceDestroy                    (H handle);
 B aaSurfaceIgnoreWMPaint              (H handle,B state);
 B aaSurfaceMinMaxSizeSet              (H handle,_size*minsize,_size*maxsize);
 B aaSurfaceMaximize                   (H handle,B state);
 B aaSurfaceRequiresResize             (H handle,_rect*rect);
 B aaSurfaceElseProcSet                (H handle,N(*Proc)(HWND hWindow,H uiMessage,H uiParam,N ulParam,BP issuedef));
 B aaSurfaceStatus                     (H handle,_surfacestatus*surfacestatus);
 B aaSurfaceCursorCapture              (H handle,B state);
 B aaSurfaceMoveableSet                (H handle,B state);
 B aaSurfaceSizeableSet                (H handle,B state);
 B aaSurfaceResizeCounterGet           (H handle,HP counter);
 B aaSurfaceResizeCounterReset         (H handle);
 B aaSurfaceDisableRect                (H handle,_rect*r1);
 B aaSurfaceClipperGet                 (H handle,_rect*r1);
 B aaSurfaceClipperSet                 (H handle,_rect*r1);
 B aaSurfaceFlipSet                    (H handle,B hflipstate,B vflipstate);
 B aaSurfaceBlendSet                   (H handle,B state);
 B aaSurfaceAlphaSet                   (H handle,B alpha);
 B aaSurfaceVisualize                  (H handle,B tool,H parent);
 B aaSurfaceRoundedSet                 (H handle,B state,Z rwid,Z rhit);
 B aaSurfaceShow                       (H handle,B state);
 B aaSurfaceTraySet                    (H handle,H iconresnum,VP fmt,...);
 B aaSurfaceTrayClickClear             (H handle);
 B aaSurfaceIsTrayClicked              (H handle,_cord*cord,BP isright);
 B aaSurfaceTitleSet                   (H handle,VP fmt,...);
 B aaSurfaceTitleAppendf               (H handle,VP fmt,...);
 B aaSurfaceIconSetUsingResource       (H handle,H resnum,H index);
 B aaSurfaceFocus                      (H handle);
 B aaSurfaceMinimize                   (H handle);
 B aaSurfaceRestore                    (H handle);
 B aaSurfaceRectSet                    (H handle,_rect*rect);
 B aaSurfaceCordSet                    (H handle,_cord*cord);
 B aaSurfaceSizeSet                    (H handle,_size*size);
 B aaSurfaceRectGet                    (H handle,_rect*rect);
 B aaSurfaceCordGet                    (H handle,_cord*cord);
 B aaSurfaceSizeGet                    (H handle,_size*size);
 B aaSurfaceViewportSet                (H handle,_rect*rect);
 B aaSurfaceCenter                     (H handle,_rect*rect);
 B aaSurfaceRectAlign                  (H handle,_rect*rect,B ha,B va);
 B aaSurfaceMonitorAlign               (H handle,B mid,B ha,B va);
 B aaSurfaceCordAdjust                 (H handle,N xamnt,N yamnt);
 B aaSurfaceOnTop                      (H handle,B state);
 B aaSurfaceCordToVisualCord           (H handle,_cord*cord,_cord*vcord);
 B aaSurfaceVisualCordToCord           (H handle,_cord*vcord,_cord*cord);
 B aaSurfaceCaretReset                 (H handle);
 B aaSurfaceCaretShow                  (H handle,B state);
 B aaSurfaceCaretRectSet               (H handle,_rect*rect);
 B aaSurfaceCaretGet                   (H handle,BP isshown,_rect*rect,HP counter);
 B aaSurfaceCaretSpeedSet              (H handle,H speed);
 B aaSurfaceBlit                       (H handle,_rect*rect,H dhandle,_rect*drect,B flip);
 B aaSurfaceImageDrawUsingSurface      (H handle,_rect*imagerect,H shandle,_rect*srect,B hflip,B vflip,B xalpha);
 B aaSurfaceImageDraw                  (H handle,_size*imgsize,_rect*imgrect,VP img,_rect*drect,B hflip,B vflip,B xalpha);
 B aaSurfaceImageGrab                  (H handle,_rect*rect,_cord*imgcord,_size*imgsize,VP img);
 B aaSurfaceImageTile                  (H handle,_size*imgsize,_rect*imgrect,VP img,_rect*drect,B hflip,B vflip,B xalpha);
 B aaSurfaceImageWarp                  (H handle,_size*imgsize,_rect*imgrect,VP img,_cord*c1,_cord*c2,_cord*c3,_cord*c4,B hflip,B vflip,B xalpha);
 B aaSurfaceImageRgbaReplace           (H handle,_rect*rect,_rgba*p1,_rgba*p2,B logic,B checkalpha);
 B aaSurfacePixelStyleSet              (H handle,_pixelstyle*pixelstyle);//VP data);
 B aaSurfacePixelStyleGet              (H handle,_pixelstyle*pixelstyle);//VP data);
 B aaSurfacePixelPutProc               (VP surfs,N x,N y,_rgba*p1);
 B aaSurfacePixelSetProc               (VP surfs,N x,N y,_rgba*p1);
 B aaSurfacePixelGetProc               (VP surfs,N x,N y,_rgba*p1);
 B aaSurfacePixelPutProcGet            (H handle,PP proc);
 B aaSurfacePixelSetProcGet            (H handle,PP proc);
 B aaSurfacePixelGetProcGet            (H handle,PP proc);
 B aaSurfacePixelPutProcSet            (H handle,B(*Proc)(VP,N,N,_rgba*));
 B aaSurfacePixelSetProcSet            (H handle,B(*Proc)(VP,N,N,_rgba*));
 B aaSurfacePixelGetProcSet            (H handle,B(*Proc)(VP,N,N,_rgba*));
 B aaSurfacePixelPut                   (H handle,_cord*c1,_rgba*p1);
 B aaSurfacePixelSet                   (H handle,_cord*c1,_rgba*p1);
 B aaSurfacePixelGet                   (H handle,_cord*c1,_rgba*p1);
 B aaSurfaceMaskNotSet                 (H handle,_rgba*p1);
 B aaSurfaceMaskNotGet                 (H handle,_rgba*p1);
 B aaSurfaceMaskSet                    (H handle,_rgba*p1);
 B aaSurfaceMaskGet                    (H handle,_rgba*p1);
 B aaSurfaceLine                       (H handle,_cord*c1,_cord*c2,_rgba*p1);
 B aaSurfaceClear                      (H handle,_rgba*p1);
 B aaSurfaceFill                       (H handle,_rect*rect,_rgba*p1);
 B aaSurfaceFrame                      (H handle,_rect*rect,_rgba*p1);
 B aaSurfaceFramePart                  (H handle,_rect*rect,_rgba*p1,B dol,B dot,B dor,B dob,B dotlbr,B dotrbl);
 B aaSurfaceFillFrame                  (H handle,_rect*rect,B thickness,_rgba*p1,_rgba*p2);
 B aaSurfacePoly                       (H handle,_cord**cords,_rgba*p1,_rgba*p2);
 B aaSurfaceBar                        (H handle,_rect*rect,_rgba*p1,_rgba*p2,H hsk,H vsk);
 B aaSurfaceTriangle                   (H handle,_cord*c1,_cord*c2,_cord*c3,_rgba*p1);
 B aaSurfaceTriangleFill               (H handle,_cord*c1,_cord*c2,_cord*c3,_rgba*p1);
 B aaSurfaceEllipse                    (H handle,_rect*rect,_rgba*p1);
 B aaSurfaceEllipseFill                (H handle,_rect*rect,_rgba*p1);
 B aaSurfaceEllipseFillFrame           (H handle,_rect*rect,N thick,_rgba*p1,_rgba*p2);
 B aaSurfaceFloodFill                  (H handle,_rect*r1,_cord*c1,_rgba*p1);
 B aaSurfaceArc                        (H handle,_rect*rect,N astart,N astop,N arot,_rgba*p1);
 B aaSurfaceRoundedFrame               (H handle,_rect*rect,N r,_rgba*p1);
 B aaSurfaceRoundedFill                (H handle,_rect*rect,N r,_rgba*p1);
 B aaSurfaceChamfer                    (H handle,_rect*rect,B state,_rgba*p1,N rad);
 B aaSurfaceGimpTile                   (H handle,_rect*rect,N sz,_rgba*p1,_rgba*p2);
 B aaSurfaceDragBar                    (H handle,_rect*rect,_rgba*p1,_rgba*p2);
 B aaSurfaceLabel                      (H handle,_rect*rect,_rgba*p1,H fhandle,_rgba*p2,N xadj,N yadj,N ha,N va,H maxchars,VP fmt,...);
 B aaSurfaceFuzz                       (H handle,_rect*rect,_rgba*p1,B level,H xmod,H ymod);
 B aaSurfacePrintf                     (H handle,_cord*cord,H fhandle,_rgba*p1,H maxchars,VP fmt,...);
 B aaSurfaceScroll                     (H handle,_rect*rect,N xpixels,N ypixels,_rgba*pn);
 B aaSurfaceBevel                      (H handle,_rect*rect,_rgba*p1,B state);
 B aaSurfaceBlur                       (H handle,_rect*rect,B hstrength,B vstrength);
 B aaSurfaceConvolve                   (H handle,_rect*rect,FP matrix,N n,_rgba*p1,B absflag);
 B aaSurfaceButtonFrame                (H handle,_rect*r1,B state,B depth);
 B aaSurfaceGradientFill               (H handle,_rect*rect,_cord*c1,_rgba*p1,_rgba*p2,B type,F tilt);
 B aaSurfaceField                      (H handle,_rect*rect,_rgba*p1,H fhandle,_rgba*p2,B masked,N xadj,N yadj,B usecaret,H pos,H maxchars,VP fmt,...);
 B aaSurfaceLog                        (H handle,_rect*rect,_rgba*p1,H fhandle,_rgba*p2,VP fmt,...);
 B aaSurfaceLogWriteSet                (H handle,B state);
 B aaSurfaceUpdateAreaAdd              (H handle,_rect*rect,B update);
 B aaSurfaceUpdateAreaRemove           (H handle,_rect*rect,B update);
 B aaSurfaceUpdateAreaReset            (H handle);
 B aaSurfaceUpdate                     (H handle);
 B aaSurfaceUpdateAndStatus            (H handle,_surfacestatus*status);
 B aaSurfaceCaptureScreen              (H handle,_rect*r1,HWND hwnd,_rect*r2,B vflip);
 B aaSurfaceExtraDataSet               (H handle,H bytes);
 B aaSurfaceExtraDataGet               (H handle,HP bytes,PP ptr);

 B aaSurfaceDropAccept                 (H handle,B state);
 B aaSurfaceDropClear                  (H handle);

 B aaSurfaceSpotIdRangeReserve         (H handle,HP firstid,H count);
 B aaSurfaceSpotFindByNumber           (H handle,H sn,_surfacespot**surfacespot);
 B aaSurfaceSpotFindById               (H handle,H id,_surfacespot**surfacespot);
 B aaSurfaceSpotAdd                    (H handle,H id,_surfacespot**surfacespot);
 B aaSurfaceSpotRemove                 (H handle,H id);
 B aaSurfaceSpotPurge                  (H handle);
 B aaSurfaceSpotSet                    (H handle,H id,H type,Z depth,N x,N y,H w,H h,_surfacespot**surfacespot);
 B aaSurfaceSpotStateSet               (H handle,H id,B isover,B ispress,B isfocus,B ispaint,_surfacespot**surfacespot);

 B aaSurfaceArrow                      (H handle,_cord*cd1,_cord*cd2,N which,N thick,N hang,D ang,_rgba*pn1,_rgba*pn2);
 B aaSurfaceCheckMark                  (H handle,_rect*r1,_rgba*p1,_rgba*p2,_rgba*p3);
 B aaSurfaceCrossMark                  (H handle,_rect*r1,_rgba*p1,_rgba*p2,_rgba*p3);
 B aaSurfaceRadioButton                (H handle,_rect*r1,B state,_rgba*p1,_rgba*p2,_rgba*p3);;
 B aaSurfaceCloseIcon                  (H handle,_rect*r1,_rgba*p1);
 B aaSurfaceMaximizeIcon               (H handle,_rect*r1,_rgba*p1);
 B aaSurfaceRestoreIcon                (H handle,_rect*r1,_rgba*p1);
 B aaSurfaceMinimizeIcon               (H handle,_rect*r1,_rgba*p1);

 B aaSurfaceCaption                    (H handle,H spotidbase,H fonthandle,VP fmt,...);
 B aaSurfaceCaptionButtons             (H handle,H spotidbase,H usebits,H overbits,H pressbits);

/*-----------------------------------------------------------------------*/

 B aaImageYuv420ToBgra                 (_size*size,Z ystride,Z uvstride,VP yplane,VP uplane,VP vplane,VP dest);

/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 H surface_handle;
 _rgba txt_bg_pen;
 _rgba txt_fg_pen;
 _rgba sel_bg_pen;
 _rgba sel_fg_pen;
 _rgba caret_pen;
 B caret_state;
 H caret_pos;
 B caret_type;
 H sel_start;
 H sel_count;
 H position;
 H font_handle;
 _fontstatus font_status;
 H txt_len;
 B txt_buf[_4K];
 _rect rect;
 _rect char_rect[_4K];
 }
 _fancytext;

 B aaFancyTextInit                     (_fancytext*fancytext,H surfacehandle,H fonthandle);
 B aaFancyTextRectSet                  (_fancytext*fancytext,_rect*rect);
 B aaFancyTextSelSet                   (_fancytext*fancytext,H selstart,H selcount);
 B aaFancyTextCaretSet                 (_fancytext*fancytext,H position,B type,B state);
 B aaFancyTextPositionSet              (_fancytext*fancytext,H position);
 B aaFancyTextWrite                    (_fancytext*fancytext,H chars,VP txt);
 B aaFancyTextWritef                   (_fancytext*fancytext,VP fmt,...);
 B aaFancyTextPaint                    (_fancytext*fancytext);



/*-----------------------------------------------------------------------*/

 #define aa_CURSOR_None                1
 #define aa_CURSOR_Arrow               2
 #define aa_CURSOR_HourGlass           3
 #define aa_CURSOR_Resize              4
 #define aa_CURSOR_ResizeV             5
 #define aa_CURSOR_ResizeH             6
 #define aa_CURSOR_ResizeB             7
 #define aa_CURSOR_ResizeF             8
 #define aa_CURSOR_Move                9
 #define aa_CURSOR_Beam                10
 #define aa_CURSOR_Hand                11
 #define aa_CURSOR_Help                12
 #define aa_CURSOR_TimeGlass           13
 #define aa_CURSOR_SlashRound          14
 #define aa_CURSOR_ArrowUp             15

 B aaCursorSet                         (B id);
 B aaCursorGet                         (BP id);
 B aaCursorSimulate                    (B flag,N x,N y,H wid,H hit,N etc,H del);


/*-----------------------------------------------------------------------*/

 B aaAppBarSet                         (B state,B orientation,H depth);
 B aaAppBarGet                         (BP state,BP orientation,_rect*rect);

/*-----------------------------------------------------------------------*/


 structure
 {
 _size size;
 H total_frames;
 H total_ms;
 H frame_number;
 H frame_delay;
 H ms;
 }
 _gifstatus;

 structure
 {
 H handle;
 _gifstatus status;
 }
 _gifunit;


 B aaGifCreate                         (HP handle,VP filename);
 B aaGifCreateUsingResource            (HP handle,H resnum);
 B aaGifDestroy                        (H handle);
 B aaGifStatus                         (H handle,_gifstatus*gifstatus);
 B aaGifRewind                         (H handle);
 B aaGifFrameNext                      (H handle,PP img);

/*-----------------------------------------------------------------------*/




 structure
 {
 B is_ok;
 Q seq;
 Q events_waiting;
 Q microsecs;
 N wheel;
 H is_caps:1;
 H is_numl:1;
 H is_scrl:1;
 H is_shift:1;
 H is_ctrl:1;
 H is_alt:1;
 H is_win:1;
 H is_left:1;
 H is_mid:1;
 H is_right:1;
 H is_focus_surface:1;
 H is_over_surface:1;
 H rsvd:20;
 Q key_microsecs;
 Q key_seq;
 B key_msg;
 B key_sys;
 B key_inj;
 B skey,vkey,akey,xkey;
 B vkey_used_count;
 B vkey_down_count;
 B vkey_held_count;
 B vkey_up_count;
 C vkey_state[256];
 _cord cord;
 HWND over_hwnd;
 H over_handle;
 _cord over_cord;
 HWND focus_hwnd;
 H focus_handle;
 _cord focus_cord;
 H spot_id;
 H spot_type;
 N spot_index;
 _rect spot_rect;
 _cord spot_cord;
 _surfacespot*spot_ptr;
 }
 _inputstate;


/*------------------------------------*/

/*
 #define aa_IE_LeftDown                0
 #define aa_IE_LeftUp                  1
 #define aa_IE_LeftHeld                2

 #define aa_IE_RightDown               3
 #define aa_IE_RightUp                 4
 #define aa_IE_RightHeld               5

 #define aa_IE_SpotEnter               6
 #define aa_IE_SpotChange              7
 #define aa_IE_SpotLeave               8

 #define aa_IE_WheelChange             9

 #define aa_IE_KeyDown                 10
 #define aa_IE_KeyUp                   11
 #define aa_IE_KeyHeld                 12

 #define aa_IE_Move                    14

 #define aa_IE_DragStart               15
 #define aa_IE_Drag                    16
 #define aa_IE_DragStop                17

 #define aa_IE_Click                   18
 #define aa_IE_SpotClick               19

 #define aa_IE_FocusChange             24

 #define aa_IE_SurfaceEnter            25
 #define aa_IE_SurfaceChange           26
 #define aa_IE_SurfaceLeave            27

 #define aa_IE_KeyMsg                  28
 #define aa_IE_VkeyStateChange         29

*/

/*
 groups
   0    1    2   3     4   5    6    7     8     9    10
 left,right,spot,wheel,key,move,drag,click,focus,surf,key
 */

 #define aa_IE_LeftDown                0
 #define aa_IE_LeftUp                  1
 #define aa_IE_LeftHeld                2

 #define aa_IE_RightDown               3
 #define aa_IE_RightUp                 4
 #define aa_IE_RightHeld               5

 #define aa_IE_SpotEnter               6
 #define aa_IE_SpotChange              7
 #define aa_IE_SpotLeave               8

 #define aa_IE_WheelChange             9

 #define aa_IE_KeyDown                 12
 #define aa_IE_KeyUp                   13
 #define aa_IE_KeyHeld                 14

 #define aa_IE_Move                    15

 #define aa_IE_DragStart               18
 #define aa_IE_Drag                    19
 #define aa_IE_DragEnd                 20

 #define aa_IE_Click                   21
 #define aa_IE_SpotClick               22

 #define aa_IE_FocusChange             24

 #define aa_IE_SurfaceEnter            27
 #define aa_IE_SurfaceChange           28
 #define aa_IE_SurfaceLeave            29

 #define aa_IE_KeyMsg                  30
 #define aa_IE_VkeyStateChange         31


 structure
 {
 H magic;
 B is_ok;
 B is_dragging;
 Q seq;
 B internal_flag;
 Q event_bit;
 B bits_on;
 B event_byt[64];
 B event[64];
 _inputstate ises[5];
 _inputstate*curr;
 _inputstate*prev;
 _inputstate*ldwn;
 _inputstate*rdwn;
 _inputstate*pcur;
 _surfacespot*c_spot;
 _surfacespot*p_spot;
 _surfacespot*l_spot;
 _surfacespot*r_spot;
 B key_rep[256];
 }
 _inputengine;





 B aaInputKeySimulate                  (B virtkey,B isscan,B isdown);
 B aaInputKeyPairSimulate              (B virtkey1,B virtkey2,H sleep);
 B aaInputKeyPattern                   (H state);
 B aaInputKeyStringSimulate            (VP fmt,...);
 B aaInputKeyCharSimulate              (B ch,B count);
 B aaInputStateGet                     (_inputstate*inputstate);
 B aaInputEngine                       (_inputengine*inputengine);
 B aaInputEventToString                (Q eventbit,H from,H count,VP str);



/*-----------------------------------------------------------------------*/


/*-----------------------------------------------------------------------*/



 structure
 {
 H magic;
 _size screen_size;
 B screen_bits;
 _size screen_dpi;
 H screen_vrefresh;
 HWND taskbar_hwnd;
 _rect taskbar_rect;
 B taskbar_orientation;
 HWND tray_hwnd;
 _rect tray_rect;
 B is_wide_screen;
 B is_tall_screen;
 F aspect_ratio;
 B monitor_count;
 B monitor_primary_index;
 _rect monitor_rect[16];
 _size monitor_mm[16];
 D monitor_diagonal_mm[16];
 D monitor_ppmm[16][2];
 B monitor_name[16][33];
 H monitor_handle[16];
 F monitor_aspect[16];
 _rect virtual_rect;
 _rect desktop_rect;
 }
 _displayinfo;



 B aaDisplaySet                        (_size*size,B bits,B revert);
 B aaDisplayInfoGet                    (_displayinfo*displayinfo);
 B aaDisplayMonitorFromCord            (_displayinfo*displayinfo,_cord*cord,BP monitorindex);
 B aaDisplayGammaGet                   (WP gbuf);
 B aaDisplayGammaSet                   (WP gbuf);
 B aaDisplayGammaBrightnessSet         (WP gbuf,B brightness);
 B aaDisplayBrightnessSet              (B brightness);
 B aaDisplayBrightnessFlash            (B count,H sleep);
 B aaDisplayPixelGet                   (_cord*cord,_rgba*pn);
 B aaDisplayPixelSet                   (_cord*cord,_rgba*pn);
 B aaDisplayInfoToString               (_displayinfo*displayinfo,VP str);
 B aaDisplayMonitorPowerSet            (B state);
 B aaDisplayPowerBrightnessGet         (BP acordc,BP aclev,BP dclev);
 B aaDisplayPowerBrightnessSet         (B acordc,B aclev,B dclev);
 B aaDisplayToMm                       (_displayinfo*displayinfo,B monitorindex,_cord*pixel,DP xmm,DP ymm);
 B aaDisplayFromMm                     (_displayinfo*displayinfo,B monitorindex,D xmm,D ymm,_cord*pixel);


/*-----------------------------------------------------------------------*/


 #define aa_NOTE_C                     0
 #define aa_NOTE_Cs                    1
 #define aa_NOTE_Db                    1
 #define aa_NOTE_D                     2
 #define aa_NOTE_Ds                    3
 #define aa_NOTE_Eb                    3
 #define aa_NOTE_E                     4
 #define aa_NOTE_F                     5
 #define aa_NOTE_Fs                    6
 #define aa_NOTE_Gb                    6
 #define aa_NOTE_G                     7
 #define aa_NOTE_Gs                    8
 #define aa_NOTE_Ab                    8
 #define aa_NOTE_A                     9
 #define aa_NOTE_As                    10
 #define aa_NOTE_Bb                    10
 #define aa_NOTE_B                     11


 structure
 {
 H frequency;
 B bits;
 B channels;
 H rate;
 B bps;
 B mode;
 }
 _audiomode;


 structure
 {
 H magic;
 _audiomode i_mode;
 _audiomode o_mode;
 }
 _audioconverter;




 structure
 {
 H magic;
 F gInFIFO[4096];
 F gOutFIFO[4096];
 F gFFTworksp[2*4096];
 F gLastPhase[4096/2+1];
 F gSumPhase[4096/2+1];
 F gOutputAccum[2*4096];
 F gAnaFreq[4096];
 F gAnaMagn[4096];
 F gSynFreq[4096];
 F gSynMagn[4096];
 N frame_size;
 N osamp;
 N gRover;
 }
 _aapitchshift;



 structure
 {
 N octave;
 N note;
 N piano;
 D fine;
 F pitch;
 F tempo;
 }
 _aapitchtempo;


 structure
 {
 B is_record;
 B id;
 C name[33];
 _audiomode mode;
 B is_paused;
 H inactive;
 H sample_position;
 H samples_qued;
 H samples_written;
 H samples_surplus;
 Q mcs;
 D div;
 H blocksize;
 H maxblocks;
 HANDLE wave_device;
 HMIXER mixer_device;
 B is_mute;
 W volume;
 D decibels;
 VP proc;
 }
 _audiostatus;


 structure
 {
 H handle;
 _audiostatus status;
 }
 _audiounit;



 B aaAudioCountGet                     (BP playcount,BP reccount);
 B aaAudioNameGet                      (B id,B rec,VP name);

 B aaAudioModeSet                      (_audiomode*audiomode,H frequency,B bits,B channels);
 B aaAudioModeCopy                     (_audiomode*audiomode,_audiomode*saudiomode);
 B aaAudioModeIsValid                  (_audiomode*audiomode);


 B aaAudioBpmToSamples                 (_audiomode*audiomode,D bpm,HP samples);
 B aaAudioBpmFromSamples               (_audiomode*audiomode,H samples,DP bpm);
 B aaAudioSamplesToTime                (_audiomode*audiomode,H samples,DP ms);
 B aaAudioSamplesFromTime              (_audiomode*audiomode,D ms,HP samples);


 B aaAudioToFloats                     (_audiomode*audiomode,H isamples,VP idata,FP odata);
 B aaAudioFromFloats                   (_audiomode*audiomode,H isamples,FP idata,VP odata);

 B aaAudioConverterInit                (_audioconverter*audioconverter,_audiomode*imode,_audiomode*omode);
 B aaAudioConverterProcess             (_audioconverter*audioconverter,H isamples,VP idata,D tempo,HP osamples,VP odata);

 B aaAudioPitchTempoGet                (_aapitchtempo*aapitchtempo,N octave,N note,D fine,N mode);

 B aaAudioPitchShiftInit               (_aapitchshift*aapitchshift,N framesize,N osamp);
 B aaAudioPitchShift                   (_aapitchshift*aapitchshift,F amount,N isamps,F rate,FP indata,FP outdata);



 B aaAudioCreate                       (HP handle,B id,B rec,_audiomode*audiomode,H blocksize,H maxblocks,B(*proc)(H,H,H,H,H,VP,VP));
 B aaAudioDestroy                      (H handle);
 B aaAudioStatus                       (H handle,_audiostatus*audiostatus);
 B aaAudioReset                        (H handle);
 B aaAudioPause                        (H handle,B state);
 B aaAudioWrite                        (H handle,H samples,VP data);
 B aaAudioRead                         (H handle,H samples,VP data);
 B aaAudioPeek                         (H handle,H sample,H samples,VP data);
 B aaAudioDiscard                      (H handle,H samples);
 B aaAudioMuteSet                      (H handle,B state);
 B aaAudioVolumeSet                    (H handle,W volume);


/*-----------------------------------------------------------------------*/

 #define aa_BIQUAD_LPass               1
 #define aa_BIQUAD_HPass               2
 #define aa_BIQUAD_BPass               3
 #define aa_BIQUAD_Notch               4
 #define aa_BIQUAD_PeakR               5
 #define aa_BIQUAD_LShlf               6
 #define aa_BIQUAD_HShlf               7


 structure
 {
 H magic;
 B type;
 H rate;
 D freq,gain,width;
 D a0,a1,a2,a3,a4;
 D x1,x2,y1,y2;
 }
 _biquad;


 B aaBiquadInit                        (_biquad*bq,B type,H srate,D freq,D gain,D width);
 B aaBiquadProcess                     (_biquad*bq,D sin,DP sout);


/*-----------------------------------------------------------------------*/

 PUB B aa_math_scan_zigzag[64];
 PUB B aa_math_scan_zigzag_jpeg[64];


 structure
 {
 H magic;
 B ret;
 H mt[624];
 Z mti;
 H mag01[2];
 }
 _twister;



 B aaMathDct                           (IP block,B fwd,B descale);
 B aaMathSinTableCreate                (FP*table);
 B aaMathCosTableCreate                (FP*table);
 B aaMathDtmfSet                       (H samples,_audiomode*audiomode,N amp,B code,VP buf);
 B aaMathLatLongDistanceGet            (D lat1,D lon1,D lat2,D lon2,DP distance);
 B aaMathLatLongCordGet                (D lat,D lon,_size*size,_cord*cord);
 D aaMathDoubleRound                   (D val,N numer,N denom);
 H aaMathRand32                        (H lo,H hi);
 Q aaMathRand64                        (Q lo,Q hi);
 D aaMathRandDouble                    (D lo,D hi);
 B aaMathRandomGet                     (HP val);
 B aaMathTwisterInit                   (_twister*twister,H seed,HP key);
 H aaMathTwisterInt32                  (_twister*twister);
 N aaMathTwisterInt31                  (_twister*twister);
 D aaMathTwisterReal1                  (_twister*twister);
 D aaMathTwisterReal2                  (_twister*twister);
 D aaMathTwisterReal3                  (_twister*twister);
 D aaMathTwisterRes53                  (_twister*twister);
 B aaMathAngleToCord                   (D angle,_rect*rect,_cord*cord);
 B aaMathLog2                          (Y val,YP res);
 B aaMathLog2D                         (D val,DP res);
 B aaMathIsPowerOfTwo                  (Q val);



/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 C digits[1400];
 Z sign_bit;
 Z last_digit;
 Z base;
 }
 _big;

/**------------------------*/

 B aaBigInit                           (_big*r);
 B aaBigCopy                           (_big*r,_big*a);
 B aaBigDump                           (_big*r,B showdigits,VP fmt,...);
 B aaBigBaseSet                        (_big*r,Z base);

 B aaBigToInt                          (_big*r,GP val);
 B aaBigFromInt                        (_big*r,G val);

 B aaBigToString                       (_big*r,H maxchars,VP str);
 B aaBigFromString                     (_big*r,H chars,VP str);
 B aaBigFromStringf                    (_big*r,VP fmt,...);

 B aaBigIsOdd                          (_big*r);
 B aaBigIsEven                         (_big*r);
 B aaBigIsZero                         (_big*r);
 B aaBigIsOne                          (_big*r);

 B aaBigCompare                        (_big*r,_big*a,ZP dif);
 B aaBigAdd                            (_big*r,_big*a,_big*b);
 B aaBigSub                            (_big*r,_big*a,_big*b);
 B aaBigMul                            (_big*r,_big*a,_big*b);
 B aaBigDiv                            (_big*r,_big*a,_big*b);
 B aaBigMod                            (_big*r,_big*a,_big*b);
 B aaBigPow                            (_big*r,_big*a,_big*b);

 B aaBigCompareInt                     (_big*r,G a,ZP dif);
 B aaBigAddInt                         (_big*r,_big*a,G b);
 B aaBigSubInt                         (_big*r,_big*a,G b);
 B aaBigMulInt                         (_big*r,_big*a,G b);
 B aaBigDivInt                         (_big*r,_big*a,G b);
 B aaBigModInt                         (_big*r,_big*a,G b);
 B aaBigPowInt                         (_big*r,_big*a,G b);

 B aaBigInc                            (_big*r);
 B aaBigDec                            (_big*r);
 B aaBigSquareRoot                     (_big*r,_big*a);
 B aaBigIsPrime                        (_big*r,Z rounds);

 B aaBigShiftLeft                      (_big*r,_big*a,_big*b);
 B aaBigShiftRight                     (_big*r,_big*a,_big*b);
 B aaBigShiftLeftInt                   (_big*r,_big*a,G b);
 B aaBigShiftRightInt                  (_big*r,_big*a,G b);

 B aaBigBitSet                         (_big*r,_big*a);
 B aaBigBitIsSet                       (_big*r,_big*a);
 B aaBigBitClear                       (_big*r,_big*a);

 B aaBigBitSetInt                      (_big*r,G a);
 B aaBigBitIsSetInt                    (_big*r,G a);
 B aaBigBitClearInt                    (_big*r,G a);





/*-----------------------------------------------------------------------*/

 structure
 {
 B is_connected;
 B is_failed;
 B is_ready;
 B is_previewmode;
 B is_detecting;
 B is_detected;
 B has_sourcebox;
 B is_sourcebox_open;
 B is_frameready;
 B id;
 B bits;
 _size size;
 B name[33];
 B ver[33];
 H surface_handle;
 _surfacestatus surface_status;
 H frame_number;
 H frames_dropped;
 Q ms_start;
 D fps;
 }
 _vidcapstatus;

 structure
 {
 H handle;
 _vidcapstatus status;
 }
 _vidcapunit;


 B aaVidCapCountGet                    (BP count);
 B aaVidCapNameGet                     (B id,VP name);
 B aaVidCapCreate                      (HP handle,B id);
 B aaVidCapCreateAutoDetect            (HP handle,B id,_size*size);
 B aaVidCapDestroy                     (H handle);
 B aaVidCapStatus                      (H handle,_vidcapstatus*vidcapstatus);
 B aaVidCapFormatSet                   (H handle,_size*size,B bits);
 B aaVidCapPreviewSet                  (H handle,B state);
 B aaVidCapFrameIsReady                (H handle);
 B aaVidCapFrameNext                   (H handle);
 B aaVidCapSourceBoxShow               (H handle);


/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 H samples;
 D duration;
 _audiomode mode;
 BP ptr;
 }
 _wav;


 B aaWavLoad                           (_wav*wav,VP filename);
 B aaWavLoadUsingResource              (_wav*wav,H resnum);
 B aaWavRelease                        (_wav*wav);

/*-----------------------------------------------------------------------*/

 #define aa_INITYPE_Section            1
 #define aa_INITYPE_Text               2
 #define aa_INITYPE_Unsigned           3
 #define aa_INITYPE_Signed             4
 #define aa_INITYPE_Float              5
 #define aa_INITYPE_SignedFloat        6
 #define aa_INITYPE_On                 10
 #define aa_INITYPE_Off                11
 #define aa_INITYPE_True               12
 #define aa_INITYPE_False              13
 #define aa_INITYPE_Yes                14
 #define aa_INITYPE_No                 15
 #define aa_INITYPE_TagOpen            16
 #define aa_INITYPE_TagClose           17


 structure
 {
 H magic;
 B is_success;
 B is_fail;
 H entries;
 BP type;
 _data field;
 _data data;
 }
 _ini;


 B aaIniOpen                           (_ini*ini,VP filename);
 B aaIniClose                          (_ini*ini);
 B aaIniEntryGet                       (_ini*ini,H index,PP fmem,PP dmem,VP txt);

/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 BP mem;
 Q bytes;
 }
 _fileunit;


 structure
 {
 H volume;
 H object[2];
 }
 _fileid;


 structure
 {
 C drive;
 C path[32][MAX_PATH];
 B path_count;
 C file[MAX_PATH];
 C filename[MAX_PATH];
 C extension[32][MAX_PATH];
 B extension_count;
 }
 _fileparts;


 structure
 {
 H is_archive:1;
 H is_hidden:1;
 H is_normal:1;
 H is_offline:1;
 H is_read_only:1;
 H is_system:1;
 H is_temp:1;
 H reserved:25;
 }
 _fileattributes;



 structure
 {
 W major_version;
 W minor_version;
 W build_number;
 W revision_number;
 W language;
 W codepage;
 B is_debug_info;
 B is_pre_release;
 B is_private_build;
 B is_special_build;
 B for_dos;
 B for_dos16;
 B for_dos32;
 B for_nt;
 B for_nt32;
 B for_win16;
 B for_win32;
 B for_os216;
 B for_os232;
 B for_pm16;
 B for_pm32;
 B is_application;
 B is_dll;
 B is_drv;
 B is_drv_comm;
 B is_drv_display;
 B is_drv_installable;
 B is_drv_keyboard;
 B is_drv_language;
 B is_drv_mouse;
 B is_drv_network;
 B is_drv_printer;
 B is_drv_sound;
 B is_drv_system;
 B is_font;
 B is_font_raster;
 B is_font_truetype;
 B is_font_vector;
 B is_static_lib;
 B is_vxd;
 B company_name[129];
 B file_description[257];
 B file_version[65];
 B internal_name[129];
 B legal_copyright[257];
 B legal_trademarks[257];
 B original_filename[257];
 B product_name[129];
 B product_version[65];
 B comments[_1K];
 B private_build[257];
 B special_build[257];
 }
 _filedetails;


 structure
 {
 B file_name[513];
 B is_exists;
 B is_folder;
 Q bytes;
 _systime created;
 _systime modified;
 _fileattributes attributes;
 _fileid id;
 }
 _fileinformation;



 B aaFilePartsGet                      (VP filename,_fileparts*fileparts);
 B aaFileEqualsFile                    (VP filename,VP filename2);
 B aaFileInfoGet                       (VP filename,QP bytes,BP isfolder,_systime*ctime,_systime*mtime,_fileid*id);
 B aaFileInformationGet                (VP filename,_fileinformation*fileinformation);
 B aaFileExists                        (VP filename,...);
 B aaFileDelete                        (VP filename,...);
 B aaFileCopy                          (VP filename,VP destfilename,B allowoverwrite);
 B aaFileRename                        (VP filename,VP destfilename);
 B aaFileSaveFromMemory                (VP filename,H bytes,VP mem);
 B aaFileAppendFromMemory              (VP filename,H bytes,VP mem);
 B aaFileAppendf                       (VP filename,VP fmt,...);
 B aaFileLoadToMemory                  (VP filename,Q fromoffset,H bytes,PP mem,HP bytesloaded);
 B aaFileLoadToBuffer                  (VP filename,Q fromoffset,H bytes,VP mem,HP bytesloaded);
 B aaFileUniqueCreate                  (VP filename,VP path,H chars,B alpha,B num,VP ext,B docreate);
 B aaFileTimeSet                       (VP filename,_systime*ctime,_systime*mtime);
 B aaFileSizeSet                       (VP filename,Q bytes);
 B aaFileIsUpxCompressed               (VP filename);
 B aaFileAttributesGet                 (VP filename,_fileattributes*fileattribs);
 B aaFileAttributesSet                 (VP filename,_fileattributes*fileattribs);
 B aaFileDetailsGet                    (VP filename,_filedetails*filedetails,VP string);
 B aaFileFolderCreate                  (VP fmt,...);
 B aaFileFolderDelete                  (VP fmt,...);
 B aaFileFolderExists                  (VP fmt,...);
 B aaFileFolderWorkingSet              (VP fmt,...);
 B aaFileFolderWorkingGet              (VP foldername);
 B aaFileFolderRename                  (VP foldername,VP newfoldername);
 B aaFileFolderTreeCreate              (VP foldername,B levels,B hex);
 B aaFileFolderTreeDelete              (VP foldername,B levels,B hex,B delfiles);
 B aaFileUnitLoad                      (_fileunit*unit,VP fmt,...);//VP filename);
 B aaFileUnitRelease                   (_fileunit*unit);

/*-----------------------------------------------------------------------*/

 structure
 {
 B is_cancelled;
 B is_success;
 B is_failure;
 B path[_1K];
 H count;
 B filename[256][129];
 }
 _fileboxstatus;

 B aaFileBoxOpen                       (H surfacehandle,VP initdir,VP initfile,VP fltr,B maxfiles,VP caption);
 B aaFileBoxClose                      (V);
 B aaFileBoxStatus                     (_fileboxstatus*fileboxstatus);

/*-----------------------------------------------------------------------*/

 structure
 {
 B is_cancelled;
 B is_success;
 B is_failure;
 B path[_1K];
 }
 _folderboxstatus;


 B aaFolderBoxOpen                     (H surfacehandle,VP initdir,VP caption);
 B aaFolderBoxClose                    (V);
 B aaFolderBoxStatus                   (_folderboxstatus*folderboxstatus);

/*-----------------------------------------------------------------------*/

 structure
 {
 B is_folder;
 B is_dotty;
 _systime created;
 _systime modified;
 _systime accessed;
 H attributes;
 Q file_bytes;
 B alt_file[14];
 B file_name[MAX_PATH];
 }
 _direntry;


 structure
 {
 B in_progress;
 B is_completed;
 B is_gettimes;
 B file_spec[300];
 H total_entries;
 H file_entries;
 H folder_entries;
 H dir_entries;
 _direntry*entry;
 }
 _dirstatus;


 structure
 {
 H handle;
 _dirstatus status;
 }
 _dirunit;


 B aaDirOpen                           (HP handle,B gettimes,VP filespec);
 B aaDirClose                          (H handle);
 B aaDirStatus                         (H handle,_dirstatus*dirstatus,H iterations);


/*-----------------------------------------------------------------------*/

 structure
 {
 B in_progress;
 B is_completed;
 B is_cancelled;
 B is_incfiles;
 H max_depth;
 B root[513];
 B spec[300];
 Q total_folders_found;
 Q total_files_found;
 Q total_folders_added;
 Q total_files_added;
 B cur_dir[_1K];
 _dirunit dir;
 VP proc;
 _list list;
 }
 _dirwalkerstatus;


 structure
 {
 H handle;
 _dirwalkerstatus status;
 }
 _dirwalkerunit;


 B aaDirWalkerCreate                   (HP handle,VP root,VP spec,B incfiles,H maxdepth,B(*proc)(H,VP,_dirwalkerstatus*,_direntry*));
 B aaDirWalkerDestroy                  (H handle);
 B aaDirWalkerStatus                   (H handle,_dirwalkerstatus*dirwalkerstatus,H iterationsa,H iterationsb);

/*-----------------------------------------------------------------------*/


 #define aa_DRIVETYPE_UNKNOWN          0
 #define aa_DRIVETYPE_ERROR            1
 #define aa_DRIVETYPE_REMOVABLE        2
 #define aa_DRIVETYPE_FIXED            3
 #define aa_DRIVETYPE_REMOTE           4
 #define aa_DRIVETYPE_CDROM            5
 #define aa_DRIVETYPE_RAMDISK          6

 structure
 {
 B drive;
 H type;
 Q size;
 Q left;
 Q used;
 H page_size;
 B type_txt[33];
 H volume_id;
 B volume_name[256];
 H max_filename_len;
 B digest[65];
 H crc;
 }
 _driveinfo;


 structure
 {
 B num_found;
 B ret[26];
 _driveinfo info[26];
 }
 _drivelist;


 B aaDriveInfoGet                      (B drive,_driveinfo*driveinfo);
 B aaDriveEject                        (B drive,B state);
 B aaDriveListGet                      (_drivelist*drivelist);

/*-----------------------------------------------------------------------*/


 #define aa_FILECREATE_OPEN            0
 #define aa_FILECREATE_CREATE          1
 #define aa_FILECREATE_CREATENEW       2

 #define aa_FILEMODE_NONE              0
 #define aa_FILEMODE_R                 1
 #define aa_FILEMODE_W                 2
 #define aa_FILEMODE_RW                3

 #define aa_FILESHARE_NONE             0
 #define aa_FILESHARE_R                1
 #define aa_FILESHARE_W                2
 #define aa_FILESHARE_RW               3

 #define aaFileStreamCreateQuick(h,f)  aaFileStreamCreate(h,f,aa_FILECREATE_CREATE,aa_FILEMODE_RW,aa_FILESHARE_RW,0,NO)

 structure
 {
 B filename[257];
 B is_created;
 B is_std_input;
 B is_std_output;
 B is_delete;
 Q bytes;
 Q offset;
 Q left;
 Q offset_stack[8];
 H offset_stack_count;
 _fileid id;
 HANDLE _handle;
 }
 _filestreamstatus;



 structure
 {
 H handle;
 _filestreamstatus status;
 }
 _filestreamunit;


 B aaFileStreamCreate                  (HP handle,VP filename,B create,B rwmode,B shmode,B cmode,B deleteon);
 B aaFileStreamDestroy                 (H handle);
 B aaFileStreamStatus                  (H handle,_filestreamstatus*filestreamstatus);
 B aaFileStreamInfoGet                 (H handle,QP bytes,_systime*ctime,_systime*mtime,_fileid*id);
 B aaFileStreamRead                    (H handle,H bytes,VP data);
 B aaFileStreamPeek                    (H handle,H bytes,VP data);
 B aaFileStreamWrite                   (H handle,H bytes,VP data);
 B aaFileStreamWritef                  (H handle,VP fmt,...);
 B aaFileStreamWriteByte               (H handle,B beo,B val);
 B aaFileStreamWriteWord               (H handle,B beo,W val);
 B aaFileStreamWriteDword              (H handle,B beo,H val);
 B aaFileStreamWriteQuad               (H handle,B beo,Q val);
 B aaFileStreamWriteFloat              (H handle,B beo,F val);
 B aaFileStreamWriteDouble             (H handle,B beo,D val);
 B aaFileStreamReadByte                (H handle,B beo,BP val);
 B aaFileStreamReadWord                (H handle,B beo,WP val);
 B aaFileStreamReadDword               (H handle,B beo,HP val);
 B aaFileStreamReadQuad                (H handle,B beo,QP val);
 B aaFileStreamReadFloat               (H handle,B beo,FP val);
 B aaFileStreamReadDouble              (H handle,B beo,DP val);
 B aaFileStreamPeekByte                (H handle,B beo,BP val);
 B aaFileStreamPeekWord                (H handle,B beo,WP val);
 B aaFileStreamPeekDword               (H handle,B beo,HP val);
 B aaFileStreamPeekQuad                (H handle,B beo,QP val);
 B aaFileStreamPeekFloat               (H handle,B beo,FP val);
 B aaFileStreamPeekDouble              (H handle,B beo,DP val);
 B aaFileStreamOffsetSet               (H handle,Q offset);
 B aaFileStreamOffsetAdjust            (H handle,G offsetamount);
 B aaFileStreamOffsetPush              (H handle);
 B aaFileStreamOffsetPop               (H handle);
 B aaFileStreamSizeSet                 (H handle,Q bytes);
 B aaFileStreamSizeAdjust              (H handle,G bytes);
 B aaFileStreamFlush                   (H handle);
 B aaFileStreamStringLen               (H handle,HP chars,BP stringmode);
 B aaFileStreamStringRead              (H handle,HP chars,BP stringmode,H maxchars,VP buf);
 B aaFileStreamStringLook              (H handle,H fromoff,H index,HP count,HP offset,HP chars,BP stringmode,H maxchars,VP buf);
 B aaFileStreamWriteEof                (H handle);
 B aaFileStreamSearch                  (H handle,H entrybytes,QP offset,VP data);
 B aaFileStreamSearchf                 (H handle,H entrybytes,QP offset,VP fmt,...);


/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 B is_initialized;
 B is_from_file;
 B is_from_memory;
 B file_name[_1K];
 _memoryunit mun;
 HP line_offset;
 HP line_chars;
 H line_count;
 H li;
 }
 _textreader;

 B aaTextReaderNew                     (_textreader*textreader,H bytes,VP mem);
 B aaTextReaderOpen                    (_textreader*textreader,VP filename,H startline,H maxlines);
 B aaTextReaderDelete                  (_textreader*textreader);
 B aaTextReaderLineGet                 (_textreader*textreader,H line,VP txt);




/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 H stage;
 _filestreamunit fsu;
 _memoryunit bulk_mem;
 Q bulk_off;
 Q bulk_len;
 Q prev_file_off;
 B user_data[64];
 _list list;
 VP proc;
 Q line_number;
 Q user_lines;
 }
 _textloader;


 B aaTextLoaderNew                     (_textloader*textloader,Q offset,VP file,B(*proc)(_textloader*,Q,H,VP));
 B aaTextLoaderDelete                  (_textloader*textloader);
 B aaTextLoaderYield                   (_textloader*textloader,H ita);
 B aaTextLoaderProc                    (_textloader*textloader,Q linenum,H chars,VP txt);

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/

 structure
 {
 _rgba col_scrollbar;
 _rgba col_activecaption,col_inactivecaption;
 _rgba col_activecaption_right,col_inactivecaption_right;
 _rgba col_menu;
 _rgba col_window,col_windowframe;
 _rgba col_menutext,col_windowtext,col_captiontext;
 _rgba col_activeborder,col_inactiveborder;
 _rgba col_appworkspace;
 _rgba col_highlight,col_highlighttext;
 _rgba col_graytext,col_btntext,col_inactivecaptiontext;
 _rgba col_3ddkshadow,col_3dlight;
 _rgba col_infotext,col_infobk;
 _rgba col_desktop;
 _rgba col_3dface,col_3dshadow,col_3dhighlight,col_3dhilight;
 _rgba col_btnface;
 _rgba col_btnhilight;
 }
 _sysrgba;



 structure
 {
 _size caption_size;
 _size caption_button_size;
 _size caption_button_size_small;
 B caption_font[65];
 _size caption_icon_size;
 }
 _sysmetrics;


 structure
 {
 B windows[MAX_PATH];
 B system[MAX_PATH];
 B desktop[MAX_PATH];
 B start_menu[MAX_PATH];
 B start_up[MAX_PATH];
 B send_to[MAX_PATH];
 B programs[MAX_PATH];
 B program_files[MAX_PATH];
 B program_filesx86[MAX_PATH];
 B temp[MAX_PATH];
 B roaming[MAX_PATH];
 B program_data[MAX_PATH];
 B local_app_data[MAX_PATH];
 B favorites[MAX_PATH];
 B documents[MAX_PATH];
 B module[MAX_PATH];
 B current_dir[MAX_PATH];
 B temp_ie_a[MAX_PATH];
 B temp_ie_b[MAX_PATH];
 }
 _syspath;


 structure
 {
 H count;
 H key_off[256];
 H key_len[256];
 H key_hash[256];
 H val_off[256];
 H val_len[256];
 BP key_ptr[256];
 BP val_ptr[256];
 B buf[_32K];
 }
 _sysvars;




 structure
 {
 H version;
 B author[65];
 B copyright[65];
 B is_safemode;
 F cpu_mhz;
 H processor_count;
 B processor_brand[129];
 H os_hardware_page_size;
 D profiler_hz;
 H allocation_granularity;
 N show_state;
 B command_line[2049];
 B via_shortcut;
 B process_filename[_1K];
 B process_file[_1K];
 H process_id;
 H thread_id;
 H process_handle;
 H thread_handle;
 B class_name[257];
 HINSTANCE instance;
 HANDLE std_input_handle;
 HANDLE std_output_handle;
 HANDLE std_error_handle;
 B default_browser[_1K];
 B default_browser_cmd[_1K];
 H os_version[3];
 H os_platform;
 H os_service_pack[2];
 H os_flags;
 B os_string[129];
 N timezone_bias;
 B timezone_string[6];
 B is_dls;
 B is_std;
 N timezone_bias_total;
 B is_admin;
 B user_name[129];
 B computer_name[129];
 B fqdn_name[257];
 Q process_filebytes;
 _systime process_filedate;
 H language_id;
 B language_string[257];
 B is_restart_on_crash;
 H crash_msrunning_required;
 B comspec[257];
 B product_key[65];
 H product_key_hash;
 N wheel_lines;
 B is_console;
 }
 _sysinfo;


 structure
 {
 B is_plugged_in;
 B is_battery;
 B is_charging;
 F level;
 }
 _syspower;




 B aaSysRgbaGet                        (_sysrgba*sysrgba);
 B aaSysMetricsGet                     (_sysmetrics*sysmetrics);
 B aaSysPathGet                        (_syspath*syspath);
 B aaSysPathToString                   (_syspath*syspath,VP str);
 B aaSysVarsGet                        (_sysvars*sysvars);
 B aaSysVarsSet                        (VP name,VP fmt,...);
 B aaSysvarsExplode                    (_sysvars*sysvars,H index,_stringexplode*stringexplode);
 B aaSysVarsToString                   (_sysvars*sysvars,VP str);
 B aaSysInfoGet                        (_sysinfo*sysinfo);
 B aaSysInfoToString                   (_sysinfo*sysinfo,VP str);
 B aaSysPowerGet                       (_syspower*syspower);
 B aaSysBenchmark                      (B testnum,DP time);
 B aaSysRemoteSessionGet               (BP type);
 B aaSysTrayGet                        (HWND*wnd,_rect*rect);
 B aaSysFileIconGet                    (VP filename);
 B aaSysRestartOnCrashSet              (B state,H msrunreq);
 B aaSysCpuLoadRefresh                 (V);
 B aaSysShortCutCreate                 (VP filename,VP shortcutname,VP workingpath,VP iconfile,H iconindex);
 B aaSysUnInstallSet                   (CP applicationname,CP displayname,CP uninstallexepath);
 B aaSysUnInstallRemove                (CP applicationname);
 B aaSysStartupAppSet                  (VP applicationname,VP applicationexepath);
 B aaSysStartupAppGet                  (VP applicationname,VP applicationexepath);
 B aaSysStartupAppRemove               (VP applicationname);
 B aaSysFileAssociationSet             (CP extension,CP mimetype,CP appcmdline,CP deficon,CP description);
 B aaSysFileAssociationRemove          (CP extension);
 B aaSysContextMenuSet                 (CP extension,CP menuname,VP deficon,CP appcmdline);
 B aaSysContextMenuRemove              (CP extension,CP menuname);
 B aaSysSchemeHandlerSet               (VP scheme,VP deficon,VP appcmdline);
 B aaSysTweak                          (V);



/*-----------------------------------------------------------------------*/

 B aaResourceInfoGet                   (H num,HP bytes);
 B aaResourceToMemory                  (H num,HP bytes,PP mem);
 B aaResourceToFile                    (H num,HP bytes,VP filename);

/*-----------------------------------------------------------------------*/

 #define aa_DIGESTTYPE_Ripemd160       1
 #define aa_DIGESTTYPE_Md5             2
 #define aa_DIGESTTYPE_Sha1            3   // 20bytes/160bits/40chars
 #define aa_DIGESTTYPE_Crc32           4
 #define aa_DIGESTTYPE_Sha256          5

 structure
 {
 B type;
 H digest[8];
 }
 _digeststatus;


 structure
 {
 H handle;
 _digeststatus status;
 }
 _digestunit;


 B aaDigestCreate                      (HP handle,B type);
 B aaDigestDestroy                     (H handle);
 B aaDigestStatus                      (H handle,_digeststatus*digeststatus);
 B aaDigestWrite                       (H handle,H bytes,VP data,B finish,VP rdig,VP rdigstr);
 B aaDigestReset                       (H handle);
 B aaDigestToString                    (H handle,VP string);
 B aaDigestMac                         (H handle,H keylen,VP key,H bytes,VP data,VP rdig,VP rdigstr);

 B aaDigestQuick                       (B type,VP digstr,H bytes,VP data);
 B aaDigestQuickf                      (B type,VP digstr,VP fmt,...);

/*-----------------------------------------------------------------------*/

 #define aa_CRYPTOTYPE_Arc4            1
 #define aa_CRYPTOTYPE_Des1            2
 #define aa_CRYPTOTYPE_Des2            3
 #define aa_CRYPTOTYPE_Des3            4

 B aaCryptoCreate                      (HP handle,B type,B keylen,VP key);
 B aaCryptoDestroy                     (H handle);
 B aaCryptoTranscode                   (H handle,H bytes,VP data,B dir);

/*-----------------------------------------------------------------------*/


 E{
 JSON_TYPE_OBJOPEN=1,
 JSON_TYPE_ARRAYOPEN=2,
 JSON_TYPE_OBJCLOSE=3,
 JSON_TYPE_ARRAYCLOSE=4,
 JSON_TYPE_KEY=10,
 JSON_TYPE_STRING=11,
 JSON_TYPE_INT=12,
 JSON_TYPE_FLOAT=13,
 JSON_TYPE_FALSE=14,
 JSON_TYPE_TRUE=15,
 JSON_TYPE_NULL=16,
 JSON_TYPE_UNKNOWN=17
 };


 structure
 {
 B is_keyobj;
 B is_keyarray;
 B is_keyvalue;
 Z depth;
 Z open_line;
 Z close_line;
 Z parent_line;
 Z num_elements;
 Z element_index;
 Z next_element;
 Z prev_element;
 H bytes;
 B type;
 H off;
 H len;
 H hash;
 G val_int;
 D val_float;
 B val_bool;
 B user_data[32];
 }
 _jsonline;



 structure
 {
 B is_encode;
 B is_decoding;
 B decode_success;
 B decode_failure;
 H mem_bytes;
 BP mem;
 H lines;
 _jsonline*line;
 }
 _jsonstatus;



 structure
 {
 H handle;
 _jsonstatus status;
 }
 _jsonunit;


 B aaJsonCreate                        (HP handle,B encflag);
 B aaJsonDestroy                       (H handle);
 B aaJsonStatus                        (H handle,_jsonstatus*jsonstatus);
 B aaJsonReset                         (H handle,B encflag);
 B aaJsonAppendf                       (H handle,VP fmt,...);
 B aaJsonAppendBytes                   (H handle,H bytes,VP data);
 B aaJsonDecode                        (H handle);
 B aaJsonEncodeObjectOpen              (H handle);
 B aaJsonEncodeObjectClose             (H handle);
 B aaJsonEncodeArrayOpen               (H handle);
 B aaJsonEncodeArrayClose              (H handle);
 B aaJsonEncodeKey                     (H handle,VP fmt,...);
 B aaJsonEncodeString                  (H handle,VP fmt,...);
 B aaJsonEncodeFloat                   (H handle,D val);
 B aaJsonEncodeInt                     (H handle,G val);
 B aaJsonEncodeBool                    (H handle,B val);
 B aaJsonEncodeNull                    (H handle);
 B aaJsonEncodeKeyString               (H handle,VP key,VP fmt,...);
 B aaJsonEncodeKeyFloat                (H handle,VP key,D val);
 B aaJsonEncodeKeyInt                  (H handle,VP key,G val);
 B aaJsonEncodeKeyBool                 (H handle,VP key,B val);
 B aaJsonEncodeKeyNull                 (H handle,VP key);
 B aaJsonParserLineGet                 (H handle,H line,_jsonline*jsonline,VP str);
 B aaJsonParserKeyFind                 (H handle,HP line,H from,Z depth,VP val,VP fmt,...);
 B aaJsonDumpLineGet                   (H handle,HP line,H maxchars,VP str);




/*-----------------------------------------------------------------------*/


 structure
 {
 H instance_limit;
 H instance_count;
 H instance_bytes;
 H instance_initial;
 }
 _classstatus;



 B aaClassEmptyIdGet                   (BP id);
 B aaClassCreate                       (B id,H limit,H bytes,H initial,B(*Destructor)(H));
 B aaClassDestroy                      (B id);
 B aaClassStatus                       (B id,_classstatus*classstatus);
 B aaClassNew                          (B id,HP handle,PP mem);
 B aaClassDelete                       (B id,H handle);
 B aaClassCheck                        (B id,H handle,PP mem,BP isprotected);
 B aaClassIndexGet                     (B id,H handle,HP index);
 B aaClassProtect                      (B id,H handle,B state);
 B aaClassNext                         (B id,HP handle,PP mem);
 B aaClassGet                          (B id,H instanceindex,HP handle,PP mem);
 B aaClassIdGet                        (BP id,H handle);


/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 B is_exit;
 H id;
 H id_base;
 H stage;
 VP proc;
 H boost;
 H cycle;
 B ram[_8K];
 BP local_ram;
 BP shared_ram;
 }
 _task;


 B aaTaskNew                           (_task*task,H id,B(*proc)(_task*));
 B aaTaskDelete                        (_task*task);
 B aaTaskStageSet                      (_task*task,H stage);
 B aaTaskExit                          (_task*task);
 B aaTaskYield                         (_task*task);

/*-----------------------------------------------------------------------*/

/*
 if using taskgroups, never let a task call aaTaskDelete,
 just call aaTaskExit, and leave the taskgroup library
 to call aaTaskDelete
*/

 structure
 {
 H magic;
 _task*task;
 H id_base;
 H task_slots;
 H task_count;
 H task_pf;
 B shared_ram[_8K];
 }
 _taskgroup;

 B aaTaskGroupNew                      (_taskgroup*taskgroup,H idbase);
 B aaTaskGroupDelete                   (_taskgroup*taskgroup);
 B aaTaskGroupAdd                      (_taskgroup*taskgroup,HP id,H boost,B(*proc)(_task*));
 B aaTaskGroupYield                    (_taskgroup*taskgroup);

/*-----------------------------------------------------------------------*/

 B aaSettingsCreate                    (VP category);
 B aaSettingsDestroy                   (VP category);
 B aaSettingsRead                      (VP category,VP name,HP bytes,H maxbytes,VP data);
 B aaSettingsWrite                     (VP category,VP name,H bytes,VP data,B allowoverwrite);
 B aaSettingsDelete                    (VP category,VP name);
 B aaSettingsLengthGet                 (VP category,VP name,HP bytes);

 B aaSettingsEnumStart                 (VP category);
 B aaSettingsEnumStep                  (H index,VP name,HP bytes,VP data);
 B aaSettingsEnumStop                  (V);

 B aaSettingsDrop                      (VP name);
 B aaSettingsSave                      (VP name,H bytes,VP data);
 B aaSettingsLoad                      (VP name,HP bytes,H maxbytes,VP data);

/*-----------------------------------------------------------------------*/

 B aaClipBoardTextWritef               (B global,VP fmt,...);
 B aaClipBoardTextWrite                (B global,H chars,VP text);
 B aaClipBoardTextRead                 (B global,HP chars,H maxchars,VP text);
 B aaClipBoardDiscard                  (B global);
 B aaClipBoardTextPaste                (B global,VP fmt,...);
 B aaClipBoardFileSet                  (B global,VP filename);
 B aaClipBoardFileRead                 (B global,HP chars,H maxchars,VP text);

/*-----------------------------------------------------------------------*/

 #define aa_IPCLOGICSTATE_None         0
 #define aa_IPCLOGICSTATE_Lock         1
 #define aa_IPCLOGICSTATE_Release      2
 #define aa_IPCLOGICSTATE_Both         3


 structure
 {
 B is_incoming;
 B is_locked;
 B is_exited;
 Q session;
 H index;
 H bytes;
 H hog_level;
 BP ram;
 }
 _ipcstatus;

 structure
 {
 H handle;
 _ipcstatus status;
 }
 _ipcunit;


 B aaIpcCreate                         (HP handle,B incoming,H bytes,VP name);
 B aaIpcDestroy                        (H handle);
 B aaIpcStatus                         (H handle,_ipcstatus*ipcstatus,B logicstate);

/*-----------------------------------------------------------------------*/


 structure
 {
 B name[129];
 B is_active;
 H tid;
 HANDLE initial_handle;
 HANDLE desktop_handle;
 }
 _desktopstatus;


 structure
 {
 H handle;
 _desktopstatus status;
 }
 _desktopunit;


 B aaDesktopCreate                     (HP handle,VP fmt,...);
 B aaDesktopDestroy                    (H handle);
 B aaDesktopStatus                     (H handle,_desktopstatus*desktopstatus);
 B aaDesktopSwitch                     (H handle,B state);


/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 B is_sys_func;
 _aavector proc_data;
 H proc_count;
 B ret_ram[8];
 B ret;
 H proc_index;
 VP proc_func;
 H parm_count;
 H parm_bytes;
 B parm_ram[512];
 B user_ram[_1K];
 BP parm_ram_ptr;
 BP user_ram_ptr;
 }
 _vm;


 B aaVmNew                             (_vm*vm);
 B aaVmDelete                          (_vm*vm);
 B aaVmRamSwap                         (_vm*vm,BP parmram,BP userram);
 B aaVmProcGet                         (_vm*vm,H index,VP name,PP proc,HP proclen);
 B aaVmProcFind                        (_vm*vm,VP name,HP index,PP proc,HP proclen,B addifok);
 B aaVmProcAdd                         (_vm*vm,HP index,VP name,VP proc);
 B aaVmProcLoad                        (_vm*vm,H index);
 B aaVmParmPush                        (_vm*vm,H psize,VP parm);
 B aaVmParmPtr                         (_vm*vm,VP ptr);
 B aaVmParmPtrPtr                      (_vm*vm,PP ptr);
 B aaVmParmByte                        (_vm*vm,B parm);
 B aaVmParmWord                        (_vm*vm,W parm);
 B aaVmParmDword                       (_vm*vm,H parm);
 B aaVmParmQuad                        (_vm*vm,Q parm);
 B aaVmParmDouble                      (_vm*vm,D parm);
 B aaVmParmMulti                       (_vm*vm,VP fmt,...);
 B aaVmCall                            (_vm*vm);
 B aaVmCallEx                          (_vm*vm,VP name,VP fmt,...);
 B aaVmAaHeaderFunctions               (V);

/*-----------------------------------------------------------------------*/
 #ifdef __cplusplus
 }
 #endif
 #endif
/*-----------------------------------------------------------------------*/
