#include "round_table.h"

void runRoundTable(Player* pPlayer)
{
    char cInput;
   // printf("\nWELCOME\n");

    do
    {
        pPlayer->nPotions = 8;
        displayRoundTable(pPlayer);
        scanf(" %c", &cInput);
        processInputs(pPlayer, cInput);
    } while (cInput != '0');
}

void displayRoundTable(Player* pPlayer)
{
    printf("\n");
    printf("\x1b[48;5;242m╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\x1b[0m\n");
    printf("\x1b[48;5;242m║   ▀██▀▀█▄    ▄▄█▀▀██   ▀██▀  ▀█▀ ▀█▄   ▀█▀ ▀██▀▀█▄   █▀▀██▀▀█     █     ▀██▀▀█▄   ▀██▀      ▀██▀▀▀▀█     ▀██▀  ▀██▀  ▄▄█▀▀██   ▀██▀      ▀██▀▀█▄   ║\x1b[0m\n");
    printf("\x1b[48;5;242m║    ██   ██  ▄█▀    ██   ██    █   █▀█   █   ██   ██     ██       ███     ██   ██   ██        ██  ▄        ██    ██  ▄█▀    ██   ██        ██   ██  ║\x1b[0m\n");
    printf("\x1b[48;5;242m║    ██▀▀█▀   ██      ██  ██    █   █ ▀█▄ █   ██    ██    ██      █  ██    ██▀▀▀█▄   ██        ██▀▀█        ██▀▀▀▀██  ██      ██  ██        ██    ██ ║\x1b[0m\n");
    printf("\x1b[48;5;242m║    ██   █▄  ▀█▄     ██  ██    █   █   ███   ██    ██    ██     ▄▀▀▀▀█▄   ██    ██  ██        ██           ██    ██  ▀█▄     ██  ██        ██    ██ ║\x1b[0m\n");
    printf("\x1b[48;5;242m║   ▄██▄  ▀█▀  ▀▀█▄▄▄█▀    ▀█▄▄▀   ▄█▄   ▀█  ▄██▄▄▄█▀    ▄██▄   ▄█▄  ▄██▄ ▄██▄▄▄█▀  ▄██▄▄▄▄▄█ ▄██▄▄▄▄▄█    ▄██▄  ▄██▄  ▀▀█▄▄▄█▀  ▄██▄▄▄▄▄█ ▄██▄▄▄█▀  ║\x1b[0m\n");
    printf("\x1b[48;5;242m╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\x1b[0m\n");

    printf("\n\t\t\t\t\t\t\t Player: %s | %s\n", pPlayer->cName, pPlayer->cJobName);
    printf("\t\t\t\t\t\t\t Level: %d\n", pPlayer->nLevel);
    printf("\t\t\t\t\t\t\t Runes: %d\n", pPlayer->nRunes);
    printf("\t\t\t\t\t\t\t Shards:");


    if (pPlayer->sShards.nStormveil==0)
    {
        printf(" ◇ ");
    }
    else{
        printf("\x1b[38;5;14m ◇ \x1b[0m");
    }



      if (pPlayer->sShards.nRaya==0)
    {
        printf(" ◇ ");
    }


    else{
        printf("\x1b[38;5;4m ◇ \x1b[0m");
    }



          if (pPlayer->sShards.nRedmane==0)
    {
        printf(" ◇ ");
    }
    else{
        printf("\x1b[38;5;9m ◇ \x1b[0m");
    }

        if (pPlayer->sShards.nLeyndell==0)
    {
        printf(" ◇ ");
    }
    else{
        printf("\x1b[38;5;11m ◇ \x1b[0m");
    }

        if (pPlayer->sShards.nVolcano==0)
    {
        printf(" ◇ \n");
    }
    else{
        printf("\x1b[38;5;1m ◇ \x1b[0m\n");
    }
   
    printf("\t\t\t\t\t\t\t Stats:\n\n");
    printf("\t\t\t\t\t\t\t Health: %d\t\t Strength: %d\n", pPlayer->sStats.nHealth, pPlayer->sStats.nStrength);
    printf("\t\t\t\t\t\t\t Endurance: %d\t\t Intelligence: %d\n", pPlayer->sStats.nEndurance, pPlayer->sStats.nIntelligence);
    printf("\t\t\t\t\t\t\t Dexterity: %d\t\t Faith: %d\n", pPlayer->sStats.nDexterity, pPlayer->sStats.nFaith);
 
    if (pPlayer->equippedWeapon == NULL)  {
        printf("\n\t\t\t\t\t\t\t No weapon equipped.\n");
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t Equipped Weapon: %s\n", pPlayer->equippedWeapon->weapon);
        printf("\t\t\t\t\t\t\t  HP: %d\t INT: %d\n", pPlayer->equippedWeapon->nHp, pPlayer->equippedWeapon->nInt);
        printf("\t\t\t\t\t\t\t  STR: %d\t END: %d\n", pPlayer->equippedWeapon->nStr, pPlayer->equippedWeapon->nEnd);
        printf("\t\t\t\t\t\t\t  DEX: %d\t FTH: %d\n", pPlayer->equippedWeapon->nDex, pPlayer->equippedWeapon->nFth);
    }

    printf("\n=============================================================================================================================================\n\n");
    printf("\t\t\t\t\t\t\t[1] Fast travel\n");
    printf("\t\t\t\t\t\t\t[2] Level Up\n");
    printf("\t\t\t\t\t\t\t[3] Inventory\n");
    printf("\t\t\t\t\t\t\t[4] Shop\n");
    printf("\t\t\t\t\t\t\t[5] Save\n");
    printf("\t\t\t\t\t\t\t[0] Quit Game\n");

    printf("\n\t\t\t\t\t\t\tINPUT:");
}

