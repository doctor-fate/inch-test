unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
unsigned long low = 0;unsigned long high = nel - 1;
unsigned long mid;
        while (low <= high) {
                mid = (low + high) / 2;
        if (compare(mid) < 0) {
                low = mid + 1;
        } 
        else if (compare(mid) > 0) {
                high = mid - 1;
        }       
        else {
                return mid;
        }
        }
        return nel;
}