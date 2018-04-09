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

typedef unsigned char   byte;
typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;


void line(u32 size, u16 val)
{
    u32 vrama = aVRAM;
    u32 count = 0;
    if (size > 240) return 0;
    while (count < size)
    {
	*(u16*)vrama = val;
	vrama+=2;
	count++;
    }
}

void put(u32 x, u32 y, u16 val)
{
    *(u16*)(0x06000000+(x*y)) = val;
}

int main()
{
    *(u16*)REG_DISPCNT = 0x0403;


    u32 vram = aVRAM;
    int count=0;

    line(25, ZRQ);

    put(100, 100, ZRQ);
    
    while(1);
}
