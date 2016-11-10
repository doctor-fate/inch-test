int maxarray(void *base, unsigned long nel, unsigned long width, 
        int (*compare)(void *a, void *b)) 
        {
                int i, j;
                i=0;
                j=0;
                for (i= 0; i< nel; i++)
                if (compare(base + width*i,base + width*j) > 0) 
                {
                        j=i;
                        }
        return j;
}