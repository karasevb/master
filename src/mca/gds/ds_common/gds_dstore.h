/*
 * Copyright (c) 2015-2017 Intel, Inc. All rights reserved.
 * Copyright (c) 2017-2018 Mellanox Technologies, Inc.
 *                         All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#ifndef PMIX_DSTORE_H
#define PMIX_DSTORE_H

#include <src/include/pmix_config.h>
#include "src/mca/gds/ds_common/dstore_seg.h"

#include "src/mca/gds/gds.h"
#include "src/mca/pshmem/pshmem.h"

BEGIN_C_DECLS

#include <src/include/pmix_config.h>
#include "src/class/pmix_value_array.h"

#define INITIAL_SEG_SIZE 4096
#define NS_META_SEG_SIZE (1<<22)
#define NS_DATA_SEG_SIZE (1<<22)

#define PMIX_DSTORE_ESH_BASE_PATH "PMIX_DSTORE_ESH_BASE_PATH"

typedef struct {
    pmix_value_array_t super;
    ns_map_data_t ns_map;
    size_t num_meta_seg;
    size_t num_data_seg;
    seg_desc_t *meta_seg;
    seg_desc_t *data_seg;
    bool in_use;
} ns_track_elem_t;

pmix_status_t dstore_init(pmix_info_t info[], size_t ninfo);

void dstore_finalize(void);

pmix_status_t dstore_setup_fork(const pmix_proc_t *peer, char ***env);

pmix_status_t dstore_cache_job_info(struct pmix_nspace_t *ns,
                                pmix_info_t info[], size_t ninfo);

pmix_status_t dstore_register_job_info(struct pmix_peer_t *pr,
                                pmix_buffer_t *reply);

pmix_status_t dstore_store_job_info(const char *nspace,
                                pmix_buffer_t *job_data);

pmix_status_t dstore_store(const pmix_proc_t *proc,
                                pmix_scope_t scope,
                                pmix_kval_t *kv);


pmix_status_t dstore_fetch(const pmix_proc_t *proc,
                                pmix_scope_t scope, bool copy,
                                const char *key,
                                pmix_info_t info[], size_t ninfo,
                                pmix_list_t *kvs);

pmix_status_t dstore_add_nspace(const char *nspace,
                                pmix_info_t info[],
                                size_t ninfo);

pmix_status_t dstore_del_nspace(const char* nspace);

pmix_status_t dstore_assign_module(pmix_info_t *info, size_t ninfo,
                                int *priority);

pmix_status_t dstore_store_modex(struct pmix_nspace_t *nspace,
                                pmix_list_t *cbs,
                                pmix_byte_object_t *bo);

END_C_DECLS

#endif