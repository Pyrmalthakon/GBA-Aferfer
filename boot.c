#define WIDTH 240
#define HEIGHT 160

#define KHL 0x0000
#define HMR 0x001F
#define SFR 0x03FF
#define ZRQ 0x7C00
#define CYAN 0x7FE0
#define BYD 0x7FFF


#define aIO 0x04000000
#define aVRAM 0x06000000

#define REG_DISPCNT 0x04000000
#define REG_DISPSTAT 0x04000004
#define REG_DISPSTAT 0x040000060

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;

int main()
{
    *(u16*)REG_DISPCNT = 0x0403;


    unsigned int vram = aVRAM;
    u16 lsd = 0x1bad;
    u16 des = 0xa;
    while (vram != 0x6017FFF)
    {
	*(u16*)vram = lsd;
	vram++;
	des++;
	lsd+= des;
	if (lsd > 0xffaa) lsd = 0x0bca;
	if (des > 0xab) des = 0;

	if (vram > 0x6017FAB)
	    vram = aVRAM;
	
    }
    
    while(1);
}
