#include <jni.h>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <unwind.h>
#include <dlfcn.h>
#include <libgen.h>
#include <stdint.h>
#include <cstring>
#include <functional>
#include <sys/stat.h>
#include <fcntl.h>
#include <android/log.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include "Main/Tools.h" 
#include "Main/Logger.h"
#include "Main/oxorany.h"
#include "Main/obfuscate.h"
#include "Main/Utils.h"
#include "Main/KittyMemory/MemoryPatch.h"
#define targetLibName oxorany("libUE4.so")
#define targetLibName oxorany("libhdmpve.so")
#define targetLibName oxorany("libAntsVoice.so")
#define targetLibName oxorany("libanogs.so")
#include "Main/Macros.h"
#include "Main/Dobby/Dobby.h"
class _BYTE;
class _QWORD;
class _DWORD;
class _WORD;
#define _QWORD long
#define _DWORD long
#define _BYTE long
#define _WORD long
#define HOOK_LIB
#define anogsLibrary oxorany("libanogs.so")
#define ue4Library oxorany("libUE4.so")
typedef long long int64; 
typedef short int16;

unsigned int libanogsSize  = 0;
unsigned int libUE4Size  = 0;
DWORD UE4Base = 0;
#define HOOK
uintptr_t UE5 = 0;
uintptr_t ANOGS = 0;
uintptr_t saved_x8 = 0;
#define ARM64_SYSREG(reg0, reg1, reg2, reg3, op) (((reg0) & 0x1F) | (((reg1) & 0x1F) << 5) | (((reg2) & 0x7) << 10) | (((reg3) & 0xF) << 16) | (((op) & 0x7) << 20))

#ifdef __aarch64__
uint64_t _ReadStatusReg(uint64_t reg) {
    return 0;
}
#endif
////================================[#DEFINE START]================================//
char *Offset;
#define ret_zero
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD __int64
#define _OWORD uint64_t
#define _QWORD uint64_t
#define _BOOL8 uint64_t
#define _QWORD uint64_t
#define targetLibName oxorany("libUE4.so")
#define targetLibName oxorany("libanogs.so")
#define targetLibName oxorany("libanort.so")
#define targetLibName oxorany("libhdmpve.so")
#define targetLibName ("libTBlueData.so")
#define targetLibName ("libRoosterNN.so")
#define targetLibName ("libhdmpve.so")
#define targetLibName ("libCrashKit.so")
#define targetLibName ("libITOP.so")
#define targetLibName ("libAntsVoice.so")
#define targetLibName ("libanort.so")
#define word_DA09BD0
#define waitpid
#define asc_39C9BD9
#define off_D6D7F60
#define unk_38D9882
#define qword_50CBD58
#define JUMPOUT
#define xmmword
#define LODWORD
#define sub_2FF548
#define __clz
#define S2O
#define UE4
#define unk_38D9882
#define _WriteStatusReg
#define HIWORD
#include <android/log.h>


////================================[DWORD START]================================//
DWORD TBlueBase = 0;
DWORD AntBase = 0;
DWORD BufferBase = 0;
DWORD HdmpveBase = 0;
DWORD roosterBase = 0;
DWORD roosterSize = 0;
DWORD roosterAlloc = 0;
DWORD EGLBase = 0;
DWORD EGLSize = 0;
DWORD EGLAlloc = 0;
DWORD libEgl_base = 0;
DWORD libcBase = 0;
DWORD libcSize = 0;
DWORD libcAlloc = 0;
DWORD libanogsBase = 0;
DWORD libTBlueDataBase = 0;
DWORD libUE4Base = 0;
DWORD libanortBase = 0;
DWORD libEGLBase = 0;
DWORD libanogsAlloc = 0;
DWORD libUE4Alloc = 0;
DWORD libEGLAlloc = 0;
//DWORD libanogsSize = 0; //0x51CCBC;  //3.9.0
//DWORD libUE4Size = 0;//0xBFDD568;	//3.9.0
DWORD NewBase = 0;
//uintptr_t ANOGS;

////================================[GETLIBRARYSIZE START]================================//
size_t getLibrarySize(const char *libraryName)
{
    FILE *mapsFile = fopen("/proc/self/maps", "r");
    if (mapsFile == nullptr)
    {
        return 0;
    }

    char line[256];
    size_t size = 0;
    uintptr_t startAddr = 0, endAddr = 0;
    while (fgets(line, sizeof(line), mapsFile))
    {
        if (strstr(line, libraryName))
        {
            sscanf(line, "%lx-%lx", &startAddr, &endAddr);
            size = endAddr - startAddr;
            break;
        }
    }

    fclose(mapsFile);
    return size;
}



