#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SEED 1234
#define MAPSIZE 1000000
#define FORLOOP(i, statement1) for(int i = 0; i < sizeof(chset)/sizeof(chset[0]); i++){\
     statement1;\
     }
char map[MAPSIZE];
#define FORLOOP2(i, statement1, statement2) for(int i = 0; i < sizeof(chset)/sizeof(chset[0]); i++){\
    statement1;\
    unsigned int mapindex = 0;\
    if(count == limit){print_map(); exit(0);}\
    count++;\
    statement2;\
    mapindex = mapindex % MAPSIZE;\
    map[mapindex] = 'Y';\
}
unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed );
void print_map();
int main(int argc, char* argv[]){
    int limit = 0;
    if (argc != 2){
        printf("Usage: ./a.out number\n");
        return 0;
    }
    int ret = sscanf(argv[1], "%d", &limit);
    //printf("%d %u\n", limit, limit);
    if (ret != 1 || limit < 0){ 
        printf("Please enter positive number\n");
        return 0;
    }
    memset(map,' ', sizeof(map));
    unsigned int count = 0;
    char chset[][4] = {"abc", "mnp", "xmz", "%1", "2Y", "W3", "#$", "$Q", "Qsd", "L0"};
    char buff[32];
    //printf("Going to generate input for following character set\n");
    //FORLOOP(i, printf("%s\n",chset[i]))
    FORLOOP(i,\
    FORLOOP(j,\
    FORLOOP(k,\
    FORLOOP(l,\
    FORLOOP(m,\
    FORLOOP(n,\
    FORLOOP(o,\
    FORLOOP(p,\
    FORLOOP2(q,\
    sprintf(buff, "%s%s%s%s%s%s%s%s%s",chset[i],\
             chset[j],\
             chset[k],\
             chset[l],\
             chset[m],\
             chset[n],\
             chset[o],\
             chset[p],\
             chset[q]),\
             printf("%s\t%u\n", buff, mapindex = MurmurHash2(buff, strlen(buff) - 1, SEED))
             )))))))))
    return 0;
}
void print_map(){
    for(int i = 0; i < MAPSIZE; i++){
        if(map[i] != ' '){
            printf("%d\t",i,map[i]);
        }
    }
    printf("\n");
}
