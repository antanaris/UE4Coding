// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE4CodingGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE4CODING_API AUE4CodingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "X") 
	TSubclassOf<AActor> RandomNumberBPClass;

	AUE4CodingGameModeBase();

};
