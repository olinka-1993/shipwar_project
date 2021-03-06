#include "assert.h"
#include <csignal>
#include <iostream>
#include <cstdlib>
#include <cstddef>      //NULL
#include "shipwar.hpp"
#include <stdio.h>

void test_big_ships(){
        Shipwar *game = new Shipwar();
        if ( NULL == game) {
                std::abort();
        } 
        game->fill_big_ships();
        int r = 0;
        for(int i = 0; i < 100; i++){
                r += game->current_sea[i];
        }

        FILE * pFile;
        pFile = fopen ("../../test_results/big_ships/results.txt","w");
        if(12 == r){
                if (pFile!=NULL) {
                        fputs ("big ships - pass",pFile);
                        fclose (pFile);
                }
        } else {
                if (pFile!=NULL) {
                       fputs ("big ships - fail",pFile);
                       fclose (pFile);
                }
        }
}
