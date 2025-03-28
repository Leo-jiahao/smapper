/**
 * @file smapper_test.c
 * @author jiahao.li
 * @brief 
 * @version 0.1
 * @date 2025-03-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "smapper.h"
    
enum BOARD_T {
    BOARD_A,
    BOARD_B,
    BOARD_C,
};

#define VAR_A(X) \
    SMAPPER_CASE(X, BOARD_A, 1) \
    SMAPPER_CASE(X, BOARD_B, 2) \
    SMAPPER_CASE(X, BOARD_C, 3) 

#define VAR_B(X) \
    SMAPPER_CASE(X, BOARD_A, "BOARD_A") \
    SMAPPER_CASE(X, BOARD_C, "BOARD_C") 

#define VAR_C(X) \
    SMAPPER_CASE(X, BOARD_A, 9.5) \
    SMAPPER_CASE(X, BOARD_B, 9.6) \
    SMAPPER_CASE(X, BOARD_C, 9.8) 


#define BOARD_MAPPINGS(X) \
    SMAPPER_SWITCH(X, var_a, VAR_A, int, 1) \
    SMAPPER_SWITCH(X, var_b, VAR_B, const char *, "var_b") \
    SMAPPER_SWITCH(X, var_c, VAR_C, double, 0.0) \

DEFINE_SMAPPER(board_config, BOARD_MAPPINGS)

int main()
{
    smapper_init_board_config(BOARD_B);
    printf("var_a:%d\n", smapper_get_var_a());
    printf("var_b:%s\n", smapper_get_var_b());
    printf("var_c:%.2f\n", smapper_get_var_c());
}


