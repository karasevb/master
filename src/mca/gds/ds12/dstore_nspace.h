#ifndef NSPACE_INFO_H
#define NSPACE_INFO_H

#include <src/include/pmix_config.h>

typedef struct ns_map_data_s ns_map_data_t;
typedef struct ns_map_s ns_map_t;

struct ns_map_data_s {
    char name[PMIX_MAX_NSLEN+1];
    size_t tbl_idx;
    int track_idx;
};

struct ns_map_s {
    int in_use;
    ns_map_data_t data;
};

#endif // NSPACE_INFO_H
