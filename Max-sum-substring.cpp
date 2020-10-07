#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]){

    // check command line
    if (argc != 2) {cout << "usage: enter one number for the legnth of the string"; exit(-1);}
    int size = atol(argv[1]);
    if (size < 1) {fprintf(stderr, "error: range must be at least 1\n"); exit(-1);}

    vector<int> ref = vector<int>(size);
    srand(time(0));

    //creates a string of random numbers
    //legnth=size
    //range -100...100
    for(int i=0; i<size; i++){
        ref[i]=rand()%201-100;
        cout << ref[i] << " ";
    }
    cout << "\n\n";

    int maxval = 0; //value of sum of MSS
    int maxstart = 0; //begining index of MSS
    int maxend = 0; //ending index of MSS

    int tempval = 0; //val of current substring
    int tempstart = 0; //beginging index of current substring
    int tempend = 0; //ending index of current substring

    for(int i=0; i<size; i++){
        //if positive add to temp value
        if(ref[i] >= 0){
            tempval += ref[i];
        }
        //if negative check if current substring is > max
        else{
            if(tempval > maxval){
                maxval = tempval;
                maxstart = tempstart;
                maxend = tempend;
            }

            //add to temp string
            tempval += ref[i];
            //if val of substring dips negative start new substring
            if(tempval < 0){
                tempval = 0;
                tempstart = i+1;
            }
        }
        tempend = i;
    }
    //final check 
    if(tempval > maxval){
        maxval = tempval;
        maxstart = tempstart;
        maxend = tempend;
    }

    cout << "the max sub substring has a value of: " << maxval 
    << "\nstarting index: " << maxstart << "\nending index: " << maxend << "\n";

    return 0;
}
