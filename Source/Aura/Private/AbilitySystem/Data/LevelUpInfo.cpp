// Copyright CrimsonAzure


#include "AbilitySystem/Data/LevelUpInfo.h"

int32 ULevelUpInfo::FindLevelForXP(int32 InExp) const
{
	int32 Level = 1;
	bool bSearching = true;

	while (bSearching)
	{
		// LevelUpInfo[1] = Level 1 Information
		// LevelUpInfo[2] = Level 2 Information
		if (LevelUpInfo.Num() - 1 <= Level) return Level;

		if (InExp >= LevelUpInfo[Level].LevelUpRequirement)
		{
			++Level;
		}
		else
		{
			bSearching = false;
		}
	}
	return Level;
}
