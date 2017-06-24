/**5.1-2**/
int RANDOM_ZORE_ONE(){

    Sleep(500);     //<windows.h>, to bring srand(time(0)) into effect
    srand((unsigned)time(0));

    return rand() % 2;
}

int RANDOM(int a, int b){
    int k = 0;
    k = ceil(log(b - a + 1) / log(2));

    dynamic_bitset<> dbs(k);
    do{
        dbs.reset();             //set all bits to zore
        for(int i = 0; i < k; i++){
            if(RANDOM_ZORE_ONE() == 1){
                dbs.set(i);      //set the bit at this pos to one
            }
        }
    }while(dbs.to_ulong() >= b - a + 1);

    return a + dbs.to_ulong();
}

/**5.1-3**/
int Random(){
    int x, y;
    while(true){
        x = BIASED-RANDOM();
        y = BIASED-RANDOM();
        if(x != y){
            return x;
        }
    }
}
