
void __cdecl ERR(char *param_1)

{
  if ((DAT_00bc2128 == (FILE *)0x0) &&
     (DAT_00bc2128 = _fopen("errorlog.txt","w"), DAT_00bc2128 == (FILE *)0x0)) {
    return;
  }
  FID_conflict:_vfprintf(DAT_00bc2128,param_1,&stack0x00000008);
  _fprintf(DAT_00bc2128,"\n");
  _fflush(DAT_00bc2128);
  return;
}