int runemath(Player* pPlayer) {
    int nRunecost = (pPlayer->nLevel * 100) / 2;
    char trash;

    if (pPlayer->nRunes >= nRunecost) {
        printf("Leveled UP!\n");
        pPlayer->nRunes -= nRunecost;
        pPlayer->nLevel++;
        scanf(" %c", &trash);  // This can be removed if not needed
        return 1;
    } else {
        printf("\nInsufficient Runes\n");
        printf("\nEnter any input to continue:");
        scanf(" %c", &trash);  // This can be removed if not needed
        return 0;
    }
} 

void processInputs(Player* pPlayer, char cInput)
{
    switch (cInput)
    {
    case '1':
        clear();
        processFastTravel(pPlayer);
        break;
    case '2':
        clear();
        processlevelup(pPlayer);
        break;
    case '3':
        clear();
        processInventory(pPlayer);
        break;
    case '4':
        clear();
        processShop(pPlayer);
        break;
    case '5':
        clear();
        savePlayerData(pPlayer);
        break;
    case '0':
        break;
    default:
        break;
    }
}

void processFastTravel(Player* pPlayer)
{
    char cAreaIndex;
    char cFastTravel;
    int nTotalShards;
    int nFlag1 = 0;
    int nFlag2, nFlag3;

    nTotalShards = pPlayer->sShards.nStormveil + pPlayer->sShards.nRaya + pPlayer->sShards.nVolcano + pPlayer->sShards.nRedmane;

    do {
        do {
            nFlag2 = 0;
            nFlag3 = 0;
            printf("SELECT YOUR DESTINATION\n\n");
            printf("[1]: [STORMVEIL CASTLE]\n");
            printf("[2]: [RAYA LUCARIA]\n");
            printf("[3]: [REDMANE CASTLE]\n");
            printf("[4]: [VOLCANO MANOR]\n");

            if (nTotalShards < 2)
                printf("[LOCKED]: [LEYNDELL ROYAL CAPITAL]\n");
            else
                printf("[5]: [LEYNDELL ROYAL CAPITAL]\n");
    
            if (pPlayer->sShards.nLeyndell == 0)
                printf("[LOCKED]: [ELDEN THRONE]\n");
            else
                printf("[6]: [ELDEN THRONE]\n");

            printf("\n[0]: BACK\n");

            printf("\n[INPUT]: ");
            scanf(" %c", &cAreaIndex);

            if (cAreaIndex == '5' && nTotalShards < 2)
                cAreaIndex = '7';
    
            if (cAreaIndex == '6' && pPlayer->sShards.nLeyndell == 0)
                cAreaIndex = '7';

            if (cAreaIndex == '0')
                nFlag2 = 1;

        } while (cAreaIndex != '0' && cAreaIndex != '1' && cAreaIndex != '2' && cAreaIndex != '3' && cAreaIndex != '4' && cAreaIndex != '5' && cAreaIndex != '6');

        while (cFastTravel != '1' && cFastTravel != '2' && nFlag2 != 1 && nFlag3 != 1) {
            printf("\nSELECT YOUR DESTINATION\n\n");
            printf("[1]: Starting Area\n");

            switch (cAreaIndex) {
                case '1':
                    if (pPlayer->sShards.nStormveil == 1)
                        printf("[2]: Boss Area\n");
                    else {
                        printf("[LOCKED]: Boss Area\n");
                        nFlag1 = 1;
                    }
                    break;
                case '2':
                    if (pPlayer->sShards.nRaya == 1)
                        printf("[2]: Boss Area\n");
                    else {
                        printf("[LOCKED]: Boss Area\n");
                        nFlag1 = 1;
                    }
                    break;
                case '3':
                    if (pPlayer->sShards.nRedmane == 1)
                        printf("[2]: Boss Area\n");
                    else {
                        printf("[LOCKED]: Boss Area\n");
                        nFlag1 = 1;
                    }
                    break;
                case '4':
                    if (pPlayer->sShards.nVolcano == 1)
                        printf("[2]: Boss Area\n");
                    else {
                        printf("[LOCKED]: Boss Area\n");
                        nFlag1 = 1;
                    }
                    break;
                case '5':
                    if (nTotalShards > 1 && pPlayer->sShards.nLeyndell == 1)
                        printf("[2]: Boss Area\n");
                    else {
                        printf("[LOCKED]: Boss Area\n");
                        nFlag1 = 1;
                    }
                    break;
            }

            printf("\n[0]: BACK\n\n");
            printf("[INPUT]: ");
            scanf(" %c", &cFastTravel);

            if (nFlag1 == 1 && cFastTravel == '2')
                cFastTravel = 'a';

            if (cFastTravel == '0') {
                nFlag2 = 2;
                nFlag3 = 1;
            }
        }
    } while (nFlag2 != 0 && nFlag2 != 1);

    if (nFlag2 == 0 && nFlag3 == 0)
        areaSelect(cAreaIndex, cFastTravel, pPlayer);
}
