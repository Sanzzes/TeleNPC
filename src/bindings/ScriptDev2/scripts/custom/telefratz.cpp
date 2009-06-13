/*
TELEFRATZ SCRIPTING PROJECT
Powered by CWDB

Created for MaNGOS - ScriptDev2 1018+
*/

#include "precompiled.h"
long long int money;
int costo;

bool GossipHello_telefratz(Player *player, Creature *_Creature)
{

    if ( player->GetTeam() == ALLIANCE ) {
player->ADD_GOSSIP_ITEM( 0, "Shopping Mall", GOSSIP_SENDER_MAIN, 4022);
player->ADD_GOSSIP_ITEM( 7, "WoPC Exclusiv"	, GOSSIP_SENDER_MAIN, 4042);
player->ADD_GOSSIP_ITEM( 5, "PvP-Arena"        , GOSSIP_SENDER_MAIN, 4020);
player->ADD_GOSSIP_ITEM( 5, "Dalaran City"        , GOSSIP_SENDER_MAIN, 4025);
player->ADD_GOSSIP_ITEM( 2, "Entferne Wiederbelungsnachwirkung", GOSSIP_SENDER_MAIN, 4021);
player->ADD_GOSSIP_ITEM( 2, "Gebt mir 300 Gold", GOSSIP_SENDER_MAIN, 4023);
player->ADD_GOSSIP_ITEM( 0, "Aufwiedersehen"			, GOSSIP_SENDER_MAIN, 6660);

	}  else {


player->ADD_GOSSIP_ITEM( 0, "Shopping Mall", GOSSIP_SENDER_MAIN, 4022);
player->ADD_GOSSIP_ITEM( 7, "WoPC Exclusiv"			, GOSSIP_SENDER_MAIN, 4042);
player->ADD_GOSSIP_ITEM( 5, "PvP-Arena"        , GOSSIP_SENDER_MAIN, 4020);
player->ADD_GOSSIP_ITEM( 5, "Dalaran City"        , GOSSIP_SENDER_MAIN, 4025);
player->ADD_GOSSIP_ITEM( 2, "Entferne Wiederbelungsnachwirkung", GOSSIP_SENDER_MAIN, 4021);
player->ADD_GOSSIP_ITEM( 2, "Gebt mir 300 Gold", GOSSIP_SENDER_MAIN, 4023);
player->ADD_GOSSIP_ITEM( 0, "Aufwiedersehen"			, GOSSIP_SENDER_MAIN, 6660);
	}
	
	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());

return true;

}


