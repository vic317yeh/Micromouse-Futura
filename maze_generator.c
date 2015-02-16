#include <iostream>
using namespace std;

const int16_t MAX_WIDTH=16;
const int16_t MAX_HEIGHT=16;


int16_t NORTHMASK = 0x01;
int16_t EASTMASK = 0x02;
int16_t SOUTHMASK = 0x04;
int16_t WESTMASK =0x08;

const int16_t MAZE[16][16]={{14,8,9,13,13,13,12,10,10,10,9,12,10,8,10,9},{12,3,4,0,0,0,1,14,8,10,3,5,12,2,9,5},{6,9,5,7,7,7,6,9,6,8,10,3,5,12,3,5},{12,3,6,10,10,10,9,6,9,7,12,9,5,6,9,5},{6,9,12,10,10,10,2,11,6,10,3,6,3,12,3,5},{12,2,1,14,8,10,10,10,10,10,10,10,10,2,9,5},{5,13,4,9,5,12,8,8,11,14,8,10,8,11,5,5},{5,4,3,5,5,5,5,4,9,12,3,12,2,9,5,5},{5,5,12,3,5,5,5,6,3,6,9,6,8,3,5,5},{5,5,6,9,5,5,5,14,8,9,5,12,2,9,5,5},{5,5,12,2,1,5,4,9,5,4,3,6,8,3,5,5},{4,0,2,8,3,4,3,6,1,5,12,9,6,9,5,5},{5,5,12,3,14,2,10,10,2,1,5,6,9,6,1,5},{6,2,3,12,9,12,10,10,10,3,6,9,6,9,5,5},{12,10,10,3,6,2,10,10,10,10,10,2,11,6,1,5},{6,10,10,10,10,10,10,10,10,10,10,10,10,10,2,3}};

//check number of digit in a number
int numDigits(int number)
{
    if (number==0)
        return 1;
    
    int digits = 0;
    
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

int main()
{
    int16_t counter=MAX_HEIGHT;
    
    if (MAX_HEIGHT%2==0)
        counter=MAX_WIDTH-2;
    else
        counter=MAX_WIDTH-1;
    
    for (int i=2*MAX_HEIGHT-1; i>=0; i--){
        
        for (int j=MAX_WIDTH-1; j>=0; j--){
            
            //odd lines
            if (i%2!=0&&j!=0&&MAZE[(MAX_WIDTH-1)-j][i/2]&NORTHMASK)
                printf("+---");
            
            if (i%2!=0&&j!=0&&(!(MAZE[(MAX_WIDTH-1)-j][i/2]&NORTHMASK)))
                printf("+   ");
            
            if (i%2!=0&&j==0&&MAZE[(MAX_WIDTH-1)-j][i/2]&NORTHMASK)
                printf("+---+\n");
            
            if (i%2!=0&&j==0&&(!(MAZE[(MAX_WIDTH-1)-j][i/2]&NORTHMASK)))
                printf("+   +\n");
            
            
            //even lines
            if (i%2==0&&j!=0&&MAZE[(MAX_WIDTH-1)-j][i/2]&WESTMASK){
                if (numDigits(counter)>1)
                    printf("|%d ", counter);
                
                else
                    printf("| %d ", counter);
                
            }
            if (i%2==0&&j!=0&&(!(MAZE[(MAX_WIDTH-1)-j][i/2]&WESTMASK))){
                if (numDigits(counter)>1)
                    printf(" %d ", counter);
                
                else
                    printf("  %d ", counter);
            }
            if (i%2==0&&j==0&&MAZE[(MAX_WIDTH-1)-j][i/2]&WESTMASK){
                if (numDigits(counter)>1)
                    printf("|%d |\n", counter);
                
                else
                    printf("| %d |\n", counter);
            }
            if (i%2==0&&j==0&&(!(MAZE[(MAX_WIDTH-1)-j][i/2]&WESTMASK))){
                if (numDigits(counter)>1)
                    printf(" %d |\n", counter);
                
                else
                    printf("  %d |\n", counter);
            }
            
            
            //update counter
            if (i%2==0){
                if (j==0)
                    counter--;
                
                if (j==MAX_WIDTH/2){
                    if (MAX_WIDTH%2!=0)
                        counter++;
                }
                else if (j>MAX_WIDTH/2)
                    counter--;
                else counter++;
            }
            
        }
        
        if (i%2==0){
            if (i==2*MAX_HEIGHT/2){}
            else if (i>2*MAX_HEIGHT/2)
                counter--;
            else counter++;
        }
    }
    
    //last line
    for (int i=0; i<MAX_WIDTH;i++){
        if (i!=MAX_WIDTH-1)
            printf("+---");
        else printf("+---+\n");
    }
    
}
