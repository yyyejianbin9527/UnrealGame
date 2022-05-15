// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BlasterPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAME_API ABlasterPlayerState : public APlayerState
{
	GENERATED_BODY()


public:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual void OnRep_Score() override;

	UFUNCTION()
	virtual void OnRep_Defeats();
	
	/*
	 *
	 */

	void AddToScore(float ScoreAmount);

	void AddToDefeats(int32 DefeatsAmount);
	
protected:

private:

	class ABlasterCharacter* Character;

	class ABlasterPlayerController* Controller;

	UPROPERTY(ReplicatedUsing="OnRep_Defeats")
	int32 Defeats;

	
	
};
