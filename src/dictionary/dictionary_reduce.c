//
//  dictionary_reduce.c
//  
//
//  Created by Colton Simmons on 4/23/18.
//

#include "dictionary_reduce.h"
#include "dictionary_generator.h"
#include "../lib/hashmap.h"
#include "../tagger/tags.h"

HASHMAP_FUNCS_CREATE(freq, const char, const char);

struct hashmap reduce_map(struct hashmap map){
    FILE *fp = fopen ("updated.txt", "w");
    struct hashmap newmap;
    hashmap_init(&newmap, hashmap_hash_string, hashmap_compare_string, 0);
    
    struct hashmap_iter *iter;
    struct tagcounts_t *data;
    iter = hashmap_iter(&map);
    
    for (iter = hashmap_iter(&map); iter; iter = hashmap_iter_next(&map, iter)) {
        int highest;
        char* tag = (char *)malloc(5*sizeof(char));
        data = (tagcounts_t*)hashmap_iter_get_data(iter);
        highest = get_highest_frequency(data);
        char* key = (char *)hashmap_iter_get_key(iter);
        hash_to_tag(highest, tag);
        freq_hashmap_put(&newmap, key, tag);
        fprintf (fp, "%s\t%s\n", key, tag);
    }
    hashmap_destroy(&map);
    return newmap;
}
