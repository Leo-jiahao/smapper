/**
 * @file smapper.h
 * @author jiahao.li
 * @brief 
 * @version 0.1
 * @date 2025-03-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef __SMAPPER_H__
#define __SMAPPER_H__

#define SMAPPER_CASE(X, match, result) \
    X##_SMAPPER_CASE(match, result)

#define X_SMAPPER_CASE(match, result) \
    case match: return result;

#define SMAPPER_SWITCH(X, var_name, cases, type, default_val) \
X##_SMAPPER_SWITCH(var_name, cases, type, default_val)

#define X_SMAPPER_SWITCH(var_name, cases, type, default_val) \
    type __smapper_##var_name(int val){\
        switch(val){\
            cases(X)\
            default: return default_val;\
        };\
    }\
    static type smapper_##var_name = (type)0;\
    type smapper_get_##var_name(void) {return smapper_##var_name;}

#define Y_SMAPPER_SWITCH(var_name, cases, type, default_val) \
    smapper_##var_name = __smapper_##var_name(val);

#define Z_SMAPPER_SWITCH(var_name, cases, type, default_val) \
    type smapper_get_##var_name(void);

#define DEFINE_SMAPPER(name, mappings) \
    mappings(X)\
    void smapper_init_##name(int val){\
        static int init_flag_##name = 0;\
        if(init_flag_##name) return;\
        init_flag_##name = 1;\
        mappings(Y)\
    }

#define DECLARE_SMAPPER(name, mappings) \
    mappings(Z)    \
    void smapper_init_##name(int val);

#endif
