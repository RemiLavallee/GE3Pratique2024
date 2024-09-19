// Fill out your copyright notice in the Description page of Project Settings.


#include "TorcheManager.h"

#include "Torch.h"

// Sets default values
ATorcheManager::ATorcheManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATorcheManager::BeginPlay()
{
	Super::BeginPlay();

	for (const auto Torch : Torches)
	{
		Torch->TorcheManager = this;
	}
	
}

// Called every frame
void ATorcheManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATorcheManager::ValidateTorchHit(ATorch* TorchHit)
{
	if(NextTorcheIndex >= Torches.Num())
	{
		return false;
	}
	
	if(TorchHit != Torches[NextTorcheIndex])
	{
		return false;
	}
	
	NextTorcheIndex++;

	if(NextTorcheIndex == Torches.Num())
	{
		DoorToOpen->Destroy();
	}

	return true;
}

