// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaserTrap.generated.h"

UCLASS()
class ALaserTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserTrap();

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LaserBase;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LaserBeam;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
