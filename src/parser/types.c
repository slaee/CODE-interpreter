#include <string.h>
#include "types.h"

DataType to_data_type(char* type) {
    if(strcmp(type, "INT") == 0) return DATA_TYPE_INT;
    else if (strcmp(type, "FLOAT") == 0) return DATA_TYPE_FLOAT;
    else if (strcmp(type, "STRING") == 0) return DATA_TYPE_STRING;
    else if (strcmp(type, "CHAR") == 0) return DATA_TYPE_CHAR;
    else if (strcmp(type, "BOOL") == 0) return DATA_TYPE_BOOL;
    else if (strcmp(type, "VOID") == 0) return DATA_TYPE_VOID;
    else return DATA_TYPE_UNKNOWN;
}