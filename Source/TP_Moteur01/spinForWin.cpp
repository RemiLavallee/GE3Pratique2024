// Fill out your copyright notice in the Description page of Project Settings.


#include "spinForWin.h"

#include "ToolContextInterfaces.h"

// Sets default values
AspinForWin::AspinForWin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AspinForWin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AspinForWin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator Rotator =FRotator();
	Rotator.Yaw += DeltaTime * 20.0;
	AddActorLocalRotation(Rotator);
}

