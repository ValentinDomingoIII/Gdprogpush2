#include "character_creation.h"
#include "RoundTable.h"
#include "stdio.h"
#include "area.h"
#include "structures.h"

void runRoundTable(Player* player)
{
    char cInput;
    printf("\nWELCOME\n");
  do
  {
    displayRoundTable(player);
    scanf(" %c",&cInput);
    processInputs(player,cInput);
  } while (cInput!='6');
     
}

void displayRoundTable(Player* player)
{
    printf("Name: %s\n", player->name);
    printf("Job Class: %s\n", player->jobName);
    printf("Level: %d\n", player->level);

    printf("[1] Fast travel\n");
    printf("[2] Level Up\n");
    printf("[3] Inventory\n");
    printf("[4] Shop\n");
    printf("[5] Save\n");
    printf("[0] Quit Game\n");

    printf("INPUT:");
}


int runemath(Player* player)
{
    int nRunecost;
    char trash;
    nRunecost=(player->level*100)/2;
    if(player->runes>=nRunecost)
    {
        printf("Leveled UP!");
        player->runes=player->runes - nRunecost;
        player->level++;
        scanf(" %c",&trash);
    }
    else
    {
        printf("\nInsufficient Runes\n");
        scanf(" %c",&trash);
    }

    
}

void processlevelup(Player* player)
{
    char cChoice,cChoice2;
    int nRune=(player->level*100)/2;
    do
    {
        nRune=(player->level*100)/2;
    printf("\nLEVEL UP\n\n");
    printf("-> Level up DEXTERITY \n");
    printf("-> Level up STRENGTH \n");
    printf("-> Level up INTELLIGENCE \n");
    printf("-> Level up FAITH \n");

    
    printf("-> BACK \n");


printf("\nLevel up cost:%d\n",nRune);
printf("\nINPUT:");
    scanf(" %c",&cChoice);


    switch (cChoice)
    {
    case '1':
        printf("\nLevel up Dexerity?");
        scanf(" %c",&cChoice2);
        if (cChoice2=='1')
        {
        
        runemath(player);
        
        printf("\n\nLevel:%d",player->level);
        printf("\n\nRUNES:%d",player->runes);
        }
        

        break;


    case '2':
        printf("\nLevel up Strength?");
        scanf(" %c",&cChoice2);
         if (cChoice2=='1'){
        runemath(player);
        
        printf("\n\nLevel:%d",player->level);
        printf("\n\nRUNES:%d",player->runes);
         }
           break;
    
    case '3':
        printf("\nLevel up Intelligence?");
        scanf(" %c",&cChoice2);
         if (cChoice2=='1')
         {
        runemath(player);
        
        printf("\n\nLevel:%d",player->level);
        printf("\n\nRUNES:%d",player->runes);
         }
           break;

    case '4':
        printf("\nLevel up Faith?");
        scanf(" %c",&cChoice2);
         if (cChoice2=='1'){
        runemath(player);
        
        printf("\n\nLevel:%d",player->level);
        printf("\n\nRUNES:%d",player->runes);
         }
    
    default:
        break;
    }
    } while (cChoice!='5');
    


}

void processInputs(Player* player, char cInput)
{
    switch (cInput)
    {
    case '1':
        processFastTravel(player);
        break;
    break;
    case '2':
        processlevelup(player);
        break;
    case '3':
        //no inventory yet
    break;
    case '4':
    //no shop yet
    break;
    case '5':
        savePlayerData(player);
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
    int nFlag = 0;

    nTotalShards = pPlayer->nShards.nStormveil + pPlayer->nShards.nRaya + pPlayer->nShards.nVolcano + pPlayer->nShards.nRedmane;

    do {

    printf("SELECT YOUR DESTINATION\n\n");
    printf("[1]: [STORMVEIL CASTLE]\n");
    printf("[2]: [RAYA LUCARIA]\n");
    printf("[3]: [REDMANE CASTLE]\n");
    printf("[4]: [VOLCANO MANOR]\n");

    if(nTotalShards < 2)
        printf("[LOCKED]: [LEYNDELL ROYAL CAPITAL]\n");
    else
        printf("[5]: [LEYNDELL ROYAL CAPITAL]\n");
    
    if(pPlayer->nShards.nLeyndell == 0)
        printf("[LOCKED]: [ELDEN THRONE]\n");
    else
        printf("[6]: [ELDEN THRONE]\n");

    printf("\n[INPUT]: ");
    scanf(" %c", &cAreaIndex);

    if(cAreaIndex == '5' && nTotalShards < 2)
            cAreaIndex = '0';
    
    if(cAreaIndex == '6' && pPlayer->nShards.nLeyndell == 0)
        cAreaIndex = '0';

    } while (cAreaIndex != '1' && cAreaIndex != '2' && cAreaIndex != '3' && cAreaIndex != '4' && cAreaIndex != '5' && cAreaIndex != '6');

    do {

        printf("\nSELECT YOUR DESTINATION\n\n");
        printf("[1]: Starting Area\n");

        switch(cAreaIndex){
            case '1':
                if(pPlayer->nShards.nStormveil == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;

            case '2':
                if(pPlayer->nShards.nRaya == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;
            
            case '3':
                if(pPlayer->nShards.nRedmane == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;
            
            case '4':
                if(pPlayer->nShards.nVolcano == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;
            
            case '5':
                if(pPlayer->nShards.nStormveil == 1)
                    printf("[2]: Boss Area\n");
                else{
                    printf("[LOCKED]: Boss Area\n");
                    nFlag = 1;
                }
                break;
        }

        printf("[INPUT]: ");
        scanf(" %c", &cFastTravel);

        if(nFlag == 1 && cFastTravel == '2')
            cFastTravel = '0';

    } while(cFastTravel != '1' && cFastTravel != '2');

    areaSelect(cAreaIndex, cFastTravel, pPlayer);
}