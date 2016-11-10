void revarray(void *base, unsigned long nel, unsigned long width)
{
    int i;
    char help[width];
    
for (i=0; i<nel/2; i++) {
        memcpy(help, base+i*width , width);
        memcpy( base+i*width, base+ (nel-1)*width - i* width, width);
        memcpy( base+ (nel-1)*width - i* width, help, width);
    }
}