#define MICRODUST_NULL 0
#define MICRODUST_SUCCESS 0
#define MICRODUST_FAIL    1
#define MICRODUST_TRUE    1
#define MICRODUST_FALSE   0

#define MICRODUST_NUM_1024 1024

typedef enum 
{
    MDJSS_TASK_TYPE_CTR,
    MDJSS_TASK_TYPE_MSG,
    MDJSS_TASK_TYPE_RESULT
}MDJSS_TASK_TYPE;

#define ASSERTSUCCESS(val) if ((val) != MICRODUST_SUCCESS) \
{\
    return val; \
}

#define ASSERTPTR(val) if ((val) == MICRODUST_NULL)\
{\
    return MICRODUST_FAIL; \
}

