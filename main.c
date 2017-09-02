#include <stdio.h>
#include <string.h>
#include "appitem.h"
#include "file_handler.h"

int main() {
    printf("Hello, World!\n");
    BASE_APP_ITEM testApp = Appitem_create_dummy();
    BASE_APP_ITEM testApp2 = Appitem_create_invalid();

    FILE* fp;
    fileh_file_init(fp, "vStore");

    BASE_APP_ITEM newApp;
    newApp.appUID = 10;
    newApp.appSize = 20;
    strcpy(newApp.appName, "JPedro");

    fp = fopen("vStore.mED", "a+");
    fileh_vstore_insertApp(fp, newApp);
    fclose(fp);

    int AppCount;
    fp = fopen("vStore.mED", "r+");
    AppCount = fileh_vstore_getAppCount(fp);
    printf("%d", AppCount);

    printf("FIZ\n\n");
//    fprintf(fp, "Funcionando?\n");
//    fclose(fp);


    return 0;
}