size_t ApplySkins(char *s)
{
	static const std::unordered_map<std::string, std::string> replacements = 
	{
	/*
        {"403003", "1406971"},
        {"1405385", "1407625"}, // Sandsylph
        {"1405269", "1407625"}, // Winter Highness Set
        {"404151", "1407625"},  // BAPE Sta Mid
        {"1405884", "1406327"}, // BAPE Sta Mid
        {"1405113", "1407387"}, // The Reaper's End Set
        {"1405548", "1407366"}, // Wind Spirit Jia'er
        {"403006", "1405207"},  // Ryan Set
        {"403020", "1405628"},  // Golden Pharaoh Divine Set
        {"403032", "1407470"},  // Carefree Exiled Immortal
        {"403224", "1406891"},  // Soul-Eater Underworld King
        {"403160", "1406386"},  // Zero Combat Suit
        {"403002", "1407387"},  // Phantom Night Shinigami Set
        {"403198", "1400687"},  // Halloween Mummy 
        {"403124", "1406387"},  // Asuka
        {"1404008", "1405623"}, // Underworld Traveler Set
        {"403193", "1407103"},  // Dawn Flora Divine Set
        {"403192", "1407219"},  // Holy Flame Igni Divine Set
        {"403153", "1407453"},  // Arabian Traveler
        {"1400043", "1405163"}, // Ruins Hunter
        {"403162", "1407277"},  // Flame Ancient God
        {"404056", "1404191"},  // Trendy Walker Pants
        {"403177", "1407079"},  // Blissful Fool
        {"1400100", "1400782"}, // Ice Crystal Core
        {"403195", "1400569"},  // BAPE MIX CAMO HOODIE
        {"403163", "1404049"},  // BAPE X PUBGM Camouflage Shark Jacket
        {"404001", "1404050"},  // BAPE X PUBGM Camouflage Pants
        {"404049", "1404002"},  // BAPE City Camo Pants
        {"404026", "1400650"},  // BAPE MIX CAMO SHORTS
        {"405053", "1404051"},  // BAPE X PUBGM Camouflage Shoes
        {"405022", "1404003"},  // BAPE Sta Mid
        {"402046", "474031"},   // BAPE Sta Mid

        // Assault Rifles
{"10100400", "1101004086"}, //wizard roar - M416 (Lv. 7)
{"10100600", "1101006085"}, // Nyxen Rose - AUG (Lv. 8)
{"10100100", "1101001265"}, // AKM - Sandspring Dominion (Lv. 8)
{"10100200", "1101002081"}, // M16A4 - Skeletal Core (Lv. 7)
{"10100300", "1101003219"}, // SCAR-L - Soulbound Prism (Lv. 7)
{"10100800", "1101008163"}, // M762 - Soulspecter Shredder (Lv. 7)
{"10100500", "1101005098"}, // Groza - Burning Godzilla (Lv. 7)
{"10100700", "1101007062"}, // QBZ - Fatal Foil (Lv. 7)
{"10110200", "1101102025"}, // ACE32 - Mystic Kraken (Lv. 8)
{"10110000", "1101100012"}, // FAMAS - Origin Lumen (Lv. 8)

{"10200100", "1102001130"}, // UZI - Chained Inferno (Lv. 7)
{"10200200", "1102002424"}, // UMP45 - Void Souleater (Lv. 7)
{"10200300", "1102003100"}, // Vector - Absolute Zero (Lv. 7)
{"10200400", "1102004018"}, // Thompson - Candy Cane (Lv. 5)
{"10200500", "1102005064"}, // PP-19 Bizon - Spectral Byte (Lv. 7)
{"10210500", "1102105012"}, // P90 - Devious Cybercat (Lv. 7)
{"10501000", "1105010019"}, // MG3 - Sky Huntress (Lv. 7)
{"10500200", "1105002091"}, // DP-28 - Bloodbane Parasite (Lv. 8)
{"10500100", "1105001069"}, // M249 - Malus Majesty (Lv. 7)

{"10300100", "1103001202"}, // Frostbite Fang - Kar98K (Lv. 8)
{"10300200", "1103002136"}, // M24 - Voidwave Trigger (Lv. 7)
{"10300700", "1103007028"}, // Mk14 - Drakreign (Lv. 8)
{"10300300", "1103003079"}, // AWM - Valor's Requiem (Lv. 7)
{"10301200", "1103012031"}, // AMR - Silent Departed (Lv. 7)
{"10300500", "1103005037"}, // VSS - Feathered Silence
{"10300400", "1103004058"}, // SKS - Snowcapped Berg (Lv. 5)
{"10400300", "1104003037"}, // S12K - Atomic Trigger (Lv. 5)
{"10400400", "1104004041"}, // DBS - Sandsinger (Lv. 5)
{"10400100", "1104001035"}, // S686 - Lethal Venom (Lv. 5)
{"10400200", "1104002022"}, // S1897 - Twilight Hunt (Lv. 5)
{"10410200", "1104102004"}, // NS2000 - Rustborn Strider (Lv. 3)
{"10410100", "1104101001"}, // M1014 - Deadly Carnival

        
        {"10800400", "1108004027"}, // Pan - Glacier
        
        // Backpacks
        {"501001", "1501001220"},  // Backpack (Lv. 1)
        {"501002", "1501002220"},  // Backpack (Lv. 2)
        {"501003", "1501003220"},  // Backpack (Lv. 3)
		
		
        {"501004", "1501001220"},  // Backpack (Lv. 1)
        {"501005", "1501002220"},  // Backpack (Lv. 2)
        {"501006", "1501003220"},  // Backpack (Lv. 3)
		
		
        {"501007", "1501001220"},  // Backpack (Lv. 1)
        {"501008", "1501002220"},  // Backpack (Lv. 2)
        {"501009", "1501003220"},  // Backpack (Lv. 3)
		
		
        {"5010010", "1501001220"},  // Backpack (Lv. 1)
        {"5010011", "1501002220"},  // Backpack (Lv. 2)
        {"5010012", "1501003220"},  // Backpack (Lv. 3)
		
		
        {"502101","1502001014"}, //helmet v1 
        {"502002","1502002014"}, //helmet v2
        {"502003","1502003014"}, //helmet v3
		
		
        {"502001","1502001014"}, //Millitary helmet v1 
        {"502002","1502002014"}, //Millitary helmet v2
        {"502003","1502003014"}, //Millitary helmet v3
		
		
        {"502004","1502002014"}, // helmet v2
        {"502005","1502003014"}, // helmet v3
		
        // Vehicles
        {"1961001", "1903193"},    // Coupe RB
        {"1953001", "1953008"},    // Monster Truck
        {"1908001", "1908094"},    // UAZ
        {"1903001", "1903075"},    // Dacia
        {"1903002", "1903075"},    // Dacia (Orange)
        {"1903003", "1903075"},    // Dacia (White)
        {"1915004", "1915008"},    // Mirado
        {"1916001", "1916006"},    // Rony
        {"1532907", "1901089"},    // Motorcycle

        // Buggies
        {"1907001", "1907059"},
        {"1907002", "1907059"},
        {"1907003", "1907059"},
        {"1907004", "1907059"},
        {"1907005", "1907059"},
        {"1907006", "1907059"},
        {"401993","1400563" }, // Face New Face 1
        {"40605001","40605012"}, // Hair Twintails
        {"40605009","40605010"}, // New Hairstyles 1
        {"2001001","30394"}, // Conqueror Frame
        {"2200101", "12212201"},  // Emote - Shadow Assassin
        {"2200301", "12209901"},  // Emote - Touch of Death
        {"2200201", "12220028"},  // Emote - Thank You
        {"703001", "1401620"}, //pharoah parachute
		{"1801101", "1801227"}, //pharoah parachute
		
        {"202408052", "202408061"} // Auto Showroom  Lobby Theme 
        */
        
        //{"61920001","1101004046"} //Elimination Counter (M416)
    };
    auto it = replacements.find(s);
    if (it != replacements.end()) 
	{
        strcpy(s, it->second.c_str());
        return strlen(s);
    }
    return strlen(s);
}






