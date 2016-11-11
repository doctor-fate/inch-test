unsigned int f(unsigned int a,
               unsigned int b, 
               unsigned int c,
               unsigned int d) {  
    return a + b + c + d;
}

int main() {
    f(1, 2, 3, 4);
    
    f(1, 2,
        3, 4);
        
        
    f(
        1, 2, 3, 4
    )
    
    f(
        1, 
        2,
        3,
        4);
    
    f(1,
      2,
      3,
      4);
      
    f(1, 2,
    3, 4);
      
    return 0;
}
