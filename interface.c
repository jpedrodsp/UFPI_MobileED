//
// Created by jpedro on 02/09/2017.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "data_system.h"
#include "appitem.h"
#include "desktop.h"
#include "data_vstore.h"
#include "data_vapps.h"
#include "data_vrom.h"

// Interface Chart

// Main Menu
    // Desktop
    // vStore
        // Show vStore Apps
        // Install an App
    // vApps
        // Show Installed Apps
        // Uninstall an App
    // vROM
        // Show Apps
        // Stop an App

void interface_configure_cmd() {
    // Define o tamanho do prompt de comando para 60x30

    /*char text[32];
    strcpy(text, "mode CON: COLS=");
    strcat(text, INTERFACE_HSIZE);
    system(text);*/
    system("mode CON: COLS=60 LINES=40");


}

void interface_print_bar (int h_size, int barChar) {
    int i;
    for (i = 0; i < h_size; ++i) {
        printf("%c", barChar);
    }
    printf("\n");
}

void interface_print_centralized (int h_size, const char* text) {
    int i;
    int size = strlen(text);
    int blocks = (h_size - 2 - size) / 2;
    for (i = 0; i < blocks; ++i) {
        printf(" ");
    }
    printf(" ");
    printf("%s", text);
    /*printf(" ");
    for (i = 0; i < blocks; ++i) {
        printf(" ");
    }*/
    printf("\n");
}

void interface_print_centralized_nojump (int h_size, const char* text) {
    int i;
    int size = strlen(text);
    int blocks = (h_size - 2 - size) / 2;
    for (i = 0; i < blocks; ++i) {
        printf(" ");
    }
    printf(" ");
    printf("%s", text);
    /*printf(" ");
    for (i = 0; i < blocks; ++i) {
        printf(" ");
    }*/
}

void interface_print_centralized_bar (int h_size, const char* text, int barChar) {
    int i;
    int size = strlen(text);
    int blocks = (h_size - 2 - size) / 2;
    for (i = 0; i < blocks; ++i) {
        printf("%c", barChar);
    }
    printf(" ");
    printf("%s", text);
    printf(" ");
    for (i = 0; i < blocks; ++i) {
        printf("%c", barChar);
    }
    if (size % 2 == 1) {
        printf("%c", barChar);
    }
    printf("\n");
}

void interface_jump_to_vcenter (int _linesToPrint, int _linesPrinted) {
    int res = 0;
    res = (INTERFACE_VSIZE - _linesToPrint) / 2;
    int i;
    if (res % 2 == 1) {
        for (i = 0; i < (res - 1 -_linesPrinted); ++i) {
            printf("\n");
        }
    } else {
        for (i = 0; i < (res - _linesPrinted); ++i) {
            printf("\n");
        }
    }

}

int interface_main_show(BASE_APP_ITEM* vStore, BASE_APP_ITEM* vApps, BASE_APP_ITEM* vROM, int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT]){
    int option;
    do {
        int i;
        system("cls");
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("%s | %s %s\n", SYSTEM_TIME, SYSTEM_NAME, SYSTEM_VERSION);
        printf("Bem-vindo, %s!\n", SYSTEM_USER_NAME);
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        desktop_print(desktop, vApps);
        printf("\n### Escolha uma opção abaixo: \n");
        printf("1. %s\n", VSTORE_NAME);
        printf("2. %s\n", VAPPS_NAME);
        printf("3. %s\n", VROM_NAME);
        printf("\n0. Sair do aplicativo\n");
        printf("\nDigite uma opção: \n");

        fflush(stdin);
        scanf("%d", &option);

        switch (option) {
            case 0:
                return interface_main_to_exit();
                break;
            case 1:
                interface_main_to_vStore(vStore, vApps, desktop);
                break;
            case 2:
                interface_main_to_vApps(vApps, vROM, desktop);
                break;
            case 3:
                interface_main_to_vROM(vROM);
                break;
            default:
                break;
        }
    } while (option != 0 && option != 1 && option != 2 && option != 3);
    return 0;
}

