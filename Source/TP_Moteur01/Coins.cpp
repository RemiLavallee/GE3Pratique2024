// Fill out your copyright notice in the Description page of Project Settings.


#include "Coins.h"

#include "TP_Moteur01Character.h"

// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoins::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoins::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	auto Player = Cast<ATP_Moteur01Character>(OtherActor);

	if(Player != nullptr)
	{
		Player->CoinCounter++;
		FString Message = FString::Printf(TEXT("Coins: %d"), Player->CoinCounter);
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, Message);
	}

	Destroy();
}





