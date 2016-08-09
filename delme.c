
 #define SOUP_TEXT                     '1'
 #define SOUP_JS                       '2'
 #define SOUP_STYLE                    '3'
 #define SOUP_DOC                      '4'
 #define SOUP_OTAG                     '5'
 #define SOUP_CTAG                     '6'
 #define SOUP_STAG                     '7'
 #define SOUP_COMMENT                  '8'


 structure
 {
 H _count;
 H _index;
 H _type;
 BP tag;
 BP id,clas,method,action,name;
 BP type,value,src,href,lang;
 BP xmlns,title,link,rel,content;
 BP http_equiv,property,target;
 BP role,width,height,style;
 BP baseurl,maxlength,alt,dir;
 BP onclick,border,tabindex,selected;
 BP disabled,autocomplete,onload;
 BP onsubmit,jsaction,itemscope,itemtype;
 BP itemprop,content_type,sizes,ss_bar;
 BP white_space,nowrap,z_index,uc,accesskey;
 B _user_data[8];
 }
 _soupline;


 structure
 {
 H type;
 H line;
 H index;
 H off;
 H len;
 BP ptr;
 }
 _souptoken;


 structure
 {
 H magic;
 _cell token_ctx;
 _souptoken*token;
 _memoryunit src;
 H line_count;
 _soupline*line;
 }
 _soup;


 B aaSoupNew                           (_soup*soup,H bytes,VP buf);
 B aaSoupDelete                        (_soup*soup);
 B aaSoupLineGet                       (_soup*soup,H line,VP str);
 B aaSoupMatch                         (_soup*soup,H line,VP fmt,...);





 B aa_SoupExtendTokens                 (_soup*soup)
 {
 D chdiv;
 H chlisi,chsta,chadd;

 if(soup==NULL) { return RET_BADPARM; }
 chlisi=soup->token_ctx.slots;
 if(chlisi<0x0100) { chsta=0; chadd=0x0150; } else
 if(chlisi<0x0200) { chsta=1; chadd=0x0200; } else
 if(chlisi<0x0300) { chsta=2; chadd=0x0225; } else
                   { chsta=3; chadd=0x0275; }
 chdiv=(30+(chsta*10))/100.0;
 chadd=(chadd+chlisi)+(chlisi*chdiv);
 aaMemoryReAllocate((VP)&soup->token_ctx.mem,chadd*sizeof(_souptoken));
 soup->token_ctx.slots=chadd;
 //aaDebugf("chadd=%i rem=%i",chadd,soup->token_ctx.slots-soup->token_ctx.count);
 return RET_YES;
 }








 B aa_SoupAppendToken                  (_soup*soup,H type,H index,H off,H len,VP buf)
 {
 BP bp,src;
 _souptoken*stk;
 H sof;
 //B qc;
 H add;

 bp=(BP)buf;
 stk=(_souptoken*)soup->token_ctx.mem;
 src=(BP)soup->src.mem;
 sof=soup->src.used;
 aaMemoryCopy(&src[sof],len,&bp[off]);
 src[sof+len]=NULL_CHAR;
 add=0;

 if(type==SOUP_OTAG||type==SOUP_DOC||type==SOUP_STAG)
  {
  if(len>=2)
   {
   if(src[sof]==QUOTE_CHAR)
    {
    if(src[(sof+len)-1]==QUOTE_CHAR)
     {
     src[sof]=src[(sof+len)-1]=DQUOTE_CHAR;
     }
    }

   // comment out if you don't want quotes removed
   if(1)
    {
    if(src[sof]==DQUOTE_CHAR&&src[(sof+len)-1]==DQUOTE_CHAR)   {   add=1;   }
    }
   }
  }
 stk[soup->token_ctx.count].type=type;
 stk[soup->token_ctx.count].line=soup->line_count;
 stk[soup->token_ctx.count].index=index;
 stk[soup->token_ctx.count].off=sof;
 stk[soup->token_ctx.count].len=len;
 if(add)
  {
  stk[soup->token_ctx.count].len-=(add);
  stk[soup->token_ctx.count].off+=add;
  src[(sof+len)-(1)]=NULL_CHAR;
  stk[soup->token_ctx.count].ptr=&src[sof+add];
  }
 else
  {
  stk[soup->token_ctx.count].ptr=&src[sof];
  }
 sof+=(len+1);
 soup->src.used=sof;
 if(index==0)
  {
  soup->line[soup->line_count]._index=soup->token_ctx.count;
  }
 soup->token_ctx.count++;
 return RET_YES;
 }





 B aaSoupNew                           (_soup*soup,H bytes,VP buf)
 {
 H go,off,left,start,sub;
 H stage,len,used,wid,add;
 H flag,pos,ti,li,rem;
 H type,loc,j,lti,ltc;
 H line_tok_slots;
 BP bp;
 B ch,dh,eh;
 B in_script;
 B in_style;
 _parser ka,kb;
 _souptoken*stk;
 BP src;
 B qc;
 N which;
 //Q ms;

 #ifdef aa_VERSION
 aa_ZIAG(__FUNCTION__);
 #endif
 if(soup==NULL) { return RET_BADPARM; }

 //ms=aaMsRunning();
 aaMemoryFill(soup,sizeof(_soup),0);
 soup->magic=aaHPP(aaSoupNew);
 soup->token_ctx.slots=5000;
 soup->token_ctx.count=0;
 aaMemoryAllocate(&soup->token_ctx.mem,soup->token_ctx.slots*sizeof(_souptoken));
 soup->token=(_souptoken*)soup->token_ctx.mem;
 aaMemoryUnitAllocate(&soup->src,bytes+_2K);
 line_tok_slots=2000;
 aaMemoryAllocate((VP)&soup->line,line_tok_slots*sizeof(_soupline));

 bp=(BP)buf;
 off=0;
 left=bytes-off;
 start=off;
 stage=0;
 type=0;
 in_script=NO;
 in_style=NO;

 for(go=0;go<aaBillion(1);go++)
  {
  left=bytes-off;
  if(left==0) { break; }

  rem=line_tok_slots-soup->line_count;
  if(rem<100)
   {
   aaMemoryReAllocate((VP)&soup->line,(line_tok_slots+3000)*sizeof(_soupline));
   line_tok_slots+=3000;
   }
  rem=soup->token_ctx.slots-soup->token_ctx.count;
  if(rem<100)
   {
   aa_SoupExtendTokens(soup);
   rem=soup->token_ctx.slots-soup->token_ctx.count;
   }


  switch(stage)
   {
   case 0:
   stage=80;
   break;



   case 80:
   used=0;
   start=off;
   stage=100;
   break;


   case 100: // read in till we find '<'
   ch=bp[off+0];
   if(ch==CR_CHAR||ch==LF_CHAR||ch==SPACE_CHAR||ch==HTAB_CHAR)
    {
    if(used==0) { off++; stage=80; break;    }
    }
   used++;
   if(ch!='<') { off++;   break; }

   if(in_script==YES)
    {
    if(left>=9)
     {
     if(bp[off+1]=='/')
      {
      if(aaStringNICompare(&bp[off],"</script>",9,0)==YES) { stage=130; break; }
      }
     }
    off++;
    break;
    }
   if(in_style==YES)
    {
    if(left>=8)
     {
     if(bp[off+1]=='/')
      {
      if(aaStringNICompare(&bp[off],"</style>",8,0)==YES) { stage=130; break; }
      }
     }
    off++;
    break;
    }


   stage=130;
   break;




   case 130: // chars before '<' are text
   len=(off-start);
   if(len!=0)
    {
    if(in_script) {  aa_SoupAppendToken(soup,SOUP_JS,0,start,len,buf);     } else
    if(in_style)  {  aa_SoupAppendToken(soup,SOUP_STYLE,0,start,len,buf);  } else
                  {  aa_SoupAppendToken(soup,SOUP_TEXT,0,start,len,buf);   }
    soup->line[soup->line_count]._count=1;
    soup->line_count++;
    }
   stage=180;
   break;




   case 180: // handle '<'
   used=0;
   type=SOUP_OTAG;
   start=off;
   off++;
   stage=200;
   break;


   case 200: // is '!' after '<'
   ch=bp[off+0];
   if(ch=='!') { type=SOUP_DOC;  off++; stage=240; break; }
   if(ch=='/') { type=SOUP_CTAG;        stage=210; break; }
   stage=210;
   break;



   case 210: // read all till '>'
   ch=bp[off+0];
   if(ch!='>') { off++; break; }
   if(bp[off-1]=='/')
    {
    if(type!=SOUP_OTAG) oof;
    type=SOUP_STAG;
    }
   stage=220;
   break;


   case 220:
   ti=0;
   stage=230;
   break;




   case 230: // tag done
   len=(off-start)+1;

   if(type==SOUP_COMMENT)
    {
    aa_SoupAppendToken(soup,type,0,start,len,buf);
    off++;
    soup->line[soup->line_count]._count=1;
    soup->line_count++;
    stage=80;
    break;
    }

   if(in_script==YES&&type==SOUP_CTAG)
    {
    if(bp[start+2]=='s'||bp[start+2]=='S')
     {
     if(aaStringNICompare(&bp[start],"</script>",9,0)==YES) { in_script=NO;  }
     }
    }
   else
   if(in_script==NO&&type==SOUP_OTAG)
    {
    if(bp[start+1]=='s'||bp[start+1]=='S')
     {
     if(aaStringNICompare(&bp[start],"<script",7,0)==YES)  {  in_script=YES;   }
     }
    }

   if(in_style==YES&&type==SOUP_CTAG)
    {
    if(bp[start+2]=='s'||bp[start+2]=='S')
     {
     if(aaStringNICompare(&bp[start],"</style>",8,0)==YES) { in_style=NO;  }
     }
    }
   else
   if(in_style==NO&&type==SOUP_OTAG)
    {
    if(bp[start+1]=='s'||bp[start+1]=='S')
     {
     if(aaStringNICompare(&bp[start],"<style",6,0)==YES)  {  in_style=YES;   }
     }
    }



   aaParserInit(&ka,&bp[start],len);
   aaParserCopy(&kb,&ka,NO);
   sub=0;
   while(1)
    {
    if(sub==F32)     { break; }
    if(ka.to_end<1)  { break; }
    switch(sub)
     {
     case 0:
     if(aaCharIsVisible(ka.ch)!=YES) { aaParserSeek(&ka,1); break; }
     if(ka.ch==QUOTE_CHAR)           { aaParserStackPush(&ka); aaParserSeek(&ka,1); sub=20; break; }
     if(ka.ch==DQUOTE_CHAR)          { aaParserStackPush(&ka); aaParserSeek(&ka,1); sub=30; break; }
     if(ka.ch=='=')                  {                         aaParserSeek(&ka,1);         break; }
     if(aaCharIsAlphaNum(ka.ch)||ka.ch=='_'||ka.ch=='@')
      {
      aaParserStackPush(&ka);
      aaParserSeek(&ka,1);
      sub=10;
      break;
      }
     aaParserSeek(&ka,1);
     break;



     case 10:
     if(aaCharIsVisible(ka.ch))
      {
      while(1)
       {
       flag=1;
       if(aaCharIsAlphaNum(ka.ch)) { break; }
       if(ka.ch=='=') { flag=0; break; }
       if(ka.ch=='>') { flag=0; break; }
       break;
       }
      if(flag==1) { aaParserSeek(&ka,1); break; }
      }
     pos=ka.offset;
     aaParserStackPop(&ka);
     aa_SoupAppendToken(soup,type,ti,start+ka.offset,pos-ka.offset,buf);
     ti++;
     aaParserSeek(&ka,pos-ka.offset);
     sub=0;
     break;



     case 20:
     case 30:
     if(sub==20&&ka.ch!=QUOTE_CHAR)  { aaParserSeek(&ka,1); break; }
     if(sub==30&&ka.ch!=DQUOTE_CHAR) { aaParserSeek(&ka,1); break; }
     pos=ka.offset;
     aaParserStackPop(&ka);
     aa_SoupAppendToken(soup,type,ti,start+ka.offset,(pos-ka.offset)+1,buf);
     wid=(pos-ka.offset)+1;
     if(wid>=3)
      {
      qc=bp[start+ka.offset];
      aaStringFindCharVisible(&bp[start+ka.offset],wid,&loc,YES,1,YES);
      if(loc!=1)
       {
       stk=(_souptoken*)soup->token_ctx.mem;
       add=loc-1;
       stk[soup->token_ctx.count-1].off+=add;
       stk[soup->token_ctx.count-1].len-=add;
       stk[soup->token_ctx.count-1].ptr=&soup->src.mem[stk[soup->token_ctx.count-1].off];
       stk[soup->token_ctx.count-1].ptr[0]=qc;
       }
      else
       {
       loc=0;
       }
      aaStringFindCharVisible(&bp[start+ka.offset],wid,&loc,YES,1,NO);
      if((wid-loc)!=2)
       {
       loc=(wid-loc)-2;
       stk=(_souptoken*)soup->token_ctx.mem;
       stk[soup->token_ctx.count-1].ptr=&soup->src.mem[stk[soup->token_ctx.count-1].off];
       stk[soup->token_ctx.count-1].len-=(loc+0);
       stk[soup->token_ctx.count-1].ptr[stk[soup->token_ctx.count-1].len-1]=qc;
       stk[soup->token_ctx.count-1].ptr[stk[soup->token_ctx.count-1].len+0]=NULL_CHAR;
       }
      }
     ti++;
     aaParserSeek(&ka,(pos-ka.offset)+1);
     sub=0;
     break;
     }
    }
   off++;
   soup->line[soup->line_count]._count=ti;
   soup->line_count++;
   stage=80;
   break;



   case 240: // handle <!
   dh=0;
   ch=bp[off+0];
   if(left>=1) { dh=bp[off+1]; }
   if(ch=='-'&&dh=='-') { type=SOUP_COMMENT; off+=2; stage=250; break; }
   if(ch!='>')          {                    off+=1; break; }
   stage=220;
   break;


   case 250:
   dh=eh=0;
   ch=bp[off+0];
   if(left>=2) { eh=bp[off+2]; }
   if(left>=1) { dh=bp[off+1]; }
   if(ch=='-'&&dh=='-'&&eh=='>') {  off+=2; stage=220; break; }
   off++;
   break;
   }
  }

 stk=(_souptoken*)soup->token_ctx.mem;
 src=(BP)&soup->src.mem[0];
 for(ti=0;ti<soup->token_ctx.count;ti++)
  {
  stk[ti].ptr=&src[stk[ti].off];
  }
 soup->token=(_souptoken*)soup->token_ctx.mem;

 aaLeu;
 for(li=0;li<soup->line_count;li++)
  {
  ltc=soup->line[li]._count;
  lti=soup->line[li]._index;
  soup->line[li]._type=stk[lti].type;
  soup->line[li].tag=stk[lti].ptr;
  if(stk[lti].type<SOUP_OTAG) { continue; }
  if(stk[lti].type>SOUP_STAG) { continue; }
  if(ltc<2) { continue; }
  for(j=0;j<ltc;j++)
   {
   qc=stk[lti+j].ptr[0];
   //if(qc==QUOTE_CHAR||qc==DQUOTE_CHAR) { continue; }
   if(qc==DQUOTE_CHAR) { continue; }
   aaStringIsIString(stk[lti+j].ptr,&which,
                      "id","class","method","action","name","type","value", // 6
                      "src","href","lang","xmlns","title","link","rel", // 13
                      "content","http-equiv","property","target","role", // 18
                      "width","height","style","baseurl","maxlength","alt", // 24
                      "dir","onclick","border","tabindex","selected","disabled", //30
                      "autocomplete","onload","onsubmit","jsaction", //34
                      "itemscope","itemtype","itemprop","Content-Type","sizes", //39
                      "ss-bar","white-space","nowrap","z-indeX","uc","accesskey",
                      NULL);
   if(which==-1) { continue; }
   switch(which)
    {
    case 0: soup->line[li].id=stk[lti+j+1].ptr; break;
    case 1: soup->line[li].clas=stk[lti+j+1].ptr; break;
    case 2: soup->line[li].method=stk[lti+j+1].ptr; break;
    case 3: soup->line[li].action=stk[lti+j+1].ptr; break;
    case 4:     soup->line[li].name=stk[lti+j+1].ptr; break;
    case 5:     soup->line[li].type=stk[lti+j+1].ptr; break;
    case 6:     soup->line[li].value=stk[lti+j+1].ptr; break;
    case 7:     soup->line[li].src=stk[lti+j+1].ptr; break;
    case 8:     soup->line[li].href=stk[lti+j+1].ptr; break;
    case 9:     soup->line[li].lang=stk[lti+j+1].ptr; break;
    case 10:     soup->line[li].xmlns=stk[lti+j+1].ptr; break;
    case 11:     soup->line[li].title=stk[lti+j+1].ptr; break;
    case 12:     soup->line[li].link=stk[lti+j+1].ptr; break;
    case 13:     soup->line[li].rel=stk[lti+j+1].ptr; break;
    case 14:     soup->line[li].content=stk[lti+j+1].ptr; break;
    case 15:     soup->line[li].http_equiv=stk[lti+j+1].ptr; break;
    case 16:     soup->line[li].property=stk[lti+j+1].ptr; break;
    case 17:     soup->line[li].target=stk[lti+j+1].ptr; break;
    case 18:     soup->line[li].role=stk[lti+j+1].ptr; break;
    case 19:     soup->line[li].width=stk[lti+j+1].ptr; break;
    case 20:     soup->line[li].height=stk[lti+j+1].ptr; break;
    case 21:     soup->line[li].style=stk[lti+j+1].ptr; break;
    case 22:     soup->line[li].baseurl=stk[lti+j+1].ptr; break;
    case 23:     soup->line[li].maxlength=stk[lti+j+1].ptr; break;
    case 24:     soup->line[li].alt=stk[lti+j+1].ptr; break;
    case 25:     soup->line[li].dir=stk[lti+j+1].ptr; break;
    case 26:     soup->line[li].onclick=stk[lti+j+1].ptr; break;
    case 27:     soup->line[li].border=stk[lti+j+1].ptr; break;
    case 28:     soup->line[li].tabindex=stk[lti+j+1].ptr; break;
    case 29:     soup->line[li].selected=stk[lti+j+1].ptr; break;
    case 30:     soup->line[li].disabled=stk[lti+j+1].ptr; break;
    case 31:     soup->line[li].autocomplete=stk[lti+j+1].ptr; break;
    case 32:     soup->line[li].onload=stk[lti+j+1].ptr; break;
    case 33:     soup->line[li].onsubmit=stk[lti+j+1].ptr; break;
    case 34:     soup->line[li].jsaction=stk[lti+j+1].ptr; break;
    case 35:     soup->line[li].itemscope=stk[lti+j+1].ptr; break;
    case 36:     soup->line[li].itemtype=stk[lti+j+1].ptr; break;
    case 37:     soup->line[li].itemprop=stk[lti+j+1].ptr; break;
    case 38:     soup->line[li].type=stk[lti+j+1].ptr; break;
    case 39:     soup->line[li].sizes=stk[lti+j+1].ptr; break;
    case 40:     soup->line[li].ss_bar=stk[lti+j+1].ptr; break;
    case 41:     soup->line[li].white_space=stk[lti+j+1].ptr; break;
    case 42:     soup->line[li].nowrap=stk[lti+j+1].ptr; break;
    case 43:     soup->line[li].z_index=stk[lti+j+1].ptr; break;
    case 44:     soup->line[li].uc=stk[lti+j+1].ptr; break;
    case 45:     soup->line[li].accesskey=stk[lti+j+1].ptr; break;
    case 46:     soup->line[li].alt=stk[lti+j+1].ptr; break;
    }
   }
  }
 //aaDebugf("took %I64d",aaMsRunning()-ms);
 return RET_YES;
 }








 B aaSoupDelete                        (_soup*soup)
 {
 #ifdef aa_VERSION
 aa_ZIAG(__FUNCTION__);
 #endif

 if(soup==NULL) { return RET_BADPARM; }
 if(soup->magic!=aaHPP(aaSoupNew)) { return RET_NOTINITIALIZED; }
 if(soup->src.bytes) { aaMemoryUnitRelease(&soup->src); }
 if(soup->token_ctx.slots) { aaMemoryRelease(soup->token_ctx.mem); }
 if(soup->line)  { aaMemoryRelease(soup->line); }
 aaMemoryFill(soup,sizeof(_soup),0);
 return RET_YES;
 }






 B aaSoupLineGet                       (_soup*soup,H line,VP str)
 {
 H t;
 B qc;

 #ifdef aa_VERSION
 aa_ZIAG(__FUNCTION__);
 #endif

 if(soup==NULL) { return RET_BADPARM; }
 if(soup->magic!=aaHPP(aaSoupNew)) { return RET_NOTINITIALIZED; }
 if(str) { aaStringNull(str); }
 if(line>=soup->line_count) { return RET_BOUNDS; }
 if(str!=NULL)
  {
  if(soup->line[line]._type==SOUP_OTAG) { aaStringAppendf(str,"<");   }
  else
  if(soup->line[line]._type==SOUP_STAG) { aaStringAppendf(str,"<");   }
  else
  if(soup->line[line]._type==SOUP_CTAG) { aaStringAppendf(str,"</");  }
  for(t=0;t<soup->line[line]._count;t++)
   {
   if(t!=0&&((t%2)==1)) {    aaStringAppendf(str," "); }
   aaStringAppendf(str,"%s",soup->token[soup->line[line]._index+t].ptr);
   if(t>=1&&((t%2)==1))
    {
    qc=soup->token[soup->line[line]._index+t].ptr[0];
    //if(qc!=QUOTE_CHAR&&qc!=DQUOTE_CHAR)
    if(qc!=DQUOTE_CHAR)
     {
     aaStringAppendf(str,"=");
     }
    }
   }
  if(soup->line[line]._type==SOUP_OTAG) { aaStringAppendf(str,">");   }
  else
  if(soup->line[line]._type==SOUP_STAG) { aaStringAppendf(str,"/>");  }
  else
  if(soup->line[line]._type==SOUP_CTAG) { aaStringAppendf(str,">");   }
  }
 return RET_YES;
 }




 B aaSoupMatch                         (_soup*soup,H line,VP fmt,...)
 {
 H i,sl;
 H len,fin,cnt;
 B txt[_4K];
 B str[_4K];
 va_list argptr;
 _parser pa;
 B tok[16][33];
 B typ[16];

 aaFmt(fmt,argptr,str);
 #ifdef aa_VERSION
 aa_ZIAG(__FUNCTION__);
 #endif

 if(soup==NULL) { return RET_BADPARM; }
 if(soup->magic!=aaHPP(aaSoupNew)) { return RET_NOTINITIALIZED; }
 aaParserInit(&pa,str,0);
 fin=NO;
 cnt=0;
 while(1)
  {
  if(aaParserSeekToVisibleChar(&pa,YES)!=YES) { break; }
  aaParserStackPush(&pa);
  if(aaParserSeekToCharList(&pa,",",YES)!=YES) { fin=YES; }
  if(aaParserStackString(&pa,&len,sizeof(txt),txt,YES)!=YES) { break; }
  aaStringCopyfLen(tok[cnt],&sl,"%s",txt);
  typ[cnt]=0;
  if(sl>=1&&tok[cnt][0]=='<')     {   typ[cnt]=aaBitSet(typ[cnt],0);   }
  if(sl>=2&&tok[cnt][1]=='/')     {   typ[cnt]=aaBitSet(typ[cnt],1);   }
  if(sl>=2&&tok[cnt][sl-1]=='>')  {   typ[cnt]=aaBitSet(typ[cnt],2);   }
  if(sl>=3&&tok[cnt][sl-2]=='/')  {   typ[cnt]=aaBitSet(typ[cnt],3);   }
  while(1)
   {
   if(typ[cnt]==(1+4))   { aaStringDeleteChars(tok[cnt],0,0,1); aaStringLastCharSet(tok[cnt],0,0,1); break; }
   if(typ[cnt]==(1+2+4)) { aaStringDeleteChars(tok[cnt],0,0,2); aaStringLastCharSet(tok[cnt],0,0,1); break; }
   if(typ[cnt]==(1+4+8)) { aaStringDeleteChars(tok[cnt],0,0,1); aaStringLastCharSet(tok[cnt],0,0,1); aaStringLastCharSet(tok[cnt],0,0,1); break; }
   break;
   }
  cnt++;
  if(fin) { break; }
  aaParserSeek(&pa,1);
  }

 for(i=0;i<cnt;i++)
  {
  if(typ[i]==(1+4))
   {
   if(soup->line[line+i]._type!=SOUP_OTAG) { return RET_NO; }
   if(tok[i][0]=='*'&&tok[i][1]==NULL_CHAR) { continue; }
   if(aaStringICompare(tok[i],soup->line[line+i].tag,0)==YES) { continue; }
   }
  if(typ[i]==(1+2+4))
   {
   if(soup->line[line+i]._type!=SOUP_CTAG) { return RET_NO; }
   if(tok[i][0]=='*'&&tok[i][1]==NULL_CHAR) { continue; }
   if(aaStringICompare(tok[i],soup->line[line+i].tag,0)==YES) { continue; }
   }
  if(typ[i]==(1+4+8))
   {
   if(soup->line[line+i]._type!=SOUP_STAG) { return RET_NO; }
   if(tok[i][0]=='*'&&tok[i][1]==NULL_CHAR) { continue; }
   if(aaStringICompare(tok[i],soup->line[line+i].tag,0)==YES) { continue; }
   }
  if(typ[i]==0)
   {
   if(tok[i][0]=='*'&&tok[i][1]==NULL_CHAR) { continue; }
   if(aaStringICompare(tok[i],"text",0)==YES)
    {
    if(soup->line[line+i]._type!=SOUP_TEXT) { return RET_NO; }
    }
   continue;
   }
  return RET_NO;
  }
 return RET_YES;
 }
