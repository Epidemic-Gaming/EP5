#include "$CurrentDir:mpmissions\\dayzOffline.chernarusplus\\loadouts\\Loadout.c"


class Epidemic
{
    void First_Spawn(PlayerBase player)
    {

    	autoptr Loadout loadout; 
    	loadout = new Loadout; // from Loadout.c
    	EntityAI itemTop;   // shirt slot inventory
		EntityAI itemBot;   // pants
		EntityAI itemBck;   // backpack
		EntityAI itemWst;   // belt
		
		EntityAI itemEnt;   // an item entity 

		float rand;

        player.RemoveAllItems();

		//set hunger and thirst  -- 1500 is full for a long time. 5000 is the limit, maybe without puking
		player.GetStatWater().Set(1500);
        player.GetStatEnergy().Set(6000);

        loadout.dress_player(player);

		itemTop = player.FindAttachmentBySlotName("Body");
		itemBot = player.FindAttachmentBySlotName("Legs");
		itemBck = player.FindAttachmentBySlotName("Back");
		itemWst = player.FindAttachmentBySlotName("Hips");

		player.GetInventory().CreateInInventory("CivilianBelt");
		player.GetInventory().CreateInInventory("CombatBoots_Black");


		itemEnt = itemTop.GetInventory().CreateInInventory("BandageDressing");
		itemEnt = itemTop.GetInventory().CreateInInventory("Canteen");
		itemEnt = itemTop.GetInventory().CreateInInventory("TacticalBaconCan");
		itemEnt = itemBot.GetInventory().CreateInInventory("KitchenKnife");
		itemEnt = itemBck.GetInventory().CreateInInventory("FlashLight");
		itemEnt = itemBck.GetInventory().CreateInInventory("Battery9V");
		itemEnt = itemBck.GetInventory().CreateInInventory("Battery9V");	
	}
};