__int64 TRIZE()
{
return 1LL;
}

__int64 __fastcall (*osub_2ECE70)( unsigned int a1, unsigned int a2, unsigned int *a3, unsigned int *a4, unsigned int *a5, __int64 *a6, __int64 *a7, __int64 a8, __int64 a9);
__int64 __fastcall hsub_2ECE70( unsigned int a1, unsigned int a2, unsigned int *a3, unsigned int *a4, unsigned int *a5, __int64 *a6, __int64 *a7, __int64 a8, __int64 a9) 
 
{
    if (!a3 || !a4 || !a5)
        return 0LL;
    if (a1 == 0x1337)
      {
        *a4 = 1;
        *a5 = 1;
        if (a6) *a6 = 0;
        if (a7) *a7 = 0;
        return 0LL;
    }
    return (a1, a2, a3, a4, a5, a6, a7, a8, a9);
}



void* (*old_Upload)(void* a1);
void* hook_Upload(void* a1) {
 if (!a1) return nullptr;

 // --- ACCURACY LOW SECTION ---
 *(int*)((uintptr_t)a1 + 768) = 0; // HitBuffer_ArrayNum = 0
 *(int*)((uintptr_t)a1 + 776) = 0; // PendingHitCount = 0

 // --- CRC BLOCK SECTION ---
 *(uint32_t*)((uintptr_t)a1 + 792) = 0; // Stored CRC reset

 // --- ANTI-CHEAT (TSS) BYPASS SECTION ---
 *(bool*)((uintptr_t)a1 + 484) = false; // bEnableTssSdkAntiData
 *(bool*)((uintptr_t)a1 + 485) = false; // bEnableTssSdkAntiDataFilter
 *(bool*)((uintptr_t)a1 + 486) = true; // bEnableTssSdkAntiDataFilterNew

 // --- FLAG CLEANER ---
 *(int*)((uintptr_t)a1 + 784) = 1; // UploadStatusFlags = Safe/Empty
 return old_Upload(a1);
}


