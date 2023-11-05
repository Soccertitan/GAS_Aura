// Copyright CrimsonAzure


#include "AbilitySystem/AbilityTasks/TargetDataUnderMouse.h"

UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility);
	
	return MyObj;
}

void UTargetDataUnderMouse::Activate()
{
	APlayerController* PC = Ability->GetCurrentActorInfo()->PlayerController.Get();
	
	FHitResult HitResult;
	PC->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	
	ValidData.Broadcast(HitResult.Location);
}
