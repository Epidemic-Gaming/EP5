/*
 loadout types based on array index
 0 - Bandit
 1 - Soldier
 2 - Paramedic
 3 - Hunter
 4 - Civilian
*/
class Loadout
{
	autoptr TStringArray starting_tops = 
	{
		"EpidemicHoodieBlack"
	};
	
	autoptr TStringArray  starting_bottoms = 
	{
        "EpidemicCargoPantsBlack"
	};
	
	autoptr TStringArray starting_bags = 
	{
	};
	
	autoptr TStringArray starting_shoes = 
	{
	};


	void dress_player(PlayerBase player){
		// select a random item from each list of starting items
		int  top_idx = Math.RandomIntInclusive(0, starting_tops.Count() - 1);
		int  bot_idx = Math.RandomIntInclusive(0, starting_bottoms.Count() - 1);
		int  bag_idx = Math.RandomIntInclusive(0, starting_bags.Count() - 1);
		int  sho_idx = Math.RandomIntInclusive(0, starting_shoes.Count() - 1);


		// create the selected item in the relevant slot
		player.GetInventory().CreateInInventory(starting_tops[top_idx]);
		player.GetInventory().CreateInInventory(starting_bottoms[bot_idx]);
		player.GetInventory().CreateInInventory(starting_bags[bag_idx] );
		player.GetInventory().CreateInInventory(starting_shoes[sho_idx]);
	}
};