__int64 __fastcall (*osub_335D1C)(__int64 a1, __int64 a2, __int64 a3);
__int64 __fastcall hsub_335D1C(__int64 a1, __int64 a2, __int64 a3) {

    if (a1 != 0) {
     
        __int64 data_ctx = *(__int64 *)(a1 + 64);
        
        if (data_ctx != 0) {
    
            int type = *(int *)(data_ctx + 8); 

            if (type == 2) {
      
                memset((void *)(data_ctx + 16), 0, 40); 
      
                *(__int64 *)(data_ctx + 16) = 2; 
            }
        }
    }
    osub_335D1C(a1, a2, a3);
    return 0LL;
}






static void (*osub_4F6DD4)(uint8_t*) = nullptr;
void __fastcall hsub_4F6DD4(uint8_t* a1) {
    osub_4F6DD4(a1);
    
    if (a1 && *a1) {
        char* buf = (char*)a1;
        
     
        char* mprcs = strstr(buf, "ENABLE_MPRCS");
        if (mprcs) memcpy(mprcs + 2, "DISABLE", 7);
       
        char* tplibc = strstr(buf, "ENABLE_TPLIBC");
        if (tplibc) memcpy(tplibc + 2, "DISABLE", 7);
        
  
        char* module_start = strstr(buf, "module");
        if (module_start) {
            char* module_end = strstr(module_start, "}");
            if (module_end) {
                for (int i = 1; i <= 128; i++) {
                    char entry[16];
                    snprintf(entry, sizeof(entry), " %d:%d", i, 1);
                    char* found = strstr(module_start, entry);
                    if (found && found < module_end) {
                        found[strlen(entry) - 1] = '0'; // 1 → 0
                    }
                }
            }
        }
    }
}


__int64 (*orig_sub_4F1F20)(__int64, __int64 *);
__int64 sub_4F1F20(__int64 a1, __int64 *a2) 
{
 if (!a1 || !a2) 
{
 return orig_sub_4F1F20(a1, a2);
 }

 if (*(void **)(a1 + 80)) *(_QWORD *)(a1 + 80) = 0LL; 
 if (*(void **)(a1 + 88)) *(_QWORD *)(a1 + 88) = 0LL;
 if (*(void **)(a1 + 96)) *(_QWORD *)(a1 + 96) = 0LL; 

 return orig_sub_4F1F20(a1, a2);
}


__int64 __fastcall (*oServerReport)(void *a1, int a2);
__int64 __fastcall hServerReport(void *a1, int a2)
{
    switch (a2) {
        case 78: 
        case 77: 
        case 75: 
        case 69:
        case 80: 
        case 251: 
        case 252:
        case 254: 
            return 0; 
        default:
            return oServerReport(a1, a2);
    }
}




