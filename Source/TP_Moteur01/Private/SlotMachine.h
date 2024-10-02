// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlotMachine.generated.h"

UCLASS()
class ASlotMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlotMachine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	virtual void Spin(UStaticMeshComponent* component);

	virtual void TriggerDelay(float delayTime);
private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* ReelsComponent;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* LeverComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PivotLeverMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ReelLeftMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ReelMidMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ReelRightMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BoxMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* WinButtonMesh;

	float LeverAngle;

	FTimerHandle TimerHandle;
};