int interface_main_to_exit() {
    int option = 0, i;
    do {
        system("cls");
        interface_print_bar(INTERFACE_HSIZE, 6);
        interface_print_centralized_bar(INTERFACE_HSIZE, "SAIR DO PROGRAMA?", 6);
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        interface_print_centralized(INTERFACE_HSIZE, "Deseja sair do programa?");
        interface_print_centralized(INTERFACE_HSIZE, "Digite 1 para sair.");
        printf("\n");
        interface_print_centralized_nojump(INTERFACE_HSIZE, "Digite: ");
        scanf(" %d", &option);
        if (option == 1) {
            return 1;
        } else {
            return 0;
        }

    } while (option != 1 && option != 0);
}

int interface_main_to_vStore(BASE_APP_ITEM* _vStore, BASE_APP_ITEM* _vApps, int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT]) {
    int option = 0, i, cleanInstall = 0, installUID, ec;
    do {
        system("cls");
        interface_print_bar(INTERFACE_HSIZE, 6);
        interface_print_centralized_bar(INTERFACE_HSIZE, "Loja de Aplicativos", 6);
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        int count = vStore_return_count(_vStore);

        for (i = 0; i < count; i++) {
            printf("\t[UID %04d.: %s (TAM: %2d Mb)\n", _vStore[i].appUID, _vStore[i].appName, _vStore[i].appSize);
        }
        printf("\n");
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        printf("Aperte para Continuar...");
        fflush(stdin);
        scanf("*%c");

        system("cls");
        interface_print_bar(INTERFACE_HSIZE, 6);
        interface_print_centralized_bar(INTERFACE_HSIZE, "Loja de Aplicativos", 6);
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        printf("\t1. Listar Aplicativos Disponíveis\n");
        printf("\t2. Instalar um Aplicativo\n");
        printf("\t0. Sair de %s\n", VSTORE_NAME);
        printf("\n");

        printf("\t## Digite uma opção: ");
        fflush(stdin);
        scanf("%d", &option);

        switch (option) {
            case 0:
                return 0;
            case 1:
                option = -1;
                continue;
                break;
            case 2:
                do {
                    system("cls");
                    interface_print_bar(INTERFACE_HSIZE, 6);
                    interface_print_centralized_bar(INTERFACE_HSIZE, "Loja de Aplicativos", 6);
                    interface_print_bar(INTERFACE_HSIZE, 6);
                    printf("\n");
                    interface_print_centralized(INTERFACE_HSIZE, "Insira o UID do aplicativo a ser instalado.");
                    interface_print_centralized_nojump(INTERFACE_HSIZE, "UID.: ");

                    fflush(stdin);
                    scanf("%d", &installUID);
                    ec = vStore_find_byUID(_vStore, installUID);
                    if (ec == -1) {
                        system("cls");
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        interface_print_centralized_bar(INTERFACE_HSIZE, "Loja de Aplicativos", 6);
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        printf("\n");
                        interface_print_centralized(INTERFACE_HSIZE, "O Aplicativo não foi encontrado.");
                        interface_print_centralized(INTERFACE_HSIZE, "Aperte para Continuar...");
                        interface_print_centralized_nojump(INTERFACE_HSIZE, "");
                        fflush(stdin);
                        scanf("*%c");
                        return 1;
                    } else {
                        installUID = MobileED_install_copy_from_vStore(_vStore, _vApps, desktop, ec);
                        if (ec == 1) {
                            system("cls");
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            interface_print_centralized_bar(INTERFACE_HSIZE, "Loja de Aplicativos", 6);
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            printf("\n");
                            interface_print_centralized(INTERFACE_HSIZE, "Você não tem espaço suficiente na memória.");
                            interface_print_centralized(INTERFACE_HSIZE, "Aperte para Continuar...");
                            interface_print_centralized_nojump(INTERFACE_HSIZE, "");
                            fflush(stdin);
                            scanf("*%c");
                            return 1;
                        } else {
                            system("cls");
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            interface_print_centralized_bar(INTERFACE_HSIZE, "Loja de Aplicativos", 6);
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            printf("\n");
                            interface_print_centralized(INTERFACE_HSIZE, "O aplicativo foi instalado.");
                            interface_print_centralized(INTERFACE_HSIZE, "Aperte para Continuar...");
                            interface_print_centralized_nojump(INTERFACE_HSIZE, "");
                            fflush(stdin);
                            scanf("*%c");
                            return 0;
                        }
                    }

                } while (1);
                break;
            default:
                break;
        }

    } while (option != 1 && option != 0);
}