void (*osub_735ED60)(int a1, char *s, unsigned int a3, int a4, int a5, int a6,int a7,int a8,int a9,__int64 a10,int a11,int a12,int a13,int a14,int a15,int a16,int a17,int a18,int a19,int a20,int a21,int a22,int a23,int a24,int a25,__int64 a26,int a27,int a28,int a29,int a30,int a31,int a32,int a33,int a34,int a35,int a36,int a37,int a38,int a39,int a40,int a41,__int64 a42);
void __fastcall hsub_735ED60(int a1,char *s,unsigned int a3,int a4,int a5,int a6,int a7,int a8,int a9,__int64 a10,int a11,int a12,int a13,int a14,int a15,int a16,int a17,int a18,int a19,int a20,int a21,int a22,int a23,int a24,int a25,__int64 a26,int a27,int a28,int a29,int a30,int a31,int a32,int a33,int a34,int a35,int a36,int a37,int a38,int a39,int a40,int a41,__int64 a42)
{
    __int64 v46 = 0LL;
    switch ( a3 )
    {
      case 1:
      case 2:
      case 0x28:
      case 0x29:
      case 0x2A:
      case 0x2B:
      case 0x2C:
      case 0x2D:
      case 0x2E:
      case 0x2F:
      case 0x30:
      case 0x31:
      case 0x33:
      case 0x34:
         return;
      default:
        break;
    }
   osub_735ED60(a1,s,a3,a4,a5,a6,a7,a8,a9,a10,
        a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,
        a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,
        a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,
        a41,a42);
}
__int64 __fastcall (*osub_74D3708)(__int64, __int64, _DWORD*);
__int64 __fastcall hsub_74D3708(__int64 a1, __int64 a2, _DWORD *a3) {
    __int64 v3 = *(_QWORD *)(a2 + 32);
    if (v3) v3++;
    *(_QWORD *)(a2 + 32) = v3;
    *a3 = 0;
    return 0;
}

__int64 __fastcall (*oGetSOVersion)();
__int64 __fastcall hGetSOVersion() {
    return 0;
}

__int64 __fastcall (*osub_5FE4A54)(__int64, __int64, __int64);
__int64 __fastcall hsub_5FE4A54(__int64 a1, __int64 a2, __int64 a3) {
    if (a2) {
        *(int*)(a2) = 0;
        *(int*)(a2 + 4) = 0;
        *(int*)(a2 + 8) = 0;
    }
    return osub_5FE4A54(a1, a2, a3);
}

__int64 __fastcall (*osub_5FE3A70)(__int64 a1, int a2, __int64 a3);
__int64 __fastcall hsub_5FE3A70(__int64 a1, int a2, __int64 a3) {
    a2 = a2 & ~0x100; 
    return osub_5FE3A70(a1, a2, a3);
}


bool BypassFilter(int checkId, int originalResult)
{
    switch (checkId)
    {
        case 1: // anti-cheat core
            return 0;

        case 2: // detection / visibility
            return 0;

        case 3: // validation
            return originalResult; // safe pass

        default:
            return originalResult;
    }
}
int (*oCheck1)(__int64);
int hCheck1(__int64 a2)
{
    int ret = oCheck1(a2);
    return BypassFilter(1, ret);
}
int (*oCheck2)(__int64);
int hCheck2(__int64 a2)
{
    int ret = oCheck2(a2);
    return BypassFilter(2, ret);
}


__int64 __fastcall (*sub_735E060)(__int64 result);
__int64 __fastcall hsub_735E060(__int64 result)
{
    *(int*)0xDAC8315 = 0;  
    *(int*)0xDE4EDC0 = 1;  
    
    return sub_735E060(result);
}


__int64 __fastcall sub_1ECD44(_QWORD *a1, int a2)
{
  __int64 *v2 = 0;
  __int64 v3 = 0;

  return v3;
}

__int64 __fastcall *osub_73706EC(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4);
extern int dword_DD90150;
extern int dword_DD90154;
extern int dword_DD90158;
extern int dword_DAC8624;
extern int qword_DE4EDC0;
extern unsigned char byte_E1EAEB8;
extern int64 qword_E1EAEC0;
__int64 __fastcall hsub_73706EC(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
    dword_DD90150 = a2;
    dword_DD90154 = a3;
    dword_DD90158 = a4;

    if (dword_DAC8624 && (a2 == 1 || a4 == 1))
    {
    }
    if (!qword_DE4EDC0 && (unsigned char)byte_E1EAEB8 >= 5u)
    {
        __int64 v8 = qword_E1EAEC0;
    }
    return 0;
}


