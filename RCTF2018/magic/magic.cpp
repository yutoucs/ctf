#include <stdio.h>

/*
unsigned char key_table[]={
	0x58, 0x71, 0x8F, 0x32, 0x05, 0x06, 0x51, 0xC7, 
	0xA7, 0xF8, 0x3A, 0xE1, 0x06, 0x48, 0x82, 0x09, 
	0xA1, 0x12, 0x9F, 0x7C, 0xB8, 0x2A, 0x6F, 0x95, 
	0xFD, 0xD0, 0x67, 0xC8, 0xE3, 0xCE, 0xAB, 0x12, 
	0x1F, 0x98, 0x6B, 0x14, 0xEA, 0x89, 0x90, 0x21, 
	0x2D, 0xFD, 0x9A, 0xBB, 0x47, 0xCC, 0xEA, 0x9C, 
	0xD7, 0x50, 0x27, 0xAF, 0xB9, 0x77, 0xDF, 0xC5,
  0xE9, 0xE1, 0x50, 0xD3, 0x38, 0x89, 0xEF, 0x2D,
  0x72, 0xC2, 0xDF, 0xF3, 0x7D, 0x7D, 0x65, 0x95, 
  0xED, 0x13, 0x00, 0x1C, 0xA3, 0x3C, 0xE3, 0x57, 
  0xE3, 0xF7, 0xF7, 0x2C, 0x73, 0x88, 0x34, 0xB1, 
  0x62, 0xD3, 0x37, 0x19, 0x26, 0xBE, 0xB2, 0x33, 
  0x20, 0x3F, 0x60, 0x39, 0x87, 0xA6, 0x65, 0xAD, 
  0x73, 0x1A, 0x6D, 0x49, 0x33, 0x49, 0xC0, 0x56, 
  0x00, 0xBE, 0x0A, 0xCF, 0x28, 0x7E, 0x8E, 0x69, 
  0x87, 0xE1, 0x05, 0x88, 0xDA, 0x54, 0x3E, 0x3C, 
  0x0E, 0xA9, 0xFA, 0xD7, 0x7F, 0x4E, 0x44, 0xC6, 
  0x9A, 0x0A, 0xD2, 0x98, 0x6A, 0xA4, 0x19, 0x6D, 
  0x8C, 0xE1, 0xF9, 0x30, 0xE5, 0xFF, 0x33, 0x4A, 
  0xA9, 0x52, 0x3A, 0x0D, 0x67, 0x20, 0x1D, 0xBF, 
  0x36, 0x3E, 0xE8, 0x56, 0xBF, 0x5A, 0x88, 0xA8, 
  0x69, 0xD6, 0xAB, 0x52, 0xF1, 0x14, 0xF2, 0xD7, 
  0xEF, 0x92, 0xF7, 0xA0, 0x70, 0xA1, 0xEF, 0xE3, 
  0x1F, 0x66, 0x2B, 0x97, 0xF6, 0x2B, 0x30, 0x0F, 
  0xB0, 0xB4, 0xC0, 0xFE, 0xA6, 0x62, 0xFD, 0xE6, 
  0x4C, 0x39, 0xCF, 0x20, 0xB3, 0x10, 0x60, 0x9F, 
  0x34, 0xBE, 0xB2, 0x1C, 0x3B, 0x6B, 0x1D, 0xDF, 
  0x53, 0x72, 0xF2, 0xFA, 0xB1, 0x51, 0x82, 0x04, 
  0x30, 0x56, 0x1F, 0x37, 0x72, 0x7A, 0x97, 0x50, 
  0x29, 0x86, 0x4A, 0x09, 0x3C, 0x59, 0xC4, 0x41, 
  0x71, 0xF8, 0x1A, 0xD2, 0x30, 0x88, 0x63, 0xFF, 
  0x85, 0xDE, 0x24, 0x8C, 0xC3, 0x37, 0x14, 0xC7};

typedef struct struct1
{
	char k;
	int n;
	int none;
}Struct;

Struct*  safe_get_struct(Struct* t_struct, signed int a2)
{
  Struct* result; // rax@3

  if ( a2 >= 0 && a2 <= 255 )
    result = &t_struct[a2];
  else
    memset(result,0,sizeof(result));
  return result;
}

void set_struct(Struct* Dst,int index)
{
	Struct* result; // rax@1
  Struct* v3; // rax@3
  __int64 v4; // [sp+24h] [bp-1Ch]@14
  Struct* v5; // [sp+28h] [bp-18h]@8
  Struct* v6; // [sp+30h] [bp-10h]@5
  Struct* v7; // [sp+38h] [bp-8h]@1
  Struct* struct_ptr; // [sp+50h] [bp+10h]@1
  unsigned int _index; // [sp+58h] [bp+18h]@1

   struct_ptr = Dst;
  _index = index;
  result = safe_get_struct(Dst, index);
  v7 = result;
  if ( result )
  {
    if ( _index & 0xF )
      v3 = safe_get_struct(struct_ptr, _index - 1);
    else
      v3 = 0;
    v6 = v3;
    if ( _index + 15 <= 0x1E )
      result = 0;
    else
      result = safe_get_struct(struct_ptr, _index - 16);
    v5 = result;
    if ( v6 || result )
    {
      if ( v6 )
      {
        v7->n = v7->k + v6->n;
        result = v7;
        v7->none = 2 * v6->none;
      }
      if ( v5 )
      {
        v4 = v5->n +v7->k;
        if ( v4 < (signed int)v7->n)
        {
          v7->n= v4;
          result = v7;
          v7->none = 2 * v5->none | 1;
        }
      }
    }
    else
    {
      result = v7;
      v7->n = v7->k;
    }
  }
}
bool get_res(unsigned char* key)
{
	
	Struct* Dst;
	Dst=(Struct*)malloc(256*(sizeof(Struct)));
	memset(Dst,0,0xC00);
	for (int i = 0; (signed int)i <= 255; ++i )
  {
    Dst[i].k = key[i];
    Dst[i].n = 0x7FFFFFFF;
    Dst[i].none = 0;
    set_struct(Dst, i);
  
  }
  if(Dst[255].n==0x700&&Dst[255].none!=0)
  {
  	return 1;
  }
  else
  	return 0;
}

int main()
{
	unsigned int seed=0x5AFFE78F;
	unsigned char key[256]={0,};
	while(seed<=0x5B028A8F)
	{
		srand(seed);
		memcpy(key,key_table,256);
		for(int i=0;i<=255;i++)
		{
			key[i]^=rand();
			
		}
		if(get_res(key))
		{
			printf("\nresult is:%x\n",seed);	
			break;
		}
		else
		{
		  printf("\nseed:%x",seed);
		  seed++;
	  }
	}
	
	return 0;
}
//0x5b00e398

*/



//0123456789abcdefghhgfedcba9876543210


unsigned char key[]={
	0x89, 0xC1, 0xEC, 0x50, 0x97, 0x3A, 0x57, 0x59, 
	0xE4, 0xE6, 0xE4, 0x42, 0xCB, 0xD9, 0x08, 0x22, 
	0xAE, 0x9D, 0x7C, 0x07, 0x80, 0x8F, 0x1B, 0x45, 
	0x04, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

int main()
{
	  unsigned char c = 0x66;
    for (int i = 0; i < 26; i++)
    {
      for (int j = 0; j < 256; j++)
      {
        if ((((j+0xcc)&0xff)^c) == key[i])
          printf("%.2x", (unsigned char)j);
      }
      c = ~c;
    }//238cbefd25d765f4b6b3b60fe174a2effc384ed21a4ab11096a5
    return 0;
}



/*
reg[1]=key
reg[2]=input

//A9  A0    AC   AE
reg[5]=ch
reg[5]+=0xcc
reg[5]&=0xff
reg[5]^0x66
reg[5]==key

c=0x66;
for(int i=0;i<26;i++)
{
	ch=input[i];
	ch+=0xcc;
	ch&=0xff;
	ch^=c;
	c=~c;
	//ch==key[i];
}
*/