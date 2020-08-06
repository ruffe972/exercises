#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <sodium.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

static const int CODE_LEN = 6;  // One-time password length

// Maximum console command length bound (exclusive)
static const int COMMAND_LEN_BOUND = 255;

static const char *QR_IMAGE_PATH = "/tmp/qr_pam.png";


// Generate random code
static void gen_code(char *code) {
    for (int i = 0; i < CODE_LEN; i++) {
        code[i] = '0' + randombytes_uniform(10);
    }
    code[CODE_LEN] = '\0';
}


PAM_EXTERN int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    if (sodium_init() < 0) {
        return PAM_SYSTEM_ERR;
    }
    char code[CODE_LEN + 1];
    gen_code(code);

    char command[COMMAND_LEN_BOUND];

    // Generate qr code
    sprintf(command, "qrencode -o %s %s", QR_IMAGE_PATH, code);
    system(command);

    // Open generated image
    sprintf(command, "eog %s &", QR_IMAGE_PATH);
    system(command);

    // Request a password
    const char *input = getpass("Code: ");

    if (input != NULL && strcmp(input, code) == 0) {
        return PAM_SUCCESS;
    } else {
        return PAM_AUTH_ERR;
    }
}