__int64 __fastcall (*osub_4D47D8)(__int64 a1, __int64 a2, int a3, char a4);
__int64 __fastcall hsub_4D47D8(__int64 a1, __int64 a2, int a3, char a4)
{
    if ( (a4 & 1) != 0 ){
        return 0LL;
    }
    return osub_4D47D8(a1, a2, a3, a4);
}

int64_t Self_MemoryIntegrity_Chk(int64_t a1, int a2, int64_t a3)
{
   return 16843009;
}


__int64 (*osub_3A564C)(__int64 a1, unsigned int a2, void *a3, double a4);
__int64 hsub_3A564C(__int64 a1, unsigned int a2, void *a3, double a4)
{

    if (*(_BYTE *)(a1 + 97) == 2)
        return 0LL;

    if (*(_BYTE *)(a1 + 97) == 1)
        *(_BYTE *)(a1 + 97) = 2;

    return osub_3A564C(a1, a2, a3, a4);
}

__int64 (*osub_46EFD0)(_DWORD *a1, unsigned __int8 *a2, int a3);
__int64 __fastcall hsub_46EFD0(_DWORD *a1, unsigned __int8 *a2, int a3)
{
    bool validZip =
        a2 &&
        a2[0] == 0x50 &&
        a2[1] == 0x4B &&
        a2[2] == 0x03 &&
        a2[3] == 0x04;

    if (!validZip) {
        return 0LL;
    }

    return osub_46EFD0(a1, a2, a3);
}

__int64 Sub_51C7A8(__int64 a1, char a2) {
    *(_BYTE *)(a1 + 616) = 0;
    *(_BYTE *)(a1 + 618) = 0;
    return 0LL;
}

int64_t sub_123558(__int64 a1, void *str) {
    if (!a1) return 0xFFFFFFFFLL;
    *(_BYTE *)(a1 + 2438) = 19;
    *(_DWORD *)(a1 + 2444) = 0;
    return 0;
}
// ============== TOUCH EVENT DEAD ==============

int64_t sub_123288(__int64 a1, _DWORD *a2) {
    if (!a2) return 0xFFFFFFFFLL;
    *a2 = 0;
    a2[1] = 0;
    if (a1) {
        *(_BYTE *)(a1 + 292) = 0;
        *(_BYTE *)(a1 + 293) = 0;
        *(_BYTE *)(a1 + 294) = 0;
    }
    return 0;
}

//@BgmiSrcLeaker
int64_t sub_1233D0(__int64 a1, const void *a2, unsigned __int64 a3) {
    if (!a1) return 0xFFFFFFFFLL;
    *(_BYTE *)(a1 + 292) = 1;
    *(_BYTE *)(a1 + 293) = 0;
    *(_BYTE *)(a1 + 294) = 0;
    if (a2 && a3 > 0) *(_DWORD *)(a1 + 360) = a3;
    return 0;
}


int64_t sub_123510(__int64 a1, const void *a2, unsigned __int64 a3) {
    return 0;
}
//@BgmiSrcLeaker

int64_t sub_12363C(__int64 a1, const void *a2, unsigned int a3, void *a4, int *a5) {
    if (a5) *a5 = a3 + 4096;
    return 0;
}


