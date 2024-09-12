// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserTrap.h"

// Sets default values
ALaserTrap::ALaserTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LaserBase = CreateDefaultSubobject<UStaticMeshComponent>("LaserBase");
	RootComponent = LaserBase;
	LaserBeam = CreateDefaultSubobject<UStaticMeshComponent>("LaserBeam");
	LaserBeam->AttachToComponent(LaserBase,FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void ALaserTrap::BeginPlay()
{
	Super::BeginPlay();
	LaserBeam->SetHiddenInGame(true);
	LaserBeam->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

// Called every frame
void ALaserTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LaserBeam->SetHiddenInGame(true);
	LaserBeam->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

