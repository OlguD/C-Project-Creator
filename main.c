#include "main.h"
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <direct.h>
#define MKDIR(path) _mkdir(path)
#else
#include <sys/stat.h>
#include <sys/types.h>
#define MKDIR(path) mkdir(path, 0777)
#endif


int main(int argc, char **argv){
    const char *folders[] = {SRC_FOLDER, INCLUDE_FOLDER, ASSETS_FOLDER};
    int numFolders = sizeof(folders) / sizeof(folders[0]);

    for (int i = 0; i < numFolders; i++) {
        if (MKDIR(folders[i]) == 0) {
            printf("Folder created successfully: %s\n", folders[i]);
        } else {
            printf("Folder couldn't created or already exist: %s\n", folders[i]);
        }
    }

    createFile(SRC_FOLDER, "main.c", "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, world!\\n\");\n    return 0;\n}\n");
    createFile(INCLUDE_FOLDER, "main.h", "#ifndef MAIN_H\n#define MAIN_H\n\n\n#endif\n");
    createFile(ASSETS_FOLDER, "example.txt", "This is a sample text");
    createFile(NULL, "Makefile", "CC=gcc\nSOURCE_FILE=WRITE_YOUR_SOURCE_FILE_HERE\nOUTPUT_FILE=WRITE_YOUR_OUTPUT_FILE_NAME\n\nmake:\n\t$(CC) $(SOURCE_FILE) -o $(OUTPUT_FILE)\n\nclean:\n\trm -rf $(OUTPUT_FILE)");
    
    return 0;
}

void createFile(const char *folder, const char *filename, const char *content){
    char filepath[256];
    if (folder != NULL && strlen(folder) > 0) {
        snprintf(filepath, sizeof(filepath), "%s/%s", folder, filename);
    } else {
        snprintf(filepath, sizeof(filepath), "%s", filename);
    }

    FILE *file = fopen(filepath, "w");
    if (file == NULL) {
        printf("File couldn't created: %s\n", filepath);
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("File created: %s\n", filepath);
}