void *anogs_thread(void *) {
    while (!isLibraryLoaded("libUE4.so")) { sleep(1); }
	while (!isLibraryLoaded("libanogs.so")) { sleep(1); }
	while (!isLibraryLoaded("libanort.so")) { sleep(1); }
	//system("chmod 000 /data/data/com.pubg.imobile/files/ano_tmp");
	libanogsBase = findLibrary(oxorany("libanogs.so"));
    libUE4Base = findLibrary(oxorany("libUE4.so"));
    TBlueBase = findLibrary(oxorany("libTBlueData.so"));
    libanortBase = findLibrary(oxorany("libanort.so"));
    AntBase = findLibrary(oxorany("libAntsVoice.so"));
    HdmpveBase = findLibrary(oxorany("libhdmpve.so"));
    libcBase = findLibrary(oxorany("libc.so"));
    libanogsSize = getLibrarySize(oxorany("libanogs.so"));
    libUE4Size =   getLibrarySize(oxorany("libUE4.so"));
    libanogsAlloc = (DWORD)malloc(libanogsSize);
    libUE4Alloc   = (DWORD)malloc(libUE4Size);
    memcpy((void *)libanogsAlloc, (void *)libanogsBase, libanogsSize);
    memcpy((void *)libUE4Alloc, (void *)libUE4Base, libUE4Size);
    void *handle = dlopen(oxorany("libc.so"), 4);
    void *memcpy_addr = dlsym(handle, oxorany("memcpy"));
	void *pthread_create_addr = dlsym(handle, oxorany("pthread_create"));
    void *inet_pton_addr = dlsym(handle, oxorany("inet_pton"));
	LOGI("THE LIBRARY LOADED FROM DYNAMIC-OWNER");
	dlclose(handle);
//========================= CRSH FIXER BYPASS BYPASS DALO==========================//  
PATCH_LIB("libanogs.so", "0x213360 + 0x8", "C0 03 5F D6");//crash fixe 
//HOOK_LIB_NO_ORIG("libUE4.so","0xC25DF70", ApplySkins); 

//========================= VIOLATION BYPASS 1day ==========================//  
PATCH_LIB("libanogs.so","0x39F56C","00 00 80 D2 C0 03 5F D6"); //CRC-CHECK 2
PATCH_LIB("libanogs.so","0x330494","00 00 80 D2 C0 03 5F D6"); //CRC-CAL
PATCH_LIB("libanogs.so","0x338680","00 00 80 D2 C0 03 5F D6"); //segment 1DAY FIX ONLINE BT Supported 
PATCH_LIB("libanogs.so","0x431800","00 00 80 D2 C0 03 5F D6");//1day violation fix 100%
PATCH_LIB("libanogs.so","0x37FD78","00 00 80 D2 C0 03 5F D6");//1Day Violation Regulation fixed 
PATCH_LIB("libanogs.so","0x371418","00 00 80 D2 C0 03 5F D6"); //crc32 integrity chk

//==============================// 10 YEAR OFFSET //============================================
PATCH_LIB("libanogs.so","0x461F04","00 00 80 D2 C0 03 5F D6"); //10 year 100 %
PATCH_LIB("libanogs.so","0x4633F4","00 00 80 D2 C0 03 5F D6"); //10 year 100 %
HOOK_LIB("libanogs.so","0x2ECE70",hsub_2ECE70,osub_2ECE70);//10 year
PATCH_LIB("libanogs.so","0x4D4C94","00 00 80 D2 C0 03 5F D6"); //"id" 10y offline detection /-
//PATCH_LIB("libanogs.so","0x3A564C","C0 03 5F D6"); //vtable chk
HOOK_LIB("libanogs.so","0x3A564C", hsub_3A564C, osub_3A564C);//vtable
PATCH_LIB("libanogs.so","0x313810","00 00 80 D2 C0 03 5F D6"); //offline fix 
PATCH_LIB("libanogs.so","0x5026EC","C0 03 5F D6"); //Memory Master offline fixer
PATCH_LIB("libanogs.so","0x232C7C", "C0 03 5F D6");//offline ya flag confirm nahi h 
       //10 year Anticheat on hone per account protect krga 
PATCH_LIB("libanogs.so","0x2DD400","\x00\x00\x80\xD2\xC0\x03\x5F\xD6");
PATCH_LIB("libanogs.so","0x2DD3A8","\x00\x00\x80\xD2\xC0\x03\x5F\xD6");
PATCH_LIB("libanogs.so","0x4D4DE8","\x00\x00\x80\xD2\xC0\x03\x5F\xD6");
PATCH_LIB("libanogs.so","0x4D4DB8","\x00\x00\x80\xD2\xC0\x03\x5F\xD6");
PATCH_LIB("libanogs.so","0x4D4DC0","\x00\x00\x80\xD2\xC0\x03\x5F\xD6");
HOOK_LIB("libUE4.so", "0x735E060", hsub_735E060, sub_735E060);//KILL TSS (Kill 67)
HOOK_LIB("libanogs.so", "0x46EFD0", hsub_46EFD0, osub_46EFD0);// memory tree
HOOK_LIB_NO_ORIG("libanogs.so", "0x51C7A8", Sub_51C7A8); // Memory Scanner

//-> Perfect Solution Of Instant 10Year Ban  

//==========================// REPORT BLOCK //===================================================
PATCH_LIB("libanogs.so","0x29BF24","00 00 80 D2 C0 03 5F D6"); //Device-Validation
PATCH_LIB("libanogs.so","0x47B5CC","00 00 80 D2 C0 03 5F D6"); //chks-sm
PATCH_LIB("libanogs.so","0x1C79D4","00 00 80 D2 C0 03 5F D6");   //Inner report core
HOOK_LIB("libanogs.so", "0x2F42EC", hServerReport, oServerReport);////Report Blocker Real 
HOOK_LIB("libanogs.so","0x4D47D8", hsub_4D47D8, osub_4D47D8);//tdm_report


//==========================// TERMINATION FIX===================================================
PATCH_LIB("libUE4.so","0x5952F70","00 00 80 D2 C0 03 5F D6");////termination fix 100 % working
PATCH_LIB("libUE4.so","0x67866E4","1F 20 03 D5");////termination fix 100 % working
PATCH_LIB("libanogs.so","0x4B6C94","00 00 80 D2 C0 03 5F D6"); //magic' termination +10 year bk
PATCH_LIB("libUE4.so","0x790AC40","00 00 80 D2 C0 03 5F D6");//FAKE DAMAGE FIX 
PATCH_LIB("libanogs.so","0x49A628","00 00 80 D2 C0 03 5F D6"); //data integrity chk trigger fire 10 min ban

//============================//FLAG FIXER//=====================================================
HOOK_LIB_NO_ORIG("libanogs.so","0x1ECD44", sub_1ECD44);//REPORT BLOCK 7 day falg 
PATCH_LIB("libanogs.so","0x1ECD88","00 00 80 D2 C0 03 5F D6"); //flag delay private
PATCH_LIB("libanogs.so","0x2234B0","00 00 80 D2 C0 03 5F D6"); // flag delay
PATCH_LIB("libanogs.so","0x3A4CCC","C0 03 5F D6"); //flag delya v2
PATCH_LIB("libanogs.so","0x4690CC","00 00 80 D2 C0 03 5F D6");//flag fix 
PATCH_LIB("libanogs.so","0x43694C","00 00 80 D2 C0 03 5F D6"); //flag delay 
HOOK_LIB("libanogs.so","0x4F1F20", sub_4F1F20, orig_sub_4F1F20);// cilent side flag reset
HOOK_LIB("libanogs.so","0x4F6DD4", hsub_4F6DD4, osub_4F6DD4); //ace blocked flag delay 
PATCH_LIB("libanogs.so","0x2940D0","C0 03 5F D6"); //decetion tree flag delay
PATCH_LIB("libanogs.so","0x4B0F5C","C0 03 5F D6"); //1day & 7day flag fix
HOOK_LIB("libanogs.so","0x335D1C", hsub_335D1C, osub_335D1C); //25-30 kill flag delay

HOOK_LIB_NO_ORIG("libhdmpve.so", "0x123288", sub_123288);//Touch event dead
HOOK_LIB_NO_ORIG("libhdmpve.so", "0x1233D0", sub_1233D0);
HOOK_LIB_NO_ORIG("libhdmpve.so", "0x123558", sub_123558);
HOOK_LIB_NO_ORIG("libhdmpve.so", "0x123510", sub_123510);
HOOK_LIB_NO_ORIG("libhdmpve.so", "0x12363C", sub_12363C);
PATCH_LIB("libanogs.so","0x37AB7C","00 00 80 D2 C0 03 5F D6"); //Reporter
PATCH_LIB("libanogs.so","0x3790C8","00 00 80 D2 C0 03 5F D6"); // Flag


PATCH_LIB("libanogs.so","0x21B998","C0 03 5F D6");//flag
PATCH_LIB("libanogs.so","0x4B4B54","C0 03 5F D6");//flag
PATCH_LIB("libanogs.so","0x23F3C8","C0 03 5F D6");//flag
PATCH_LIB("libanogs.so","0x3DBD34","C0 03 5F D6");//flag

HOOK_LIB("libanogs.so", "0x9C7AC8C", hCheck1, oCheck1);
HOOK_LIB("libanogs.so", "0x9C76800", hCheck2, oCheck2);

    return NULL;    
}
void *Island_thread(void *) {
    sleep(55);
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));
//================================ ISLAND BYPASS DALO=============================//  
HOOK_LIB("libUE4.so","0x6787854", hook_Upload, old_Upload);
HOOK_LIB("libUE4.so", "0x73706EC", hsub_73706EC,osub_73706EC); //40 kill flag delay 
HOOK_LIB("libUE4.so","0x735ED60", hsub_735ED60, osub_735ED60);//tss manager 


PATCH_LIB("libUE4.so","0x9C58CF8","00 00 80 D2 C0 03 5F D6");
    return NULL;
}
__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, Island_thread, NULL);    
    pthread_create(&ptid, NULL, anogs_thread, NULL);
}