int interface_main_to_vApps(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _vROM, int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT]) {
    int i;
    int count = 0;
    int option, UID, ec = 0;
    do {
        system("cls");
        interface_print_bar(INTERFACE_HSIZE, 6);
        interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        count = vApps_return_count(_vApps);
        for (i = 0; i < count; ++i) {
            printf("\t[UID %04d.: %s (TAM: %2d Mb)\n", _vApps[i].appUID, _vApps[i].appName, _vApps[i].appSize);
        }
        printf("\n");
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\t1. Iniciar aplicativo\n");
        printf("\t2. Desinstalar aplicativo\n");
        printf("\t0. Voltar ao menu inicial\n");
        fflush(stdin);
        scanf("%d", &option);

        switch (option) {
            case 0:
                break;
            case 1:
                do {
                    system("cls");
                    interface_print_bar(INTERFACE_HSIZE, 6);
                    interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                    interface_print_bar(INTERFACE_HSIZE, 6);
                    printf("\n");
                    interface_print_centralized(INTERFACE_HSIZE, "Digite o UID do aplicativo para executar:");
                    interface_print_centralized_nojump(INTERFACE_HSIZE, "UID.: ");

                    fflush(stdin);
                    scanf("%d", &UID);

                    ec = vApps_execute_app(_vApps, _vROM, UID);

                    if (ec == 0) {
                        system("cls");
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        printf("\n");
                        desktop_remove_item(desktop, UID);
                        interface_print_centralized(INTERFACE_HSIZE, "Aplicativo executado.");
                        interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                        fflush(stdin);
                        scanf("*%c");
                        return 0;
                    } else if (ec == 1) {
                        system("cls");
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        printf("\n");
                        interface_print_centralized(INTERFACE_HSIZE, "O aplicativo especificado não está instalado.");
                        interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                        fflush(stdin);
                        scanf("*%c");
                        return 1;
                    } else if (ec == 2) {
                        system("cls");
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        printf("\n");
                        interface_print_centralized(INTERFACE_HSIZE, "Não há espaço na ROM.");
                        interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                        fflush(stdin);
                        scanf("*%c");
                        return 2;
                    } else if (ec == 3) {
                        system("cls");
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        printf("\n");
                        interface_print_centralized(INTERFACE_HSIZE, "O aplicativo já estava em execução.");
                        interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                        fflush(stdin);
                        scanf("*%c");
                        return 2;
                    }
                } while (option != 0 && option != 1 && option != 2 && option != 3);
                break;
            case 2:
                if (count != 0) {
                    do {
                        system("cls");
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        printf("\n");
                        interface_print_centralized(INTERFACE_HSIZE, "Digite o UID do aplicativo para desinstalar:");
                        interface_print_centralized_nojump(INTERFACE_HSIZE, "UID.: ");

                        fflush(stdin);
                        scanf("%d", &UID);

                        ec = vApps_uninstall_app(_vApps, _vROM, UID);

                        if (ec == 0) {
                            system("cls");
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            printf("\n");
                            desktop_remove_item(desktop, UID);
                            interface_print_centralized(INTERFACE_HSIZE, "Aplicativo desinstalado.");
                            interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                            fflush(stdin);
                            scanf("*%c");
                            return 0;
                        } else if (ec == 1) {
                            system("cls");
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            printf("\n");
                            interface_print_centralized(INTERFACE_HSIZE, "O aplicativo ainda está em execução..");
                            interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                            fflush(stdin);
                            scanf("*%c");
                            return 1;
                        } else if (ec == 2) {
                            system("cls");
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            printf("\n");
                            interface_print_centralized(INTERFACE_HSIZE, "O aplicativo não está instalado.");
                            interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                            fflush(stdin);
                            scanf("*%c");
                            return 2;
                        }
                    } while (ec != 0);
                    break;
                } else {
                    system("cls");
                    interface_print_bar(INTERFACE_HSIZE, 6);
                    interface_print_centralized_bar(INTERFACE_HSIZE, "Menu de Aplicativos", 6);
                    interface_print_bar(INTERFACE_HSIZE, 6);
                    printf("\n");
                    interface_print_centralized(INTERFACE_HSIZE, "Não há aplicativos instalados.");
                    interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                    fflush(stdin);
                    scanf("*%c");
                    return 3;
                }
        }
    } while (option != 0 && option != 1 && option != 2);
}

