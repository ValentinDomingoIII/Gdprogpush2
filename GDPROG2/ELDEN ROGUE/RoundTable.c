#include "character_creation.h"
#include "stdio.h"

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

    printf("Fast travel\n");
    printf("Level Up\n");
    printf("Inventory\n");
    printf("Shop\n");
    printf("Save\n");
    printf("Quit Game\n");

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
    //add fast travel function
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