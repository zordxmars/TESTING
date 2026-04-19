__int64 __fastcall sub_36A5B8(_DWORD *a1, _QWORD *a2)
{
  int v9;
  const void *v6;
  void *v7;
  __int64 v8;
  size_t v15;
  char v14;

  v9 = (*(__int64 (__fastcall **)(_DWORD *))(*(_QWORD *)a1 + 88LL))(a1);

  if ( v9 >= (*(int (__fastcall **)(_QWORD *))(*a2 + 96LL))(a2) )
  {
    v8 = (*(__int64 (__fastcall **)(_DWORD *))(*(_QWORD *)a1 + 48LL))(a1);
    v7 = (void *)(v8 + (*(int (__fastcall **)(_DWORD *))(*(_QWORD *)a1 + 96LL))(a1));

    v6 = (const void *)(*(__int64 (__fastcall **)(_QWORD *))(*a2 + 48LL))(a2);
    v15 = (*(__int64 (__fastcall **)(_QWORD *))(*a2 + 96LL))(a2);

    memcpy(v7, v6, v15);

    a1[20] += (*(__int64 (__fastcall **)(_QWORD *))(*a2 + 56LL))(a2);
    a1[19] += (*(__int64 (__fastcall **)(_QWORD *))(*a2 + 96LL))(a2);

    (*(void (__fastcall **)(_QWORD *))(*a2 + 128LL))(a2);

    v14 = 1;
  }
  else
  {
    v14 = 0;
  }

  return v14 & 1;
}

__int64 sub_3A4CCC()
{
  return 0LL;
}

__int64 (*osub_4D47D8)(__int64, __int64, int, char);

__int64 hsub_4D47D8(__int64 a1, __int64 a2, int a3, char a4)
{
    switch (a3)
    {
        case 110100:
        case 110101:
        case 110102:
        case 40004:
            return 0; 
    }

    return osub_4D47D8 ? osub_4D47D8(a1,a2,a3,a4) : 0;
}

HOOK_LIB_NO_ORIG("libanogs.so","0x36A5B8",sub_36A5B8);//FLAG-DELAY 1
HOOK_LIB_NO_ORIG("libanogs.so","0x3A4CCC",sub_3A4CCC);//FLAG-DELAY 2