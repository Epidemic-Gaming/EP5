#include "$CurrentDir:mpmissions\\dayzOffline.chernarusplus\\loadouts\\Epidemic.c"

void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	/* old weather
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

    weather.GetOvercast().SetLimits( 0.0 , 0.5 );
    weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.2 );
    weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );

    weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
    weather.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
    weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);
	*/ 

	// less rain
	Weather weather = g_Game.GetWeather();

    weather.GetOvercast().SetLimits(0.0, 0.0);
    weather.GetRain().SetLimits(0.0, 0.0);
    weather.GetFog().SetLimits(0.0, 0.0);

    weather.GetOvercast().SetForecastChangeLimits(0.0, 0.0);
    weather.GetRain().SetForecastChangeLimits(0.0, 0.0);
    weather.GetFog().SetForecastChangeLimits(0.0, 0.0);

    weather.GetOvercast().SetForecastTimeLimits(0, 0);
    weather.GetRain().SetForecastTimeLimits(0,0);
    weather.GetFog().SetForecastTimeLimits(0,0);

    weather.GetOvercast().Set(Math.RandomFloatInclusive(0.0, 0.0), 0, 0);
    weather.GetRain().Set(Math.RandomFloatInclusive(0.0, 0.0), 0, 0);
    weather.GetFog().Set(Math.RandomFloatInclusive(0.0, 0.0), 0, 0);

    weather.SetWindMaximumSpeed(0);
    weather.SetWindFunctionParams(0, 0, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();


	/* Populate custom buildings */
    // GetCEApi().ExportProxyData( "7500 0 7500", 10000 );
	
	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		autoptr Epidemic epi; 
    	epi = new Epidemic; 
	    epi.First_Spawn(player); 
	}
};


Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
