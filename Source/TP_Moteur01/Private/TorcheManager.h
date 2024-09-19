// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TorcheManager.generated.h"

UCLASS()
class ATorcheManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorcheManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool ValidateTorchHit(class ATorch* TorchHit);

private:

	UPROPERTY(EditAnywhere)
	TArray<ATorch*> Torches;

	int NextTorcheIndex;

	UPROPERTY(EditAnywhere)
	AActor* DoorToOpen;

};