void SendDefaultMenu_telefratz(Player *player, Creature *_Creature, uint32 action )
{

if(!player->getAttackers().empty())

	{
	player->CLOSE_GOSSIP_MENU();
    _Creature->MonsterSay("Du bist im Kampfmodus!", LANG_UNIVERSAL, NULL);
return;
    }

money = player-> GetMoney();
costo = 3000000;

if ( player->isDead() )
   {
	player->CLOSE_GOSSIP_MENU();
      _Creature->MonsterSay("Du bist Tot", LANG_UNIVERSAL, NULL);
      return;
   }

if ( player->IsMounted() )
   {
	player->CLOSE_GOSSIP_MENU();
      _Creature->MonsterSay("Du musst dich vorher dismounten", LANG_UNIVERSAL, NULL);
      return;
   }

if ( player->isInFlight() || player->IsInWater() || player->GetInstanceId() )
   {
	player->CLOSE_GOSSIP_MENU();
      _Creature->MonsterSay("Das kannst du nicht", LANG_UNIVERSAL, NULL);
      return;
   }


switch(action)

{



case 5552:
    if ( player->GetTeam() == ALLIANCE ) {
player->ADD_GOSSIP_ITEM( 0, "Shopping Mall", GOSSIP_SENDER_MAIN, 4022);
player->ADD_GOSSIP_ITEM( 7, "WoPC Exclusiv"	, GOSSIP_SENDER_MAIN, 4042);
player->ADD_GOSSIP_ITEM( 5, "PvP-Arena"        , GOSSIP_SENDER_MAIN, 4020);
player->ADD_GOSSIP_ITEM( 5, "Dalaran City"        , GOSSIP_SENDER_MAIN, 4025);
player->ADD_GOSSIP_ITEM( 2, "Entferne Wiederbelungsnachwirkung", GOSSIP_SENDER_MAIN, 4021);
player->ADD_GOSSIP_ITEM( 2, "Gebt mir 300 Gold", GOSSIP_SENDER_MAIN, 4023);
player->ADD_GOSSIP_ITEM( 0, "Aufwiedersehen"			, GOSSIP_SENDER_MAIN, 6660);

	}  else {


player->ADD_GOSSIP_ITEM( 0, "Shopping Mall", GOSSIP_SENDER_MAIN, 4022);
player->ADD_GOSSIP_ITEM( 7, "WoPC Exclusiv"	, GOSSIP_SENDER_MAIN, 4042);
player->ADD_GOSSIP_ITEM( 5, "PvP-Arena"        , GOSSIP_SENDER_MAIN, 4020);
player->ADD_GOSSIP_ITEM( 5, "Dalaran City"        , GOSSIP_SENDER_MAIN, 4025);
player->ADD_GOSSIP_ITEM( 2, "Entferne Wiederbelungsnachwirkung", GOSSIP_SENDER_MAIN, 4021);
player->ADD_GOSSIP_ITEM( 2, "Gebt mir 300 Gold", GOSSIP_SENDER_MAIN, 4023);
player->ADD_GOSSIP_ITEM( 0, "Aufwiedersehen"			, GOSSIP_SENDER_MAIN, 6660);
	}

player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());

break;

case 6660:
player->CLOSE_GOSSIP_MENU();
_Creature->MonsterSay("Aufwiedersehen bis Bald!", LANG_UNIVERSAL, NULL);
break;

case 4020:

    if (player->getLevel() >= 0)
        
    {
        player->CLOSE_GOSSIP_MENU();
        player->TeleportTo(530, -2052.761230f, 6652.012207f, 13.052157f, 3.717858f);
        //player->ModifyMoney(1*costo);
    }
    
break;

case 4021:
    if(!player->HasAura(15007,0))
    {
        _Creature->MonsterSay("Du hast keine Wiederbelebungsnachwirkung", LANG_UNIVERSAL, NULL);
        player->CLOSE_GOSSIP_MENU();
        return;
    }

    player->RemoveAurasDueToSpell(15007);
    player->CLOSE_GOSSIP_MENU();
    _Creature->MonsterSay("Deine Wiederbelebungsnachwirkungen wurden entfernt!", LANG_UNIVERSAL, NULL);
break;

case 4025:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(571, 5804.15f, 624.771f, 647.767f, 1.64f);
break;

case 4022:

if ( player->GetTeam() == ALLIANCE )
{
	player->CLOSE_GOSSIP_MENU();
	player->TeleportTo(0, -12158.4f, -1919.15f, 153.648f, 3.80327f);
}
else
{
	player->CLOSE_GOSSIP_MENU();
	player->TeleportTo(0, -12158.4f, -1919.15f, 153.648f, 3.80327f);
}
break;

case 4040:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(1, -6471.76f, 2967.85f, 7.71294f, 3.78682f);
break;

case 4041:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(0, -12879.17f, -1405.336f, 120.040f, 2.67f);
break;


case 4047:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(0, -1789.25f, -4236.05f, 2.23253f, 0.90f);
break;


case 4052:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(0, -13220.023f, 221.5747f, 33.242992f, 1.3f);
break;

case 4053:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(1, -7945.070f, -2120.027f, -218.109741f, 0.46f);
break;

case 4054:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(1, -956.519f, -3752.50f, 5.374513f, 1.5f);
break;

case 4061:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(469, -7664.0f, -1100.0f, 400.0f, 1.0f);
break;

case 4062:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(550, 4.0f, 0.0f, 4.0f, 6.0f);
break;

case 4063:

player->CLOSE_GOSSIP_MENU();
player->TeleportTo(615, 3228.0f, 384.0f, 71.0f, 1.0f);
break;

case 4023:
player->CLOSE_GOSSIP_MENU();
player->ModifyMoney(1*costo);
break;

case 4042:
player->ADD_GOSSIP_ITEM( 5, "Support (Wer Hilfe braucht)"                       , GOSSIP_SENDER_MAIN, 4047);
player->ADD_GOSSIP_ITEM( 5, "Quest Area"                       , GOSSIP_SENDER_MAIN, 4040);
player->ADD_GOSSIP_ITEM( 5, "Home City (Custom City)"                       , GOSSIP_SENDER_MAIN, 4041);
player->ADD_GOSSIP_ITEM( 7, "Events"				, GOSSIP_SENDER_MAIN, 4050);
player->ADD_GOSSIP_ITEM( 7, "-Instanzen-"				, GOSSIP_SENDER_MAIN, 4060);
player->ADD_GOSSIP_ITEM( 7, "-Hauptmenue-"					 , GOSSIP_SENDER_MAIN, 5552);
player->ADD_GOSSIP_ITEM( 0, "Aufwiedersehen"			, GOSSIP_SENDER_MAIN, 6660);

player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());

break;

case 4050:
player->ADD_GOSSIP_ITEM( 5, "PvP Event"                       , GOSSIP_SENDER_MAIN, 4052);
player->ADD_GOSSIP_ITEM( 5, "UnGoro Such Event"                       , GOSSIP_SENDER_MAIN, 4053);
player->ADD_GOSSIP_ITEM( 5, "Ratchet Such Event"                       , GOSSIP_SENDER_MAIN, 4054);
player->ADD_GOSSIP_ITEM( 7, "-Zuruek-"					 , GOSSIP_SENDER_MAIN, 4042);
player->ADD_GOSSIP_ITEM( 0, "Aufwiedersehen"			, GOSSIP_SENDER_MAIN, 6660);

player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());

break;

case 4060:
player->ADD_GOSSIP_ITEM( 5, "Blackwing Lair T7.5"                       , GOSSIP_SENDER_MAIN, 4061);
player->ADD_GOSSIP_ITEM( 5, "T8 Instance Part 1"                       , GOSSIP_SENDER_MAIN, 4062);
player->ADD_GOSSIP_ITEM( 5, "T8 Instance Part 2"                       , GOSSIP_SENDER_MAIN, 4063);
player->ADD_GOSSIP_ITEM( 7, "-Zuruek-"					 , GOSSIP_SENDER_MAIN, 4042);
player->ADD_GOSSIP_ITEM( 0, "Aufwiedersehen"			, GOSSIP_SENDER_MAIN, 6660);

player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());

break;

   }
}

bool GossipSelect_telefratz(Player *player, Creature *_Creature, uint32

sender, uint32 action )

{
if (sender == GOSSIP_SENDER_MAIN)
SendDefaultMenu_telefratz(player, _Creature, action   );

return true;

}
void AddSC_telefratz()
{
    Script *newscript;
 
newscript = new Script;
newscript->Name = "telefratz";
newscript->pGossipHello = &GossipHello_telefratz;
newscript->pGossipSelect = &GossipSelect_telefratz;
newscript->pItemHello = NULL;
newscript->pGOHello = NULL;
newscript->pAreaTrigger = NULL;
newscript->pItemQuestAccept = NULL;
newscript->pGOQuestAccept = NULL;
newscript->pGOChooseReward = NULL;

newscript->RegisterSelf();
}