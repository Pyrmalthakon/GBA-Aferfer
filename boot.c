/* Dimensions de l'écran GBA. */
#define WIDTH 240
#define HEIGHT 160
/*Quelques couleurs à définir. */
#define KHL 0x0000
#define HMR 0x001F
#define SFR 0x03FF
#define ZRQ 0x7C00
#define CYAN 0x7FE0
#define BYD 0x7FFF

/*Emplacements importants dans la RAM de la GBA.*/
#define aIO 0x04000000
#define aVRAM 0x06000000

#define REG_DISPCNT 0x04000000
#define REG_DISPSTAT 0x04000004
#define REG_DISPSTAT 0x040000060

typedef unsigned char   byte;
typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;

u32 pos = 0;

void putpixel(u32 x, u32 y, u16 val) 
{
    // Simple fonction qui modifie la valeur d'un point donné de l'écran par modification de l'emplacement associé de la VRAM.
    u32 addr = 0x06000001;
    addr += x * 2;
    addr += (y * 240)*2;
    *(u16*)addr = val; 
}

void print(u16 val)
{
    //Plus ou moins la même chose que précédemment, mais saute directement au prochain pixel pour les prochains appels de la fonction.
    *(u16*)(0x06000001+(pos*2)) = val;
    pos++;
}

int main()
{
    *(u16*)REG_DISPCNT = 0x0403;
    
    print(CYAN);
    print(HMR);
    print(ZRQ);
    
    
    while(1);
}
