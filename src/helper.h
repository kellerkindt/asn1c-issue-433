#include <stdio.h>
#include <asn_application.h>
#include <CPM.h>



inline static void BAIL(char* message, int result) {
    if (result != 0) {
        fprintf(
                stderr,
                "Encountered an error, bailing out of %s: %d\n",
                message,
                result
        );
        exit(result);
    }
}


inline static int helper_print_cpm(CPM_t *message, FILE *stream) {
    asn_TYPE_descriptor_t *descriptor = &asn_DEF_CPM;
    return asn_fprint(stream, descriptor, (void*)message);
}

inline static int helper_send_cpm(CPM_t *message) {
    asn_TYPE_descriptor_t *descriptor = &asn_DEF_CPM;

    int result;
    unsigned char buffer[8000];
    size_t buffer_len = sizeof(buffer);

    if ((result = asn_check_constraints(descriptor, message, buffer, &buffer_len)) != 0) {
        fflush(stdout);
        fflush(stderr);
        fprintf(stderr, "Constraint check failed for '%s' because '%s'\n", descriptor->name, buffer);
        fflush(stderr);
        return result;
    }

    asn_enc_rval_t r = uper_encode_to_buffer(descriptor, NULL, (void*)message, &buffer, sizeof(buffer));

    if (r.encoded >= 0) {
        int size = (r.encoded + 7) / 8;
        for (int i = 0; i < size; ++i) {
            printf("%02x", buffer[i]);
        }
        printf("\n");
        fflush(stdout);

        return 0;
    } else {
        return -1;
    }
}



inline static int helper_check_cpm(CPM_t *message, FILE *stream) {
    asn_TYPE_descriptor_t *descriptor = &asn_DEF_CPM;

    int result;
    char buffer[8000];
    size_t buffer_len = sizeof(buffer);

    if ((result = asn_check_constraints(descriptor, (void*)message, buffer, &buffer_len)) != 0) {
        fprintf(stream, "%s\n", buffer);
        fflush(stream);
    }

    return result;
}


inline static void helper_free_cpm(CPM_t **message) {
    asn_TYPE_descriptor_t *descriptor = &asn_DEF_CPM;
    descriptor->op->free_struct(descriptor, (void*)*message, 0);
    *message = NULL;
}
