#ifndef _TYPES_H_
#define _TYPES_H_

typedef enum {
    DATA_TYPE_INT,
    DATA_TYPE_CHAR,
    DATA_TYPE_FLOAT,
    DATA_TYPE_STRING,
    DATA_TYPE_BOOL,
    DATA_TYPE_VOID,
    DATA_TYPE_UNKNOWN = -20
} DataType;

DataType to_data_type(char* type);

#endif