int interface_main_to_vROM (BASE_APP_ITEM* _vROM) {
    int i;
    int count = 0;
    int option, UID, ec = 0;
    do {
        system("cls");
        interface_print_bar(INTERFACE_HSIZE, 6);
        interface_print_centralized_bar(INTERFACE_HSIZE, "Menu ROM", 6);
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        count = vROM_return_count(_vROM);
        for (i = 0; i < count; ++i) {
            printf("\t[UID %04d.: %s (TAM: %2d Mb)\n", _vROM[i].appUID, _vROM[i].appName, _vROM[i].appSize);
        }
        printf("\n");
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\t1. Fechar aplicativo\n");
        printf("\t0. Voltar ao menu inicial\n");
        fflush(stdin);
        scanf("%d", &option);

        switch (option) {
            case 0:
                return 0;
                break;
            case 1:
                if (count == 0) {
                    system("cls");
                    interface_print_bar(INTERFACE_HSIZE, 6);
                    interface_print_centralized_bar(INTERFACE_HSIZE, "Menu ROM", 6);
                    interface_print_bar(INTERFACE_HSIZE, 6);
                    printf("\n");
                    interface_print_centralized(INTERFACE_HSIZE, "Não há aplicativos em execução.");
                    interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                    fflush(stdin);
                    scanf("*%c");
                } else {
                    do {
                        system("cls");
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        interface_print_centralized_bar(INTERFACE_HSIZE, "Menu ROM", 6);
                        interface_print_bar(INTERFACE_HSIZE, 6);
                        printf("\n");
                        interface_print_centralized(INTERFACE_HSIZE, "Digite o UID do aplicativo para fechar:");
                        interface_print_centralized_nojump(INTERFACE_HSIZE, "UID.: ");

                        fflush(stdin);
                        scanf("%d", &UID);

                        ec = vROM_close_app(_vROM, UID);

                        if (ec == 0) {
                            system("cls");
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            interface_print_centralized_bar(INTERFACE_HSIZE, "Menu ROM", 6);
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            printf("\n");
                            interface_print_centralized(INTERFACE_HSIZE, "Aplicativo fechado com sucesso.");
                            interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                            fflush(stdin);
                            scanf("*%c");
                            return 0;
                        } else if (ec == 1) {
                            system("cls");
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            interface_print_centralized_bar(INTERFACE_HSIZE, "Menu ROM", 6);
                            interface_print_bar(INTERFACE_HSIZE, 6);
                            printf("\n");
                            interface_print_centralized(INTERFACE_HSIZE,
                                                        "O aplicativo especificado não estava em execução..");
                            interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte para continuar...");

                            fflush(stdin);
                            scanf("*%c");
                            return 1;

                        }
                    } while (ec != 0 && ec != 1);
                }
                break;
        }
    } while (option != 0 && option != 1);
}
